//
// Created by ggggg on 2017/3/10.
//
#include "List.h"
#include "fatal.h"
#include <iostream>
#include <cstdlib>

//初始化链表
List MakeEmpty(List L){
    if(L != NULL)
        DeleteList(L); //如果链表非空，则删除链表
    L = new(Node);
    L->Next = NULL;
    return L;
}

/*
 * Correct DeleteList algorithm
 */
void DeleteList(List L){
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

//Return true if L is empty
bool IsEmpty(List L){
    return L->Next == NULL;
}

/*
 * Return true if P is the last position in list L
 * Parameter L is unused in this implementation
 */
bool IsLast(Position P, List L){
    return P->Next == NULL;
}

/*
 * Return Position of X in L; NULL is not found
 */
Position Find(ElementType X, List L){
    Position P;
    P = L->Next;
    while(P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

/*
 * If X is not found, then Next field of returned
 * Position is NULL
 * Assumes a header
 */
Position FindPrevious(ElementType X, List L){
    Position P = L;
    while(P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

/*
 * Delete first occurrence of X from a list
 * Assume use of a header node
 */
void Delete(ElementType X, List L){
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if(!IsLast(P, L)){
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

/*
 * Insert (after legal position P)
 * Header implementation assumed
 * Parameter L is unused in this implementation
 */
void Insert(ElementType X, List L, Position P){
    Position TmpCell;
    TmpCell = new(Node);
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

/*
 * 返回头结点的位置
 */
Position Header(List L){
    return L;
}

/*
 * 返回第一个元素的位置
 */
Position First(List L){
    return L->Next;
}

//获取位置P的下一个位置
Position Advance(Position P){
    return P->Next;
}

/*
 * 获取位置P处结构里的值
 */
ElementType Retrieve(Position P){
    return P->Element;
}

/*
 * 打印链表
 */
void PrintList(const List L){
    Position P = Header(L);
    if(IsEmpty(L))
        printf("Empty list\n");
    else{
        do{
            P = Advance(P);
            printf("%d ", Retrieve(P));
        }while(!IsLast(P, L));
        printf("\n");
    }
}

/*
 * 打印链表L中那些由P所指定的位置上的元素，例如P = 1,3,4,6，
 * 将L中的第1，第3，第4，第6个元素打印出来
 */
void PrintLots(List L, List P){
    int count = 1;
    Position Lpos, Ppos;
    Lpos = First(L);
    Ppos = First(P);
    while(Lpos != NULL && Ppos != NULL){
        if(Ppos->Element == count++){
            printf("%d ", Lpos->Element);
            Ppos = Advance(Ppos);
        }
        Lpos = Advance(Lpos);
    }
}

/*
 * 通过只调整指针来交换两个相邻的元素，BeforeP是 要调换两个元素的前一个指针。
 */
void SwapWithNext(Position BeforeP, List L){
    Position P, AfterP;
    if(BeforeP != NULL){
        P = Advance(BeforeP);
        if(P != NULL){
            AfterP = Advance(P);
            if(AfterP != NULL){
                P->Next = AfterP->Next;
                BeforeP->Next = AfterP;
                AfterP->Next = P;
            }
        }
    }
}

/*
 * 求两个链表的交期
 */
List IntersectList(List L1, List L2){
    List ResultList;
    Position L1Pos, L2Pos, ResultPos;
    ResultList = MakeEmpty(NULL);
    L1Pos = First(L1);
    L2Pos = First(L2);
    ResultPos = Header(ResultList);
    while(L1Pos != NULL && L2Pos != NULL){
        if(L1Pos->Element < L2Pos->Element)
            L1Pos = Advance(L1Pos);
        else if(L1Pos->Element > L2Pos->Element)
            L2Pos = Advance(L2Pos);
        else{
            Insert(L1Pos->Element, ResultList, ResultPos);
            ResultPos = Advance(ResultPos);
            L1Pos = Advance(L1Pos);
            L2Pos = Advance(L2Pos);
        }
    }
    return ResultList;
}

/*
 * 求两个链表的并集
 */
List UnionList(Position L1, Position L2){
    List ResultList;
    ElementType InsertElement;
    Position L1Pos, L2Pos, ResultPos;
    ResultList = MakeEmpty(NULL);
    L1Pos = First(L1);
    L2Pos = First(L2);
    ResultPos = Header(ResultList);
    while(L1Pos != NULL && L2Pos != NULL){
        if(L1Pos->Element < L2Pos->Element){
            InsertElement = L1Pos->Element;
            L1Pos = Advance(L1Pos);
        }
        else if(L1Pos->Element > L2Pos->Element){
            InsertElement = L2Pos->Element;
            L2Pos = Advance(L2Pos);
        }
        else{
            InsertElement = L1Pos->Element;
            L1Pos = Advance(L1Pos);
            L2Pos = Advance(L2Pos);
        }
        Insert(InsertElement, ResultList, ResultPos);
        ResultPos = Advance(ResultPos);
    }
    while(L1Pos != NULL){
        Insert(L1Pos->Element, ResultList, ResultPos);
        ResultPos = Advance(ResultPos);
        L1Pos = Advance(L1Pos);
    }
    while(L2Pos != NULL){
        Insert(L2Pos->Element, ResultList, ResultPos);
        ResultPos = Advance(ResultPos);
        L2Pos = Advance(L2Pos);
    }
    return ResultList;
}

/*
 * 将链表以O(N)进行反转链表
 */
void ReverseList(List L){
    if(IsEmpty(L) || L->Next->Next == NULL) //如果链表是空或者只有一个元素，则不排序
        return;
    Position CurrentPos, PreviousPos, NextPos;
    CurrentPos = L->Next; //当前指针
    PreviousPos = NULL; //上一个指针
    NextPos = L->Next->Next; //探测指针
    while(NextPos != NULL){ //探测指针指向链表尾部时，停止循环
        CurrentPos->Next = PreviousPos; //当前指针指向上一个指针
        PreviousPos = CurrentPos; //将上一个指针后移
        CurrentPos = NextPos; //将当前指针后移
        NextPos = Advance(NextPos); //将探测指针后移，直到触到尾指针NULL
    }
    CurrentPos->Next = PreviousPos; //最后一个指针还没有链接前一个指针
    L->Next = CurrentPos; // 将头结点链接原来尾节点
}