//
// Created by ZhouDaxia on 2017/4/2.
//

#include "HashTable.h"

HashTable::HashTable(unsigned int _length) : length(_length){}

unsigned int HashTable::H(Object const & object) const {
    return object.Hash() % length;
}