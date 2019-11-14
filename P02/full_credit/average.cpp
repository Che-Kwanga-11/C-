#include "average.h"
Average::Average():_sum{0},_values{0}{}
/*Average::Average&*/ 
  Average& Average::operator+=(double value){ // operator method to increment sum and values
   _sum+=value; // increments sum by the double given
   _values++; // increments _values by 1
   return *this;
}
  std::istream& operator>>(std::istream& ist,Average& A){
    double temp; 
    ist>>temp; // streams into the temp variable 
    A._sum+=temp; //increments _sum by temp
    A._values++; // increments values by 1
}
  std::ostream& operator<<(std::ostream& ost,const Average& A){
    double temp;
    if(A._values>0){
     temp=(A._sum/A._values);// calculates average if values greater than 0
   }else{
     ost<<"undefined";
     return ost;// returns undefined if no values given
} 
     ost<<std::to_string(temp);
     return ost;
}
