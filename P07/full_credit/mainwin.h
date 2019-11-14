#ifndef Mainwin_H
#define Mainwin_H
#include <gtkmm.h>
class Mainwin : public Gtk::Window {
public:
Mainwin();
Gtk::Entry* entry;
virtual ~Mainwin();
protected:
void on_button1_click(); // Square root
void on_button2_click(); // natural log
void on_button3_click(); // cosine

private:

Gtk::Button* button1; //square root
Gtk::Button* button2; //natural log
Gtk::Button* button3; //cosine
};
#endif
