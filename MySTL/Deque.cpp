//
// Created by ggggg on 2017/3/26.
//
#include "Deque.h"

void Deque::Enqueue(Object& object) {
    EnqueueTail(object);
}

Object& Deque::Dequeue() {
    return DequeueHead();
}
