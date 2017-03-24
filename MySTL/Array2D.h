//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_ARRAY2D_H
#define C_TEST_ARRAY2D_H
#include "Array.h"

template <class T>
class Array2D{
protected:
    unsigned int numberOfRows;
    unsigned int numberOfColumns;
    Array<T> array;
public:
    class Row{
        Array2D& array2D;
        unsigned int const row;
    public:
        Row(Array2D& _array2D, unsigned int _row) : array2D(_array2D), row(_row){}
        T& operator [] (unsigned int column) const{
            return array2D.Select(row, column);
        }
    };
u
    Array2D(unsigned int, unsigned int);
    T& Select(unsigned int, unsigned int);
    Row operator [] (unsigned int);
};


#endif //C_TEST_ARRAY2D_H
