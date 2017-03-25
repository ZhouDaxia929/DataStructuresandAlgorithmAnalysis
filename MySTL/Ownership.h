//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_OWNERSHIP_H
#define C_TEST_OWNERSHIP_H

/*
 * Container类是从Object基类及Ownership类共同派生出来的，
 * 因此，所有的容器都有一个与他们相联系的所有权。
 */

class Ownership {
    bool isOwner;
protected:
    Ownership() : isOwner(true){}

    //这个备份构造函数的作用很巧妙：它把初始容器的所有权转移给备份容器。
    Ownership(Ownership& arg) : isOwner(arg.isOwner){
        arg.isOwner = false;
    }

public:
    void AssertOwnership(){
        isOwner = true;
    }
    void RescindOwnership(){
        isOwner = false;
    }
    bool IsOwner() const{
        return isOwner;
    }
};


//#endif //C_TEST_OWNERSHIP_H
//
//void SomeContainer::Purge(){
//    if(IsOwner()){
//        for each Object i in this container{
//                delete &i;
//        }
//    }
//    Now clean up the container itself
//}
//
//SomeContainer::~SomeContainer(){
//    Purge();
//}
