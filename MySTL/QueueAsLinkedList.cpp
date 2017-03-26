//
// Created by ggggg on 2017/3/26.
//

#include "QueueAsLinkedList.h"
#include <iostream>
using namespace std;

QueueAsLinkedList::QueueAsLinkedList() : list(){}

void QueueAsLinkedList::Purge() {
    if(IsOwner()){
        ListElement<Object*> const* ptr;
        for(ptr = list.Head(); ptr != 0; ptr = ptr->Next())
            delete ptr->Datum();
    }
    list.Purge();
    count = 0;
}

QueueAsLinkedList::~QueueAsLinkedList() {
    Purge();
}

Object& QueueAsLinkedList::Head() const {
    if(count == 0)
        cout << "queue is empty" << endl;
    return *list.First();
}

void QueueAsLinkedList::Enqueue(Object& object) {
    list.Append(&object);
    count++;
}

Object& QueueAsLinkedList::Dequeue() {
    if(count == 0)
        cout << "queue is enpty" << endl;
    Object& result = *list.First();
    list.Extract(&result);
    count--;
    return result;
}