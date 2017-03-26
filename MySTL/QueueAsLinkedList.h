//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_QUEUEASLINKEDLIST_H
#define C_TEST_QUEUEASLINKEDLIST_H


#include "Queue.h"
#include "LinkedList.h"

class QueueAsLinkedList : public virtual Queue{
protected:
    //仅需要一个链表
    LinkedList<Object*> list;
public:
    QueueAsLinkedList();
    ~QueueAsLinkedList();
    //...
    void Purge();

    Object& Head() const;
    void Enqueue(Object&);
    Object& Dequeue()''
};


#endif //C_TEST_QUEUEASLINKEDLIST_H
