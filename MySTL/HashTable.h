//
// Created by ZhouDaxia on 2017/4/2.
//

#ifndef C_TEST_HASHTABLE_H
#define C_TEST_HASHTABLE_H


#include "SearchableContainer.h"

class HashTable : public virtual SearchableContainer{
protected:
    unsigned int length;
public:
    HashTable(unsigned int);
    virtual unsigned int H(Object const&) const; //即哈希函数
};


#endif //C_TEST_HASHTABLE_H
