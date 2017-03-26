//
// Created by ggggg on 2017/3/26.
//

#include "DequeAsArray.h"
#include <iostream>
using namespace std;

Object& DequeAsArray::Head() const {
    return QueueAsArray::Head();
}

void DequeAsArray::EnqueueTail(Object& object) {
    QueueAsArray::Enqueue(object);
}

Object& DequeAsArray::DequeueHead() {
    return QueueAsArray::Dequeue();
}

Object& DequeAsArray::Tail() const {
    if(count == 0)
        cout << "deque is empty" << endl;
    return *array[tail];
}

void DequeAsArray::EnqueueHead(Object& object) {
    if(count == array.Length())
        cout << "deque is full" << endl;
    if(head-- == 0)
        head = array.Length() - 1U;
    array[head] = &object;
    count++;
}

Object& DequeAsArray::DequeueTail() {
    if(count == 0)
        cout << "deque is empty" << endl;
    Object& result = *array[tail];
    if(tail-- == 0)
        tail = array.Length() - 1U;
    count--;
    return result;
}
