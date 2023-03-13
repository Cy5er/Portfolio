/* Add include guards here */
#ifndef PRINTER_HPP
#define PRINTER_HPP
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "string_printer.hpp"
/**
 * @brief: A storage for StringPrinter pointers associated with a name. The
 * class has ownership of the objects.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * 
 * A default constructor that initializes the object with zero printers.
 * 
 * A copy constructor that copies the object.
 * 
 * Add: A function that adds a new StringPrinter object to the collection
 * and associates it with a name.
 * Takes two parameters:
 *  - a string that contains the name
 *  - the StringPrinter pointer to be added
 * Throws:
 *  - std::invalid_argument if an association for the name already exists ("Duplicate index").
 *  - std::invalid_argument if the pointer is null ("Invalid printer").
 * Note: The Printers object takes ownership of the pointer and is
 *  therefore responsible for eventually calling delete on the pointer.
 * 
 * Indexing operator: The collection is indexed using the
 * name (string) and returns a reference to the associated StringPrinter.
 * Throws:
 *  - std::invalid_argument if an association does not exist ("Unknown index").
 * 
 * Copy assignment operator: copies the object given to self.
 * ------------
 * Members:
 * Whatever you deem necessary.
 * ------------
 * Other:
 * Copying means copying the contained StringPrinters as well.
 * Remember to also implement the destructor.
 */

class Printers{
    private:
        std::map<const std::string, StringPrinter *> arr_;
    public:
        Printers();
        ~Printers();
        Printers(const Printers& );
        void Add(const std::string&, StringPrinter*);
        StringPrinter& operator[] (const std::string&);
        Printers& operator=(const Printers&);

};
#endif