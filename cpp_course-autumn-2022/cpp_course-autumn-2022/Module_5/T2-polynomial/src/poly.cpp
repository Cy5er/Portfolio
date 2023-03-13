#include "poly.hpp"

#include <iostream>
#include <sstream>
#include <vector>

/* Recommended order for implementing:
 * 1. Unary operator-
 * 2. Binary operators: operator+= & operator+
 * 3. operator-= & operator-
 * 4. Operators for comparisons.
 * 5. Input & output operators.
 */

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}


Poly operator+(const Poly& a, const Poly& b){
    Poly p;
    auto aStepper = a.begin();
    auto bStepper = b.begin();
    while (aStepper != a.end() && bStepper != b.end()){
        if ((*aStepper).first == (*bStepper).first) {
            p[(*aStepper).first] = (*aStepper).second + (*bStepper).second;
            aStepper++;
            bStepper++;
        }
        else if (((*aStepper).first < (*bStepper).first)){
            p[(*aStepper).first] = (*aStepper).second;
            aStepper++;
        }
        else {
            p[(*bStepper).first] = (*bStepper).second;
            bStepper++;
        }
    }
    while (aStepper != a.end()){
        p[(*aStepper).first] = (*aStepper).second;
        aStepper++;
    }
    while (bStepper != b.end()){
        p[(*bStepper).first] = (*bStepper).second;
        bStepper++;
    }
    return p;
}

Poly operator-(const Poly& a, const Poly& b){
    Poly p;
    auto aStepper = a.begin();
    auto bStepper = b.begin();
    while (aStepper != a.end() && bStepper != b.end()){
        if ((*aStepper).first == (*bStepper).first) {
            p[(*aStepper).first] = (*aStepper).second - (*bStepper).second;
            aStepper++;
            bStepper++;
        }
        else if (((*aStepper).first < (*bStepper).first)){
            p[(*aStepper).first] = (*aStepper).second;
            aStepper++;
        }
        else {
            p[(*bStepper).first] = -(*bStepper).second;
            bStepper++;
        }
    }
    while (aStepper != a.end()){
        p[(*aStepper).first] = (*aStepper).second;
        aStepper++;
    }
    while (bStepper != b.end()){
        p[(*bStepper).first] = -(*bStepper).second;
        bStepper++;
    }
    return p;
}

Poly operator-(const Poly& p){
    Poly p1;
    auto stepper = p.begin();
    while(stepper != p.end()){
        p1[(*stepper).first] = - p[(*stepper).first];
        stepper++;
    }
    return p1;
}

Poly& Poly::operator+=(const Poly& b){
    auto bStepper = b.begin();
    while(bStepper != b.end()){
        this->values_[(*bStepper).first] += (*bStepper).second;
        bStepper++;
    }

    return *this;
}

Poly& Poly::operator-=(const Poly& b){
    auto bStepper = b.begin();
    while(bStepper != b.end()){
        this->values_[(*bStepper).first] -= (*bStepper).second;
        bStepper++;
    }

    return *this;
}

bool operator<(const Poly& a, const Poly& b){ return (*a.end() < *b.end()); }
bool operator==(const Poly& a, const Poly& b){ return (*a.end() == *b.end()); }
bool operator>(const Poly& a, const Poly& b){ return (*a.end() > *b.end()); }
bool operator!=(const Poly& a, const Poly& b){ return (*a.end() != *b.end()); }

const std::string delims("x+");
inline bool isDelim(char c) {
    for (long unsigned int i = 0; i < delims.size(); ++i)
        if (delims[i] == c)
            return true;
    return false;
}

std::istream& operator>>(std::istream& is, Poly& p){

    std::vector<int> nums;
    std::string line;
    std::getline(is, line,' ');
    std::size_t prev = 0, pos;
    while ((pos = line.find_first_of("x+-", prev)) != std::string::npos) {
        if (pos > prev){
            std::stringstream ss1(line.substr(prev, pos-prev));
            int toAdd;
            ss1 >> toAdd;

            if (prev > 0 && line[prev-1] == '-'){
                nums.push_back(-toAdd);
            } 
            else nums.push_back(toAdd);
        }
        prev = pos+1;
    }
    if (prev < line.length()){
        std::stringstream ss2(line.substr(prev, std::string::npos));
        int toAdd;
        ss2 >> toAdd;
        nums.push_back(toAdd);
    }
    for (size_t i = 0; i < nums.size();i += 2){
        p[nums[i+1]] += nums[i];
    }

    return is;
    
}


std::ostream& operator<<(std::ostream& os, const Poly& p){
    auto stepper = p.rbegin();
    if (stepper == p.rend()) return os;

    if ((*stepper).second != 0){
    os << (*stepper).second << "x" << (*stepper).first;
    }
    stepper++;

    while (stepper != p.rend()){
    if ((*stepper).second != 0){
    if ((*stepper).second > 0){ os << "+";}

    os <<(*stepper).second << "x" << (*stepper).first;
    }

    stepper++;

    }

    return os;
}