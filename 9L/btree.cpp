#include "btree.h"

// helper method for tree display
void BTreeNode::indent(int depth){
    for(int i=0; i<depth; i++)
        cout << "\t";
}

BTreeNode * BLeaf::insert(int &newKey, string item){
  // find position for insert into current node
 int pos=size-1;
 while (pos>=0 && newKey<keys[pos]) {
     keys[pos+1] = keys[pos];
     data[pos+1] = data[pos];
     pos--;
 }
 keys[pos+1] = newKey;
 data[pos+1] = item;
 size++;

 if(size < ORDER) // if curent leaf node does not overflow
     return 0;

 else { // need split
     // create new leaf
     BLeaf *sibling = new BLeaf();

     // copy upper half of the current node's elements over
     for(int i=0; i < ORDER/2; i++){
         sibling->data[i] = data[i + (ORDER + 1)/2];
         sibling->keys[i] = keys[i + (ORDER + 1)/2];
     }

     // update size for both nodes
     sibling->size = ORDER/2;
     size -= ORDER/2;

     // send back new key by reference
     newKey = sibling->keys[0]; // sibling->keys[0] same as keys[(ORDER + 1)/2]

     // and return pointer to new node
     return sibling;
 }
}

void BLeaf::dump(int depth){
    indent(depth);
    int i;
    for(i = 0; i<size-1; i++)
        cout << keys[i] << ":" << data[i] << " ";
    cout << keys[i] << ":" << data[i] << endl;
}

BTreeNode * BInternal::insert(int &newKey, string item){
  int pos = 0;
  while (pos < size -1  && newKey >= keys[pos + 1]) {
      pos++;
  }
  int newerKey = newKey;
  BTreeNode *s = child[pos]->insert(newerKey, item);

  if(s) {
    for(int i= size-1; i >= pos + 1; i--) {
      keys[i+1] = keys[i];
      child[i+1] = child[i];
    }
    child[pos+1] = s;
    keys[pos+1] = newerKey;
    size++;
  }

  if (size < ORDER) {
    return 0;
  } else {
    BInternal *sibling = new BInternal();
    for (int i = 0; i < ORDER/2; i++) {
        sibling->child[i] = child[i + (ORDER + 1)/2];
        sibling->keys[i] = keys[i + (ORDER + 1)/2];
    }
    sibling->size = ORDER/2;
    size -= ORDER/2;

    // send back new key by reference
    newKey = sibling->keys[0]; // sibling->keys[0] same as keys[(ORDER + 1)/2]

    // and return pointer to new node
    return sibling;
  }
}

void BInternal::dump(int depth){
    indent(depth);
    cout << "[";
    int i;
    for(i=1; i<size-1; i++) // keys[0] not displayed
        cout << keys[i] << ",";
    cout << keys[i] << "]" << endl;

    // call dump on all children
    for(int i=0; i<size; i++)
        child[i]->dump(depth+1);
}

void BTree::insert(int newKey, string item){
    BTreeNode * split = root->insert(newKey, item);
    if(split) {
        // splitting root; new root now has two children
        BInternal *newRoot = new BInternal();
        newRoot->child[0] = root;
        newRoot->child[1] = split;
        newRoot->keys[1] = newKey;
        newRoot->size = 2;
        root = newRoot;
    }
}
