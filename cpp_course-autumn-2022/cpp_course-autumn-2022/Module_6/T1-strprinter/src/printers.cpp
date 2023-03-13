#include "printers.hpp"

Printers::Printers() : arr_(){};
Printers::~Printers(){
    for (auto i : arr_){
        delete i.second;
    }
}
void Printers::Add(const std::string& str, StringPrinter* pointer){
    if (pointer == NULL){
        throw std::invalid_argument("Invalid printer");
    }
    else if(arr_.find(str) != arr_.end()){
        throw std::invalid_argument("Duplicate index");
    }
    else{
        arr_.insert({str,pointer});
    }
}

StringPrinter& Printers::operator[](const std::string& str){
    if(arr_.find(str) == arr_.end()){
        throw std::invalid_argument("Unknown index");
    }
    else{
        return *arr_.at(str);
    }
}

Printers& Printers::operator=(const Printers& pointer){
    for (auto i : pointer.arr_){
        (*this).Add(i.first,i.second->Clone());
    }
    return *this;
}

Printers::Printers(const Printers& pointer){
    for (auto i:pointer.arr_){
        std::cout << i.first << std::endl;
        (*this).Add(i.first, i.second->Clone());
    }
}