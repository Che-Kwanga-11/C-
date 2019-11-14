#include"coach.h"
#include "stock.h"
int weight_of_passengers=60;

Coach::Coach(double weight):Stock::Stock(weight){
 Stock::_art={ // Coach
"               ",
" ______________",
" | [] [] [] []|",
" |            |",
"='OO--------OO'",
"###############",
};}
void Coach::add_passengers(int passengers){
_passengers+=passengers;
}// throws exception if greater than 120
double Coach::weight(){
double total_weight=Stock::_weight+(Coach::_passengers*weight_of_passengers);
return total_weight;
}

