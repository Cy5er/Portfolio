# Source: https://pynative.com/python-postgresql-tutorial/
import psycopg2
from psycopg2 import Error
from sqlalchemy import create_engine, text
import pandas as pd
import numpy as np
from pathlib import Path


def run_sql_from_file(sql_file, psql_conn):
    '''
	read a SQL file with multiple stmts and process it
	adapted from an idea by JF Santos
	Note: not really needed when using dataframes.
    '''
    sql_command = ''
    for line in sql_file:
        #if line.startswith('VALUES'):        
     # Ignore commented lines
        if not line.startswith('--') and line.strip('\n'):        
        # Append line to the command string, prefix with space
           sql_command +=  ' ' + line.strip('\n')
           #sql_command = ' ' + sql_command + line.strip('\n')
        # If the command string ends with ';', it is a full statement
        if sql_command.endswith(';'):
            # Try to execute statement and commit it
            try:
                #print("running " + sql_command+".") 
                psql_conn.execute(text(sql_command))
                #psql_conn.commit()
            # Assert in case of error
            except:
                print('Error at command:'+sql_command + ".")
                ret_ =  False
            # Finally, clear command string
            finally:
                sql_command = ''           
                ret_ = True
    return ret_

DATADIR = str(Path(__file__).parent.parent) # for relative path 

try:
   # Connect to an test database 
   # NOTE: 
   # 1. NEVER store credential like this in practice. This is only for testing purpose
   # 2. Replace your "database" name, "user" and "password" that we provide to test the connection to your database 
   connection = psycopg2.connect(
   database="grp18_dairyfarm",  # TO BE REPLACED
   user='grp18',    # TO BE REPLACED
   password='PXiK3Oev', # TO BE REPLACED
   host='dbcourse2022.cs.aalto.fi', 
   port= '5432'
   )

   # Create a cursor to perform database operations
   cursor = connection.cursor()
   # Print PostgreSQL details
   print("PostgreSQL server information")
   print(connection.get_dsn_parameters(), "\n")
   # Executing a SQL query
   cursor.execute("SELECT version();")
   # Fetch result
   record = cursor.fetchone()
   print("You are connected to - ", record, "\n")

   #dostuff:
   print("Do stuff:", "\n")

   #Connect to db using SQLAlchemy create_engine
   DIALECT = 'postgresql+psycopg2://'
   database ='grp18_dairyfarm'
   db_uri = "%s:%s@%s/%s" % ('grp18', 'PXiK3Oev', 'dbcourse2022.cs.aalto.fi', database)
   print(DIALECT+db_uri) # postgresql+psycopg2://test_admin:pssword@localhost/tutorial4
   engine = create_engine(DIALECT + db_uri)
   sql_file1  = open(DATADIR + '/code/sqlstuff.sql')
   psql_conn  = engine.connect()
   
   #make the tables
   run_sql_from_file (sql_file1, psql_conn)

   #create the trigger for updating the organic values in route
   psql_conn.execute((""" DROP TRIGGER IF EXISTS organiccheck ON consistsof; """))
   
   psql_conn.execute(("""  
   CREATE OR REPLACE FUNCTION organiccheckk() 
   RETURNS trigger AS 
   $BODY$
   BEGIN
         UPDATE route 
         SET organic = 'N' 
         WHERE number = NEW.number AND NEW.id IN (SELECT id FROM dairyfarm WHERE organic = 'N');
         RETURN NEW;
   END; $BODY$
   LANGUAGE plpgsql;"""))

   psql_conn.execute((""" 
   CREATE TRIGGER organiccheck 
   AFTER INSERT 
   ON consistsof
   FOR EACH ROW
   EXECUTE PROCEDURE organiccheckk(); """))

   #read the data
   farms = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='Farms')
   drivers = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='Drivers')
   routes = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='PlannedMIlkRoute')
   visits = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='MilkPickUp')
   silos = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='SiloLog')

   #rename stuff
   farms.columns = ['id','name','organic','address','a','b','latitude','longitude']
   drivers.columns = ['id','gender','firstname','surname','homeaddress','phonenumber','employmentstartdate']
   
   #take the wanted stuff, mostly columns
   farms = farms.loc[:,['id','name','address','organic','latitude','longitude']]
   drivers = drivers.loc[:,['id','gender','employmentstartdate']]

   #insert data to tables
   farms.to_sql('dairyfarm', con=engine, if_exists='append', index=False)
   drivers.to_sql('driver', con=engine, if_exists='append', index=False)


   #route
   routes = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='PlannedMIlkRoute')
   routes.columns = ['u','number','firststop','secondstop','thirdstop','fourthstop','fifthstop']
   routes.index = ['q','w','x','0','1','2']
   routes = routes.loc[['0','1','2'],['number']]
   routes['organic'] = ['Y', 'Y', 'Y'] #added this
   routes.to_sql('route', con=engine, if_exists='append', index=False)

   #consistof
   consistsof = pd.read_excel(DATADIR + '/data/SampleData_for_Dairy_Farms.xls', sheet_name='PlannedMIlkRoute')
 

   i = 3
   maxj = 4
   while i < 6:
       j = 1
       if (i == 4):
           maxj = 6
       if (i == 5):
           maxj = 3
       while j < maxj:
            #store stop 1
            currentRoute = consistsof.iloc[[i],[1,j+1]]
            #rename and organise the cloumns
            currentRoute.columns = ['number','id']
            #insert data
            currentRoute.to_sql('consistsof', con=engine, if_exists='append', index=False)
            j = j + 1
       i = i + 1
    
   #silo data aka run
   r = 2
   while r < 32:
       #take one days' silo data
       currentRun = silos.iloc[r:r+3,1:9]
       #rename and otganize columns
       currentRun.columns = ['date','route','silo','totalmilk','mfat','mprot', 'scc', 'driverid']
       currentRun = currentRun.loc[:,['date','silo','driverid','route','mfat','mprot', 'scc','totalmilk',]]
       #drop null rows
       currentRun = currentRun.dropna()
       #insert the data
       currentRun.to_sql('run', con=engine, if_exists='append', index=False)
       r = r + 6

   #the complicated table: visitdata
   row = 0
   while row <= 30:
       #take the current date
       thisDate = visits.iat[row+1,0]
       #take one days' visits
       currentVisit = visits.iloc[row:row+5,2:12]
       #flip rows to columns
       currentVisit = currentVisit.transpose()
       #add the date
       currentVisit['date'] = [thisDate,thisDate,thisDate,thisDate,thisDate,thisDate,thisDate,thisDate,thisDate,thisDate]
       #rename columns
       currentVisit.columns = ['farmid','mfat','mprot','scc','amountofmilk','date']
       currentVisit = currentVisit.loc[:,['date','farmid','amountofmilk','mfat','mprot','scc']]
       #insert the data
       currentVisit.to_sql('visitdata', con=engine, if_exists='append', index=False)
       row = row + 6
   

   #test
   result = psql_conn.execute((""" SELECT * FROM route """ ))
   print(f'After create and insert:\n{result.fetchall()}')


except (Exception, Error) as error:
   print("Error while connecting to PostgreSQL", error)
finally:
   if (connection):
      cursor.close()
      connection.close()
      print("PostgreSQL connection is closed")