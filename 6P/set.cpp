#include "set.h"
#include <iostream>


// Constructors
Set::Set() { // constructs empty set
  _size = 0;
  _head = new Elem;
  _tail = new Elem;
  _head->next = _tail;
  _tail->prev = _head;
  _tail->next = nullptr;
  _head->prev = nullptr;
}
Set::Set(const Set &rhs) { // copy constructor
  copyCode(rhs);
}
Set::Set(ELEMENT_TYPE* first, ELEMENT_TYPE* last) {
  _size = 0;
  _head = new Elem; //_head = first;
  _tail = new Elem; // _tail = last);
  _head->next = _tail;
  _tail->prev = _head;
  _tail->next = nullptr;
  _head->prev = nullptr;
  for (int i = 0; first[i] != *last; i++) {
    this->insert(first[i]);
  }
  this->insert(*last);
}

// Destructor
Set::~Set() {
  destructCode();
}

// assignment operator
Set& Set::operator=(const Set &rhs) {
  destructCode();
  copyCode(rhs);
  return *this;
}

//-----Basic operations-----
void Set::insert(ELEMENT_TYPE arty) {

  //// cout << "Inserting: " << arty << endl;
  if (find(arty) != this->end()) {
    return;
  }
  Elem* jk = new Elem;

  jk -> info = arty;

  // If the List is empty //
  if (_size == 0) {
    _head->next = jk;
    _tail->prev = jk;
    jk->next = _tail;
    jk->prev = _head;
    _size++; return;
  // If the list has one element //
  } else if (_size == 1) {

      // If insert before elem
      if (arty < _head->next->info) {
        jk->next = _head->next;
        _head->next->prev = jk;
        _head->next = jk;
        jk->prev = _head;
        //delete jk;
        _size++; return;

      // If insert after Elem
    } else if (arty > _head->next->info) {
        jk->prev = _tail->prev;
        _tail->prev->next = jk;
        _tail->prev = jk;
        jk->next = _tail;
        //delete jk;
        _size++; return;
      } else {
        return;
      }

    // If the list has more than one element
    } else if (_size > 1) {

      Elem* curr = _head;
      // Iterate until curr->next < jk,  //insert between curr and curr->next
      while (curr->next != _tail && curr->next->info < jk->info) {
        //// cout << ".";
        curr = curr-> next;
      }
      //// cout << endl;

      // insert between _tail and _tail->prev
      if (curr == _tail) {
        jk->prev = _tail->prev;
        _tail->prev->next = jk;
        _tail->prev = jk;
        jk->next = _tail;
        //delete jk;
        _size++; return;

      // insert between curr and curr->next
      } else {
        curr->next->prev = jk;
        jk->next = curr->next;
        jk->prev = curr;
        curr->next = jk;
        //delete jk;
        _size++; return;
      }
  }
  // if (find(arty)) {
  //   return;
  // }
  // Elem* jk = new Elem;
  // Elem* curr = _head;
  // jk -> info = arty;
  //
  //
  // while (curr->next != _tail && curr->info < jk->info) {
  //       curr = curr-> next;
  // }
  // // adding between curr and curr->prev
  //
  // dump(cout, *this);
  //
  // curr->prev->next = jk;
  // jk->prev = curr->prev;
  // jk->next = curr;
  // curr->prev = jk;
  // _size++;
}
void Set::erase(ELEMENT_TYPE infoo) {
  if (find(infoo) == this->end()) {
    return;
  }

  Elem * curr = _head->next;
  while (curr != _tail) {
      if (curr->info == infoo) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete curr;
        _size--;
        return;
      }
      curr = curr-> next;

  }


  // if (_size == 0) {
  //   return;
  // } else if (_head->next->info == infoo) {
  //   if (_size == 1) {
  //     delete _head->next;
  //     _head->next = _tail;
  //     _tail->prev = _head;
  //     _size--;
  //     return;
  //   } else {
  //     delete _head->next;
  //     _head->next= _head->next->next;
  //     _head->next->prev = _head;
  //     _size--;
  //     return;
  //   }
  // } else if (_size > 1) {
  //   Elem* curr = _head->next;
  //   while (curr->info != infoo && curr->next != _tail) {
  //     curr = curr-> next;
  //   }
  //   if (curr->next == _tail) {
  //     delete curr->next;
  //     curr->next = _tail;
  //     _tail->next = nullptr;
  //     _tail->prev = curr;
  //     _size--;
  //     return;
  //   } else {
  //     curr->next->prev = curr->prev;
  //     curr->prev->next = curr->next ;
  //     delete curr;
  //     _size--;
  //     return;
  //   }
  // }
}
void Set::clear() {
  if (_size == 0) {
    delete _tail;
    delete _head;
    _tail = nullptr;
    _head = nullptr;
  } else {

    Elem * temp;
    while (_head->next != _tail) {
      temp = _head->next;
      _head->next = temp->next;
      delete temp;
    }
    delete _tail;
    delete _head;
  }


  _size = 0;
  _head = new Elem;
  _tail = new Elem;
  _head->next = _tail;
  _tail->prev = _head;
  _tail->next = nullptr;
  _head->prev = nullptr;

}
int Set::size() const {
  return _size;
}
ostream& operator<< (ostream& aa, Set& bb) {
  Set::Iterator a = bb.begin();
  while (a != bb.end()) {
    aa << *a << " ";
    a++;
  }
  return aa;
}

