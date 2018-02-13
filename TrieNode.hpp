#ifndef TrieNode_HPP
#define TrieNode_HPP
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TrieNode {
  //private:

  public:
    /* Constructor */
    /*
    TrieNode() {
      for (unsigned int set = 0; set < 27; set++) {
        children[set] = nullptr;
      }
      word = false;
      frequency = 0;
      wordstring = '';
    }
    */
    TrieNode* left;
    TrieNode* right;
    TrieNode* middle;
    char letter;   // the const Data in this node.
    bool wordLabel;
    unsigned int frequency;
    string wordstring;

    TrieNode(const char & character) {
      letter = character;
      left = right = middle = 0;
      wordLabel = false;
      frequency = 0;
    }
    
  //public:


/*
    TrieNode * children[27];
    */
};

#endif
