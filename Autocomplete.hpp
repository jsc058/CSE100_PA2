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
  return (a.second < b.second);
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
    vector<string> predictedW(10);

    // Finding the prefix
    TrieNode * to_compare = trie->root; // start at root to traverse down
    int index = 0; // index for the word
    vector<pair<string,unsigned int>> all_words;
    string current;

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

    // Start DFS from the last letter of the prefix
    all_words = search(*to_compare, prefix);

    // Sort vector alphabetically and then by frequency
    sort(all_words.begin(), all_words.end());
    sort(all_words.begin(), all_words.end(), sortbysec);

    // Input the top 10 words to return
    for (int i = 0; i < 10; i++) {
      current = all_words[i].first;
      predictedW.push_back(current);
    }

    return predictedW;
  }

  // DFS helper function
  // start: last letter of the prefix
  vector<pair<string,unsigned int>> search(TrieNode& start, const string prefix) {
    vector<pair<string,unsigned int>> possibles;
    vector<pair<string,unsigned int>> possibles_sub;
    stack<TrieNode> completions;
    string currWord;
    TrieNode * curr = start.middle;

    // If prefix is a word, add to possibles
    if (start.wordLabel) {
      possibles.push_back(make_pair(prefix, start.frequency));
    }

    // Add all children of the prefix end to the stack
    if (curr->middle != nullptr) {
      completions.push(*curr);
    }
    if (curr->right != nullptr) {
      completions.push(*curr->right);
    }
    if (curr->left != nullptr) {
      completions.push(*curr->left);
    }

    // Pop from stack to find all completions
    while (completions.size() != 0) {
      currWord = prefix;
      curr = &completions.top();
      completions.pop();
      currWord.append(&curr->letter);

      // Explore the left and right possible words
      if (curr->left != nullptr || curr->right != nullptr) {
        possibles_sub = search(*curr, currWord);
        possibles.insert(possibles.end(), possibles_sub.begin(), possibles_sub.end());
      }

      // Explore additions to current word
      if (curr->middle != nullptr) {
        possibles_sub = search(*curr, currWord);
        possibles.insert(possibles.end(), possibles_sub.begin(), possibles_sub.end());
      }

      // Push to results if the node is a word node
      if (curr->wordLabel) {
        possibles.push_back(make_pair(currWord, curr->frequency));
      }

    }

    return possibles;
  }

  /* Destructor */
  ~Autocomplete() {
    deleteAll(trie->root);
  }



private:

  //you may add your own code here
  static void deleteAll(TrieNode * node) {
    if (node == nullptr) {
      return;
    }

    //if (node->left != nullptr) {
      deleteAll(node->left);
    //}

    //if (node->right != nullptr) {
      deleteAll(node->right);
    //}

    //if (node->middle != nullptr){
      deleteAll(node->middle);
    //}

    delete node;

  }



};

#endif // AUTOCOMPLETE_HPP
