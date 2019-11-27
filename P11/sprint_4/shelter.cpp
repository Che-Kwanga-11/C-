#include "shelter.h"
#include <algorithm>
#include <sstream>
#include "dog.h"
#include "rabbit.h"
#include "cat.h"

Shelter::Shelter(std::string name) : _name{name} { }
std::string Shelter::name() {return _name;}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}
int Shelter::num_animals() {return _available.size();}
Animal& Shelter::animal(int index) {return *(_available[index]);}

void Shelter::add_client(Client& client) {_clients.push_back(client);}
int Shelter::num_clients() {return _clients.size();}
Client& Shelter::client(int index) {return _clients[index];}

void Shelter::adopt(Client& client, Animal& animal) {
    client.adopt(animal);
    auto index = std::find(_available.begin(), _available.end(), &animal);
    if (index != _available.end()) _available.erase(index);
    // OR use the "erase remove" idiom, which removes ALL elements matching animal
    // _available.erase(std::remove(_available.begin(), _available.end(), &animal), _available.end());

}
void Shelter::save(std::ostream& ost){
  ost<<_available.size()<<std::endl;
  for(int i=0;i<Shelter::num_animals();++i){
   std::stringstream sstr;
   ost<<_available[i]->save(sstr)<<std::endl;
}
 ost<<_clients.size()<<std::endl;
 for(int i=0;i<Shelter::num_clients();++i){
   ost<<_clients[i]<<std::endl;
}
ost<<_name<<std::endl;
}
void Shelter::open(std::istream& ist){
  int animal_number,age,clients_number;
  std::string breed,name,gender,family;
  ist>>animal_number;
  for(int i=0;i<animal_number;++i){
  ist>>family;
  if(family=="dog"){Animal* new_dog=new Dog(ist);
   _available.push_back(new_dog);
}

   if(family=="rabbit"){Animal* new_rabbit=new Rabbit(ist);
   _available.push_back(new_rabbit);
  }
    if(family=="cat"){Animal* new_cat=new Cat(ist);
   _available.push_back(new_cat);
  }
}
 
 ist>>clients_number;
 for(int i=0;i<clients_number;++i){
    std::string client;
    ist>>client;
  // _clients.push_back(client);
}
ist>>_name;
}
