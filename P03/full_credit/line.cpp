#include"line.h"
#include <cstring>
#include <cmath>
 Line::Line(double x1,double y1,double x2,double y2 ):_x1{x1},_x2{x2},_y1{y1},_y2{y2}{}
 
 std::string Line::to_string(){
std::string s_x1=std::to_string(x1);
std::string s_y1=std::to_string(y1);
std::string s_x2=std::to_string(x2);
std::string s_y2=std::to_string(y2);
std::string S = "("+s_x1+","+s_y1+")"+"-"+"("+s_x2+","+s_y2+")";
return S;
}
 double Line::length(){
  double ln_x=(_x1-_x2)*(_x1-_x2);
  double ln_y=(_y1-_y2)*(_x1-_x2);
  double length = std::sqrt(ln_y+ln_x);
  return length;
}

