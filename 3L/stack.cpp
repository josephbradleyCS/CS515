#include "stack.h"

// array implementation of stack
stack::stack(int ss){
  _arr = new int[ss];
  _tos = -1;
 _capacity = ss;

	for(int i=0; i<ss; i++)
		_arr[i]=0;
}

// copy constructor
stack::stack(const stack& cs) {
  _arr = new int[cs._capacity];

  _tos = cs._tos;
  _capacity = cs._capacity;

  for (int i = 0; i <cs._capacity; i++) {
    _arr[i] = cs._arr[i];
  }

}

//assignment operator
stack& stack::operator=(const stack& cs) {
  if (this == &cs) {
    return *this;
  }
  delete []_arr;
  _tos = cs._tos;
  _capacity = cs._capacity;
  _arr = new TYPE[cs._capacity];

  for (int i = 0; i < _capacity; i++) {
    _arr[i] = cs._arr[i];
  }
  return *this;
}

// move constructor
stack::stack(stack&& cs) {
  //delete []_arr;

  _tos = cs._tos;
  _capacity = cs._capacity;
  _arr = cs._arr;
  cs._arr = nullptr;
  cs._tos = -1;
  cs._capacity = 0;
}

// move assignment operator
stack& stack::operator=(stack&& cs) {
    if (this == &cs) {
      return *this;
    }
    delete []_arr;
    _tos = cs._tos;
    _capacity = cs._capacity;
    _arr = cs._arr;
    cs._arr = nullptr;
    cs._tos = -1;
    cs._capacity = 0;
    return *this; // uHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
}

stack::~stack() {
  //if (_arr)
    delete [] _arr;
}



void stack::push(const TYPE data){
  if (_tos == _capacity - 1) {
    throw FullStackException();
  } else {
    _tos++;
    _arr[_tos] = data;
  }
}

void stack::pop() {
  if (empty()) {
    throw EmptyStackException();
  } else {
    _tos--;
  }
}

TYPE& stack::top() {
  if (empty()) {
    throw EmptyStackException();
  }
  return _arr[_tos];

}

// void stack::dump(ostream &os){
//     if (empty()) {
//       cout << "Empty Stack";
//     } else {
//       for (int i = 0; i < _tos; i++) {
//         cout << _arr[i] << " ";
//       }
//     }
//     cout << endl;
// }


bool stack::empty(){
    return (_tos == -1);
}

int stack::size(){
    return _tos+1;
}

int stack::capacity() {
  return _capacity;
}
