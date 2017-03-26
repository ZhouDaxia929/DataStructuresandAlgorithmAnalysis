//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_DEQUEASARRAY_H
#define C_TEST_DEQUEASARRAY_H


#include "Deque.h"
#include "QueueAsArray.h"

//Deque提供接口，QueueAsArray提供实现
class DequeAsArray : public Deque, public QueueAsArray{
public:
    DequeAsArray(unsigned int);
    //...
    Object& Head() const;
    void EnqueueTail(Object&);
    Object& DequeueHead();

    Object& Tail() const;
    void EnqueueHead(Object&);
    Object& DequeueTail();
};


#endif //C_TEST_DEQUEASARRAY_H
