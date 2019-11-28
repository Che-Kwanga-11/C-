#include "rabbit.h"
#include <map>

Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::Rabbit(std::istream& ist):Animal(ist){
    std::string breed;
    ist>>breed;
        if(breed=="California White"){_breed=Rabbit_breed::CALIFORNIA_WHITE;}
        else if(breed=="Vienna White"){ _breed=Rabbit_breed::VIENNA_WHITE;}
        else if(breed=="Chinchilla"){_breed=Rabbit_breed::CHINCHILLA;} 
        else if(breed=="Giant Chinchilla"){_breed=Rabbit_breed::GIANT_CHINCHILLA;} 
        else if(breed=="Flemish Chinchilla"){_breed=Rabbit_breed::FLEMISH_CHINCHILLA;} 
        else if(breed=="Rex"){_breed=Rabbit_breed::REX;} 
        else if(breed=="Lionhead"){_breed=Rabbit_breed::LIONHEAD;} 
        else if(breed=="Silver Fox"){_breed=Rabbit_breed::SILVER_FOX;} 
        else if(breed=="New Zealand"){_breed=Rabbit_breed::NEW_ZEALAND;} 
        else if(breed=="Lop"){_breed=Rabbit_breed::LOP;} 
        else if(breed=="Polish"){_breed=Rabbit_breed::POLISH;} 
        else if(breed=="Harlequin"){_breed=Rabbit_breed::HARLEQUIN;} 
}
Rabbit::~Rabbit() { }
std::string Rabbit::family() const {return "rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

std::string to_string(const Rabbit_breed& breed) {
    std::map<Rabbit_breed,std::string> rabbits_map {
        { Rabbit_breed::CALIFORNIA_WHITE,  "California White"}, 
        { Rabbit_breed::VIENNA_WHITE,  "Vienna White"},
        { Rabbit_breed::CHINCHILLA,  "Chinchilla"}, 
        { Rabbit_breed::GIANT_CHINCHILLA,  "Giant Chinchilla"}, 
        { Rabbit_breed::FLEMISH_CHINCHILLA,  "Flemish Chinchilla"}, 
        { Rabbit_breed::REX,  "Rex"}, 
        { Rabbit_breed::LIONHEAD,  "Lionhead"}, 
        { Rabbit_breed::SILVER_FOX,  "Silver Fox"}, 
        { Rabbit_breed::NEW_ZEALAND,  "New Zealand"}, 
        { Rabbit_breed::LOP,  "Lop"}, 
        { Rabbit_breed::POLISH,  "Polish"}, 
        { Rabbit_breed::HARLEQUIN,  "Harlequin"},
    };
    try {
        return rabbits_map.at(breed);
    } catch (std::exception& e) {
        return "Unknown";
    }
}
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
 std::string Rabbit::save(std::stringstream& ost){
  ost<<"rabbit"<<std::endl;
  ost<<_name<<std::endl;
  ost<<_gender<<std::endl;
  ost<<_age<<std::endl;
  ost<<_breed<<std::endl;
  return ost.str();
}
