//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_STACK_H
#define C_TEST_STACK_H

#include "Container.h"

class Stack : public virtual Container{
public:
    virtual Object& Top() const = 0;
    virtual void Push(Object&) = 0;
    virtual Object& Pop() = 0;
};

#endif //C_TEST_STACK_H
