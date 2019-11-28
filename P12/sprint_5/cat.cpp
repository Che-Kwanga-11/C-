#include "cat.h"


Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::Cat(std::istream& ist):Animal(ist){
    std::string breed;
    ist>>breed;
        if(breed=="Mix"){_breed=Cat_breed::MIX;}
        else if(breed=="Siamese"){ _breed=Cat_breed::SIAMESE;}
        else if(breed=="Persian"){_breed=Cat_breed::PERSIAN;} 
        else if(breed=="Maine Coon"){_breed=Cat_breed::MAINE_COON;} 
        else if(breed=="Ragdoll"){_breed=Cat_breed::RAGDOLL;} 
        else if(breed=="Bengal"){_breed=Cat_breed::BENGAL;} 
        else if(breed=="Abyssinian"){_breed=Cat_breed::ABYSSINIAN;} 
        else if(breed=="Birman"){_breed=Cat_breed::BIRMAN;} 
        else if(breed=="Oriental Shorthair"){_breed=Cat_breed::ORIENTAL_SHORTHAIR;} 
        else if(breed=="Devon Rex"){_breed=Cat_breed::DEVON_REX;} 
        else if(breed=="American Shorthair"){_breed=Cat_breed::AMERICAN_SHORTHAIR;} 
        else if(breed=="Himalayan"){_breed=Cat_breed::HIMALAYAN;} 
}
Cat::~Cat() { }

std::string Cat::family() const {return "cat";}
std::string Cat::breed() const {return ::to_string(_breed);}

    const std::map<Cat_breed, std::string> cats_map = {
        {Cat_breed::MIX                , "Mix"               },
        {Cat_breed::SIAMESE            , "Siamese"           }, 
        {Cat_breed::PERSIAN            , "Persian"           }, 
        {Cat_breed::MAINE_COON         , "Maine Coon"        }, 
        {Cat_breed::RAGDOLL            , "Ragdoll"           }, 
        {Cat_breed::BENGAL             , "Bengal"            }, 
        {Cat_breed::ABYSSINIAN         , "Abyssinian"        }, 
        {Cat_breed::BIRMAN             , "Birman"            }, 
        {Cat_breed::ORIENTAL_SHORTHAIR , "Oriental Shorthair"}, 
        {Cat_breed::DEVON_REX          , "Devon Rex"         }, 
        {Cat_breed::AMERICAN_SHORTHAIR , "American Shorthair"}, 
        {Cat_breed::HIMALAYAN          , "Himalayan"         }, 
    };
std::string to_string(const Cat_breed& breed) {
    try {
        return cats_map.at(breed);
    } catch (std::exception& e) {
        return "Unknown";
    }
}
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
 std::string Cat::save(std::stringstream& ost){
  ost<<"cat"<<std::endl;
  ost<<_name<<std::endl;
  ost<<_gender<<std::endl;
  ost<<_age<<std::endl;
  ost<<_breed<<std::endl;
  return ost.str();
}
