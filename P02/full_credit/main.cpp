#include "average.h"
#include<cstring>
#include<cstdlib>
int printScreen(Average& A){
int command;
std::cout<<"    ========================="<<std::endl;
std::cout<<"    Merely Average Calculator"<<std::endl;
std::cout<<"    ========================="<<std::endl;
std::cout<<"The Current Average is "<<A<<std::endl;
std::cout<<"\n1-Enter a new value\n2-Auto enter a random value\n9- Clear the calculator\n0-Exit\n\nCommand?"<<std::endl;
std::cin>>command;
return command;
}
int main(){
Average average{};
int command=printScreen(average);
while(command!=0){
switch(command){
  case 1:std::cout<<"Value?"<<std::endl;
         std::cin>>average;break;
  case 2:average+=std::rand()%100+1;break;
  case 9:system("clear");Average average2{};average=average2;break;
}
command=printScreen(average);
}
}
