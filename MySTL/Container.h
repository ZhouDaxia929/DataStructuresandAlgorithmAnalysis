//
// Created by ggggg on 2017/3/24.
//

#ifndef C_TEST_CONTAINER_H
#define C_TEST_CONTAINER_H


#include "Object.h"
#include "Visitor.h"
#include "Iterator.h"
#include "Ownership.h"

//抽象基类，可派生出具体容器的实现
class Container : public virtual Object, public virtual Ownership {
protected:
    unsigned int count;
    Container();

public:
    virtual unsigned int Count() const;
    virtual bool IsEmpty() const;
    virtual bool IsFull() const;
    virtual HashValue Hash() const;
    virtual void Put(ostream&) const;
    virtual Iterator& NewIterator() const;

    virtual void Purge() = 0;
    virtual void Accept(Visitor&) const = 0;
};


#endif //C_TEST_CONTAINER_H
