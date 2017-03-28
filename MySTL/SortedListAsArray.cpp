//
// Created by ZhouDaxia on 2017/3/28.
//

#include "SortedListAsArray.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

void SortedListAsArray::Insert(Object& object) {
    if(count == array.Length())
        cout << "list is full" << endl;
    unsigned int i = count;
    //把所有比要插入项大的数据项向右移动一个位置。
    while(i > 0 && *array[i - 1U] > object){
        array[i] = array[i - 1U];
        i--;
    }
    array[i] = &object;
    count++;
}

unsigned int SortedListAsArray::FindOffset(Object const& object) const {
    int left = 0;
    int right = count - 1;
    while(left <= right){
        int const middle = (left + right) / 2;
        if(object > *array[middle])
            left = middle + 1;
        else if(object < *array[middle])
            right = middle - 1;
        else
            return middle;
    }
    return count;
}

Object& SortedListAsArray::Find(Object const& object) const {
    unsigned int const offset = FindOffset(object);
    if(offset < count)
        return *array[offset];
    else
        return NullObject::Instance();
}

Position& SortedListAsArray::FindPosition(Object const& object) const {
    Pos& result = *new Pos(*this, 0);
    result.offset = FindOffset(object);
    return result;
}

void SortedListAsArray::Withdraw(Object & object) {
    if(count == 0)
        cout << "list is empty" << endl;
    unsigned int const offset = FindOffset(object);
    if(offset == count)
        cout << "object not found" << endl;
    for(unsigned int i = offset; i < count - 1U; i++)
        array[i] = array[i + 1];
    count--;
}