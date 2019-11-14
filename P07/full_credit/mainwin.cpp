#include "mainwin.h"
#include <cmath>
#include "entrydialog.h"
 Mainwin::Mainwin()
{
    button1=Gtk::manage(new Gtk::Button{"Square Root"});
    button2=Gtk::manage(new Gtk::Button{"Log"});
    button3=Gtk::manage(new Gtk::Button{"Cosine"});
    entry=Gtk::manage(new Gtk::Entry);
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
  button1->signal_clicked().connect([this]{on_button1_click();});
  button1->show();
  vbox->pack_start(*button1);
  
  button2->signal_clicked().connect([this]{on_button2_click();});
  button2->show();
  vbox->pack_start(*button2);
  
  button3->signal_clicked().connect([this]{on_button3_click();});
  button3->show();
  vbox->pack_start(*button3);
  
  entry->set_text("Nothing to report...");
  entry->show();
  vbox->pack_start(*entry);
}
  Mainwin::~Mainwin() { } 
 void on_button1_click(){
    int sqr =std::sqrt(std::stoi(entry->get_text()));
    std::string str=std::to_string(sqr);
    Gtk::MessageDialog md{*this,str};
    md.run();
}
void on_button2_click(){
    int log1 =std::log(std::stoi(entry->get_text()));
    std::string log2=std::to_string(log1);
    Gtk::MessageDialog md{*this,log2};
    md.run();
}
void on_button1_click(){
    int cos1 =std::cos(std::stoi(entry->get_text()));
    std::string cos2=std::to_string(cos1);
    Gtk::MessageDialog md{*this,cos2};
    md.run();
}

