#include "queue.h"
//#define TYPE int

// singly linked list implementation of queue
// empty queue is represented by null front and rear pointers

queue::queue(){
  _size = 0;
  _front = nullptr;
  _rear = nullptr;
}

queue::~queue(){
  node * _curr = _front;
  while (_curr) {
    _curr = _curr->next;
    delete _front;
    _front = _curr;
  }
  //delete _curr;
   _rear = _front = nullptr;

   delete _curr;
}

// copy constructor
queue::queue(const queue &v){

  // replace with rhs values

  _size = 0;
  _front = nullptr;
  _rear = nullptr;


  node * n = v._front;
  while (n) {
    enqueue(n->data);
    n = n->next;
  }
  _size = v._size;
  delete n;
}

// assignment operator
queue& queue::operator=(const queue &rhs){
  if (rhs._size == 0) {
    throw EmptyQueueException();
  }

  if (this == &rhs) {
    return *this;
  }
  // deleteing everyhting
  node * _curr = _front;
  while (_curr) {
    _curr = _curr->next;
    delete _front;
    _front = _curr;
  }
  //delete _curr;
  _rear = _front = nullptr;
  _size = 0;
  // replace with rhs values
  node * n = rhs._front;
  while (n) {
    enqueue(n->data);
    n = n->next;
  }

  _size = rhs._size;
  delete n;
  return *this;

}

void queue::enqueue(const TYPE data){
  node * a;
  if (empty()) {

    a = new node(data);
    _rear = _front = a;
    _size++;
  } else if (_front == _rear) {
    a = new node(data);
    _front->next = a;
    _rear = a;
    _size++;
  } else {
    _size++;
    a = new node(data);
    _rear->next = a;
    _rear = a;
  }
  delete a;
}

TYPE queue::dequeue(){
  if (_front == nullptr) {
    throw EmptyQueueException();
    //cout << "empty queue exception " << endl;
    return 0;
    //exit(1);
  } else {
    _size--;
  	TYPE val = _front->data;
    _front = _front->next;
    //delete _front;
  	return val;
  }

}

void queue::dump(ostream &os){
  if (!empty()) {
    node * _curr = _front;
    while (_curr != nullptr) {
      os << _curr->data << " ";
      _curr = _curr->next;
    }
    delete _curr;
  }
}

int queue::size(){
    return _size;
}

bool queue::empty(){
    return (_size == 0);
}
