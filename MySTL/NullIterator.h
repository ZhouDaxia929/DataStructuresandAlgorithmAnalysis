//
// Created by ggggg on 2017/3/24.
//

#ifndef C_TEST_NULLITERATOR_H
#define C_TEST_NULLITERATOR_H

#include "Iterator.h"

/*
 * 是一个不做任何操作的具体迭代器
 * 如果某一特殊的具体容器类没有提供与之关联的迭代器类，那么它的NewIterator成员函数就返回一个NullIterator对象的引用
 */
class NullIterator : public Iterator {
public:
    NullIterator();
    void Reset();
    bool IsDone() const;
    Object& operator *() const;
    void operator ++ ();
};


#endif //C_TEST_NULLITERATOR_H
