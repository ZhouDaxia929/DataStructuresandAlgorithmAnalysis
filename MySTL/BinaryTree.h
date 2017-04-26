//
// Created by ggggg on 2017/4/26.
//

#ifndef C_TEST_BINARYTREE_H
#define C_TEST_BINARYTREE_H


#include "Tree.h"

class BinaryTree : public virtual Tree{
protected:
    Object* key;
    BinaryTree* left;
    BinaryTree* right;
public:
    BinaryTree();
    BinaryTree(Object&); //创建一棵二叉树，并用特定的对象作为它的根。还要创建相应的两棵子树。
    void Purge();
    ~BinaryTree();

    Object& Key() const;
    virtual void AttachKey(Object&);
    virtual Object& DetachKey();
    virtual BinaryTree& Left() const;
    virtual BinaryTree& Right() const;
    virtual void AttachLeft(BinaryTree&);
    virtual void AttachRight(BinaryTree&);
    virtual BinaryTree& DetachLeft();
    virtual BinaryTree& DetachRight();
    //...
    void DepthFirstTraversal(PrePostVisitor&) const;
};


#endif //C_TEST_BINARYTREE_H
