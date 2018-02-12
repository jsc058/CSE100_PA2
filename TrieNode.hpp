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
    TrieNode(const Data & d) : data(d) {
      left = right = middle = 0;
      word = false;
      frequency = 0;
      wordstring;
    }

  //public:

    TrieNode<Data>* left;
    TrieNode<Data>* right;
    TrieNode<Data>* middle;
    Data const data;   // the const Data in this node.
    bool word;
    unisnged int frequency;
    string wordstring;
/*
    TrieNode * children[27];
    */
};

#endif
