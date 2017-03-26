//
// Created by ggggg on 2017/3/26.
//

#ifndef C_TEST_QUEUEASARRAY_H
#define C_TEST_QUEUEASARRAY_H


#include "Queue.h"
#include "Array.h"

/*
 * 给定一个长度为n的数组，那么0<=head<n、0<=tail<n。因此head与tail的差满足：
 * 0 <= (head - tail) mod n < n
 * 仅根据成员变量head和tail，不能把空队列和有n个元素的队列区分开
 * 这时候就需要使用一个成员变量count显式记录队列中元素的实际数目
 */
class QueueAsArray : public virtual Queue{
protected:
    //指向Object对象的指针数组
    Array<Object*> array;
    unsigned int head;
    unsigned int tail;
public:
    QueueAsArray(unsigned int);
    ~QueueAsArray();
    void Purge();
    //...

    Object& Head() const;
    void Enqueue(Object&);
    Object& Dequeue();
};


#endif //C_TEST_QUEUEASARRAY_H
