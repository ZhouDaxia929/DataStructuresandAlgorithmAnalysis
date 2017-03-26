//
// Created by ggggg on 2017/3/26.
//

#include "QueueAsArray.h"
#include <iostream>
using namespace std;

QueueAsArray::QueueAsArray(unsigned int size) : array(size), head(0), tail(size - 1U){}

void QueueAsArray::Purge() {
    if(IsOwner())
        for(unsigned int i = 0; i < count; i++){
            delete array[head];
            if(++head == array.Length())
                head = 0;
        }
    count = 0;
}

QueueAsArray::~QueueAsArray() {
    Purge();
}

Object& QueueAsArray::Head() const {
    if(count == 0)
        cout << "queue is empty" << endl;
    return *array[head];
}

void QueueAsArray::Enqueue(Object& object) {
    if(count == array.Length())
        cout << "queue is full" << endl;
    if(++tail == array.Length())
        tail = 0;
    array[tail] = &object;
    count++;
}

Object& QueueAsArray::Dequeue() {
    if(count == 0)
        cout << "queue is empty" << endl;
    Object& result = *array[head];
    if(++head == array.Length())
        head = 0;
    count--;
    return result;
}