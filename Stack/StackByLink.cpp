//
// Created by ggggg on 2017/3/12.
//
#include <cstdio>
#include <cstdlib>
#include "StackByLink.h"

#define MAXSIZE 100

bool IsEmptyStackByLink(Stack s){
    return s->size == 0;
}

bool IsFullByLink(Stack s){
    return s->size == s->capacity;
}

Stack createStack(int maxElement){
    Stack s;
    s = (Stack)malloc(sizeof(struct stack_record));
    if(s == NULL){
        printf("The stack alloca error\n");
        exit(-1);
    }
    s->capacity = MAXSIZE;
    s->item = NULL;
    s->size = 0;
    return s;
}

void disposeStack(Stack s){
    if(s){
        if(s->size)
            makeEmpty(s);
        free(s);
    }
}

void makeEmpty(Stack s){
    if(s){
        while(s->size){
            pop(s);
        }
    }
}

void push(ElementType x, Stack s){
    if(s){
        if(IsFullByLink(s))
            return;
        node *ptr = (node *)malloc(sizeof(node));
        if(NULL == ptr){
            printf("The node alloc is error\n");
            exit(-2);
        }
        ptr->data = x;
        ptr->next = s->item;
        s->item = ptr;
        s->size++;
    }
}

ElementType Top(Stack s){
    if(s){
        if(IsEmptyStackByLink(s)){
            printf("The stack is empty\n");
            exit(-3);
        }
        return s->item->data;
    }
}

void pop(Stack s){
    if(IsEmptyStackByLink(s)){
        printf("The stack is empty\n");
        exit(-4);
    }
    node *ptr = NULL;
    ptr = s->item->next;
    free(s->item);
    s->item = ptr;
    s->size--;
}

ElementType topAndPop(Stack s){
    ElementType x;
    if(s){
        if(IsEmptyStackByLink(s)){
            printf("The stack is empty\n");
            exit(-5);
        }
        x = Top(s);
        pop(s);
    }
    return x;
}

void TestStackByLink(){
    Stack s;
    s = createStack(10);
    ElementType x;
    for(int i = 0; i <= 10; i++){
        push(i, s);
        printf("The stack size is %d\n", s->size);
        x = Top(s);
        printf("The stack top is %d\n", x);
    }

    while(s->size){
        x = topAndPop(s);
        printf("The top stack is %d\n", x);
    }
    disposeStack(s);
}