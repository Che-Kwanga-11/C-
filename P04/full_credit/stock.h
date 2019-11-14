#ifndef _STOCK_H
#define _STOCK_H
#include <vector>
#include <string>
#include <cmath>
 class Stock{
   protected:
    double _weight; // weight in kg
    std::vector <std::string> _art; // art vector 
   public:
    Stock();
    Stock(double);
    double weight=0; // returns weight in kg
    std::string ascii_art(int);// returns art vector
};
#endif
