#ifndef _DOG_H
#define _DOG_H
#include <iostream>
#include "animal.h"
 enum class  Dog_breed{Retriever,Labrador,Shepherd,Poodle,Chihuahua,Bulldog,Beagle,Pug};
class Dog: public Animal{
  private:
  Dog_breed _breed;
  public:
  Dog(Dog_breed,std::string,Gender,int);
  ~Dog();
  std::string family() override;
  std::string breed() override;
};
#endif
