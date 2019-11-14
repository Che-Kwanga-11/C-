#include "dog.h"
 Dog::Dog(Dog_breed breed,std::string name,Gender gender,int age):_breed{breed},Animal::Animal(name,gender,age){}
 Dog::~Dog(){}
 std::string Dog::family(){return "dog";}
 std::string Dog::breed(){} //return _breed as a string


