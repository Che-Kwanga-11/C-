#ifndef _TRAIN_H
#define _TRAIN_H
#include <vector>
#include "locomotive.h"
#include "coach.h"
#include <cstring>
class Train{
private:
std::vector<Locomotive*> _locomotives;
std::vector<Coach*> _coach;
public:
void add_locomotive(Locomotive&);
void add_coach(Coach&);
double speed(double);
std::string to_art();
};
#endif
