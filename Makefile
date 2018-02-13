# A starter makefile for CSE 100 P2

#use g++ for everything
CC= g++
CXX= g++

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall -std=c++11

#include debugging symbols in executable
LDFLAGS= -g

default: main test_Auto

test_Auto: test_Auto.o
	g++ -o test_Auto test_Auto.o
main: main.o
	g++ -o main main.o
Autocomplete: Autocomplete.o
	g++ -o Autocomplete Autocomplete.o

main.o: main.cpp Autocomplete.hpp TerTrie.hpp TrieNode.hpp AutocompleteUtils.hpp
test_Auto.o: TrieNode.hpp TerTrie.hpp Autocomplete.hpp
Autocomplete.o: Autocomplete.hpp TerTrie.hpp TrieNode.hpp

clean:
	$(RM) main *.o
