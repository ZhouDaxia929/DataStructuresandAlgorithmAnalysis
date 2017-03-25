//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_ASSOCIATION_H
#define C_TEST_ASSOCIATION_H


#include "Object.h"
#include "Ownership.h"
//由于关联使用的是指针，所以Association类利用间接存储方式来实现。
class Association : public Object, public Ownership{
protected:
    Object* key;
    Object* value;
    int CompareTo(Object const&) const;

public:
    Association(Object&);
    Association(Object&, Object&);
    ~Association();

    Object& Key() const;
    Object& Value() const;

    HashValue Hash() const;
    void Put(ostream&) const;
};


#endif //C_TEST_ASSOCIATION_H
