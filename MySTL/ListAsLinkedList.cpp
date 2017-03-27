//
// Created by ZhouDaxia on 2017/3/27.
//

#include "ListAsLinkedList.h"
#include "NullObject.h"
#include <iostream>
using namespace std;

ListAsLinkedList::ListAsLinkedList() : linkedList() {}

ListAsLinkedList::Pos::Pos(ListAsLinkedList const& _list, ListElement<Object*> const* _element) : list(_list), element(_element) {}

void ListAsLinkedList::Insert(Object& object) {
    linkedList.Append(&object);
    count++;
}

Object& ListAsLinkedList::operator [] (unsigned int offset) const {
    if(offset >= count)
        cout << "invalid offset" << endl;
    unsigned int i = 0;
    ListElement<Object*> const* ptr = linkedList.Head();
    while(i < offset && ptr != 0){
        ptr = ptr->Next();
        i++;
    }
    if(ptr == 0)
        cout << "should never happen" << endl;
    return *ptr->Datum();
}

bool ListAsLinkedList::IsMember(Object const& object) const {
    ListElement<Object*> const* ptr;
    for(ptr = linkedList.Head(); ptr != 0; ptr = ptr->Next())
        if(ptr->Datum() == &object)
            return true;
    return false;
}

Object& ListAsLinkedList::Find(Object const& object) const {
    ListElement<Object*> const* ptr;
    for(ptr = linkedList.Head(); ptr != 0; ptr = ptr->Next())
        if(*ptr->Datum() == object)
            return *ptr->Datum();
    return NullObject::Instance();
}

void ListAsLinkedList::Withdraw(Object& object) {
    if(count == 0)
        cout << "list is empty" << endl;
    linkedList.Extract(&object);
    count--;
}

Position& ListAsLinkedList::FindPosition(Object const& object) const {
    ListElement<Object*> const* ptr = linkedList.Head();
    while(ptr != 0 && *ptr->Datum() != object)
        ptr = ptr->Next();
    return *new Pos(*this, ptr);
}

Object& ListAsLinkedList::operator[](Position const& arg) const {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(&position.list != this || position.element == 0)
        cout << "invalid position" << endl;
    return *position.element->Datum();
}

void ListAsLinkedList::InsertAfter(Position const& arg, Object& object) {
    Pos const& position = dynamic_cast<Pos const&>(arg);
    if(&position.list != this || position.element == 0)
        cout << "invalid position" << endl;
    linkedList.InsertAfter(position.element, &object);
    count++;
}

void ListAsLinkedList::InsertBefore(Position const& arg, Object& object) {
    Pos const& position = dynamic_cast<Pos const&>(arg);
    if(&position.list != this || position.element == 0)
        cout << "invalid position" << endl;
    linkedList.InsertBefore(position.element, &object);
    count++;
}

void ListAsLinkedList::Withdraw(Position const& arg) {
    Pos const& position = dynamic_cast<Pos const&> (arg);
    if(count == 0)
        cout << "list is empty" << endl;
    if(&position.list != this || position.element == 0)
        cout << "invalid position";
    linkedList.Extract(position.element->Datum());
    count--;
}