//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_STACKASARRAY_H
#define C_TEST_STACKASARRAY_H


#include "Stack.h"
#include "Array.h"

class StackAsArray : public Stack{
    Array<Object*> array;
    class Iter;

public:
    StackAsArray(unsigned int);
    ~StackAsArray();
    //...
    Object& Top() const;
    void Push(Object&);
    Object& Pop();
    void Purge();
    //接受一个访问器，并使它一次一个访问所有所包含的对象。
    void Accept(Visitor&) const;
    friend class Iter;
};

class StackAsArray::Iter : public Iterator{
    StackAsArray const& stack;
    unsigned int position;
public:
    Iter (StackAsArray const&);
    bool IsDone() const;
    Object& operator * ()const ;
    void  operator ++ ();
    void Reset();
    //...
};


#endif //C_TEST_STACKASARRAY_H
