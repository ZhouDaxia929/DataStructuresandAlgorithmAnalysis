//
// Created by ggggg on 2017/4/26.
//

#include "NaryTree.h"
#include <iostream>
using namespace std;

NaryTree::NaryTree(unsigned int _degree) : key(0), degree(_degree), subtree(0) {}

NaryTree::NaryTree(unsigned int _degree, Object& _key) : key(&_key), degree(_degree), subtree(_degree) {
    for(unsigned int i = 0; i < degree; i++)
        subtree[i] = new NaryTree(degree);
}

bool NaryTree::IsEmpty() const {
    return key == 0;
}

Object& NaryTree::Key() const {
    if(IsEmpty())
        cout << "invalid operation" << endl;
    return *key;
}

void NaryTree::AttachKey(Object& object) {
    if(!IsEmpty())
        cout << "invalid operation" << endl;
    key = &object;
    subtree.SetLength(degree);
    for(unsigned int i = 0; i < degree; i++)
        subtree[i] = new NaryTree(degree);
}

Object& NaryTree::DetachKey() {
    if(!IsEmpty())
        cout << "invalid operation" << endl;
    Object& result = *key;
    key = 0;
    for(unsigned int i = 0; i < degree; i++)
        delete subtree[i];
    subtree.SetLength(0);
    return result;
}

NaryTree& NaryTree::Subtree(unsigned int i) const {
    if(IsEmpty())
        cout << "invalid operation" << endl;
    return *subtree[i];
}

void NaryTree::AttachSubtree(unsigned int i, NaryTree& t) {
    if(IsEmpty())
        cout << "invalid operation" << endl;
    if(!subtree[i]->IsEmpty())
        cout << "non-empty subtree present" << endl;
    delete subtree[i];
    subtree[i] = &t;
}

NaryTree& NaryTree::DetachSubtree(unsigned int i) { //当一棵子树被删去的时候，它将被一棵空子树代替。
    if(IsEmpty())
        cout << "invalid operation" << endl;
    NaryTree& result = *subtree[i];
    subtree[i] = new NaryTree(degree);
    return result;
}