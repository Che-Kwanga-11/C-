#include "locomotive.h"

Locomotive::Locomotive(double weight, double power):_power{power},Stock::Stock(weight){
 Stock::_art= { // Locomotive
"       * # @ ",
"     . ______",
"   _()_||__||",
"  ( cse1325 |",
" /-OO----OO''",
"#############",
};}// sets weight through stock
double Locomotive::power(){
return _power;// returns power 
}
double Locomotive::weight(){
return _weight;
}

