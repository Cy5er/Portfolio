#include "boat.hpp"
#include<sstream>
//TODO: implement Boat's members

Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power) 
: Vehicle(register_number,owner) { name_ = name; draft_ = draft; power_ = power; }

void Boat::Write(std::ostream& stream) {
    stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << name_ << ";" << draft_ << ";" << power_ << std::endl;
}

void Boat::Print(){
    Write(std::cout);
}

Boat* Boat::Read(std::istream& stream) {
    
    char input[256];
    std::string parameters[3];
    stream.getline(input,256);
    std::string parsed;
    std::stringstream ssInput(input);

    getline(ssInput,parsed,';');
    if (parsed[0] != 'B') return NULL;

    for (int i = 0; i < 3; i++) {
    getline(ssInput,parsed,';');
    parameters[i] = parsed;
    }

    getline(ssInput,parsed,';');
    double draft = std::stod(parsed);

    getline(ssInput,parsed,';');
    double pow = std::stod(parsed);
    
    return new Boat(parameters[0],parameters[1],parameters[2],draft,pow);

}