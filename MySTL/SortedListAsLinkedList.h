//
// Created by ZhouDaxia on 2017/3/28.
//

#ifndef C_TEST_SORTEDLISTASLINKEDLIST_H
#define C_TEST_SORTEDLISTASLINKEDLIST_H


#include "SortedList.h"
#include "ListAsLinkedList.h"

class SortedListAsLinkedList : public virtual SortedList, public virtual ListAsLinkedList{
public:
    SortedListAsLinkedList();
    //...
    void Insert(Object&);
};


#endif //C_TEST_SORTEDLISTASLINKEDLIST_H
