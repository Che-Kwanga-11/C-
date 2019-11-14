#include "train.h"
#include "stock.h"
#include "locomotive.h"
#include "coach.h"
#include <iostream>
  void printScreen(Train train){
std::cout<<"     =========================  "<<std::endl;
std::cout<<"          Mbappe Express        "<<std::endl;
std::cout<<"     =========================  "<<std::endl;
std::cout<<train.to_art()<<std::endl;
std::cout<<"Minutes |      1   |      5   |      15   |      30  |      60  |"<<std::endl;
std::cout<<"--------|----------|----------|-----------|----------|----------"<<std::endl;
std::cout<<" m/s    |"<<"  "<<train.speed(1)<<" |"<<"  "<<train.speed(5)<<"  |"<<"  "<<train.speed(15)<<"  |"<<"  "<<train.speed(30)<<"  |"<<"  "<<train.speed(60)<<"  |"<<std::endl;
std::cout<<"1-Add a locomotive"<<std::endl;
std::cout<<"2-Add a coach"<<std::endl;
std::cout<<"9-Clear the train"<<std::endl;
std::cout<<"0-Exit"<<std::endl;
std::cout<<"\nCommand?"<<std::endl;
}
int main(){
double locomotive_weight=80000;
double locomotive_power=13500;
double coach_weight=28000;
int command;
  Train train;
   printScreen(train);
   std::cin>>command;
   while(command!=0){
    switch(command){
     case 1:{Locomotive locomotive(locomotive_weight,locomotive_power);
            Locomotive* loc_ptr;
            loc_ptr=&locomotive;
            train.add_locomotive(*loc_ptr);
            }
            break;
     case 2:{Coach coach(coach_weight);
            Coach* coach_ptr;
            int passengers;
            std::cout<<"How many passengers?"<<std::endl;
            std::cin>>passengers;
            coach.add_passengers(passengers);
            coach_ptr=&coach;
            train.add_coach(*coach_ptr);}
            break;
     case 9:Train train2; 
            train=train2;
            break;         
}
  printScreen(train);
  std::cin>>command;
}
}
