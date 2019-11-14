CXXFLAGS = --std=c++17
trains: main.o train.o stock.o locomotive.o coach.o
	$(CXX) $(CXXFLAGS) main.o train.o stock.o locomotive.o coach.o -o trains
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 
train.o: train.cpp 
	$(CXX) $(CXXFLAGS) -c train.cpp -o train.o
stock.o: stock.cpp 
	$(CXX) $(CXXFLAGS) -c stock.cpp -o stock.o
locomotive.o: locomotive.cpp 
	$(CXX) $(CXXFLAGS) -c locomotive.cpp -o locomotive.o
coach.o: coach.cpp 
	$(CXX) $(CXXFLAGS) -c coach.cpp -o coach.o
clean:
	rm -f *.o *.gch ~* a.out trains