// Set iterators
Set::Iterator Set::find(ELEMENT_TYPE a) const {
  Set::Iterator it = this->begin();
  while (it != this->end()) {
    if (*it == a) {
      return it;
    }
    it++;
  }
  return it;
}
Set::Iterator Set::begin() const {
  Set::Iterator it(_head->next);
  return it;
}
Set::Iterator Set::end() const {
  Set::Iterator it(_tail);
  return it;
}
Set::Reverse_Iterator Set::rbegin() const {
  Set::Reverse_Iterator it(_tail->prev);
  return it;
}
Set::Reverse_Iterator Set::rend() const {
  Set::Reverse_Iterator it(_head);
  return it;
}

// Iterator Class
Set::Iterator::Iterator() {
  _cur = nullptr;
}
Set::Iterator::Iterator(Elem *cur) {
  _cur = cur;
}
ELEMENT_TYPE& Set::Iterator::operator*() { //dereference
    return _cur->info;
}
Set::Iterator Set::Iterator::operator++(int a) { //post-increment operator
  _cur = _cur->next;
  return *this;
}
Set::Iterator Set::Iterator::operator--(int a) { //post-decrement operator
  _cur = _cur->prev;
  return *this;
}
bool Set::Iterator::operator==(Iterator it) const { // equality operator
  return (this->_cur == it._cur);
}
bool Set::Iterator::operator!=(Iterator it) const { // inequality operator
  return (this->_cur != it._cur);
}

// Reverse Iterator Class
Set::Reverse_Iterator::Reverse_Iterator() {
  _cur = nullptr;
}
Set::Reverse_Iterator::Reverse_Iterator(Elem *cur) {
  _cur = cur;
}
ELEMENT_TYPE& Set::Reverse_Iterator::operator*() { //dereference
    return _cur->info;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator++(int a) { //post-increment operator
  _cur = _cur->prev;
  return *this;
}
Set::Reverse_Iterator Set::Reverse_Iterator::operator--(int a) { //post-decrement operator
  _cur = _cur->next;
  return *this;
}
bool Set::Reverse_Iterator::operator==(Reverse_Iterator it) const {// equality operator
  return (this->_cur == it._cur);
}
bool Set::Reverse_Iterator::operator!=(Reverse_Iterator it) const { // inequality operator
  return (this->_cur != it._cur);
}

// common code for copy constructor and assignment
void Set::copyCode(const Set & v) {
  _size = 0;
  _head = new Elem;
  _tail = new Elem;
  _head->next = _tail;
  _tail->prev = _head;
  _tail->next = nullptr;
  _head->prev = nullptr;

  Elem * jk;


  if (v._size != 0) {
    jk = v._head -> next;
    while(jk != v._tail) {
      insert(jk->info);
      jk = jk -> next;
    }
  }


}
// common code for deallocation
void Set::destructCode() {
  if (_size == 0) {
    delete _tail;
    delete _head;
    _tail = nullptr;
    _head = nullptr;
    _size = 0;
    return;
  }


  Elem * temp;
  while (_head->next != _tail) {
    temp = _head->next;
    _head->next = temp->next;
    delete temp;
  }

  delete _tail;
  delete _head;
  _tail = nullptr;
  _head = nullptr;
  _size = 0;
}
// output set elements
ostream& Set::dump(ostream& out, const Set &v) {
  Elem * a = v._head->next;
  while (a != v._tail) {
    out << a->info << " ";
    a = a->next;
  }
  //delete a;
  return out;
}

Set operator&(const Set& a, const Set& b) {
  Set n;
  Set::Iterator i;
  Set::Iterator j;

  for (i = a.begin(); i != a.end(); i++) {
    for (j = b.begin(); j != b.end(); j++) {
      if (*i == *j) {n.insert(*i);}
    }
  }
  return n;
}
Set operator|(const Set& a, const Set& b) {
  Set n;
  Set::Iterator i;
  Set::Iterator j;
  for (i = a.begin(); i != a.end(); i++) {n.insert(*i);}
  for (j = b.begin(); j != b.end(); j++) {n.insert(*j);}
  return n;
}
Set operator-(const Set& a, const Set& b) {
  Set n;
  Set::Iterator i;
  Set::Iterator j;

  for (i = a.begin(); i != a.end(); i++) {
    n.insert(*i);
    for (j = b.begin(); j != b.end(); j++) {
      n.erase(*j);
    }
  }
  return n;
}
bool operator==(const Set& s1, const Set& s2) {
  Set::Iterator a = s1.begin();
  Set::Iterator b = s2.begin();

  while (a != s1.end() && b != s1.end()) {
    if (*a != *b) {
      return false;
    }
    a++;
    b++;
  }
  //delete a;
  //delete b;
  return true;
}
