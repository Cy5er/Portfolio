#include "diagonal_printer.hpp"

DiagonalPrinter* DiagonalPrinter::Clone() const {
            return new DiagonalPrinter(x_, y_, os_);
        }

StringPrinter& DiagonalPrinter::operator()(const std::string& str) {
            int a = 0;
            int b = str.size() - 1;
            if(x_ != "") {
                os_ << x_ << std::endl; 
            } 
            for(auto i: str) {
                os_ << std::string(a, ' ') << i << std::string(b, ' ') << std::endl;
                a++;
                b--;
            }
            if(y_ != "") {
                os_ << y_ << std::endl; 
            }
            return *this;
        }

