//
// Created by ggggg on 2017/3/25.
//

#include "StackAsArray.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

StackAsArray::StackAsArray(unsigned int size) : array(size) {}

void StackAsArray::Purge() {
    if(IsOwner()){
        for(unsigned int i = 0; i < count; i++)
            delete array [i];
    }
    count = 0;
}

StackAsArray::~StackAsArray() {
    Purge();
}

void StackAsArray::Push(Object& object) {
    if(count == array.Length())
        cout << "stack is full" << endl;
    array[count++] = &object;
}

Object& StackAsArray::Pop() {
    if(count == 0)
        cout << "stack is empty" << endl;
    return *array[--count];
}

Object& StackAsArray::Top() const {
    if(count == 0)
        cout << "stack is empty" << endl;
    return *array[count - 1U];
}

void StackAsArray::Accept(Visitor& visitor) const {
    for(unsigned int i = 0; i < count && !visitor.IsDone(); i++)
        visitor.Visit(*array[i]);
}

StackAsArray::Iter::Iter(StackAsArray const& _stack) : stack(_stack) {
    Reset();
}

bool StackAsArray::Iter::IsDone() const {
    return position >= stack.count;
}

//间接引用操作符在for循环体中被使用，以实现迭代器所指对象的存取。
Object& StackAsArray::Iter::operator * () const {
    if(position < stack.count)
        return *stack.array[position];
    else
        return NullObject::Instance();
}

void StackAsArray::Iter::operator++() {
    if(position < stack.count)
        ++position;
}

void StackAsArray::Iter::Reset() {
    position = 0;
}
