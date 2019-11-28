#include "dog.h"

// Constructor / Destructor - note how delegation to base class works!
Dog::Dog(Dog_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Dog::Dog(std::istream& ist):Animal(ist){
    std::string breed;
    ist>>breed;
        if(breed=="Mix"){_breed=Dog_breed::MIX ;}
        else if(breed=="Labrador"){ _breed=Dog_breed::LABRADOR;}
        else if(breed=="Retriever"){_breed=Dog_breed::RETRIEVER;} 
        else if(breed=="Shepherd"){_breed=Dog_breed::SHEPHERD;} 
        else if(breed=="Bulldog"){_breed=Dog_breed::BULLDOG;} 
        else if(breed=="Beagle"){_breed=Dog_breed::BEAGLE;} 
        else if(breed=="Poodle"){_breed=Dog_breed::POODLE;} 
        else if(breed=="Rottweiler"){_breed=Dog_breed::ROTTWEILER;} 
        else if(breed=="Pointer"){_breed=Dog_breed::POINTER;} 
        else if(breed=="Terrier"){_breed=Dog_breed::TERRIER;} 
        else if(breed=="Boxer"){_breed=Dog_breed::BOXER;} 
        else if(breed=="Dachshund"){_breed=Dog_breed::DACHSHUND;} 
}
Dog::~Dog() { }

// Overrides for pure virtual methods
std::string Dog::family() const {return "dog";}
std::string Dog::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Dog_breed& breed) {
    switch(breed) {
        case  Dog_breed::MIX:        return "Mix";
        case  Dog_breed::LABRADOR:   return "Labrador";
        case  Dog_breed::RETRIEVER:  return "Retriever"; 
        case  Dog_breed::SHEPHERD:   return "Shepherd"; 
        case  Dog_breed::BULLDOG:    return "Bulldog"; 
        case  Dog_breed::BEAGLE:     return "Beagle"; 
        case  Dog_breed::POODLE:     return "Poodle"; 
        case  Dog_breed::ROTTWEILER: return "Rottweiler"; 
        case  Dog_breed::POINTER:    return "Pointer"; 
        case  Dog_breed::TERRIER:    return "Terrier"; 
        case  Dog_breed::BOXER:      return "Boxer"; 
        case  Dog_breed::DACHSHUND:  return "Dachshund"; 
        default:                     return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& ost, const Dog_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
 std::string Dog::save(std::stringstream& ost){
  ost<<"dog"<<std::endl;
  ost<<_name<<std::endl;
  ost<<_gender<<std::endl;
  ost<<_age<<std::endl;
  ost<<_breed<<std::endl;
 return ost.str();
}
