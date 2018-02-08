#ifndef TrieNode.hpp
#define TrieNode.hpp
#include <string>
using namespace std;

class TrieNode {
  private:

    /* Constructor */
    TrieNode() {
      for (unsigned int set = 0; set < 27; set++) {
        children[set] = nullptr;
      }
      word = false;
      frequency = 0;
      wordstring = '';
    }

  public:

    TrieNode * children[27];
    bool word = false;
    unsigned int frequency = 0;
    string wordstring;
};

#endif
