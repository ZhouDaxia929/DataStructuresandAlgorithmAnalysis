//
// Created by ZhouDaxia on 2017/4/2.
//

#ifndef C_TEST_CHAINEDHASHTABLE_H
#define C_TEST_CHAINEDHASHTABLE_H


#include "HashTable.h"
#include "Array.h"
#include "LinkedList.h"

class ChainedHashTable : public HashTable{
    Array<LinkedList<Object*> > array;
public:
    ChainedHashTable(unsigned int);
    //...
    void Purge();
    ~ChainedHashTable();
    void Insert(Object&);
    void Withdraw(Object&);
};


#endif //C_TEST_CHAINEDHASHTABLE_H
