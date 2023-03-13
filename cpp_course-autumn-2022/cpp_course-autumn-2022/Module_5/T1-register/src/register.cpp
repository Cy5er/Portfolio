#include "register.hpp"
//TODO: implement Register's members
#include <iostream>
#include <fstream>
#include <sstream>
#include "boat.hpp"
#include "aircraft.hpp"

Register::~Register(){}

void Register::Add(Vehicle* v){ vehicles_.push_back(v); }

void Register::Save(const std::string& filename) const {

    std::ofstream os(filename);
    for (auto i : vehicles_){
        i->Write(os);
    }
    os.close();
}

bool Register::ReadLine(std::istream& stream){

    char type = stream.peek();
    if (type == 'A'){
        Add(Aircraft::Read(stream));
        return true;
    }
    else if (type == 'B'){
        Add(Boat::Read(stream));
        return true;
    } else {
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return false;
    }
    
}

int Register::Load(const std::string& filename){
    int added = 0;
    std::ifstream is(filename);

    if (is.rdstate() & (is.failbit | is.badbit)) return -1;

    while (!is.eof()){
        if(ReadLine(is)) added++;
    }
    if(ReadLine(is)) added++;

    return added;
}

void Register::Print(){
    for (auto i : vehicles_){
        i->Print();
    }
}
size_t Register::Size() const{ return vehicles_.size(); }