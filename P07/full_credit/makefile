CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
math:   entrydialog.o mainwin.o main.o
	$(CXX) $(CXXFLAGS) entrydialog.o mainwin.o main.o $(GTKFLAGS) -o  math

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o  main.o
mainwin.o: mainwin.cpp
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o  mainwin.o
entrydialog.o: entrydialog.cpp
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o  entrydialog.o

clean:
	rm -f *.o *.gch ~* a.out math
 
