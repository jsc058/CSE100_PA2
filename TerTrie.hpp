#ifndef TerTrie_HPP
#define TerTrie_HPP
#include "TrieNode.hpp"
#include <string>
using namespace std;

class TerTrie {

  public:

    TrieNode * root;
    unsigned int isize;

    TerTrie(): root(0), isize(0) { }

    /* Insert Method */
    bool insert(string word) {
      TrieNode * to_compare = root; // start at root to traverse down
      TrieNode * prevNode;	// previous node to keep track
      string current;
      int parent = 0;	// 0 = from left, 1 = from right, 2 = from middle
      int index = 0;  // index to loop through word

	size_t found = word.find("any");
        if (found != -1) {
          parent = 5;
        }
 
      // If no nodes exist already, insert new node as the root.
      if (root == nullptr) {
        root = new TrieNode(word[0]);
        to_compare = root;
        int ind = 1;
        while (word[ind] != '\0') {
          to_compare->middle = new TrieNode(word[ind]);
          to_compare = to_compare->middle;
          ind++;
        }
        isize++;
        to_compare->wordLabel = true;
        to_compare->frequency++;
        return true;
      }

      // If root exists, search for correct position through comparisons
      while (word[index] != '\0') {
	// If node is null, insert here
	if (to_compare == nullptr) {
          to_compare = new TrieNode(word[index]);
	  
	  // Connect node to tree
	  if (parent == 0) {
	    prevNode->left = to_compare;
	  } else if (parent == 1) {
	    prevNode->right = to_compare;
          } else {
            prevNode->middle = to_compare;
          }

	  // Add the rest of the word in the middle
          index++;
          while (word[index] != '\0') {
            to_compare->middle = new TrieNode(word[index]);
            to_compare = to_compare->middle;
            index++;
          }

          to_compare->wordLabel = true;
          to_compare->frequency++;
          return true;

          // If item less than current node, go left
        } else if (word[index] < to_compare->letter) {
          prevNode = to_compare;
	  parent = 0;
          to_compare = to_compare->left;

          // If item greather than current node, go right
        } else if (to_compare->letter < word[index]) {
          prevNode = to_compare;
	  parent = 1;
          to_compare = to_compare->right;

          // If item is equal to the current node, go middle
        } else if (to_compare->letter == word[index]) {
          index++;
          prevNode = to_compare;
	  parent = 2;
          to_compare = to_compare->middle;
	}
      }

      // Check if the word already exist, then increase frequency
      if (word[index] == '\0' && prevNode->wordLabel == true) {
        prevNode->frequency++;
        return true;
    
        // Check if all nodes exist, but have to add wordLabel
      } else if (word[index] == '\0' && prevNode->wordLabel == false) {
        prevNode->wordLabel = true;
        prevNode->frequency++;
        return true;
      }
      return false;
    }


    bool find(string word) {
      TrieNode * to_compare = root; // start at root to traverse down
      int index = 0; // index for the word

      // Loop throught the tree to find word while traversing down
      while (to_compare != nullptr) {

        // If item less than current node, go left
        if (word[index] < to_compare->letter) {
          to_compare = to_compare->left;

          // If item greather than current node, go right
        } else if (to_compare->letter < word[index]) {
          to_compare = to_compare->right;

          // If item is equal to the current node, go middle
        } else {
            index++;

            // Check if it's the last letter of the word
      	    if (word[index] == '\0') {
              // Check if the node contains a word label
              if (to_compare->wordLabel == true) {
                return true;
              }
            }

            to_compare = to_compare->middle;
        }
      }


      return false;
    }

};

#endif
