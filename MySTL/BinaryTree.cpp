//
// Created by ggggg on 2017/4/26.
//

#include "BinaryTree.h"
BinaryTree::BinaryTree() : key(0), left(0), right(0) {}

BinaryTree::BinaryTree(Object& _key) : key(_key), left(new BinaryTree()), right(new BinaryTree()) {}

void BinaryTree::Purge() {
    if(!IsEmpty()){
        if(IsOwner())
            delete key;
        delete left;
        delete right;
        key = 0;
        left = 0;
        right = 0;
    }
}

BinaryTree::~BinaryTree() {
    Purge();
}

void BinaryTree::DepthFirstTraversal(PrePostVisitor& visitor) const {
    if(visitor.IsDone())
        return;
    if(!IsEmpty()){
        visitor.PreVisit(*key);
        left->DepthFirstTraversal(visitor);
        visitor.Visit(*key);
        right->DepthFirstTraversal(visitor);
        visitor.PostVisit(*key);
    }
}