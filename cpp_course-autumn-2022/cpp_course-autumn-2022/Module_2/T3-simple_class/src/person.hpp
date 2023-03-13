#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON
#include <string>
#include <iostream>

// declare your Person class here

class Person{
public:
    Person(const std::string& name, const int& birth_year);
    const std::string& GetName() const;
    const int& GetAge(int year) const;
    const int& GetYear() const;
private:
    std::string name_;
    int birth_year_;
    //int age_ = 2020 - birth_year_;
    int age_;
};

#endif