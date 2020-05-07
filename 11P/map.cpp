

// A generic Map implemented with right-threaded BST
// BST is not balanced


#include <map> // helper container for thread copying
//#include "map.h"

/*-------------------------Iterator Methods ------------------------------------------------------------------------------------*/

template <typename KEY, typename T>
typename Map<KEY, T>::Elem& Map<KEY, T>::Iterator::operator*(){
	return *this->_cur;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Elem* Map<KEY, T>::Iterator::operator->(){
	return this->_cur;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::Iterator::operator++(int i){
	//cout << "cur: " << _cur->key << endl;

	if (_cur->left && _cur->left == _cur) {
		return Iterator(_cur);
	}
	if (_cur->rightThread) {
		_cur = _cur->right;
	} else { // might need to check if last node->right == end()
		if (_cur->right == nullptr) {
			return Iterator(_cur);
		}
		_cur = _cur->right;
		while (_cur->left) {
			_cur = _cur->left;
		}
	}

	Iterator it(_cur);
	while (i > 1) {
		i--;
		it++;
	}

	return it;
}

template <typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator==(Iterator it) {
	return (_cur->key == it->key);
}

template <typename KEY, typename T>
bool Map<KEY, T>::Iterator::operator!=(Iterator it) {
	if (it._cur == _cur) {
		return false;
	}
	return true;

}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::begin() const {  // return the left most (smallest) tree node

	Elem * a = _root->left;
	if (_root == _root->left) {
		return end();
	}

	while (a->left != nullptr) {
		if (_size == 0) {
			return end();
		}
		a = a->left;
	}
	return Iterator(a);

}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::end() const {  // return the dummy root node
	return Iterator(_root);
}

/*-----------------------Public MAP METHODS--------------------------------------------------------------------------------------------*/
template <typename KEY, typename T>
Map<KEY, T>::Map(){
	// create a dummy root node
	_root = new Elem;
	_root->height = -1;
	_root->left = _root;  // empty tree
	_root->right = nullptr;
	_root->rightThread = false;
	_size = 0;

}

template <typename KEY, typename T>
Map<KEY, T>::Map(const Map &v){
	//if empty tree
	if (v._root == v._root->left){
		//delete _root;
		_root = new Elem;
		_root->height = -1;
		_root->left = _root;  // empty tree
		_root->right = 0;
		_root->rightThread = false;
		_size = 0;
		return;
	} else {
		//delete _root;
		_root = new Elem;
		_root->height = -1;
		_root->left = _root;
		_root->right = 0;
		_root->rightThread = false;
		copyCode(_root->left, v._root->left); // to deep copy the tree without dummy nodes
		copyThread(_root, v._root); // to copy the threading; must pass dummy nodes to complete the threads
		_size = v._size;
	}
}

template <typename KEY, typename T>
Map<KEY, T>::~Map() {
	if(_root->left == _root) {delete _root;
	}
  else {
		destructCode(_root->left);
		delete _root;
	}
}

template <typename KEY, typename T>
Map<KEY, T>& Map<KEY, T>::operator=(const Map<KEY, T> &rhs) {
	destructCode(_root->left);
	delete _root;
	_root = new Elem;
	_root->height = -1;
	_root->left = _root;
	_root->right = nullptr;
	_root->rightThread = false;
	copyCode(_root->left, rhs._root->left);
	copyThread(_root, rhs._root);
	_size = rhs.size();
	return *this;
}

template <typename KEY, typename T>
bool Map<KEY, T>::insert(KEY key, T data) {
	return insert(_root->left, key, data, _root);
}

template <typename KEY, typename T>
int Map<KEY, T>::size() const{
	return _size;
}

template <typename KEY, typename T>
typename Map<KEY, T>::Iterator Map<KEY, T>::find(KEY key) const {
	//cout << "\tfinding: " << key << endl;
	Elem * _cur = _root->left;

	//string a = "\t";
	if (_cur == _root) {
		return end();
	}
	while (_cur != nullptr) {
		//cout << a << _cur->key << endl;
		//a = (a.append(a));
		if (key < _cur->key) {
			//cout << a << "going left\n";
			_cur = _cur->left;
		} else if (key > _cur->key) {
			//cout << a << "going right\n";
			if (!_cur->rightThread) {
				_cur = _cur->right;
			} else {
				return end();
			}
		} else {
			//cout << "returning iterator to: " << _cur->key << endl;
			return Iterator(_cur);
		}
	}
	return end();
}

template <typename KEY, typename T>
T& Map<KEY, T>::operator[](KEY key) {
	//cout << "operator[" << key << "]\n";
	Map<KEY, T>::Iterator b = find(key);
	if (b != end()) {
			return b->data;
	}
	T a;
	insert(key, a);
	b = find(key);
	return b->data;
}

/*-----------------Private Map Methods---------------------------------------------------------------------------------------------------*/

template <typename KEY, typename T>
void Map<KEY, T>::destructCode(Elem *& p) {
	//cout << "p->key" << p->key << endl;
	if (_root == _root->left) {
		return;
	}

	if( p == nullptr) {_size = 0;}
  if( p != nullptr) {
		if (!p->rightThread && p->right != nullptr) destructCode(p->right);
		if (p->left != nullptr) destructCode(p->left);
		delete p;
	}
	//p = nullptr;
	_size = 0;
}

template <typename KEY, typename T>
void Map<KEY, T>::addToMap(Elem* root, map<KEY, Elem*> &keyElemMap){
	if (root) {
		keyElemMap[root->key] = root;

	addToMap(root->left, keyElemMap);
	if (!root->rightThread)
		addToMap(root->right, keyElemMap);
	}
}

template <typename KEY, typename T>
void Map<KEY, T>::copyThread(Elem* &newRoot, Elem* origRoot){
	// construct the key-element map for new and orig tree
	map<KEY, Elem*> newKeyElemMap;
	map<KEY, Elem*> origKeyElemMap;
	addToMap(newRoot->left, newKeyElemMap);
	addToMap(origRoot->left, origKeyElemMap);

	// start at the last element in the tree, which threads to root
	typename map<KEY, Elem*>::reverse_iterator it = origKeyElemMap.rbegin();
	newKeyElemMap[it->first] -> rightThread = true;
	newKeyElemMap[it->first] -> right = newRoot;

	// then thread the rest of the tree backwardly
	it++;
	while(it != origKeyElemMap.rend()){
		if (it->second->rightThread){
			newKeyElemMap[it->first] -> rightThread = true;
			newKeyElemMap[it->first] -> right = newKeyElemMap[ origKeyElemMap[it->first]->right->key ];
		}
		it++;
	}
}

template <typename KEY, typename T>
void  Map<KEY, T>::copyCode(Elem* &newRoot, Elem* origRoot){
	if (origRoot == 0)
		newRoot = 0;
	else{
		newRoot = new Elem;
		newRoot->height = origRoot->height;
		newRoot->key = origRoot->key;
		newRoot->data = origRoot->data;
		newRoot->rightThread = origRoot->rightThread;
		copyCode(newRoot->left, origRoot->left);
		if (!origRoot->rightThread)
			copyCode(newRoot->right, origRoot->right);
	}
}

/*--------------------NEW METHODS-----------------------------------------------------------------------------------------------*/
template <typename KEY, typename T>
bool Map<KEY, T>::insert(Elem *& node, const KEY &key, const T &data, Elem *lastLeft) {
	//cout << "insert on: " << key << " by node: " << node->key << endl;
	if(_root == _root->left){
		//cout << "\t_root insert\n";
		_root->height = -1;

		_root->right = nullptr;
		_root->rightThread = false;
		_root->left = nullptr;
		_root->left = new Elem;
		_root->left->key = key;
		_root->left->data = data;
		_root->left->right = _root;
		_root->left->left = nullptr;
		_root->left->rightThread = true;
		_root->left->height = 0;
		_size++;
		return true;
	}

	bool ret = true;
  if (node == 0) {
    //cout << "\tinserting here\n";
	  node = new Elem;
	  node->key = key;
	  node->data = data;
	  node->left = nullptr;
	  node->test = false;
	  node->height = 0;
	  node->right = lastLeft;
	  node->rightThread = true;
    _size++;
		return true;
  }

	if (key < node->key) {
			//cout  << "\tgoing left\n";
			if (node->left == nullptr) {
        //cout  << "\tinserting left\n";
				// if (!node->rightThread) { // One right child
				// 	node->height = 1;
				// } else if (node->rightThread) { // One left child
				// 	node->height = node->right->height + 1;
				// }
				if (node->height == 0) {
					node->height = 1;
				}
        node->left = new Elem;
        node->left->right = node;
        node->left->rightThread = true;
        node->left->key = key;
        node->left->data = data;
        node->left->left = nullptr;
        node->left->height = 0;
				_size++;
        return true;
      } else {ret = insert(node->left, key, data, node);}
  } else if (key > node->key) {
		//cout  << "\tgoing right\n";
  	if (node->rightThread) {
      node->rightThread = false;
			if (node->height == 0) {
				node->height = 1;
			}
      node->right = new Elem;
      node->right->rightThread = true;
      node->right->right = lastLeft;
      node->right->key = key;
			node->right->data = data;
      node->right->left = nullptr;
      node->right->height = 0;
			_size++;
      return true;
    } else {ret = insert(node->right, key, data, lastLeft);}
  } else {
    //cout  << "\talready there\n";
    return false;
  }
  if (ret == false) {
    return false;
  }

	int balance = 0;

	if (node->left == nullptr && node->rightThread) { // No Children
		node->height = 0;
	}	else if (node->left == nullptr && !node->rightThread) { // One right child
		node->height = node->right->height + 1;
		balance = (-1 - node->right->height);
	} else if (node->left != nullptr && node->rightThread) { // One left child
		node->height = node->left->height + 1;
		balance = node->left->height;
	} else if (node->left != nullptr && !node->rightThread) { // 2 children
		node->height = max(node->left->height, node->right->height) + 1;
		balance = (node->left->height - node->right->height);
	}

  if (balance == 2) { // calculate load factor
    if (key < node->left->key) {
      rotateRight(node);
		} else {
      doubleRotateRight(node);
		}
  }

  if (balance == -2) { // calculate load factor
    if (key > node->right->key) {
      rotateLeft(node);
		} else {
      doubleRotateLeft(node);
		}
	}

	if (node->left == nullptr && node->rightThread) { // No Children
		node->height = 0;
	}	else if (node->left == nullptr && !node->rightThread) { // One right child
		node->height = node->right->height + 1;
	} else if (node->left != nullptr && node->rightThread) { // One left child
		node->height = node->left->height + 1;
	} else if (node->left != nullptr && !node->rightThread) { // 2 children
		node->height = max(node->left->height, node->right->height) + 1;
	}

	return ret;
}

template <typename KEY, typename T>
void Map<KEY, T>::rotateRight(Elem *& n) {
	//cout << "\t  rotateRight: " << n->key << endl;
		Elem * m = n->left;
		if (m->rightThread) {
			n->height--;
			n = m;
			n->rightThread = false;
			n->right->left = nullptr;
		} else {
			n->left = m->right;
			m->right = n;
			n->height--;
			n = m;
		}
}

template <typename KEY, typename T>
void Map<KEY, T>::rotateLeft(Elem *& n) {
	//cout << "\t  rotateLeft: " << n->key << endl;
	Elem * m;
	if (n->right->left == nullptr) {
		m = n->right;
		m->left = n;
		n->height--;
		n->rightThread = true;
		n = m;
	} else {
		m = n->right;
		m->left = n;
		n->height--;
		n->right = n->right->left;
		n = m;
	}
}

// double right rotation
template<typename KEY, typename T>
void Map<KEY, T>::doubleRotateRight(Elem *& node) {
	  //cout << "\tdoubleRotateRight: " << node->key << endl;
    rotateLeft(node->left);
    rotateRight(node);
}

// double left rotation
template<typename KEY, typename T>
void Map<KEY, T>::doubleRotateLeft(Elem *& node) {
	  //cout << "\tdoubleRotateleft: " << node->key << endl;
    rotateRight(node->right);
    rotateLeft(node);
}




/*-------------------GIVEN-----------------------------------------------------------------------------------------------------*/

template <typename KEY, typename T>
void Map<KEY, T>::printTree(ostream& out, int level, Elem *p) const{
	int i;
	if (p) {
		if (p->right && !p->rightThread)
			printTree(out, level+1,p->right);
			//cout << level << " :";
		for(i=0;i<level;i++) {
			//if (i <= 20) {break;}
			out << "  ";
		}
		out << p->key << " " << p->data << "(" << p->height << ")" << '\n';
		printTree(out, level+1,p->left);
	}
}

// outputs information in tree in inorder traversal order
template <typename KEY, typename T>
ostream& Map<KEY, T>::dump(ostream& out) const{
	if ( _root == _root->left) {// tree empty
		return out;
	}
	printTree(out, 0, _root->left);   // print tree structure
	return out;
}


// outputs using overloaded << operator
template <typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY, T>& v){
	v.dump(out);
	return out;
}
