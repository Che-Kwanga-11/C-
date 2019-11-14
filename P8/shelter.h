#ifndef _SHELTER_H
#define _SHELTER_H
#include "animal.h"
#include "iostream"
#include "dog.h"
#include <vector>
 class Shelter{
  private:
  std::string _name;
  std::vector<Animal*> _available;
  public:
  Shelter(std::string);
  std::string name();
  void add_animal(Animal*);
  int num_animals();
  Animal* animal(int);
};
#endif

