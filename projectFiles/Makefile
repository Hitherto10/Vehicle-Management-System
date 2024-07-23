CXX = g++
CXXFLAGS = -g -Wall -Wextra
objects = main.o vehicles.o motorcycle.o codeFunctions.o car.o van.o

.PHONY: all
all: program run

program: $(objects)
	$(CXX) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

vehicles.o: vehicles.cpp vehicles.h
	$(CXX) $(CXXFLAGS) -c vehicles.cpp

motorcycle.o: motorcycle.cpp motorcycle.h vehicles.h
	$(CXX) $(CXXFLAGS) -c motorcycle.cpp

car.o: car.cpp car.h vehicles.h
	$(CXX) $(CXXFLAGS) -c car.cpp

van.o: van.cpp van.h vehicles.h
	$(CXX) $(CXXFLAGS) -c van.cpp

codeFunctions.o: codeFunctions.cpp codeFunctions.h
	$(CXX) $(CXXFLAGS) -c codeFunctions.cpp

run: program
	./program

clean:
	rm -rf *.o program
