//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_NULLOBJECT_H
#define C_TEST_NULLOBJECT_H


#include "Object.h"

/*
 * 单元集类，只有唯一一个实例的类，这个实例实际上是该类本身的一个静态成员变量。
 */
class NullObject : public Object{
    static NullObject instance;
    NullObject();

protected:
    int CompareTo(Object const&) const;

public:
    bool IsNull() const;
    HashValue Hash() const;
    void Put(ostream& s) const;
    static NullObject& Instance();
};


#endif //C_TEST_NULLOBJECT_H
