#include "animal.h"

Animal::Animal(std::string name,Gender gender,int age)
    :_name{name},_gender{gender},_age{age}{}
  std::string Animal::family(){}
  std::string Animal::name(){return _name;}
  std::string Animal::breed(){} // make animal and breed method virtual that returns type of animal
 Gender Animal::gender(){return _gender;}  
  int Animal::age(){return _age;} // finish to string method 
  std::string Animal::to_string(){}
  Animal::~Animal(){}
//breed and animal should be enum classes
