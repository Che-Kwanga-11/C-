#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string VERSION{"0.1.0"};
const std::string APP_NAME{"edu.uta.cse1325.sweets.v0_1_0"};

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_animal_click();            // Create a new store
        void on_list_animals_click();          // Select an order to list
        void on_quit_click();                 // Exit the program
    private:
        Shelter *_shelter;                        // Current model
        Gtk::Label *data;                     // Information display
#ifdef __STATUSBAR
        Gtk::Label *msg;                      // Status message display
#endif
};
#endif 
      // Menu items
        /*Gtk::MenuItem *menuitem_add_sweet;    // Sweets > Add
        Gtk::MenuItem *menuitem_list_sweets;  // Sweets > List
        Gtk::MenuItem *menuitem_place_order;  // Orders > Place
        Gtk::MenuItem *menuitem_list_orders;  // Orders > List*/

/*#ifdef __TOOLBAR
        // Tool bar buttons
        Gtk::ToolButton* add_sweet_button;    // Add a new sweet
        Gtk::ToolButton* list_sweets_button;  // List all sweets
        Gtk::ToolButton* place_order_button;  // Add an order
        Gtk::ToolButton* list_orders_button;  // Select an order to list
#endif*/

        // Display widgets
