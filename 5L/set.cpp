#include "set.h"
#include "iostream"



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

Set::~Set() { // Destructor
  destructCode();
}

Set& Set::operator=(const Set &rhs) { // assignment operator
  destructCode();
  copyCode(rhs);
  return *this;
}

//-----Basic operations-----
// insert an element
void Set::insert(ELEMENT_TYPE arty) {

  //// cout << "Inserting: " << arty << endl;
  if (find(arty)) {
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

// remove an element from the set
void Set::erase(ELEMENT_TYPE infoo) {
  if (!find(infoo)) {
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

// remove all elements from set
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

//return size of the set
int Set::size() const {
  return _size;
}

bool Set::find(ELEMENT_TYPE jk) const {
  if (_size == 0) {
    return false;
  }

  Elem * a = _head->next;
  while (a != nullptr) {
    // cout << ".";
    if (a->info == jk) {
      return true;
    }
    a = a->next;
    if (a == _tail) {
      return false;
    }
  }
  //delete a;
  return false;
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
ostream& Set::dump(ostream& out, const Set &v) const {
  Elem * a = v._head->next;
  while (a != v._tail) {
    out << a->info << " ";
    a = a->next;
  }
  //delete a;
  return out;
}

// set equality
bool operator==(const Set& s1, const Set& s2) {
  Set::Elem * a = s1._head->next;
  Set::Elem * b = s2._head->next;

  while (a != s1._tail && b != s1._tail) {
    if (a->info != b->info) {
      return false;
    }
    a = a->next;
    b = b->next;
  }
  //delete a;
  //delete b;
  return true;
}

// elements are output as a single white space delimited
ostream& operator<< (ostream& aa, const Set& bb) {
  Set::Elem * a = bb._head->next;
  while (a != bb._tail) {
    aa << a->info << " ";
    a = a->next;
  }
  //delete a;
  return aa;
}
