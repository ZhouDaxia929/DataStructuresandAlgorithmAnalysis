//
// Created by ZhouDaxia on 2017/3/27.
//

#include "ListAsArray.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

ListAsArray::ListAsArray(unsigned int size) : array(size) {}

ListAsArray::Pos::Pos(ListAsArray const& _list, unsigned int _offset) : list(_list), offset(_offset) {}

void ListAsArray::Insert(Object& object) {
    if(count == array.Length())
        cout << "list is full" << endl;
    array[count] = &object;
    count++;
}

Object& ListAsArray::operator [] (unsigned int offset) const {
    if(offset >= count)
        cout << "invalid offset" << endl;
    return *array[offset];
}
//搜索某一特定对象的实例
bool ListAsArray::IsMember(Object const& object) const {
    for(unsigned int i = 0; i < count; i++)
        if(array[i] == &object)
            return true;
    return false;
}

//比较的不是地址，而是比较数据，仅仅去寻找一个相匹配的对象。
Object& ListAsArray::Find(Object const& object) const {
    for(unsigned int i = 0; i < count; i++)
        if(*array[i] == object)
            return *array[i];
    return NullObject::Instance();
}

void ListAsArray::Withdraw(Object& object) {
    if(count == 0)
        cout << "list is empty" << endl;
    unsigned int i = 0;
    while(i < count && array[i] != &object)
        i++;
    if(i == count)
        cout << "object not found" << endl;
    for(; i < count - 1U; i++)
        array[i] = array[i + 1];
    count--;
}

Position& ListAsArray::FindPosition(Object const& object) const {
    unsigned int i = 0;
    while(i < count && *array[i] != object)
        i++;
    return *new Pos(*this, i);
}

Object& ListAsArray::operator [] (Position const& arg) const {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(&position.list != this || position.offset >= count)
        cout << "invalid position" << endl;
    return *array[position.offset];
}

void ListAsArray::InsertAfter(Position const& arg, Object& object) {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(count == array.Length())
        cout << "list is full" << endl;
    if(&position.list != this || position.offset >= count)
        cout << "invalid position" << endl;
    unsigned int const insertPosition = position.offset + 1;
    for(unsigned int i = count; i > insertPosition; i--)
        array[i] = array[i - 1U];
    array[insertPosition] = &object;
    count++;
}

void ListAsArray::InsertBefore(Position const& arg, Object& object) {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(count == array.Length())
        cout << "list is full" << endl;
    if(&position.list != this || position.offset >= count)
        cout << "invalid position" << endl;
    unsigned int const insertPosition = position.offset;
    for(unsigned int i = count; i > insertPosition; i--)
        array[i] = array[i - 1U];
    array[insertPosition] = &object;
    count++;
}

void ListAsArray::Withdraw(Position const& arg) {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(count == 0)
        cout << "list is empty" << endl;
    if(&position.list != this || position.offset >= count)
        cout << "invalid position" << endl;
    for(unsigned int i = position.offset; i < count - 1U; i++)
        array[i] = array[i + 1];
    count--;
}