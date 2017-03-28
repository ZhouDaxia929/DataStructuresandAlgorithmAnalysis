//
// Created by ZhouDaxia on 2017/3/28.
//

#ifndef C_TEST_SORTEDLISTASARRAY_H
#define C_TEST_SORTEDLISTASARRAY_H


#include "SortedList.h"
#include "ListAsArray.h"

class SortedListAsArray : public virtual SortedList, public virtual ListAsArray{
    //该函数将被其他的成员用来确定排序表中数据项的位置
    unsigned int FindOffset(Object const&) const;

public:
    SortedListAsArray(unsigned int);
    //...
    void Insert(Object&);
    Object& Find(Object const&) const;
    Position& FindPosition(Object const&) const;
    void Withdraw(Object&);
};


#endif //C_TEST_SORTEDLISTASARRAY_H
