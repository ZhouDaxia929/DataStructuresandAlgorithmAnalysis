//
// Created by ggggg on 2017/3/22.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;



template <class T>
ListElement<T>::ListElement(T const & _datum, ListElement<T>* _next) : datum(_datum), next(_next){}

template <class T>
T const& ListElement<T>::Datum() const {
    return datum;
}

template <class T>
ListElement<T> const* ListElement<T>::Next() const {
    return next;
}

//缺省构造函数
template <class T>
LinkedList<T>::LinkedList() : head(0), tail(0){}

//Purge函数定义
template <class T>
void LinkedList<T>::Purge() {
    while(head != 0){
        ListElement<T>* const tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = 0;
}

//析构函数
template <class T>
LinkedList<T>::~LinkedList() {
    Purge();
}

//各个存取器
template <class T>
ListElement<T> const* LinkedList<T>::Head() const {
    return head;
}
template <class T>
ListElement<T> const* LinkedList<T>::Tail() const {
    return tail;
}
template <class T>
bool LinkedList<T>::IsEmpty() const {
    return head == 0;
}

//First和Last的定义
template <class T>
T const& LinkedList<T>::First() const {
    if(head == 0)
        cout << "list is empty" << endl;
    return head->datum;
}

template <class T>
T const& LinkedList<T>::Last() const {
    if(tail == 0)
        cout << "list is empty" << endl;
    return tail->datum;
}

//在链表的第一个元素前面插入一个元素，且成为该链的新头部
template <class T>
void LinkedList<T>::Prepend(T const & item) {
    ListElement<T>* const tmp = new ListElement<T> (item, head);
    if(head == 0)
        tail = tmp;
    head = tmp;
}

//在链表的尾部添加一个新的ListElement对象，并使之成为链表的新尾部
template <class T>
void LinkedList<T>::Append(T const& item) {
    ListElement<T>* const tmp = new ListElement<T>(item, 0);
    if(head == 0)
        head = tmp;
    else
        tail->next = tmp;
    tail = tmp;
}

//备份构造函数，可用该函数创建某一给定链表的备份
template <class T>
LinkedList<T>::LinkedList(LinkedList<T> const& linkedList) : head(0), tail(0) {
    ListElement<T> const* ptr;
    for(ptr = linkedList.head; ptr != 0; ptr = ptr->next)
        Append(ptr->datum);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T> const& linkedList) {
    if(&linkedList != this){
        Purge();
        ListElement<T> const* ptr;
        for(ptr = linkedList.head; ptr != 0; ptr = ptr->next)
            Append(ptr->datum);
    }
    return *this;
}

//删除链表中某一特定元素
template <class T>
void LinkedList<T>::Extract(T const& item) {
    ListElement<T>* ptr = head;
    ListElement<T>* prevPtr = 0;
    while(ptr != 0 && ptr->datum != item){
        prevPtr = ptr;
        ptr = ptr->next;
    }
    if(ptr == 0)
        cout << "item not found" << endl;
    else{
        if(ptr == head)
            head = ptr->next;
        else
            prevPtr->next = ptr->next;
    }
    if(ptr == tail)
        tail = prevPtr;
    delete ptr;
}

//下面是两个插入元素的函数
template <class T>
void LinkedList<T>::InsertAfter(ListElement<T> const* arg, T const& item) {
    ListElement<T>* ptr = const_cast<ListElement<T>*>(arg);
    if(ptr == 0)
        cout << "invalid position" << endl;
    ListElement<T>* const tmp = new ListElement<T>(item, ptr->next);
    ptr->next = tmp;
    if(tail == ptr)
        tail = tmp;
}

template <class T>
void LinkedList<T>::InsertBefore(ListElement<T> const* arg, T const& item) {
    ListElement<T>* ptr = const_cast<ListElement<T>*>(arg);
    if(ptr == 0)
        cout << "invalid position" << endl;
    ListElement<T>* const tmp = new ListElement<T>(item, ptr);
    if(head == ptr)
        head = tmp;
    else{
        ListElement<T>* prevPtr = head;
        while(prevPtr != 0 && prevPtr->next != ptr)
            prevPtr = prevPtr->next;
        if(prevPtr == 0)
            cout << "invalid position" << endl;
        prevPtr->next = tmp;
    }
}