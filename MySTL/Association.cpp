//
// Created by ggggg on 2017/3/25.
//

#include "Association.h"
#include "NullObject.h"

Association::Association(Object &_key) : key(&_key), value(0) {}

Association::Association(Object &_key, Object &_value) : key(&_key), value(&_value) {}

Association::~Association() {
    if(IsOwner()){  //如果关联是被包含关键字和值得所有者，那么析构函数必定删除他们
        delete key;
        delete value;
    }
}

Object& Association::Key() const {
    return *key;
}

Object& Association::Value() const {
    if(value == 0)
        return NullObject::Instance();
    else
        return *value;
}

int Association::CompareTo(Object const& object) const {
    Association const& association = dynamic_cast<Association const&> (object);
    return Key().Compare(association.Key()); //比较是基于对象的关键字进行的，不关值的事。
}

void Association::Put(ostream& s) const {
    s << "Association {" << *key;
    if(value != 0)
        s << ", " << *value;
    s << "}";
}