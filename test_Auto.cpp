#include "Autocomplete.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
  vector<string> v;
  v.push_back("apple");
  v.push_back("ape");
  v.push_back("applet");
  v.push_back("cape");
  v.push_back("tall");
  v.push_back("tap");
  v.push_back("tape");
  v.push_back("ace");

  Autocomplete wordsTest(v);

  TerTrie trie;
  bool found;
  trie.insert("apple");
  found = trie.find("apple");
  if (found) {
    cout << "Found" << endl;
  } else {
    cout << "Not found" << endl;
  }

  found = trie.find("app");
  if (found) {
    cout << "Found" << endl;
  } else {
    cout << "Not found" << endl;
  }
  
  return -1;

/*
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
*/
}
