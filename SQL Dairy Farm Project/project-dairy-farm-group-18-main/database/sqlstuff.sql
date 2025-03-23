DROP TABLE IF EXISTS driver;
CREATE TABLE driver (
    id VARCHAR(100) NOT NULL,
    firstname VARCHAR(100),
    surname VARCHAR(100),
    gender VARCHAR(100) CHECK(gender = 'M' OR gender = 'F'),
    homeaddress VARCHAR(100),
    phonenumber VARCHAR(100),
    employmentstartdate DATE,
    PRIMARY KEY (id)
);

DROP TABLE IF EXISTS rundata;
CREATE TABLE rundata (
    date DATE NOT NULL,
    silo INT NOT NULL,
    routenumber INT NOT NULL,
    PRIMARY KEY (date, silo)
);

DROP TABLE IF EXISTS run;
CREATE TABLE run (
    date DATE NOT NULL,
    silo VARCHAR(100) NOT NULL,
    driverid VARCHAR(100) NOT NULL,
    route VARCHAR(100) NOT NULL,
    mfat REAL NOT NULL,
    mprot REAL NOT NULL,
    scc INT NOT NULL,
    totalmilk REAL NOT NULL,
    PRIMARY KEY (date, silo)
);

DROP TABLE IF EXISTS visitdata;
CREATE TABLE visitdata (
    date DATE NOT NULL,
    farmid INT NOT NULL,
    amountofmilk REAL NOT NULL,
    mfat REAL,
    mprot REAL,
    scc INT,
    PRIMARY KEY(date, farmid)
);

DROP TABLE IF EXISTS dairyfarm;
CREATE TABLE dairyfarm (
    id INT NOT NULL,
    name VARCHAR(100) NOT NULL,
    address VARCHAR(100) NOT NULL,
    organic VARCHAR(100) CHECK(organic = 'Y' OR organic = 'N'),
    latitude REAL NOT NULL,
    longitude REAL NOT NULL,
    PRIMARY KEY(id)
);

DROP TABLE IF EXISTS route;
CREATE TABLE route (
    number VARCHAR(100) NOT NULL,
    organic VARCHAR(100) CHECK(organic = 'Y' OR organic = 'N'),
    PRIMARY KEY(number)
);

DROP TABLE IF EXISTS consistsof;
CREATE TABLE consistsof (
    number VARCHAR(100) NOT NULL,
    id INT NOT NULL,
    PRIMARY KEY(number,id)
);



