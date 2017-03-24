//
// Created by ggggg on 2017/3/23.
//

#include "Array2D.h"
#include "Array.h"
#include <iostream>
using namespace std;



template <class T>
Array2D<T>::Array2D(unsigned int m, unsigned int n) : numberOfRows(m), numberOfColumns(n), array(m * n){}

template <class T>
T& Array2D<T>::Select(unsigned int i, unsigned int j) {
    if(i >= numberOfRows)
        cout << "invalid row" << endl;
    if(j >= numberOfColumns)
        cout << "invalid column" << endl;
    return array[i * numberOfColumns + j];
}

template <class T>
Array2D<T>::Row Array2D<T>::operator[](unsigned int row) {
    return Row(*this, row);
}