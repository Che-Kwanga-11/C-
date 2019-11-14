#ifndef MAINWIN_H
#define MAINWIN_H
#include "entrydialog.h"
#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();
    protected:
     void on_new_store_click(Store*);
     void on_add_sweets_click();
     void on_list_click(Store*,Gtk::Label*);
    private:
        Store *_store;
        Gtk::Box Vbox;
        Gtk::Label* label;
        Gtk::MenuBar* menuBar;
        Gtk::MenuItem* Files,*quit,*newStore,*Sweets,*addSweets,*help,*about,*list;
        Gtk::Menu* menuFiles, *menuSweets,*menuHelp;
    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};
#endif 

