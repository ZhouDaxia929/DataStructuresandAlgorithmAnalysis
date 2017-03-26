//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_DEQUEASLINKEDLIST_H
#define C_TEST_DEQUEASLINKEDLIST_H


#include "Deque.h"
#include "QueueAsLinkedList.h"

class DequeAsLinkedList : public Deque, public QueueAsLinkedList{
public:
    DequeAsLinkedList();
    //...
    Object& Head() const;
    void EnqueueTail(Object&);
    Object& DequeueHead();

    Object& Tail() const;
    void EnqueueHead(Object&);
    Object& DequeueTail();
};


#endif //C_TEST_DEQUEASLINKEDLIST_H
