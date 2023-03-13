#include "aircraft.hpp"
#include<sstream>
//TODO: implement Aircraft's members

Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed) 
: Vehicle(register_number,owner) { model_ = model; wingspan_ = wingspan; cruise_speed_ = cruise_speed; }

void Aircraft::Write(std::ostream& stream) {
    stream << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" << model_ << ";" << wingspan_ << ";" << cruise_speed_ << std::endl;
}

void Aircraft::Print(){
    Write(std::cout);
}

Aircraft* Aircraft::Read(std::istream& stream) {

    char input[256];
    std::string parameters[3];
    stream.getline(input,256);
    std::string parsed;
    std::stringstream ssInput(input);

    getline(ssInput,parsed,';');
    if (parsed[0] != 'A') return NULL;

    for (int i = 0; i < 3; i++) {
    getline(ssInput,parsed,';');
    parameters[i] = parsed;
    }

    getline(ssInput,parsed,';');
    double wing = std::stod(parsed);

    getline(ssInput,parsed,';');
    unsigned int cruise = std::stoul(parsed);



    return new Aircraft(parameters[0],parameters[1],parameters[2],wing,cruise);

}