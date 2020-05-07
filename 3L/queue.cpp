#include "queue.h"

// circular array implementation of queue
queue::queue(){
    rear = -1;  // rear used as the count of queue items
    front = 0;  // front points to queue front
	for(int i=0; i<MAX_CAP; i++)
		item[i]=0;
}

void queue::enqueue(int data){
  if (!full()) {
    item[++rear%MAX_CAP] = data;
  } else {
    exit(1);
  }
}

int queue::dequeue(){
    return item[front++%MAX_CAP];
}

void queue::dump(ostream &os){
    for(int i=front; i<=rear; i++)
        os<<item[i%MAX_CAP]<<endl;
}

int queue::size(){
    return (rear - front + 1);
}

bool queue::empty(){
    return (front > rear) ? true : false;
}

bool queue::full(){
    return (size() >= MAX_CAP) ? true : false;

}
