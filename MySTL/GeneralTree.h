//
// Created by ggggg on 2017/4/26.
//

#ifndef C_TEST_GENERALTREE_H
#define C_TEST_GENERALTREE_H


#include "Tree.h"
#include "LinkedList.h"

class GeneralTree : public Tree{
protected:
    Object* key; //树的根节点
    unsigned int degree; //树根节点的度
    LinkedList<GeneralTree*> list; //指向类实例的链表指针，这个链表包含了指向给定子树的指针。
public:
    GeneralTree(Object&);
    void Purge();
    ~GeneralTree();
    Object& Key() const;
    GeneralTree& Subtree(unsigned int) const;
    //把一个欲连接的树的指针添加到链表上，然后给degree加1。
    virtual void AttachSubtree(GeneralTree&); //把某一特定的子树连接到所给定的根节点上，参数为指向一个欲连接的GeneralTree实例的引用
    virtual GeneralTree DetachSubtree(GeneralTree&); //从给定的树中删除某一特定的子树
    //...
};


#endif //C_TEST_GENERALTREE_H
