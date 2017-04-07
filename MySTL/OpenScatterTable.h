//
// Created by ggggg on 2017/4/7.
//

#ifndef C_TEST_OPENSCATTERTABLE_H
#define C_TEST_OPENSCATTERTABLE_H


#include "HashTable.h"
#include "Array.h"

class OpenScatterTable : public HashTable{
    class Entry{
    public:
        enum State{empty, occupied, deleted};
        State state;
        Object* object;
        Entry();
    };
    Array<Entry> array;
    unsigned int C(unsigned int) const; //嵌入了线性探查带来的冲突解决策略。
    unsigned int FindMatch(Object const&) const;
    unsigned int FindInstance(Object const&) const;
    unsigned int FindUnoccupied(Object const&) const;

public:
    OpenScatterTable(unsigned int);
    //...
    void Purge();
    ~OpenScatterTable();
    void Insert(Object&);
    Object& Find(Object const&) const;
    void Withdraw(Object &);
};


#endif //C_TEST_OPENSCATTERTABLE_H
