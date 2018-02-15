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
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

/**
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie.
 */

// Function to sort the vector elements by second element of pair
bool sortbysec(const pair<string,unsigned int> &a,
              const pair<string,unsigned int> &b) {
  //return (a.second > b.second);
  if (a.second > b.second) { 
    return true;
  } 
  if (a.second == b.second) {
    return a.first < b.first;
  }

  return false;
}

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
    vector<string> predictedW;

    // Finding the prefix
    TrieNode * to_compare = trie->root; // start at root to traverse down
    int index = 0; // index for the word
    vector<pair<string,unsigned int>> all_words;
    string current;
    int index2 = 0;

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
      return predictedW;
    }

    char buffer[10000];

    // Check if prefix is a word
    if (to_compare->wordLabel) {
      all_words.push_back(make_pair("", to_compare->frequency));
    }

    // Traverse all the subwords from prefeix
    traversal(to_compare->middle, buffer, 0, &all_words);

    // Sort vector by frequency
    sort(all_words.begin(), all_words.end(), sortbysec);

    // Input the top 10 words to return
    current = all_words[index2].first;
    while (index2 < 10) {
      current.insert(0, prefix);
      predictedW.push_back(current);
      index2++;
      if (index2 >= all_words.size()) {
        break;
      }
      current = all_words[index2].first;
    }

    return predictedW;
  }

  /* Destructor */
  ~Autocomplete() {
    deleteAll(trie->root);
    delete trie;
  }

private:

  //Helper method for destructor
  static void deleteAll(TrieNode * node) {

    if (node == nullptr) {
      return;
    }

    deleteAll(node->left);

    deleteAll(node->right);

    deleteAll(node->middle);

    delete node;
    node = NULL;

  }


 // Method to traverse down tree when searching for predictions
  void traversal(TrieNode * node, char* buffer, int depth,
    vector<pair<string, unsigned int>>* possibles) {
    string myWord;

    if (node != nullptr) {
      // Traverse left
      traversal(node->left, buffer, depth, possibles);

      // Store the character of this node
      buffer[depth] = node->letter;

      if (node->wordLabel) {
        buffer[depth+1] = '\0';
        myWord = buffer;
        possibles->push_back(make_pair(myWord, node->frequency));
      }

      // Traverse middle of the tree
      traversal(node->middle, buffer, depth + 1, possibles);

      // Traverse right of the tree
      traversal(node->right, buffer, depth, possibles);

    }
  }


};

#endif // AUTOCOMPLETE_HPP
