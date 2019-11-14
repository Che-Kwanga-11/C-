#ifndef _ANIMAL_H
#define _ANIMAL_H
#include <iostream>
 
  enum class Gender{ Male, Female};
  class Animal{
   protected:
    std::string _name;
    Gender _gender;
    int _age;
   public:
    Animal(std::string,Gender,int);
    ~Animal();
    virtual std::string family()=0;
    std::string name();
    virtual std::string breed()=0;
    Gender gender();
    int age();
    virtual std::string to_string()=0;
};
#endif
