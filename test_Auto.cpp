#include "Autocomplete.hpp"
#include "AutocompleteUtils.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {

  vector<string>* v = new vector<string>(10);
  /*v->push_back(string("apple"));
  v->push_back(string("ape"));
  v->push_back(string("applet"));

  v->push_back("cape");
  v->push_back("tall");
  v->push_back("tap");
  v->push_back("tape");
  v->push_back("ace");
*/
//v = getWords("TestCases/SingleWords.txt");
  Autocomplete wordsTest(AutocompleteUtils::getWords("TestCases/SingleWords.txt"));

  TerTrie trie;
  bool found;
  trie.insert("apple");
  trie.insert("ape");
  trie.insert("ape");
  trie.insert("applet");
  trie.insert("cape");
  trie.insert("tall");
  trie.insert("tap");
  trie.insert("tape");
  trie.insert("ace");
  found = trie.find("ape");
  if (found) {
    cout << "Found" << endl;
  } else {
    cout << "Not found" << endl;
  }

  found = trie.find("ace");
  if (found) {
    cout << "Found" << endl;
  } else {
    cout << "Not found" << endl;
  }

  //return -1;

  vector<string> returned;
  vector<string> correct;
  correct.push_back("ace");
  correct.push_back("ape");
  correct.push_back("apple");
  correct.push_back("applet");

  // Test 1
  returned = wordsTest.predictCompletions("a");
  if (returned == correct) {
    cout << "Passed Test 1" << endl;
  } else {
    cout << "Failed Test 1" << endl;
    return -1;
  }

  // Test 2
  vector<string> correct2;
  correct.push_back("ape");
  correct.push_back("apple");
  correct.push_back("applet");
  returned = wordsTest.predictCompletions("ap");
  if (returned == correct) {
    cout << "Passed Test 2" << endl;
  } else {
    cout << "Failed Test 2" << endl;
    return -1;
  }
  
  return -1;
}
