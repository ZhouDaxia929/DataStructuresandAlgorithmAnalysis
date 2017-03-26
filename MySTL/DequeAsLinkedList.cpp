//
// Created by ggggg on 2017/3/26.
//

#include "DequeAsLinkedList.h"
#include <iostream>
using namespace std;

Object& DequeAsLinkedList::Head() const {
    return QueueAsLinkedList::Head();
}

void DequeAsLinkedList::EnqueueTail(Object& object) {
    QueueAsLinkedList::Enqueue(object);
}

Object& DequeAsLinkedList::DequeueHead() {
    return QueueAsLinkedList::Dequeue();
}

Object& DequeAsLinkedList::Tail() const {
    if(count == 0)
        cout << "deque is empty" << endl;
    return *list.Last();
}

void DequeAsLinkedList::EnqueueHead(Object& object) {
    list.Prepend(&object);
    count++;
}

Object& DequeAsLinkedList::DequeueTail() {
    if(count == 0)
        cout << "deque is empty" << endl;
    Object& result = *list.Last();
    list.Extract(&result);
    count--;
    return result;
}