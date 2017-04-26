//
// Created by ggggg on 2017/4/26.
//

#include "GeneralTree.h"
#include <iostream>
using namespace std;

GeneralTree::GeneralTree(Object& _key) : key(&_key), degree(0), list(){}

void GeneralTree::Purge() {
    ListElement<GeneralTree*>const* ptr;
    if(IsOwner())
        delete key;
    for(ptr = list.Head(); ptr != 0; ptr = ptr->Next())
        delete ptr->Datum();
    key = 0;
    list.Purge();
}

GeneralTree::~GeneralTree() {
    Purge();
}

Object& GeneralTree::Key() const {
    return *key;
}

GeneralTree& GeneralTree::Subtree(unsigned int i) const {
    if(i >= degree)
        cout << "invalid subtree index" << endl;
    unsigned int j = 0;
    ListElement<GeneralTree*>const* ptr = list.Head();
    while(j < i && ptr != 0){
        ++j;
        ptr = ptr->Next();
    }
    if(ptr == 0)
        cout << "should never happen" << endl;
    return *ptr->Datum();
}

void GeneralTree::AttachSubtree(GeneralTree& t) {
    list.Append(&t);
    degree++;
}

GeneralTree GeneralTree::DetachSubtree(GeneralTree& t) {
    list.Extract(&t);
    degree--;
    return t;
}