// A non-generic Map ADT implemented with a BST data structure
// The BST is not-balanced and non-threaded
#include "map.h"
#include <iostream>
#include <string>



Map::Map() {
 _size = 0;
 _root = new Elem;
 _root->right = nullptr;
 _root->left = _root;
}
Map::Map(const Map &v){
	// if empty tree
	if (!v._root) {
		_root = nullptr;
		return;
	}
	if (v._root == v._root->left){
		_root = new Elem;
		_root->left = _root;
		_root->right = 0;
		_size = 0;
	} else {
		copyCode(_root, v._root);
		_size = v._size;
	}
}
Map::~Map() { // destructor
	if(_root->left == _root) {delete _root;}
  else {destructCode(_root);}
}

bool Map::insert(KEY_TYPE key, VALUE_TYPE data) {
  return insert(_root, key, data);
}
bool Map::insert(Elem *& _root, const KEY_TYPE& key, const VALUE_TYPE& data) {
  if(_root == _root->left){
		_root->left = new Elem;
		_root->left->key = key;
		_root->left->right = nullptr;
		_root->left->left = nullptr;
		_root->left->data = data;
    _size++; return true;
	}

	Elem * _cur = _root->left;
	while (_cur) {
    bool leftbool = false;
    bool rightbool = false;
    bool lsebool = true;

    if (key.length() > _cur->key.length()) { // key is greater than _cur->key; go right
      //cout << "right\n";
      rightbool = true;
    } else if (key.length() < _cur->key.length()) { // key is less than _cur->key; go left
      //cout << "left\n";
      leftbool = true;
    } else if (key.length() == _cur->key.length()) {
      if (key < _cur->key) { // go left
        //cout << "left\n";
        leftbool = true;
      } else if (key > _cur->key) { // go right
        //cout << "right\n";
        rightbool = true;
      } else { // else
        //cout << "break/return true\n";
        lsebool = true;
      }
    }

		if (leftbool) {
			if (_cur->left == nullptr) {
				_cur->left = new Elem;
				_cur->left->left = nullptr;
				_cur->left->right = nullptr;
				_cur->left->key = key;
        _cur->left->data = data;
				_size++; return true;
			} else {
				_cur = _cur->left;
			}
		} else if (rightbool) {

			if (_cur->right == nullptr) {
				_cur->right = new Elem;
				_cur->right->left = nullptr;
				_cur->right->right = nullptr;
				_cur->right->key = key;
        _cur->right->data = data;
        _size++; return true;
			} else {
				_cur = _cur->right;
			}
		} else if (lsebool) {
      break;
		}
	}
  return false;
}

bool Map::erase(KEY_TYPE key) {
  cout << "erasing: " << key << endl;
	Elem* pary = _root->left;
	Elem* nody = _root->left;
	bool isRight = 0;
  bool ret = false;

	while(nody) {
		if ((key.length() == nody->key.length() && key < nody->key) || key.length() < nody->key.length()) {     // go left
      if (nody->left == nullptr) {return false;}
			pary = nody;
			nody = nody->left;
			isRight = false;
		} else if ((key.length() == nody->key.length() && key > nody->key) || key.length() > nody->key.length()) { // go right
      if (nody->right == nullptr) {return false;}
			pary = nody;
			nody = nody->right;
			isRight = true;
		} else {
      break;
		}
	}
  // if (nody == nullptr) {
  //   return false;
  // }
  if (nody->left == nullptr && nody->right == nullptr) {// has no childs
    if (isRight) {
      pary->right = nullptr;
      delete nody; _size--;
    } else {
      pary->left = nullptr;
      if (pary == nody) {
        _root->left = _root;
      }
      delete nody; _size--;
    }
  } else if (nody->right == nullptr && nody->left != nullptr) { // has one left child
    // left shild takes the position of the deleted once
    if (pary == nody) {
      pary = _root;
    }
    if (isRight) {
      pary->right = nody->left;
      delete nody; _size--;
    } else {
      pary->left = nody->left;
      delete nody; _size--;
    }
  } else if (nody->right != nullptr && nody->left == nullptr) { // has one right child
    // nody->right takes place of pary->right;
    if (pary == nody) {
      pary = _root;
    }
    if (isRight) {
      pary->right = nody->right;
      delete nody; _size--;
    } else {
      pary->left = nody->right;
      delete nody; _size--;
    }
  } else if (nody->right != nullptr && nody->left != nullptr) { // has 2 children
    Elem * temp = nody->right;
    while (temp->left != nullptr) {
      temp = temp->left;
    }
    KEY_TYPE tempKey = temp->key;
    VALUE_TYPE tempData = temp->data;
    erase(temp->key);
    nody->key = tempKey;
    nody->data = tempData;
  }
  return true;
}
int Map::size() const {
	return _size;
}

