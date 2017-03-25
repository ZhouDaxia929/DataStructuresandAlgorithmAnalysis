//
// Created by ggggg on 2017/3/25.
//

#ifndef C_TEST_STACKASLINKEDLIST_H
#define C_TEST_STACKASLINKEDLIST_H


#include "Stack.h"
#include "LinkedList.h"

class StackAsLinkedList : public Stack{
    LinkedList<Object*> list;
    class Iter;

public:
    StackAsLinkedList();
    //...
    void Purge();
    ~StackAsLinkedList();

    //在这个实现中，栈顶在链表首部
    void Push(Object&);
    Object& Pop();
    Object& Top() const;

    void Accept(Visitor& visitor) const;

    void RPNCalculator(Stack&);

    friend class Iter;
};

class StackAsLinkedList::Iter : public Iterator{
    StackAsLinkedList const& stack;
    ListElement<Object*> const* position;
public:
    Iter (StackAsLinkedList const&);
    //...
    bool IsDone() const;
    Object& operator * () const;
    void operator ++ ();
    void Reset();
};


#endif //C_TEST_STACKASLINKEDLIST_H
