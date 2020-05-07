// A non-generic Map ADT implemented with a BST data structure
// The BST is not-balanced and non-threaded
#include "map.h"
#include <iostream>

Map::Map(){
	// create a dummy root node and set up an empty tree

	// scaffold
	cout << "constructed map" << endl;
	//scaffold
	_root = new Elem;
	_root->left = _root;
	_root->right = 0;
	_size = 0;

}

// copy constructor
Map::Map(const Map &v){
	// if empty tree

	// scaffold
	cout << "constructed map with copy" << endl;
	//scaffold

	if (v._root == v._root->left){
		_root = new Elem;
		_root->left = _root;  // empty tree
		_root->right = 0;
		_size = 0;
	} else {
		_root = new Elem;
		_root->left = _root;
		_root->right = 0;
		copyCode(_root->left, v._root->left);
		_size = v._size;
	}
}

// common copy code for deep copy a tree
void  Map::copyCode(Elem* &newRoot, Elem* origRoot){

	// scaffold
	cout << "copied code (possibly inside other method)" << endl;
	//scaffold

	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		copyCode(newRoot->left, origRoot->left);
		copyCode(newRoot->right, origRoot->right);
	}
}

Map::~Map() { // destructor

	// scaffold
	cout << "destruct map (not code) (possibly inside other method)" << endl;
	//scaffold

	if (_size == 0) {
		delete _root;
	} else {
		destructCode(_root->left);
		delete _root;
	}
}


// assignment operator
Map& Map::operator=(const Map &rhs ) {

	// scaffold
	cout << "assigment operator" << endl;
	//scaffold

	if (_size != 0) {
	destructCode(_root);
  }
	copyCode(_root, rhs._root);
	return *this;
}

// insert an element; return true if successful
bool Map::insert(KEY_TYPE key, VALUE_TYPE data) {

	// scaffold
	cout << "insert method" << endl;
	cout << "     key : " << key << endl;
	cout << "     data: " << data << endl;
	//scaffold


	if (insert(_root->left, key, data)) {
		_size++;
		cout << "     " <<  true << endl;
		return true;
	}
	cout << "     " << false << endl;
	return false;

}



// remove an element; return true if successful
bool Map::erase(KEY_TYPE key) {
	// scaffold
	cout << "erase element" << endl;
	//scaffold

	if (find(key) == end()) {
		return false;
	}

	Elem* pary = _root;
	Elem* nody = _root->left;
	bool isRight = 0;


	while(nody->key != key) {
		if (key < nody->key) { // go left
			pary = nody;
			nody = nody->left;
			isRight = false;
		} else { // goright
			pary = nody;
			nody = nody->right;
			isRight = true;
		}
	}
	// nody is the key to be erased
	if (nody->left == nullptr && nody->right == nullptr) {// has no childs
		if (isRight) {
			delete nody;
			pary->right = nullptr;
			_size--;
			return true;
		} else {
			delete nody;
			pary->left = nullptr;
			_size--;
			return true;
		}
	} else if (nody->right == nullptr && nody->left != nullptr) { // has one left child
		// left shild takes the position of the deleted once
		if (isRight) {
			pary->right = nody->left;
			delete nody;
			_size--;
			return true;
		} else {
			pary->left = nody->left;
			delete nody;
			_size--;
			return true;
		}
	} else if (nody->right != nullptr && nody->left == nullptr) { // has one right child
		// nody->right takes place of pary->right;
		if (isRight) {
			pary->right = nody->right;
			delete nody;
			_size--;
			return true;
		} else {
			pary->left = nody->right;
			delete nody;
			_size--;
			return true;
		}
	} else if (nody->right != nullptr && nody->left != nullptr) { // has 2 children
		// replace data in nody with data in nody
		VALUE_TYPE a = nody->left->data;
		bool b = erase(nody->left->key);
		nody->data = a;
		_size--;
		return b;
	}
	return false;
	}

// return size of the Map
int Map::size() const {
	// scaffold
	cout << "size call" << endl;
	//scaffold

	return _size;
}


//===========================Iterator=========================//

