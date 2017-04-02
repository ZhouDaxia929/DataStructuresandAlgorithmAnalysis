//
// Created by ZhouDaxia on 2017/4/2.
//

#include "ChainedHashTable.h"

ChainedHashTable::ChainedHashTable(unsigned int _length) : HashTable(_length), array(_length){}

void ChainedHashTable::Purge() {
    for(unsigned int i = 0; i < length; i++){
        if(IsOwner()){
            LinkedList<Object*>::ListElement const* ptr;
            for(ptr = array[i].Head(); ptr != 0; ptr = ptr->Next())
                delete ptr->Datum();
        }
        array[i].Purge();
    }
    count = 0;
}

ChainedHashTable::~ChainedHashTable() {
    Purge();
}

void ChainedHashTable::Insert(Object & object) {
    array[H(object)].Append(&object);
    count++;
}

void ChainedHashTable::Withdraw(Object & object) {
    array[H(object)].Extract(&object);
    count--;
}