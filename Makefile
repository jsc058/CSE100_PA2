# A starter makefile for CSE 100 P2

#use g++ for everything
CC= g++ 
CXX= g++

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall -std=c++11

#include debugging symbols in executable
LDFLAGS= -g	

default: main 

main: main.o
	g++ -o main main.o

main.o: main.cpp Autocomplete.hpp

Autocomplete.o: Autocomplete.hpp

clean:
	$(RM) main *.o 
