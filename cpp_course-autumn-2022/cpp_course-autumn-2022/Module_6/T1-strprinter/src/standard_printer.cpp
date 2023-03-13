#include "standard_printer.hpp"

StandardPrinter::StandardPrinter(std::ostream& os): StringPrinter(os) {}

StandardPrinter::~StandardPrinter(){}

StandardPrinter* StandardPrinter::Clone() const {
    return new StandardPrinter(os_);
}

StringPrinter& StandardPrinter::operator()(const std::string& str) {
            os_ << str << std::endl;
            return *this;
        } 