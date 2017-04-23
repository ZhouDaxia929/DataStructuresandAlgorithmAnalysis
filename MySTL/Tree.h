//
// Created by ggggg on 2017/4/15.
//

#ifndef C_TEST_TREE_H
#define C_TEST_TREE_H

#include "Container.h"
#include "TreeVisitor.h"
#include "Stack.h"

class Tree : public virtual Container{
    class Iter;
public:
    virtual Object& Key() const = 0; //返回一个指向包含在树根节点中的对象的引用。
    virtual Tree& Subtree(unsigned int) const = 0; //返回一个指向给定树的第i棵子树的引用
    virtual bool IsEmpty() const = 0; //如果树的根节点是是一棵空树即一个外部节点，返回true
    virtual bool IsLeaf() const = 0; //如果树的根节点是叶子节点，返回true
    virtual unsigned int Degree() const = 0; //返回树根节点的度。
    virtual int Height() const; //返回树的高度，空树的高度为-1
    virtual void DepthFirstTraversal(PrePostVisitor&) const;
    virtual void BreadthFirstTraversal(Visitor&) const;
    virtual void Accept(Visitor&) const;
};

class Tree::Iter : public Iterator{
    Tree const& tree;
    Stack& stack;
public:
    Iter(Tree const&);
    ~Iter();
    void Reset();
    bool IsDone() const;
    Object& operator * () const; //间接引用操作符被用来存取迭代器当前所指的对象。这时，迭代器指向树根节点上的对象
    void operator ++ (); //被用来向前移迭代器，指向前序遍历的下一个节点。
};
#endif //C_TEST_TREE_H
