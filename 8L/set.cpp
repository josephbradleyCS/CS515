#include "set.h"


Set::Set() {
  _root = new TrieNode();
  _size = 0;
}


bool Set::insert(string d) {
  TrieNode* a = _root;
  for (int i = 0; i < d.length(); i++) {
    if (a->child[d[i] - 97] == nullptr) {
      a->child[d[i] - 97] = new TrieNode;
    }
    //a->child[d[i] - 97] = d[i];
    a = a->child[d[i] - 97];
  }
  if (a->isWord) {
    return false;
  }
  _size++;
  a->isWord = true;
  return true;
}

bool Set::erase(string d) {
  TrieNode* a = _root;
  for (int i = 0; i < d.length(); i++) {
    if (a->child[d[i] - 97] == nullptr) {
      return false;
    }
    //a->child[d[i] - 97] = d[i];
    a = a->child[d[i] - 97];
  }
  if (a->isWord) {
    a->isWord = false;
    _size--;
    return true;
  }
  a->isWord = false;
  return a->isWord;
}

bool Set::find(string d) {
    TrieNode* a = _root;
    for (int i = 0; i < d.length(); i++) {
      if (a->child[d[i] - 97] == nullptr) {
        return false;
      }
      //a->child[d[i] - 97] = d[i];
      a = a->child[d[i] - 97];
    }
    if (a->isWord) {
      return true;
    }
    return false;
}

int Set::size() {
  return _size;
}




// Set::~Set() {
//   destructCode(_root);
//   delete _root;
// }
//
// void Set::destructCode(Node* n) {
//   if (n == nullptr) {
//     return;
//   }
//   if (n->left){
//     destructCode(n->left);
//   }
//   if (n->right) {
//     destructCode(n->right);
//   }
//   delete n;
// }
