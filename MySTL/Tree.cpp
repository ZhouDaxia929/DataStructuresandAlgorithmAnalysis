//
// Created by ggggg on 2017/4/15.
//

#include "TreeVisitor.h"
#include "Tree.h"
#include "Queue.h"
#include "QueueAsLinkedList.h"
#include "StackAsLinkedList.h"
#include "NullObject.h"

void Tree::DepthFirstTraversal(PrePostVisitor & visitor) const {
    if(visitor.IsDone())
        return;
    if(!IsEmpty()){
        visitor.PreVisit(Key());
        for(unsigned int i = 0; i < Degree(); i++)
            Subtree(i).DepthFirstTraversal(visitor);
        visitor.PostVisit(Key());
    }
}

void Tree::BreadthFirstTraversal(Visitor& visitor) const {
    Queue& queue = *new QueueAsLinkedList();
    queue.RescindOwnership();
    if(!IsEmpty()) //只要树不是空树，根节点入队。
        queue.Enqueue(const_cast<Tree&>(*this)); //消除对const的限定
    while(!queue.IsEmpty() && !visitor.IsDone()){ //重复直到队列为空
        Tree const& head = dynamic_cast<Tree const &>(queue.Dequeue());
        visitor.Visit(head.Key());
        for(unsigned int i = 0; i < head.Degree(); i++){
            Tree& child = head.Subtree(i);
            if(!child.IsEmpty())
                queue.Enqueue(child);
        }
    }
    delete &queue;
}

void Tree::Accept(Visitor& visitor) const {
    DepthFirstTraversal(PreOrder(visitor));
}

Tree::Iter::Iter(Tree const& _tree) : tree(_tree), stack(*new StackAsLinkedList()) {
    stack.RescindOwnership();
    Reset();
}

Tree::Iter::~Iter() {
    delete &stack;
}

void Tree::Iter::Reset() {
    stack.Purge();
    if(!tree.IsEmpty())
        stack.Push(const_cast<Tree&>(tree));
}

bool Tree::Iter::IsDone() const {
    return stack.IsEmpty();
}

Object& Tree::Iter::operator * () const {
    if(!stack.IsEmpty()){
        Tree const& top = dynamic_cast<Tree const&>(stack.Top());
        return top.Key();
    }
    else
        return NullObject::Instance();
}

void Tree::Iter::operator++() {
    if(!stack.IsEmpty()){
        Tree const& top = dynamic_cast<Tree const&> (stack.Pop());
        //在前序遍历中，节点的第一棵子树在第二棵子树之前被遍历，因此，在栈中第二棵子树应当出现在第一棵子树的下面，这就是为什么要逆序入栈。
        for(int i = top.Degree() - 1; i >= 0; i--){
            Tree& subtree = top.Subtree(i);
            if(!subtree.IsEmpty())
                stack.Push(subtree);
        }
    }
}