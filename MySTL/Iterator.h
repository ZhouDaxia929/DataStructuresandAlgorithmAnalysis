//
// Created by ggggg on 2017/3/24.
//

#ifndef C_TEST_ITERATOR_H
#define C_TEST_ITERATOR_H


#include "Object.h"

class Iterator {
public:
    virtual ~Iterator();
    //容器中所有对象都访问完毕后，通过该函数重新设定迭代器
    virtual void Reset() = 0;
    virtual bool IsDone() const = 0;
    //间接引用操作符operator*指针用来存取迭代器当前所引用的对象。如果容器已空，调用此函数，函数就返回一个NullObject实例的引用
    virtual Object& operator * () const = 0;
    //递增操作符用来使迭代器指向容器中的下一个对象。如果容器已空，则递增操作符不起作用。
    virtual void operator ++ () = 0;
};


#endif //C_TEST_ITERATOR_H

/* 使用举例
SomeContainer c;
Iterator& i = c.NewIterator();
while(!i.IsDone()){
    cout << *i << endl;
    i++;
}
delete &i;

 //SomeContainer类的NewIterator函数定义
Iterator& SomeContainer::NewIterator() const{
    return *new SomeIterator(*this);
}
 */

/*
 * 通过使用多个迭代器对多个容器进行操作
SomeContainer c;
Iterator& i = c.NewIterator();
while(!i.IsDone()){
    Iterator& j = c.NewIterator();
    while(!j.IsDone()){
        if(*i == *j)
            cout << *i << endl;
        j++;
    }
    delete &j
    i++;
}
delete &i;
*/