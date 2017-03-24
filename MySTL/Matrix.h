//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_MATRIX_H
#define C_TEST_MATRIX_H


#include "Array2D.h"

template <class T>
class Matrix : public Array2D<T>{
public:
    Matrix(unsigned int, unsigned int);
    Matrix operator * (Matrix const&) const;
    Matrix operator + (Matrix const&) const;
};


#endif //C_TEST_MATRIX_H
