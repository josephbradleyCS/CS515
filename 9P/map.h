// A generic Map implemented with right-threaded BST
// BST is not balanced

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <map>
using namespace std;

template <typename KEY, typename T>
class Map{
private:
	struct Elem {
		KEY key;
		T data;
		Elem *left;
		Elem *right;
		bool rightThread;  // normal right child link or a thread link
	};
	Elem *_root;  // a dummy root sentinel
	int _size;

	bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);

	  void rotateRight(Elem *&);
		void rotateLeft(Elem *&);
		void doubleRotateLeft(Elem *& node);
		void doubleRotateRight(Elem *& node);
		//int height(Elem * a);



	void printTree(ostream& out, int level, Elem *p) const;
	void destructCode(Elem *& p);
	void copyCode(Elem* &newRoot, Elem* origRoot);
	void addToMap(Elem* root, map<KEY, Elem*> &keyElemMap);
	void copyThread(Elem* &newRoot, Elem* origRoot);

public:
	// a simple Iterator, traverse the collection in one direction
	class Iterator{
	public:
		Iterator(){}
		explicit Iterator(Elem *cur):_cur(cur) {}
		Elem& operator*();
		Elem* operator->();
		Iterator operator++(int);
		bool operator==(Iterator it);
		bool operator!=(Iterator it);
	private:
		Elem* _cur;
	};
	Iterator begin() const;
	Iterator end() const;

	Map();
	Map(const Map &rhs);
	~Map();
	Map& operator=(const Map &rhs);
	bool insert(KEY, T);
	Iterator find(KEY) const;
	T& operator[](KEY);
	ostream& dump(ostream& out) const;
};

template<typename KEY, typename T>
ostream& operator<< (ostream&, const Map<KEY, T>&);

#include "map.cpp"  // must include source file for template compilation
#endif
