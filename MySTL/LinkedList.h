//
// Created by ggggg on 2017/3/22.
//

#ifndef C_TEST_LINKEDLIST_H
#define C_TEST_LINKEDLIST_H


template <class T>
class LinkedList;

template <class T>
class ListElement{
    T datum;
    ListElement* next;
    ListElement (T const&, ListElement*);

public:
    T const& Datum() const;
    ListElement const* Next() const;
    friend class LinkedList<T>; //友元类
};

template <class T>
class LinkedList{
    ListElement<T>* head;
    ListElement<T>* tail;
public:
    LinkedList();
    ~LinkedList();

    LinkedList(LinkedList const&);
    LinkedList& operator = (LinkedList const&);

    ListElement<T> const* Head() const;
    ListElement<T> const* Tail() const;
    bool IsEmpty() const;
    T const& First() const;
    T const& Last() const;

    void Prepend(T const&); //前插
    void Append(T const&);
    void Extract(T const&);
    void Purge();
    void InsertAfter(ListElement<T> const*, T const&);
    void InsertBefore(ListElement<T> const*, T const&);

};


#endif //C_TEST_LINKEDLIST_H
