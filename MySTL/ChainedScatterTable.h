//
// Created by ZhouDaxia on 2017/4/2.
//

#ifndef C_TEST_CHAINEDSCATTERTABLE_H
#define C_TEST_CHAINEDSCATTERTABLE_H


#include "HashTable.h"
#include "Array.h"

class ChainedScatterTable : public HashTable{
    class Entry{
    public:
        enum{null = ~0U};
        Object* object;
        unsigned int next;
        Entry();
    };
    Array<Entry> array;
public:
    ChainedScatterTable(unsigned int);
    //...
    void Purge();
    ~ChainedScatterTable();

    void Insert(Object&);
    Object& Find(Object const &) const;

    void Withdraw(Object&);
};


#endif //C_TEST_CHAINEDSCATTERTABLE_H
