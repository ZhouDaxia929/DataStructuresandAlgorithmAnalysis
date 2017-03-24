//
// Created by ggggg on 2017/3/23.
//

#include "Matrix.h"
#include "Array2D.h"
#include <iostream>
using namespace std;


template <class T>
Matrix<T> Matrix<T>::operator* (Matrix<T> const& arg) const {
    if(numberOfColumns != arg.numberOfRows)
        cout << "incompatible matrices" << endl;
    Matrix<T> result(numberOfRows, arg.numberOfColumns);
    for(unsigned int i = 0; i < numberOfRows; i++)
        for(unsigned int j = 0; j < arg.numberOfColumns; j++){
            T sum = 0;
            for(unsigned int k = 0; k < numberOfColumns; k++)
                sum += (*this)[i][k] * arg[k][j];
            result[i][j] = sum;
        }
    return result;
}