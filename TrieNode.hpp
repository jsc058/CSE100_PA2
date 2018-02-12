#ifndef TrieNode_HPP
#define TrieNode_HPP
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TrieNode {
  //private:
protected:
  
  TrieNode* left;
  TrieNode* right;
  TrieNode* middle;
  char letter;   // the const Data in this node.
  bool wordLabel;
  unsigned int frequency;
  string wordstring;

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
<<<<<<< HEAD
    TrieNode::TrieNode() {
      letter;
=======
    TrieNode(char & letter) {
      letter = letter;
>>>>>>> 6dc2b6c6433504791013fbf600393a1bfaf0257d
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
