//
// Created by ggggg on 2017/3/21.
//

#include "Array.h"

template <class T>
class Array{
protected:
    T* data;
    unsigned int base;
    unsigned int length;
public:
    Array();
    Array(unsigned int, unsigned int = 0);
    ~Array();

    Array(Array const&);
    Array& operator = (Array const&);

    T const& operator [] (unsigned int) const;
    T& operator [] (unsigned int);

    T const* Data () const;
    unsigned int Base() const;
    unsigned int Length() const;

    void SetBase(unsigned int);
    void SetLength(unsigned int);
};

//缺省构造函数
template <class T>
Array<T>::Array() : data(new T[0]), base(0), length(0) {}

//数组构造函数
template <class T>
Array<T>::Array(unsigned int n, unsigned int m) : data(new T[n]), base(m), length(n) {}

//备份构造函数
template <class T>
Array<T>::Array(Array<T> const& array) :
    data(new T[array.length]),
    base(array.base),
    length(array.length){
    for(unsigned int i = 0; i < length; i++)
        data[i] = array.data[i];
}

