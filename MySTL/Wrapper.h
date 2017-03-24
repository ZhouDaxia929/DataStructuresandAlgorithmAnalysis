//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_WRAPPER_H
#define C_TEST_WRAPPER_H

#include "Object.h"

template <class T>
class Wrapper : public Object{
protected:
    T datum;
    int CompareTo(Object const&) const;

public:
    Wrapper();
    Wrapper(T const&);
    Wrapper& operator = (T const&);
    operator T const&() const;
    HashValue Hash() const;
    void Put(ostream&) const;
};


#endif //C_TEST_WRAPPER_H
