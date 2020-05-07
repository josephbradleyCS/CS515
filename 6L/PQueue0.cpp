#include "PQueue0.h"
#include "array"
#include <iostream>

using namespace std;

PQueue::PQueue() { // default constructor, construct an empty heap
  _size = 0;
  for (int i = 1; i < MAX_SIZE + 1; i++) {
    _array[i] = 0;
  }
}

PQueue::PQueue(int* items, int size) {
  _size = size;
  for (int i = 0; i < _size; i++) {
   _array[i+1] = items[i];
 }
 buildHeap();
}

void PQueue::insert(T data) {
  _size++;
  _array[_size] = data;
  moveUp();
}

T PQueue::findMin() {
  T min;
  min = _array[1];
  return min;
}

void PQueue::deleteMin() {
  if (_size == 0) {
    return;
  } else {
    T tempVal = _array[1];
    _array[1] = _array[_size];
    _array[_size] = tempVal;
    _size--;
    moveDown(1);
  }
}

bool PQueue::isEmpty() {
  return (_size == 0);
}

int PQueue::size() {
  return _size;
}


void PQueue::buildHeap() {
  for (int i = _size/2; i >= 1; i--) {
    moveDown(i);
  }
}

void PQueue::moveDown(int index) {
  int length = _size;
  int leftChildIndex = 2*index;
  int rightChildIndex = 2*index + 1;

  if(leftChildIndex > length)
      return; //index is a leaf

  int minIndex = index;

  if (_array[index] > _array[leftChildIndex]) {
      minIndex = leftChildIndex;
  }
  if ((rightChildIndex < length) && (_array[minIndex] >= _array[rightChildIndex])) {
      minIndex = rightChildIndex;
  }
  if (minIndex != index) {
      //need to swap
      int temp = _array[index];
      _array[index] = _array[minIndex];
      _array[minIndex] = temp;
      moveDown(minIndex);
  }
}

void PQueue::moveUp() {
   if (isEmpty()) {
     return;
   }
   int i = _size;
   while (i >= 1) {
     if (_array[i] <= _array[i / 2]) {
       T a = _array[i];
       _array[i] = _array[i/2];
       _array[i/2] = a;
     }
     i = i/2;
   }
 }
