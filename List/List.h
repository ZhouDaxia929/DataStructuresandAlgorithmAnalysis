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

List MakeEmpty(List L); //初始化链表，若L非空，删除全部节点
bool IsEmpty(List L); //判断链表是否为空
bool IsLast(Position P, List L); //判断位置P是否指向链表的尾节点
Position Find(ElementType X, List L); //返回链表中第一个值为X的节点的位置指针
void Delete(ElementType X, List L); //删除链表中第一个值为X的节点
Position FindPrevious(ElementType X, List L); //返回第一个值为X的节点的前一个节点的位置指针
void Insert(ElementType X, List L, Position P); //在指定位置P插入一个值为X的新节点
void DeleteList(List L); //删除整个链表
Position Header(List L); //返回头节点
Position First(List L); //返回第一个有效节点
Position Advance(Position P); //返回指定位置的下一个节点位置指针
ElementType Retrieve(Position P); //返回指定节点位置的值
void PrintList(const List L); //打印整个链表
/*
 * 打印链表L中那些由P所指定的位置上的元素，例如P = 1,3,4,6，
 * 将L中的第1，第3，第4，第6个元素打印出来
 */
void PrintLots(List L, List P);
/*
 * 通过只调整指针来交换两个相邻的元素，BeforeP是 要调换两个元素的前一个指针。
 */
void SwapWithNext(Position BeforeP, List L);
/*
 * 求两个链表的交期
 */
List IntersectList(List L, List P);
/*
 * 求两个链表的并集
 */
List UnionList(Position L, Position P);
/*
 * 将链表以O(N)进行反转链表
 */
void ReverseList(List L);

#endif //C_TEST_LIST_H

//Place in the implementation file
struct Node{
    ElementType Element;
    Position Next;
};
