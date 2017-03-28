//
// Created by ZhouDaxia on 2017/3/28.
//

#include "SortedListAsLinkedList.h"

SortedListAsLinkedList::SortedListAsLinkedList() {}

void SortedListAsLinkedList::Insert(Object & object) {
    ListElement<Object*> const* prevPtr = 0;
    ListElement<Object*> const* ptr = linkedList.Head();
    while(ptr != 0 && *ptr->Datum() < object){
        prevPtr = ptr;
        ptr = ptr->Next();
    }
    if(prevPtr == 0)
        linkedList.Prepend(&object);
    else
        linkedList.InsertAfter(prevPtr, &object);
    count++;
}