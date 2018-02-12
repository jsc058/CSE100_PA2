#ifndef TrieNode
#define TrieNode
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
    TrieNode::TrieNode() {
      letter;
      left = right = middle = 0;
      wordLabel = false;
      frequency = 0;
      wordstring;
    }

  //public:

    TrieNode* left;
    TrieNode* right;
    TrieNode* middle;
    char letter;   // the const Data in this node.
    bool wordLabel;
    unisnged int frequency;
    string wordstring;
/*
    TrieNode * children[27];
    */
};

#endif
