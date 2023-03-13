#include "person.hpp"

// define your Person class' functions here
Person::Person(const std::string& name, const int& birth_year)
        : name_(name), birth_year_(birth_year) {
}

const std::string& Person::GetName() const {
    return name_;
}

const int& Person::GetYear() const {
    return birth_year_;
}

const int& Person::GetAge(int year) const {
    const int& age_ = year - Person::GetYear() ;
    return age_;
}