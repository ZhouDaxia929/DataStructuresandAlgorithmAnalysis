//
// Created by ggggg on 2017/3/21.
//

#include "Array.h"
#include <iostream>
using namespace std;



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

//析构函数的定义
template <class T>
Array<T>::~Array() {
    delete [] data;
}

//类存取器函数
template <class T>
T const* Array<T>::Data() const {
    return data;
}

template <class T>
unsigned int Array<T>::Base() const {
    return base;
}

template <class T>
unsigned int Array<T>::Length() const {
    return length;
}

//Array<T>类下标操作函数定义
template <class T> //对const常数型数组对象进行操作，返回一个对T类型对象的const型引用
T const& Array<T>::operator[](unsigned int position) const {
    unsigned int const offset = position - base;
    if(offset >= length)
        cout << "invalid position" << endl;
    return data[offset];
}

template <class T> //对非const型对象进行操作
T& Array<T>::operator[](unsigned int position) {
    unsigned int const offset = position - base;
    if(offset >= length)
        cout << "invalid position" << endl;
    return data[offset];
}

//set函数的定义
template <class T>
void Array<T>::SetBase(unsigned int newBase) {
    base = newBase;
}

template <class T>
void Array<T>::SetLength(unsigned int newLength) {
    T* const newData = new T[newLength];
    unsigned int const min = length < newLength ? length : newLength;
    for(unsigned int i = 0; i < min; i++)
        newData[i] = data[i];
    delete [] data;
    data = newData;
    length = newLength;
}
