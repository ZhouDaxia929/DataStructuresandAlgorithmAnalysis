//
// Created by ggggg on 2017/3/10.
//
#include <cstdlib>
#include <cstdio>
#include "List.h"
void ListTest(){
    List L, L1;
    Position P, P1;
    L = MakeEmpty(NULL);
    P = Header(L);
    PrintList(L);

    L1 = MakeEmpty(NULL);
    P1 = Header(L1);
    PrintList(L1);

    for(int i = 0; i < 50; i += 2){
        Insert(i, L, P);
        P = Advance(P);
    }
    PrintList(L);
    printf("\n");
    for(int i = 1; i < 100; i += 3){
        Insert(i, L1, P1);
        P1 = Advance(P1);
    }
    PrintList(L1);
    printf("\n");

    ReverseList(L1);
    PrintList(L1);
    printf("\n");

    ReverseList(L1);
    PrintList(IntersectList(L, L1));
    printf("\n");

    PrintList(UnionList(L, L1));
    printf("\n");

    PrintLots(L, L1);
    printf("\n");

    SwapWithNext(L, L);
    PrintList(L);

    for(int i = 0; i < 10; i += 2)
        Delete(i, L);
    for(int i = 0; i < 10; i++){
        if((i % 2 == 0) == (Find(i, L) != NULL))
            printf("Find fails\n");
    }
    printf("Finished deletions");
    PrintList(L);
    DeleteList(L);
    DeleteList(L1);

}