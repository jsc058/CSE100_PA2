#ifndef MWTrie
#define MWTrie
#include "TrieNode.hpp"
#include <string>
using namespace std;

class MWTrie {

  protected:

    TrieNode * root;

    unsigned int isize;

    unsigned int iheight;

public:

    MWTrie(): root(0), isize(0), iheight(0) { }

    /* Insert Method */
    bool insert(string word) {
      TrieNode * to_compare = root;
      int edge_val = 0;
      string current;

      for (unsigned int i = 0; i < word.length(); i++) {
        edge_val = (word[i]) - 'a';
        if (edge_val == (-32)) {
          edge_val = 26;
        }

        // If already existing letter, follow to next node
        if (to_compare->children[edge_val] != nullptr) {
          current = current + (char)edge_val;
          to_compare = to_compare->children[edge_val];
        }
        // If new letter, create new node to point to 
        else {
          //TrieNode * new_letter = new TrieNode();
          to_compare->children[edge_val] = new_letter;
          current = current + (char)edge_val;
          to_compare = new_letter;
        }

        // If at last letter, check if that word exists
        if (i == word.length() -1) {
          if (to_compare->word) {
            return false;
          }
          else {
            to_compare->word = true;
            to_compare->frequency++;
            to_compare->wordstring = current;
            return true;
          }
        }
      }
      return false;
    }

    bool find(string word) {
      TrieNode * to_compare = root;
      int edge_val = 0;

      for (unsigned int i = 0; i < word.length(); i++) {
        edge_val = (word[i]) - 'a';
        if (edge_val == (-32)) {
          edge_val = 26;
        }

        // If already existing letter, follow to next node
        if (to_compare->children[edge_val] != nullptr) {
          to_compare = to_compare->children[edge_val];
        }
        // If new letter, word is not found
        else {
          return false;
        }

        // If at last letter, check if that word exists
        if (i == word.length() -1 && to_compare->word) {
          return true;
        }
      }

      return false;

    }

};

#endif
