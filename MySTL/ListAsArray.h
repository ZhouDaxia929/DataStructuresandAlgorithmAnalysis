//
// Created by ZhouDaxia on 2017/3/27.
//

#ifndef C_TEST_LISTASARRAY_H
#define C_TEST_LISTASARRAY_H


#include "OrderedList.h"
#include "Array.h"

class ListAsArray : public virtual OrderedList{
protected:
    //指向Object对象的指针数组，用来存储有序线性表的数据项。
    Array<Object*> array;
    class Pos;

public:
    ListAsArray(unsigned int);
    //...
    void Insert(Object& );
    Object& operator [] (unsigned int) const;
    bool IsMember(Object const&) const;
    Object& Find(Object const&) const;
    void Withdraw(Object&);
    void Withdraw(Position const&);
    Position& FindPosition(Object const&) const;
    Object& operator [] (Position const&) const;
    void InsertAfter(Position const&, Object&);
    void InsertBefore(Position const&, Object&);
    friend class Pos;
};

class ListAsArray::Pos : public Position{
protected:
    ListAsArray const& list;
    unsigned int offset;
public:
    //...
    Pos(ListAsArray const&, unsigned int);
    friend class ListAsArray;
    friend class SortedListAsArray;
};


#endif //C_TEST_LISTASARRAY_H
