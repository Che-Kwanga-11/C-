#ifndef AVERAGE_HEADER
#define AVERAGE_HEADER
#include<iostream>
#include<cstring>
class Average{
    private:
      double _sum;
      int _values;// private variables
    public:
      Average(); // constructor 
      Average& operator+=(double); // operator method 
      friend std::ostream& operator<<(std::ostream&,const Average&); // output stream operator
      friend std::istream& operator>>(std::istream&,Average&); // input stream operator
 
};
 
#endif
