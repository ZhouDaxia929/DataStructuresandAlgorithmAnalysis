//
// Created by ggggg on 2017/3/23.
//

#include "Object.h"

Object::~Object() {}

bool Object::IsNull() const {
    return false;
}

/**
 *
 * @param object
 * @return
 *
 * 该函数利用运行时类型信息以保证CompareTo成员函数仅对同一类的对象才收到激发，否则就使用before函数根据对象的类型对它们进行排序
 * C++运行时间库提供了before函数的实现，排序时如果左边的类型优先于右边的类型，那么函数返回一个真值。
 */
int Object::Compare(Object const& object) const {
    if(typeid(*this) == typeid(object))
        return CompareTo(object);
    else if(typeid(*this).before(typeid(object)))
        return -1;
    else
        return 1;
}