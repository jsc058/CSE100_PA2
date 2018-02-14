#include "Autocomplete.hpp"
#include "AutocompleteUtils.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

//bool sortbysec(const pair<string,int> &a, const pair<string,int> &b) {
  //return (a.second > b.second);
//}

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
/*
  vector<pair<string,int>> tester;
  tester.push_back(make_pair("all",2));
  tester.push_back(make_pair("hoe",3));
  tester.push_back(make_pair("ball",1));
  tester.push_back(make_pair("allow",1));
  tester.push_back(make_pair("hall",1));
  tester.push_back(make_pair("start",6));
  tester.push_back(make_pair("starter",6));
  
  sort(tester.begin(), tester.end()); 
  sort(tester.begin(), tester.end(), sortbysec);
  */

  vector<string> returned;
  /*
  returned = wordsTest.predictCompletions("a");
  //cout << tester << endl;
  //vector<string> returned;
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
*/
  // Test 2
  vector<string> correct2;
  //correct2.push_back("ape");
  correct2.push_back("apple");
  correct2.push_back("applet");
  returned = wordsTest.predictCompletions("apple");
  if (returned == correct2) {
    cout << "Passed Test 2" << endl;
  } else {
    cout << "Failed Test 2" << endl;
    return -1;
  }

  // Test3
  Autocomplete wordsTest2(AutocompleteUtils::getWords("TestCases/SingleCorpus.txt"));
  vector<string> correct3;
  vector<string> returned2;
  correct3.push_back("wasn't");
  returned2 = wordsTest2.predictCompletions("wa");
  if (returned2 == correct3) {
    cout << "Passed Test 3" << endl;
  } else {
    cout << "Failed Test 3" << endl;
    return -1;
  }
vector<string>returned3;

  Autocomplete wordsTest3(AutocompleteUtils::getWords("TestCases/ModerateCorpus.txt"));
  returned3 = wordsTest3.predictCompletions("tho");
  Autocomplete wordsTest4(AutocompleteUtils::getWords("TestCases/LargeCorpus.txt"));
  
  return -1;
}
