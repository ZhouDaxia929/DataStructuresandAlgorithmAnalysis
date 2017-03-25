//
// Created by ggggg on 2017/3/25.
//

#include "StackAsLinkedList.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

StackAsLinkedList::StackAsLinkedList() : list() {}

void StackAsLinkedList::Purge() {
    if(IsOwner()){
        ListElement<Object*> const* ptr;
        for(ptr = list.Head(); ptr != 0; ptr = ptr->Next())
            delete ptr->Datum();
    }
    list.Purge();
    count = 0;
}

StackAsLinkedList::~StackAsLinkedList() {
    Purge();
}

void StackAsLinkedList::Push(Object& object) {
    list.Prepend(&object);
    count++;
}

/*
 *
 */
Object& StackAsLinkedList::Pop() {
    if(count == 0)
        cout << "stack is empty" << endl;
    Object& result = *list.First();
    list.Extract(&result);
    count--;
    return result;
}

Object& StackAsLinkedList::Top() const {
    if(count == 0)
        cout << "stack is empty" << endl;
    return *list.First();
}

void StackAsLinkedList::Accept(Visitor& visitor) const {
    ListElement<Object*> const* ptr;
    for(ptr = list.Head(); ptr != 0 && visitor.IsDone(); ptr = ptr->Next())
        visitor.Visit(*ptr->Datum());
}

StackAsLinkedList::Iter::Iter(StackAsLinkedList const& _stack) : stack(_stack) {
    Reset();
}

bool StackAsLinkedList::Iter::IsDone() const {
    return position == 0;
}

Object& StackAsLinkedList::Iter::operator * () const {
    if(position != 0)
        return *position->Datum();
    else
        return NullObject::Instance();
}

void StackAsLinkedList::Iter::operator ++ () {
    if(position != 0)
        position = position->Next();
}

void StackAsLinkedList::Iter::Reset() {
    position = stack.list.Head();
}

//该函数完全通过接口来操纵栈，并不依赖栈所使用的实现方法。
void StackAsLinkedList::RPNCalculator(Stack& stack) {
    char c;
    while(cin >> c, !cin.eof){
        if(std::isdigit(c))
            stack.Push(*new Int(c - '0'));
        else if(c == '+'){
            Int& arg2 = dynamic_cast<Int&> (stack.Pop());
            Int& arg1 = dynamic_cast<Int&> (stack.Pop());
            stack.Push(*new Int(arg1 + arg2));
            delete &arg1;
            delete &arg2;
        }
        else if(c == '*'){
            Int& arg2 = dynamic_cast<Int&> (stack.Pop());
            Int& arg1 = dynamic_cast<Int&> (stack.Pop());
            stack.Push(*new Int(arg1 * arg2));
            delete &arg1;
            delete &arg2;
        }
        else if(c == '='){
            Int& arg = dynamic_cast<Int&> (stack.Pop());
            cout << arg << endl;
            delete &arg;
        }
    }
}