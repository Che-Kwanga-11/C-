#include "stock.h"
  std::vector <std::string> _art(6);
 Stock::Stock():_weight{NAN}{}
 Stock::Stock(double weight):_weight{weight}{}
 std::string Stock::ascii_art(int row){
   return _art[row];
}
