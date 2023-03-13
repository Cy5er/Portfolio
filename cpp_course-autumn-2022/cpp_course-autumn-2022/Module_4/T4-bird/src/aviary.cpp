#include "aviary.hpp"

void Aviary::Add(Bird* birb) {
    if(birb == NULL) {
        throw std::logic_error("UR MOM");
    }
    birdemic.emplace_back((birb));
}

void Aviary::SpeakAll(std::ostream& out) const {
    for (auto& birb : birdemic) {
        birb -> Speak(out);
    }
}

const Bird* Aviary::operator[](Aviary::sizeType cock) const {
    if(Size() <= cock) {
        throw std::out_of_range("UR MOM");
    }
    return birdemic[cock];
}

Bird* Aviary::operator[](Aviary::sizeType cock) {
    if(Size() <= cock) {
        throw std::out_of_range("UR MOM");
    }
    return birdemic[cock];
}