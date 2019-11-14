#include "mainwin.h"
#include <gtkmm.h>
int main (int argc, char *argv[]) {
  auto app =Gtk::Application::create(argc,argv,"uta.cse.1325");
  Mainwin win;
  app->run(win);
}

