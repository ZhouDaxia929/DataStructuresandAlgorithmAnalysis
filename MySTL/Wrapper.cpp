//
// Created by ggggg on 2017/3/23.
//

#include <string>
#include "Wrapper.h"

template <class T>
Wrapper<T>::Wrapper() : datum() {}

template <class T>
Wrapper<T>::Wrapper(T const& d) : datum(d) {}

template <class T>
Wrapper<T>& Wrapper<T>::operator = (T const &d) {
    datum = d;
    return *this;
}

template <class T>
Wrapper<T>::operator T const& () const {
    return datum;
}

template <class T>
int Wrapper::CompareTo(Object const& obj) const {
    Wrapper<T> const& arg = dynamic_cast<Wrapper<T> const&> (obj);
    return ::Compare(datum, arg.datum); //这个函数以后自己完成
}

template <class T>
void Wrapper<T>::Put(ostream& s) const {
    s << datum;
}

typedef Wrapper<int> Int;
typedef Wrapper<char> Char;
typedef Wrapper<double> Double;
typedef Wrapper<std::string> String;