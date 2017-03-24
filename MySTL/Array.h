//
// Created by ggggg on 2017/3/21.
//

#ifndef C_TEST_ARRAY_H
#define C_TEST_ARRAY_H


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


#endif //C_TEST_ARRAY_H
