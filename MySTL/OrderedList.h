//
// Created by ZhouDaxia on 2017/3/27.
//

#ifndef C_TEST_ORDEREDLIST_H
#define C_TEST_ORDEREDLIST_H

#include "Iterator.h"
#include "SearchableContainer.h"

class Position : public Iterator{};

class List : public virtual SearchableContainer{
public:
    //存取表中某一给定位置上的对象
    virtual Object& operator [] (unsigned int) const = 0;
    virtual Object& operator [] (Position const&) const = 0;
    //查找对象在表中的位置
    virtual Position& FindPosition(Object const&) const = 0;
    //删除表中某一给定位置上的对象
    virtual void Withdraw(Position const&) = 0;
};

class OrderedList : public virtual List{
public:
    //两种位置的插入
    virtual void InsertAfter(Position const&, Object&) = 0;
    virtual void InsertBefore(Position const&, Object&) = 0;
};

#endif //C_TEST_ORDEREDLIST_H
