//
// Created by ZhouDaxia on 2017/3/27.
//

#ifndef C_TEST_LISTASLINKEDLIST_H
#define C_TEST_LISTASLINKEDLIST_H


#include "OrderedList.h"
#include "LinkedList.h"

class ListAsLinkedList : public virtual OrderedList{
protected:
    LinkedList<Object*> linkedList;

    void Insert(Object&);
    Object& operator [] (unsigned int) const;

    bool IsMember(Object const&) const;
    Object& Find(Object const&) const;

    void Withdraw(Object&);
    void Withdraw(Position const&);

    Position& FindPosition(Object const&) const;
    Object& operator [] (Position const&) const;

    void InsertAfter(Position const&, Object&);
    void InsertBefore(Position const&, Object&);
    class Pos;

public:
    ListAsLinkedList();
    //...
    friend class Pos;
};

class ListAsLinkedList::Pos : public Position{
    Pos()
    //有序线性表的一个引用
    ListAsLinkedList const& list;
    //指向链表元素的指针
    ListElement<Object*> const* element;
public:
    //...
    Pos(ListAsLinkedList const&, ListElement<Object*> const*);
    friend class ListAsLinkedList;
};


#endif //C_TEST_LISTASLINKEDLIST_H
