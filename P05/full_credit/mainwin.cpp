#include "mainwin.h"
#include "store.h"
#include "sweet.h"
#include"entrydialog.h"
   std::string* newLabel;
  Mainwin::Mainwin() : Mainwin{*(new Store)} { }
  Mainwin::Mainwin(Store& store) : _store{&store} ,Vbox(Gtk::ORIENTATION_VERTICAL,5){ 
    label= Gtk::manage(new Gtk::Label{" ",Gtk::ALIGN_START});
    menuBar =Gtk::manage(new Gtk::MenuBar{});
    Files=Gtk::manage(new Gtk::MenuItem{});
    Sweets=Gtk::manage(new Gtk::MenuItem{});
    help=Gtk::manage(new Gtk::MenuItem{});
    quit=Gtk::manage(new Gtk::MenuItem{});
    addSweets=Gtk::manage(new Gtk::MenuItem{});
    newStore=Gtk::manage(new Gtk::MenuItem{});
    about=Gtk::manage(new Gtk::MenuItem{});
    list=Gtk::manage(new Gtk::MenuItem{});
    menuFiles=Gtk::manage(new Gtk::Menu{});
    menuSweets=Gtk::manage(new Gtk::Menu{});
    menuHelp=Gtk::manage(new Gtk::Menu{});

    
    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements
  
    
    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
    Vbox.pack_start(*menuBar,Gtk::PACK_SHRINK);
    Vbox.pack_start(*label);
   
    Files->set_label("Files");
    Sweets->set_label("Sweets"); 
    help->set_label("Help");

    menuBar->append(*Files); 
    menuBar->append(*Sweets);
    menuBar->append(*help);
   
    quit->set_label("Quit");
    newStore->set_label("New Store");
    addSweets->set_label("Add a Sweet");
    about->set_label("About");
    list->set_label("List");
    quit->signal_activate().connect([this]{Gtk::Main::quit();});
    addSweets->signal_activate().connect([this]{this->on_add_sweets_click();});
    newStore->signal_activate().connect([this]{this->on_new_store_click(_store);});
    list->signal_activate().connect([this]{this->on_list_click(_store,label);});

    menuFiles->append(*quit);
    menuFiles->append(*newStore);
    menuSweets->append(*addSweets);
    menuSweets->append(*list);
    menuHelp->append(*about);

    Files->set_submenu(*menuFiles); 
    Sweets->set_submenu(*menuSweets);
    help->set_submenu(*menuHelp);
    

    set_border_width(20);
    add(Vbox);
    show_all_children();
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////
  void Mainwin::on_new_store_click(Store*_store){
   _store=new Store;
}
  
  void Mainwin::on_add_sweets_click(){
  EntryDialog ed1{*this, "Name of the sweet"};
  ed1.set_text(" ");
  ed1.run(); 
  std::string sweetName=ed1.get_text(); 
  
  EntryDialog ed2{*this, "Price of Sweet"};
  ed2.set_text(" ");
  ed2.run(); 
  std::string sweetDouble=ed2.get_text();
  double price= std::stod(sweetDouble); 
  Sweet sweet(sweetName,price);
    _store->add(sweet);
}
  void Mainwin::on_list_click(Store*_store, Gtk::Label* label){
  int size=(*_store).num_sweets();
  for(int i=0;i<size;i++){

     *newLabel="This text";//=*newLabel//+(*_store).sweet(i).name();
  // *newLabel=*newLabel+"    "+std::to_string((*_store).sweet(i).price())+"\n";
 }
 //label->set_text(*newLabel);
}

// /////////////////
// U T I L I T I E S
// /////////////////


