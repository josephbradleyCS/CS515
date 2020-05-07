#include "PQueue.h"
#include "array"
#include <iostream>

using namespace std;

template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue() {
  _size = 0;
  for (int i = 1; i < MAX_SIZE + 1; i++) {
    _array[i] = 0;
  }
}

template< class T, int MAX_SIZE >
PQueue<T, MAX_SIZE>::PQueue(T* items, int size) {
  _size = size;
  for (int i = 0; i < _size; i++) {
   _array[i+1] = items[i];
 }
 buildHeap();
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::insert(T data) {
  _size++;
  _array[_size] = data;
  moveUp();
}

template< class T, int MAX_SIZE >
T PQueue<T, MAX_SIZE>::findMin() {
  T min;
  min = _array[1];
  return min;
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::deleteMin() {
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

template< class T, int MAX_SIZE >
bool PQueue<T, MAX_SIZE>::isEmpty() {
  return (_size == 0);
}

template< class T, int MAX_SIZE >
int PQueue<T, MAX_SIZE>::size() {
  return _size;
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::buildHeap() {
  for (int i = _size/2; i >= 1; i--) {
    moveDown(i);
  }
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveDown(int index) {
  int length = _size;
  int leftChildIndex = 2*index;
  int rightChildIndex = 2*index + 1;

  if(leftChildIndex > length)
      return;

  int minIndex = index;

  if (_array[index] > _array[leftChildIndex]) {
      minIndex = leftChildIndex;
  }
  if ((rightChildIndex < length) && (_array[minIndex] >= _array[rightChildIndex])) {
      minIndex = rightChildIndex;
  }
  if (minIndex != index) {
      T temp = _array[index];
      _array[index] = _array[minIndex];
      _array[minIndex] = temp;
      moveDown(minIndex);
  }
}

template< class T, int MAX_SIZE >
void PQueue<T, MAX_SIZE>::moveUp() {
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
     i /= 2;
   }
 }
