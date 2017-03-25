//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_SEARCHABLECONTAINER_H
#define C_TEST_SEARCHABLECONTAINER_H

#include "Container.h"

class SearchableContainer : public virtual Container{
public:
    //验证某一给定对象是否在容器中，该函数查找的给定对象的指针。
    virtual bool IsMember(Object const&) const = 0;
    virtual void Insert(Object&) = 0;
    //从容器中删除对象，在对象被删除后，容器不再拥有该对象的所有权。不论在什么时候，容器不会删除它已经删除的对象。
    virtual void Withdraw(Object&) = 0;
    //用于确定对象在容器中的位置并返回一个该对象的引用。（注意，查找的不是给定的对象，而是与给定的对象比较时相等的对象）
    //如果两个关联中的关键字比较时相等——它们的值可以不同，就说这两个关联比较时相等。
    virtual Object& Find(Object const&) const = 0;
};

#endif //C_TEST_SEARCHABLECONTAINER_H