// return an iterator pointing to the end if an element is not found,
// otherwise, return an iterator to the element
Map::Iterator Map::find(KEY_TYPE key) const {

	// scaffold
	cout << "find: " << key << endl;
	//scaffold

	Elem* pary = _root;
	Elem* nody = _root->left;

	if (nody == nullptr) {
		return end();
	}

	while(nody->key != key && (nody->left != nullptr && nody->right != nullptr)) {
		if (key < nody->key) { // go left
			pary = nody;
			nody = nody->left;
		} else { // go right
			pary = nody;
			nody = nody->right;
		}
	}

	cout << "      " << (nody->key != key) << endl;

	if ( nody->key != key) {
		return end();
	}
	Iterator it(nody);
	return it;
}

// Iterators for accessing beginning and end of collection
Map::Iterator Map::begin() const {

	// scaffold
	cout << "begin" << endl;
	//scaffold

	Iterator it(_root -> left);
	return it;
}

Map::Iterator Map::end() const {
	// scaffold
	cout << "end" << endl;
	//scaffold

	Elem* nody = _root->left;

	if (nody == nullptr) {
		Iterator ii(_root);
		return ii;
	}

	while(nody->right != nullptr) {
		nody = nody->right;
	}
	Iterator ia(nody);
	return ia;
}

// overloaded subscript operator
VALUE_TYPE& Map::operator[](KEY_TYPE key) {
	return find(key)->data;
}


//===========================Iterator=========================//

// Elem Map::findarent(Elem* node) {
// 	if (node == nullptr) {
// 		return nullptr;
// 	}
//
//
// 	if (node->left != nullptr && node->left != node) {
// 		return findarent(node->left);
// 	} else if (node->left == nullptr) {
//
// 	} else if (node ->left == node) {
// 		return node;
// 	}
//
//
// 	if (node->right != nullptr && node->right != node) {
// 		return findarent(node->right);
// 	} else if (node->right == null) {
//
// 	} else if (node->right == node) {
// 		return node;
// 	}
// }

bool Map::insert(Elem *& root, const KEY_TYPE& key, const VALUE_TYPE& data) {
	// scaffold
	cout << "insert" << endl;
	//scaffold

	Elem as;
	cout << "     adssss " << endl;
	as.data = data;
	cout << "     adsss " << endl;
	as.key = key;
	cout << "     adss " << endl;

	Elem* i = &as;

	Elem* pary = root;
	Elem* nody = root->left;
	bool isRight = 0;

	while(nody->key != key) {
		cout << "while " << endl;
		if (key < nody->key && nody->left == nullptr) {// key < nody>key && nody>left == nullptr
			// insert it to the left of nody
			nody->left = i;
			i->left = nullptr;
			i->right = nullptr;
			cout << "         2 " << endl;
			return true;
		}

		if (key > nody->key && nody->right == nullptr) {
			//insert it to the right of the nody
			nody->right = i;
			i->left = nullptr;
			i->right = nullptr;
			cout << "         3 " << endl;
			return true;
		}

		if (key < nody->key) { // go left
			pary = nody;
			nody = nody->left;
			cout << "         4 " << endl;
			isRight = false;
		} else { // goright
			pary = nody;
			nody = nody->right;
			cout << "          5 " << endl;
			isRight = true;
		}
		cout << endl;
	}
	return false;
}



Map::Elem& Map::Iterator::operator*() {
	return *this->_cur;
}

Map::Elem* Map::Iterator::operator->() {
	return this->_cur;
}
// Iterator operator++(int);
bool Map::Iterator::operator==(Iterator it) const {
	return (it._cur == this->_cur);
}

bool Map::Iterator::operator!=(Iterator it) const {
	return (it._cur != this->_cur);
}

void Map::destructCode(Elem *& p) {
	// scaffold
	cout << "destruct code" << endl;
	//scaffold

	// if (p == nullptr) {
	// 	return;
	// }
	// destructCode(*&(p->left));
 	// destructCode(*&(p->right));
	delete p;
}



//
//  Do Not Modify Below Here
//
//
// output the structure of tree. The tree is output as "lying down"
// in which _root is the LEFT most Elem.
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

// outputs information in tree
ostream& Map::dump(ostream& out) const{
	if ( _root == _root->left) { // tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}

// outputs using overloaded << operator
ostream& operator<< (ostream& out, const Map& v){
	v.dump(out);
	return out;
}
