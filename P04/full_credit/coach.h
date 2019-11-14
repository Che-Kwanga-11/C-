#ifndef _COACH_H
#define _COACH_H
#include "stock.h"
class Coach:public Stock {
private:
int _passengers;
public:
Coach(double);
void add_passengers(int);
double weight();
};
#endif