Map::Iterator Map::find(KEY_TYPE key) const {
	Elem * _cur = _root->left;
	if (_cur == _root) {
		return end();
	}
	while (_cur != nullptr) {
		if ((key.length() == _cur->key.length() && key < _cur->key) || key.length() < _cur->key.length()) {
			_cur = _cur->left;
		} else if ((key.length() == _cur->key.length() && key > _cur->key) || key.length() > _cur->key.length()) {
			_cur = _cur->right;
		} else {
      return Iterator(_cur);
    }
	}
	return end();
}

Map::Iterator Map::begin() const {
	Elem* tmp = _root;
	if (_root->left == _root) { // empty tree
		return Iterator(_root);
	}
	while (tmp->left != nullptr) { // descent to leftmost node
		tmp = tmp->left;
	}
	return Iterator(tmp);
}
Map::Iterator Map::end() const {
	Iterator ia(_root);
	return ia;
}
Map& Map::operator=(const Map &rhs ) {
  if(this != &rhs) {
      if(_root->left == _root) {delete _root;}
      else {destructCode(_root);}
      _root = new Elem;
      _root->left = _root;  // empty tree
      _root->right = nullptr;
      if (rhs._root == rhs._root->left){
          _size = 0;
      } else {
          copyCode(_root->left, rhs._root->left);
          _size = rhs._size;
      }
    }
    return *this;
}
VALUE_TYPE& Map::operator[](KEY_TYPE key) {

  Iterator b = find(key);
  if (b != end()) {
      return b->data;
  }
  insert(key, "");
  b = find(key);
  return b->data;
}
Map::Elem& Map::Iterator::operator*() {
	return *this->_cur;
}
Map::Elem* Map::Iterator::operator->() {
  //cout << "key: " << this->_cur->key << ", " << "data: " << this->_cur->data << endl;
	return this->_cur;
}
//Map::Iterator Map::Iterator::operator++(int a) {}
bool Map::Iterator::operator==(Iterator it) const {
	return (it._cur->key == this->_cur->key && it._cur->data == this->_cur->data
    && it._cur->left == this->_cur->left && it._cur->right == this->_cur->right);
}
bool Map::Iterator::operator!=(Iterator it) const {
  return !(it._cur->key == this->_cur->key && it._cur->data == this->_cur->data
    && it._cur->left == this->_cur->left && it._cur->right == this->_cur->right);
}

void Map::copyCode(Elem* &newRoot, Elem* origRoot){
	if (origRoot == nullptr) {
		newRoot = nullptr;
		return;
	} else {
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		copyCode(newRoot->left, origRoot->left);
		copyCode(newRoot->right, origRoot->right);
	}
}
void Map::destructCode(Elem *& p) {
   if( p == nullptr) {_size = 0;}
   if( p != nullptr) {
     if (p->right !=nullptr) destructCode(p->right);
     if (p->left != nullptr) destructCode(p->left);
     delete p;
   }
   //p = nullptr;
   _size = 0;
}

// DO NOT TOUCH
void Map::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		printTree(out, level+1, p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->key << " " << p->data << '\n';
		printTree(out, level+1, p->left);
	}
}
ostream& Map::dump(ostream& out) const{
	if ( _root == _root->left) { // tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}
ostream& operator<< (ostream& out, const Map& v){
	v.dump(out);
	return out;
}
