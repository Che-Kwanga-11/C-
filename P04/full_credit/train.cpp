#include "train.h"
 void Train::add_locomotive(Locomotive& locomotive){
   _locomotives.push_back(&locomotive);
  }
 void Train::add_coach(Coach& coach){
   _coach.push_back(&coach);
  }
  double Train::speed(double minutes){
int l_size=Train::_locomotives.size();
  int c_size=Train::_coach.size();
  double weight, power,seconds;
    seconds=minutes*60;
    for(int i=0;i<l_size;i++){
     power+=Train::_locomotives[i]->power();
  }
    for(int i=0;i<c_size;i++){
     weight+=Train::_coach[i]->weight();
  }
     std::sqrt(2*power*seconds/weight);
  }
std::string Train::to_art(){
  std::string train_string;
int l_size=Train::_locomotives.size();
  int c_size=Train::_coach.size();
  std::vector <std::string> train(6);
   for(int i=0;i<6;i++){
    for(int j=0;j<l_size;j++){
       train[i]=train[i]+Train::_locomotives[j]->Stock::ascii_art(i);
}
 for(int i=0;i<6;i++){
    for(int j=0;j<c_size;j++){
       train[i]=train[i]+Train::_coach[j]->Stock::ascii_art(i);
}
}}
    for(int i=0;i<6;i++){
       train_string=train_string+train[i]+"\n";
}
return train_string;
}

