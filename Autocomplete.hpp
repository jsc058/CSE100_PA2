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
    TrieNode * to_compare = trie->root;
    int edge_val = 0;
    int counter = 0;

/*
    for (unsigned int i = 0; i < prefix.length(); i++) {
      edge_val = (prefix[i]) - 'a';
      if (edge_val == (-32)) {
        edge_val = 26;
      }

      // If already existing letter, follow to next node
      if (to_compare->children[edge_val] != nullptr) {
        to_compare = to_compare->children[edge_val];
      }
    }
    // At this point, to_compare holds the last node of the prefix

    // Need to store all possible completions in a vector

    if (to_compare->word) {
      predictedW[counter] = to_compare->wordstring;
      counter++;
      if (counter == 10) {
        break;
      }
    }

    // pull top 10 strings from top 10 nodes
    vecor<TrieNode> * sorted = compareSort()
    for (int i = 0; i < 10; i++) {
      predictedW[i] = sorted[i]->wordstring;
    }
*/
    return predictedW;
  }

  /* Destructor */
  ~Autocomplete() {
    //TODO
  }


  /*
   * This function returns the top ten most frequent string completions
   * by sorting through a vector of all possible completions.
   *
   */
/*
  vector<TrieNode> compareSort(vector<TrieNode> allPossible) {
    TrieNode * top;
    vector<TrieNode> sorted[10];

    for (int i = 0; i < allPossible.length()-1; i++) {
      for (int j = 1; j < allPossible.length(); j++){
        // If next element is more frequent than current, store the next element
        if (allPossible[i] < allPossible [j]) {
          top = allPossible[j];
        }
        else {
          top = allPossible[i];
        }
      }
      sorted[i] = top;
    }

    return sorted;
  }
*/
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

};

#endif // AUTOCOMPLETE_HPP
