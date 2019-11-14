#ifndef _LOCOMOTIVE_H
#define _LOCOM0TIVE_H
#include "stock.h"
#pragma once
class Locomotive :public Stock{
private:
double _power;// power of engine in kilowatts
public:
Locomotive(double,double);// constructor
double power(); 
double weight();// getter method 
};
#endif

