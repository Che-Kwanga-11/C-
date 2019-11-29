#include "mainwin.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include "client.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mainwin::Mainwin() : shelter{new Shelter{"Mavs Animal Shelter"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
   
    //         T E S T
    // Append Test to the File menu
    Gtk::MenuItem *menuitem_test = Gtk::manage(new Gtk::MenuItem("_Test", true));
    menuitem_test->signal_activate().connect([this] {
        Animal* animals[] = {
            new Dog   {Dog_breed::MIX,          "Fido",      Gender::MALE,   3},
            new Cat   {Cat_breed::MIX,          "Mouser",    Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::HARLEQUIN, "Hopper",    Gender::MALE,   7},
            new Dog   {Dog_breed::BULLDOG,      "Rover",     Gender::MALE,   3},
            new Cat   {Cat_breed::BIRMAN,       "Fluffball", Gender::FEMALE, 1},
            new Rabbit{Rabbit_breed::MIX,       "Pillbox",   Gender::MALE,   7},
            new Dog   {Dog_breed::DACHSHUND,    "Noodle",    Gender::FEMALE, 5},
            new Cat   {Cat_breed::RAGDOLL,      "Sugar",     Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::POLISH,    "Wiggles",   Gender::MALE,   7},
            new Dog   {Dog_breed::POODLE,       "Priscilla", Gender::FEMALE, 9},
            new Cat   {Cat_breed::SIAMESE,      "Shelley",   Gender::FEMALE, 2},
            new Rabbit{Rabbit_breed::LOP,       "Leo",       Gender::MALE,   4},
        };
        for (auto a : animals) shelter->add_animal(*a);

        Client clients[] = {
            Client{"Clifford Red",     "817-555-1212", "clifford@scholastic.com"},
            Client{"Mary Tyler Moore", "817-CAT-MEOW", "mtm@wjm.tv"             },
            Client{"Mr. Magoo",        "817-555-0000", "mr.magoo@fleamail.com"  },
            Client{"Columbo",          "817-COL-UMBO", "columbo@lapd.gov"       },
            Client{"Natalia Alianova", "817-BLK-WIDO", "natasha@shield.gov"     },
            Client{"Bond, James Bond", "817-007-BOND", "classified"             },
        };
        for (auto c : clients) shelter->add_client(c);
    });
    filemenu->append(*menuitem_test);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_new =Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_shelter_click();});
    filemenu->append(*menuitem_new);
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save_As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
    
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this]{this->on_open_click();});
    filemenu->append(*menuitem_open);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    //     A N I M A L
    // Create an Animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newanimal = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newanimal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_newanimal);

    //           L I S T
    // Append List to the Animal menu
    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);

    //           S H O W   A D O P T I O N S
    // Append Show Adoptions to the Animal menu
    Gtk::MenuItem *menuitem_show_adoptions = Gtk::manage(new Gtk::MenuItem("_Show Adoptions", true));
    menuitem_show_adoptions->signal_activate().connect([this] {this->on_list_adopted_click();});
    animalmenu->append(*menuitem_show_adoptions);

    //     C L I E N T
    // Create a Client menu and add to the menu bar
    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    //           N E W
    // Append New to the Client menu
    Gtk::MenuItem *menuitem_newclient = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);

    //           L I S T
    // Append List to the Client menu
    Gtk::MenuItem *menuitem_listclient = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listclient->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclient);

    //           A D O P T
    // Append Adopt to the Client menu
    Gtk::MenuItem *menuitem_adopt = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_adopt->signal_activate().connect([this] {this->on_adopt_animal_click();});
    clientmenu->append(*menuitem_adopt);

    //           S H O W   A D O P T I O N S
    // Append Show Adoptions to the Client menu
    Gtk::MenuItem *menuitem_list_adoptions = Gtk::manage(new Gtk::MenuItem("_Show Adoptions", true));
    menuitem_list_adoptions->signal_activate().connect([this] {this->on_list_adopted_click();});
    clientmenu->append(*menuitem_list_adoptions);
  //  H E L P
  // Display help and about info.
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *help_menu=Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*help_menu);
    Gtk::MenuItem *about_item=Gtk::manage(new Gtk::MenuItem("_About",true));
    about_item->signal_activate().connect([this] {this->on_about_click();});
    help_menu->append(*about_item);
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"white"});
    //2new,4save,3open,1quit,5new,6list,7 new, 8list
    Gtk::Image* image=Gtk::manage(new Gtk::Image("exit.png")); //<div>Icons made by <a href="https://www.flaticon.com/authors/freepik" title="Freepik">Freepik</a> from <a href="https://www.flaticon.com/" title="Flaticon">www.flaticon.com</a></div>
    Gtk::Image* image_shelter=Gtk::manage(new Gtk::Image("newShelter.png"));
    Gtk::Image* image_open=Gtk::manage(new Gtk::Image("open.png"));
    Gtk::Image* image_save=Gtk::manage(new Gtk::Image("save.png"));
    Gtk::Image* image_new_animal=Gtk::manage(new Gtk::Image("new_animal.png"));
    Gtk::Image* image_list_animal=Gtk::manage(new Gtk::Image("list_animal.png"));
    Gtk::Image* image_new_client=Gtk::manage(new Gtk::Image("new_client.png"));
    Gtk::Image* image_adopt_animal=Gtk::manage(new Gtk::Image("adopt_animal.png"));

    Gtk::ToolButton* quit=Gtk::manage(new Gtk::ToolButton(*image));
    Gtk::ToolButton* new_shelter=Gtk::manage(new Gtk::ToolButton(*image_shelter));
    Gtk::ToolButton* open=Gtk::manage(new Gtk::ToolButton(*image_open));
    Gtk::ToolButton* save=Gtk::manage(new Gtk::ToolButton(*image_save));
    Gtk::ToolButton* new_animal=Gtk::manage(new Gtk::ToolButton(*image_new_animal));
    Gtk::ToolButton* list_animal=Gtk::manage(new Gtk::ToolButton(*image_list_animal));
    Gtk::ToolButton* new_client=Gtk::manage(new Gtk::ToolButton(*image_new_client));
    Gtk::ToolButton* adopt_animal=Gtk::manage(new Gtk::ToolButton(*image_adopt_animal));

    new_shelter->signal_clicked().connect([this]{this->on_new_shelter_click();});
    quit->signal_clicked().connect([this] {this->on_quit_click();});
    open->signal_clicked().connect([this] {this->on_open_click();});
    save->signal_clicked().connect([this] {this->on_save_click();});
    new_animal->signal_clicked().connect([this] {this->on_new_animal_click();}); 
    list_animal->signal_clicked().connect([this] {this->on_list_animals_click();});
    new_client->signal_clicked().connect([this] {this->on_new_client_click();});
    adopt_animal->signal_clicked().connect([this] {this->on_adopt_animal_click();});           
    
    toolbar->add(*quit);
    toolbar->add(*new_shelter);
    toolbar->add(*open);
    toolbar->add(*save);
    toolbar->add(*new_animal);
    toolbar->add(*list_animal);
    toolbar->add(*new_client);
    toolbar->add(*adopt_animal);

    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    Gtk::ScrolledWindow* scroller = Gtk::manage(new Gtk::ScrolledWindow);
    scroller->add(*data);
    vbox->pack_start(*scroller, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_animal_click() {
    status("");

    Gtk::Dialog adialog{"Animal Type", *this};
    Gtk::ComboBoxText atype;
    atype.append("Dog");
    atype.append("Cat");
    atype.append("Rabbit");
    atype.set_active(0);
    adialog.get_content_area()->pack_start(atype, Gtk::PACK_SHRINK, 0);
    adialog.add_button("Select", 1);
    adialog.add_button("Cancel", 0);
    adialog.show_all();
    if (adialog.run() == 0) return;

    std::string animal_type;
    Gtk::ComboBoxText c_breed;
    if (atype.get_active_row_number() == 0) {
        animal_type = "Dog";
        for(auto b : dog_breeds) c_breed.append(to_string(b));
    } else if (atype.get_active_row_number() == 1) {
        animal_type = "Cat";
        for (auto& [c, s] : cats_map) c_breed.append(to_string(c));
    } else if (atype.get_active_row_number() == 2) {
        animal_type = "Rabbit";
        for(auto r : rabbit_breeds) c_breed.append(to_string(r));
    }
    c_breed.set_active(0);

    Gtk::Dialog dialog{animal_type + "Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add " + animal_type, 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal;
        if (animal_type == "Dog")
            animal = new Dog{dog_breeds[c_breed.get_active_row_number()], 
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else if (animal_type == "Cat")
            animal = new Cat{cat_breeds[c_breed.get_active_row_number()], 
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else if (animal_type == "Rabbit")
            animal = new Rabbit{rabbit_breeds[c_breed.get_active_row_number()], 
                             e_name.get_text(),
                             (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                             static_cast<int>(s_age.get_value())};
        else
            throw std::runtime_error{"Invalid animal type: " + animal_type};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
}

void Mainwin::on_list_animals_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n'; 
    data->set_text(oss.str());
    status("List of All Animals");
}
void Mainwin::on_new_client_click() {
    status("");
    Gtk::Dialog dialog{"Client Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_phone.get_text().size() == 0) {e_phone.set_text("*required*"); continue;}
        if (e_email.get_text().size() == 0) {e_email.set_text("*required*"); continue;}

        Client* client = new Client{e_name.get_text(), e_phone.get_text(), e_email.get_text()};
        shelter->add_client(*client);

        std::ostringstream oss;
        oss << "Added " << *client;
        status(oss.str());

        break;
    }
}

void Mainwin::on_list_clients_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n'; 
    data->set_text(oss.str());
    status("List of All Clients");
}

void Mainwin::on_adopt_animal_click() {
    status("");

    if(shelter->num_animals() == 0) {
        Gtk::MessageDialog{*this, "No animals available to adopt!"}.run();
        return;
    }
    if(shelter->num_clients() == 0) {
        Gtk::MessageDialog{*this, "No clients currently registered!"}.run();
        return;
    }

    Gtk::Dialog dialog{"Adopt an Animal", *this};

    Gtk::Grid grid;

    Gtk::ComboBoxText c_client;
    for(int i=0; i<shelter->num_clients(); ++i) {
        std::ostringstream oss;
        oss << shelter->client(i);
        c_client.append(oss.str());
    }
    c_client.set_active(0);
    Gtk::Label l_client{"Client"};
    grid.attach(l_client, 0, 1, 1, 1);
    grid.attach(c_client, 1, 1, 2, 1);

    Gtk::ComboBoxText c_animal;
    for(int i=0; i<shelter->num_animals(); ++i) {
        std::ostringstream oss;
        oss << shelter->animal(i);
        c_animal.append(oss.str());
    }
    c_animal.set_active(0);
    Gtk::Label l_animal{"Animal"};
    grid.attach(l_animal, 0, 0, 1, 1);
    grid.attach(c_animal, 1, 0, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Adopt", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    if (dialog.run()) {
        shelter->adopt(shelter->client(c_client.get_active_row_number()),
                       shelter->animal(c_animal.get_active_row_number()));
    }
}

void Mainwin::on_list_adopted_click() {
    if(shelter->num_clients() == 0) {
        Gtk::MessageDialog{*this, "No clients currently registered!"}.run();
        return;
    }

    Gtk::Dialog dialog{"List Adoptions by a Client", *this};

    Gtk::Grid grid;

    Gtk::ComboBoxText c_client;
    std::vector<int> c2index;
    for(int i=0; i<shelter->num_clients(); ++i) {
        if(shelter->client(i).num_adopted()) {
            std::ostringstream oss;
            oss << shelter->client(i);
            c_client.append(oss.str());
            c2index.push_back(i);
        }
    }
    c_client.set_active(0);
    Gtk::Label l_client{"Client"};
    grid.attach(l_client, 0, 1, 1, 1);
    grid.attach(c_client, 1, 1, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("List Adoptions", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    if(dialog.run()) {
        int index = c2index[c_client.get_active_row_number()];
        Client& client = shelter->client(index);
        std::ostringstream oss;

        for(int i=0; i < client.num_adopted(); ++i)
            oss << client.animal(i) << '\n';
        data->set_text(oss.str());

        std::ostringstream osc;
        osc << "List of animals adopted by " << client;
        status(osc.str());
    }

}
void Mainwin::on_save_click() {
  int filename_length=shelter->get_filename().size();
  if(filename_length>0){
  try{
  std::ofstream ofs{shelter->get_filename()};
  shelter->save(ofs);
}
  catch(std::exception e){
   Gtk::MessageDialog{*this,"Unable to save shelter"}.run();
} 
}else{on_save_as_click();}
}
void Mainwin::on_save_as_click() {
Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(EXT);
    filter_ctp->add_pattern("*."+EXT);
    dialog.add_filter(filter_ctp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+EXT);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
        shelter->set_filename(dialog.get_filename());
        on_save_click();
    }
}

void Mainwin::on_open_click(){
  Gtk::Dialog open_dialog{"What action should be taken on the current shelter?",*this};
  open_dialog.add_button("Save",2);
  open_dialog.add_button("Discard",1);
  open_dialog.add_button("Cancel",0);
  int open_result=open_dialog.run();
  if(open_result==2){on_save_as_click();}
  if(open_result==1){}
Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_ctp = Gtk::FileFilter::create();
    filter_ctp->set_name(EXT);
    filter_ctp->add_pattern("*."+EXT);
    dialog.add_filter(filter_ctp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled."+EXT);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        shelter->set_filename(dialog.get_filename());
    }
 try{
  std::ifstream ifs{shelter->get_filename()};
  shelter->open(ifs);
}
  catch(std::exception e){
   Gtk::MessageDialog{*this,"Unable to load shelter"}.run();
} 
}
 void Mainwin::on_new_shelter_click(){
    Gtk::Dialog dialog{"Name of shelter",*this};
    Gtk::Entry entry;
    dialog.get_content_area()->pack_start(entry,Gtk::PACK_SHRINK,0);
    dialog.show_all();
    std::string name;
    dialog.add_button("Add Shelter",1);
    while(dialog.run()) {
        if (entry.get_text().size() == 0) {entry.set_text("*required*"); continue;}
     name=entry.get_text();
     break;
}
    delete shelter;
    shelter=new Shelter(name);
   
} 
 void Mainwin::on_about_click(){
 Gtk::AboutDialog about_dialog=Gtk::AboutDialog();
 //about_dialog.set_logo("");
//about_dialog->set_license();
 about_dialog.set_version("1.0.0");
 about_dialog.set_copyright("Che Kwanga");
 about_dialog.set_transient_for(*this);
 about_dialog.set_comments("This is an animal adoption application");
 about_dialog.set_program_name("MASS");
 about_dialog.run();
}


// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
