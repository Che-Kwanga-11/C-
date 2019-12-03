#include "animal.h"
#include <iomanip>
#include <sstream>

// Constructors / Destructors
Animal::Animal(std::string name, Gender gender, int age)
    : _name{name}, _gender{gender}, _age{age} { }
Animal::Animal(std::istream& ist){
    ist>>_name;
    std::string gender;
    ist>>gender;
    if(gender=="male"){_gender=Gender::MALE;}
    else{_gender=Gender::FEMALE;}
    ist>>_age;
}
Animal::~Animal() { }

// Getters
std::string Animal::name() const {return _name;}
Gender Animal::gender() const {return _gender;}
int Animal::age() const {return _age;}

// Convert Animal and its derived classes to a string and stream representation
std::string Animal::to_string() const {
    std::ostringstream oss;
    oss<<std::setw(30)<<std::left<<_name<<" "
       <<std::setw(20)<<std::left<<::to_string(this->gender())<<" "
       <<std::setw(20)<<std::right<<this->breed()<<" "
       <<std::setw(20)<<std::right<<this->family()<<" "
       <<std::setw(20)<<std::right<<std::to_string(this->age());
    return oss.str();
}
std::ostream& operator<<(std::ostream& ost, const Animal& animal) {
    ost << animal.to_string();
    return ost;
}
  std::string Animal::save(std::stringstream& ost){
}

// Convert Gender to a string and stream representation
std::string to_string(Gender gender) {return ((gender == Gender::FEMALE) ? "female" : "male");}
std::ostream& operator<<(std::ostream& ost, const Gender& gender) {
    ost << to_string(gender);
    return ost;
}

