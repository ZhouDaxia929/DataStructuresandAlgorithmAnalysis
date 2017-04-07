//
// Created by ggggg on 2017/4/7.
//

#include "OpenScatterTable.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

OpenScatterTable::Entry::Entry() : state(empty), object(0){}

OpenScatterTable::OpenScatterTable(unsigned int _length) : HashTable(_length), array(_length){}

void OpenScatterTable::Purge() {
    for(unsigned int i = 0; i < length; i++){
        if(array[i].stat == Entry::occupied){
            if(IsOwner())
                delete array[i].object;
            array[i] = Entry();
        }
    }
    count = 0;
}

OpenScatterTable::~OpenScatterTable() {
    Purge();
}

unsigned int OpenScatterTable::C(unsigned int i) const {
    return i;
}

unsigned int OpenScatterTable::FindUnoccupied(Object const & object) const {
    unsigned int const hash = H(object);
    for(unsigned int i = 0; i < count + 1; i++){
        unsigned int const probe = (hash + C(i)) % length;
        if(array[probe].state != Entry::occupied)
            return probe;
    }
    return length;
}

void OpenScatterTable::Insert(Object & object) {
    if(count == length)
        cout << "scatter table is full" << endl;
    unsigned int const offset = FindUnoccupied(object);
    array[offset].state = Entry::occupied;
    array[offset].object = &object;
    count++;
}

//为什么要使用第三个状态，而不用empty代替，就是因为下面的这个函数通过判定empty来决定是否停止搜索。
unsigned int OpenScatterTable::FindMatch(Object const & object) const {
    unsigned int const hash = H(object);
    for(unsigned int i = 0; i < length; i++){
        unsigned int const probe = (hash + C(i)) % length;
        if(array[probe].state == Entry::empty) //遇到空单元，如果目标对象还没有找到，那么目标对象就不在表中
            break;
        if(array[probe].state == Entry::occupied && object == *array[probe].object)
            return probe;
    }
    return length;
}

Object& OpenScatterTable::Find(Object const & object) const {
    unsigned int const offset = FindMatch(object);
    if(offset < length)
        return *array[offset].object;
    else
        return NullObject::Instance();
}

unsigned int OpenScatterTable::FindInstance(Object const &object) const {
    unsigned int const hash = H(object);
    for(unsigned int i = 0; i < length; i++){
        unsigned int const probe = (hash + C(i)) % length;
        if(array[probe].state == Entry::empty)
            break;
        if(array[probe].state == Entry::occupied && object == *array[probe].object)
            return probe;
    }
    return length;
}

/*
//存在一个问题，在进行大量的插入与删除操作后，很可能就没有标志位empty的单元剩下了。这可能导致不成功的查找
void OpenScatterTable::Withdraw(Object & object) {
    if(count == 0)
        cout << "scatter table is empty" << endl;
    unsigned int const offset = FindInstance(object);
    if(offset == length)
        cout << "object not found" << endl;
    array[offset].state = Entry::deleted;
    array[offset].object = 0;
    count--;
}
*/

void OpenScatterTable::Withdraw(Object & object) {
    if(count == 0)
        cout << "scatter table is empty" << endl;
    unsigned int i = FindInstance(object);
    if(i == length)
        cout << "object not found" << endl;
    for(;;){
        unsigned int j;
        for(j = (i + 1) % length; array[j].state == Entry::occupied; j = (j + 1) % length){
            unsigned int const h = H(*array[j].object);
            if((h <= i && i < j) || (i < j && j < h) || (j < h && h <= i))
                break;
        }
        if(array[j].state == Entry::empty)
            break;
        array[i] = array[j];
        i = j;
    }
    array[i].state = Entry::empty;
    array[i].object = 0;
    count--;
}