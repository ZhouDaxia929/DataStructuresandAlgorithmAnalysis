//
// Created by ggggg on 2017/4/26.
//

#ifndef C_TEST_NARYTREE_H
#define C_TEST_NARYTREE_H


#include "Tree.h"
#include "Array.h"

class NaryTree : public Tree{
protected:
    Object* key;
    unsigned int const degree;
    Array<NaryTree*> subtree; //指向NaryTree实例的指针数组。
public:
    NaryTree(unsigned int); //创建一棵空树，把key指针社位置设置为0，subtree类型数组的长度设置为0.
    NaryTree(unsigned int, Object&); //创建一棵非空树，它的根节点包含规定的对象。
    ~NaryTree();

    bool IsEmpty() const;
    Object& Key() const;
    NaryTree& Subtree(unsigned int) const;
    virtual void AttachKey(Object&); //把某一特定对象插到在根节点处的一棵给定的N叉树中。这个操作仅为空树定义的。
    virtual Object& DetachKey(); //用来从根节点中删除对象，仅允许删除叶子节点的根节点
    virtual void AttachSubtree(unsigned int, NaryTree&); //使由第二个参数确定的N叉树成为已给定树的第i棵子树。
    virtual NaryTree& DetachSubtree(unsigned int); //从一棵给定的N叉树中删去它的第i棵子树。
    //...
};


#endif //C_TEST_NARYTREE_H
