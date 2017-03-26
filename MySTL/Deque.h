//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_DEQUE_H
#define C_TEST_DEQUE_H


#include "Queue.h"

class Deque : public virtual Queue{
public:
    virtual Object& Head() const = 0;
    virtual Object& Tail() const = 0;
    virtual void Enqueue(Object&); //仅仅调用EnqueueTail函数
    virtual void EnqueueHead(Object&) = 0;
    virtual void EnqueueTail(Object&) = 0;
    virtual Object& Dequeue(); //仅仅调用DequeueHead函数
    virtual Object& DequeueHead() const = 0;
    virtual Object& DequeueTail() const = 0;
};


#endif //C_TEST_DEQUE_H
