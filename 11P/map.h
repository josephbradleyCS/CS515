// map.h

// A generic Map implemented with right-threaded BST
// BST is not balanced

#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <map>
using namespace std;

template <typename KEY, typename T>
class Map {

private:
	struct Elem {
		bool test;
		int height;
		KEY key;
		T data;
		Elem *left;
		Elem *right;
		bool rightThread;  // normal right child link or a thread link
	};
	Elem *_root;  // a dummy root sentinel
	int _size;

	void destructCode(Elem *& p);
	void copyCode(Elem* &newRoot, Elem* origRoot);
	void addToMap(Elem* root, map<KEY, Elem*> &keyElemMap);
	void copyThread(Elem* &newRoot, Elem* origRoot);

	bool insert(Elem *& root, const KEY &key, const T &data, Elem *lastLeft);
	void rotateRight(Elem *&);
	void rotateLeft(Elem *&);
	void doubleRotateLeft(Elem *& node);
	void doubleRotateRight(Elem *& node);

	//int height(Elem * n);

	public:
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
		int size() const;
		Iterator find(KEY) const;
		T& operator[](KEY);
		bool insert(KEY, T);

		void printTree(ostream& out, int level, Elem *p) const;
		ostream& dump(ostream& out) const;

};

template <typename KEY, typename T>
ostream& operator<< (ostream& out, const Map<KEY, T>& v);



#include "map.cpp"  // must include source file for template compilation
#endif
