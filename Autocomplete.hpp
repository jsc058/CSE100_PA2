/**
 *  CSE 100 PA2 C++ Autocomplete
 *  Author: Jonathan Margoliash
 *  Modified from code authored by: Jor-el Briones, Christine Alvarado
 */

#ifndef AUTOCOMPLETE_HPP
#define AUTOCOMPLETE_HPP
#include "TerTrie.hpp"
#include <vector>
#include <string>
using namespace std;

/**
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie.
 */
class Autocomplete
{
public:

  TerTrie * trie;
  /*
  Create an Autocomplete object.
  This object should be trained on the words vector
  That is - the predictCompletions() function below should pull autocomplete
  suggestions from this vector

  Input: words. Must be all lowercase, with most  non-word characters removed (e.g. ',' ';' '%' etc.)
  In addition to alphabetic characters, words may contain digits, single apostrophes, dashes etc.
  */
  Autocomplete(const vector<string> words) {
    trie = new TerTrie();
    for (unsigned int i = 0; i < words.size(); i++) {
      trie->insert(words[i]);
    }
  }

  /* Return up to 10 of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than 10 legal completions, this
   * function returns a vector with as many completions as possible.
   * Otherwise, 10 completions should be returned.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the 10 most frequent completions
   * of the prefix)
   * If you need to choose between two or more completions which have the same frequency,
   * choose the one that comes first in alphabetical order.
   *
   * Inputs: prefix. The prefix to be completed. Must be of length >= 1.
   * Return: the vector of completions
   */
  vector<string> predictCompletions(const string prefix) {
    vector<string> predictedW(10);

    // Finding the prefix
    TrieNode * to_compare = trie->root; // start at root to traverse down
    int index = 0; // index for the word

    // Loop through the tree to find prefix
    while (to_compare != nullptr) {
      // If item less than current node, go left
      if (prefix[index] < to_compare->letter) {
        to_compare = to_compare->left;
        // If item greather than current node, go right
      } else if (to_compare->letter < prefix[index]) {
        to_compare = to_compare->right;
        // If item is equal to the current node, go middle
      } else {
          index++;
          // Check if it's the last letter of the word
          if (prefix[index] == '\0') {
            break;
          }
          to_compare = to_compare->middle;
      }
    }
    // If prefix does not exist
    if (to_compare == nullptr) {
      return nullptr;
    }

    // Start DFS from the last letter of the prefix



    return predictedW;
  }

  /* Destructor */
  ~Autocomplete() {
    //TODO
  }



private:

  //you may add your own code here
  static void deleteAll(TrieNode * node) {
    if (node == nullptr) {
      return;
    }

    if (node->left != nullptr) {
      deleteAll(node->left);
    }

    if (node->right != nullptr) {
      deleteAll(node->right);
    }

    if (node->middle != nullptr){
      deleteAll(node->middle);
    }

    delete node;

  }

  // DFS helper function
  // TODO Need to pair node and string to return
  vector<TrieNode>,string dfs(TrieNode& start) {
    stack<TrieNode> completions;
    string currentWord;
    vector<TrieNode> possibles;
    TrieNode * curr;

    completions.push(start);

    while (completions.size() != 0) {
      // Push all children first
      if (curr->middle->left != nullptr) {
        completions.push(curr->left);
      }
      if (curr->middle->right != nullptr) {
        completions.push(curr->right);
      }
      if (curr->middle != nullptr) {
        completions.push(curr->middle);
      }

      curr = completions.pop();
      currentWord.append(curr->letter);

      if (curr->wordLabel) {
        possibles.push_back(curr);
        currrentWord = null;
      }
    }
  }

};

#endif // AUTOCOMPLETE_HPP
