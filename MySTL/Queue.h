//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_QUEUE_H
#define C_TEST_QUEUE_H


#include "Container.h"

class Queue : public virtual Container{
public:
    virtual Object& Head() const = 0;
    virtual void Enqueue(Object&) = 0;
    virtual Object& Dequeue() = 0;
};


#endif //C_TEST_QUEUE_H
