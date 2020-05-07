// Doesn't Work...close though



#include "HuffTree.h"
#include "PQueue.h"
using namespace std;


// get Huffman code and return it as a string
string HuffTree::getCode(char c) {
  for (int i = 0; i < length; i++) {
    if (arr[i].data == c) {
      return arr[i].code;
    }
  }
  return "";
}

void HuffTree::buildTree(char * chs, int * freqs, int size) {

  int len = 0; while (chs[len] != '\0') {len++;}
  length = len;
  PQueue <HuffNode, 100> pq;

  arr = new HuffNode[length];

  cout << "inserting the huffnodes into the tree\n";
  //pq.print();
  //HuffNode last; last.freq = 0;
  for (int i = 0; i < size; i++) {

    HuffNode hfn;
    hfn.code = "";
    hfn.freq = freqs[i];
    hfn.data = chs[i];
    hfn.left = nullptr;
    hfn.right = nullptr;
    pq.insert(hfn);
    arr[i] = hfn;
  }

  for (int i = 0; i < length; i++) {
    arr[i].thisOne(cout);
  }
  cout << endl << "-----------------------\n";
  pq.clean();
  pq.print();

  int iteration = 0;

  while (pq.size() > 0) {
    iteration++;
    pq.clean();


    HuffNode * right = new HuffNode(pq.findMin());
    pq.deleteMin();
    // char a = right->data;
    // for (int i = 0; i < length; i++) {
    //   if (a != arr[i].data == a) {
    //     right = &arr[i]; break;
    //   }
    // }

    HuffNode * left = new HuffNode(pq.findMin());
    pq.deleteMin();
    // a = left->data;
    // for (int i = 0; i < length; i++) {
    //   if (arr[i].data == a) {
    //     left = &arr[i]; break;
    //   }
    // }

    HuffNode hfn;
    hfn.left = left;
    hfn.right = right;
    hfn.freq = (right->freq + left->freq);
    hfn.data = '\0';
    pq.insert(hfn);
    pq.print();
    //arr[length + iteration] = hfn;


    if (pq.size() == 1) {
      _root = &hfn;
      break;
    }
  }

  // _root = new HuffNode;
  // _root->left = new HuffNode(pq.findMin());
  // _root->right = &a;
  // _root->freq = (_root->left->freq + _root->right->freq);
  // _root->data = '\0';

  cout << "printTree by passing root\n";
  printTree(_root);
  pq.print();
}

void HuffTree::printTree(HuffNode * a) {
  if (a != nullptr) {
    if (a->data = '\0') {
      printTree(a->left);
      printTree(a->right);
    }
    a->thisOne(cout);
  }
}

void HuffTree::buildCodes(HuffNode * hfn, string c) {
  if (hfn == nullptr) {
    return;
  }

  if (hfn->data != '\0') {hfn->code = c; return;}


  cout << "data: " << hfn->data << endl;
  cout << "code: " << hfn->code << endl << endl;

  buildCodes(hfn->left, c + "0");
  buildCodes(hfn->right, c + "1");
  return;

}

HuffTree::~HuffTree() {

}

//-----------------------------------------
HuffNode::HuffNode(HuffNode* l, HuffNode* r, int f, char d, string c) {
  cout << "using adapted constructor\n\t";
  cout << "( left: " << l << ", right: " << r << ", " << "freq: " << f << ", char: " << d << ", code: " << c << ")\n";
  this->data = d;
  this->freq = f;
  this->left = l;
  this->right = r;
  this->code = c;
}
// HuffNode::HuffNode(HuffNode a) {
//   this->data = a.data;
//   this->freq = a.freq;
//   this->code = a.code;
//   this->left = a.left;
//   this->right = a.right;
// }



bool HuffNode::operator<=(HuffNode a) const {
  return (a.freq <= this->freq);
}
bool HuffNode::operator>(HuffNode a) const {
  return (a.freq > this->freq);
}
bool HuffNode::operator<(HuffNode a) const {

  return (a.freq < this->freq);
}
bool HuffNode::operator>=(HuffNode a) const {
  return (a.freq >= this->freq);
}
HuffNode& HuffNode::operator=(const HuffNode &a ){
  this->data = a.data;
  this->freq = a.freq;
  this->code = a.code;
  this->left = a.left;
  this->right = a.right;
  return *this;
}

void HuffNode::thisOne(ostream& out) {
  if (this == 0x0) {
    return;
  }
  if (this->left == nullptr) {
    cout << "caught one\n";
  }
  out << "( left: " << this->left << ", right: " << this->right << ", " << "freq: " << this->freq << ", char: " << this->data << ", code: " << this->code << ")\n";
}
ostream& HuffNode::dump(ostream& out, HuffNode a) const{
  out << "( left: " << a.left << ", right: " << a.right << ", " << "freq: " << a.freq << ", char: " << a.data << ", code: " << a.code << ")\n";
  return out;
}
ostream& HuffNode::operator<< (ostream& out) const {
  dump(out, *this);
  return out;
}
ostream& operator<< (ostream& out, HuffNode a){
  a.thisOne(out);
  return out;
}
