//
// Created by ZhouDaxia on 2017/4/2.
//

#include "ChainedScatterTable.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

ChainedScatterTable::Entry::Entry() : object(0), next(null){}

ChainedScatterTable::ChainedScatterTable(unsigned int _length) : HashTable(_length), array(_length){}

void ChainedScatterTable::Purge() {
    for(unsigned int i = 0; i < length; i++){
        if(array[i].object != 0){
            if(IsOwner())
                delete array[i].object;
            array[i] = Entry();
        }
    }
    count = 0;
}

ChainedScatterTable::~ChainedScatterTable() {
    Purge();
}

void ChainedScatterTable::Insert(Object & object) {
    if(count == length)
        cout << "scatter table is full" << endl;
    unsigned int probe = H(object);
    if(array[probe].object != 0){
        //当冲突发生的时候，一定会有一条从自然位置发出的链。然后下面的句子总是把数据项插入链的末尾。
        while(array[probe].next != Entry::null)
            probe = array[probe].next;
        unsigned int const tail = probe; //tail用于保存最后的位置
        probe = (probe + 1) % length; //找到链的最后位置，然后向后顺延一个位置。
        while(array[probe].object != 0)
            probe = (probe + 1) % length;
        array[tail].next = probe;
    }
    array[probe].object = &object;
    array[probe].next = Entry::null;
    count++;
}

Object& ChainedScatterTable::Find(Object const & object) const {
    for(unsigned int probe = H(object); probe != Entry::null; probe = array[probe].next){
        if(object == *array[probe].object)
            return *array[probe].object;
    }
    return NullObject::Instance();
}

void ChainedScatterTable::Withdraw(Object & object) {
    if(count == 0)
        cout << "scatter table is empty" << endl;
    unsigned int i = H(object);
    while(i != Entry::null && array[i].object != &object)
        i = array[i].next;
    if(i == Entry::null)
        cout << "object not found" << endl;
    //在位置i上的数据项被删去后，把它之后的数据项前移。
    for(;;){
        unsigned int j;
        //搜索位置i后链表的其他部分，以找出一个可以安全移动的数据项。
        for(j = array[i].next; j != Entry::null; j = array[j].next){
            unsigned int const h = H(*array[j].object);
            bool contained = false;
            for(unsigned int k = array[i].next; k != array[j].next && !contained; k = array[k].next){
                if(k == h)
                    contained = true;
            }
            if(!contained)
                break;
        }
        if(j == Entry::null)
            break;
        array[i].object = array[j].object;
        i = j;
    }
    array[i].object = 0;
    array[i].next = Entry::null;
    for(unsigned int j = (i + length - 1U) % length; j != i; j = (j + length - 1U) % length){
        if(array[j].next == i){
            array[j].next = Entry::null;
            break;
        }
    }
    count--;
}