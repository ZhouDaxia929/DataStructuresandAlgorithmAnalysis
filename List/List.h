//
// Created by ggggg on 2017/3/10.
//

#ifndef C_TEST_LIST_H
#define C_TEST_LIST_H
typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void PrintList(const List L);
void PrintLots(List L, List P);
void SwapWithNext(Position BeforeP, List L);
List IntersectList(List L, List P);
List UnionList(Position L, Position P);
void ReverseList(List L);

#endif //C_TEST_LIST_H

//Place in the implementation file
struct Node{
    ElementType Element;
    Position Next;
};
