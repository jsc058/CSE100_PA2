#ifndef TerTrie
#define TerTrie
#include "TrieNode.hpp"
#include <string>
using namespace std;

class TerTrie {

  protected:

    TrieNode * root;

    unsigned int isize;

    unsigned int iheight;

public:

    TerTrie(): root(0), isize(0), iheight(0) { }

    /* Insert Method */
    bool insert(string word) {
      TrieNode * to_compare = root; // start at root to traverse down
      int edge_val = 0;
      string current;

      // If no nodes exist already, insert new node as the root.
      if (root == nullptr) {
        root = new TrieNode(word[0]);
        to_compare = root;
        int ind = 1;
        while (word[ind] != '\0') {
          to_compare->middle = new TrieNode(word[ind]);
          ind++;
        }
        isize++;
        iheight++;
        return true;
      }

      // If root exists, search for correct position through comparisons
      while (to_compare != nullptr) {
        // If item less than current node, go left
        if (to_compare->data < item) {
          to_compare = to_compare->left;

          // If item greather than current node, go right
        } else if (item < to_compare->data) {
          to_compare = to_compare->right;

          // If item is equal to the current node, go middle
        } else {
          // Check if it's the last letter of the word
          if (word[i+1] == '\0') {
            // Check if the node contains a word label
            if (to_compare->word == true) {
              to_compare->frequency++;
              return true;
            } else {
            }
          } else {
            to_compare = to_compare->middle;
          }
        }
      }

      return false;
    }


    bool find(string word) {
      TrieNode * to_compare = root; // start at root to traverse down
      int edge_val = 0;

      // Loop throught the word to find while traversing down
      for (unsigned int i = 0; i < word.length(); i++) {
        // If item less than current node, go left
        if (to_compare->data < word[i]) {
          to_compare = to_compare->left;

          // If item greather than current node, go right
        } else if (word[i] < to_compare->data) {
          to_compare = to_compare->right;

          // If item is equal to the current node, go middle
        } else {
          // Check if it's the last letter of the word
          if (word[i+1] == '\0') {
            // Check if the node contains a word label
            if (to_compare->word == true) {
              return true;
            } else {
              return false;
            }
          } else {
            to_compare = to_compare->middle;
          }
        }
      }

      return false;
    }

};

#endif
