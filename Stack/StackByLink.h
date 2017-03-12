//
// Created by ggggg on 2017/3/12.
//

#ifndef C_TEST_STACKBYLINK_H
#define C_TEST_STACKBYLINK_H

struct stack_record;
typedef struct stack_record *Stack;
struct link_node;
typedef struct link_node node;
typedef int ElementType;

bool IsEmptyStackByLink(Stack s);
bool IsFullByLink(Stack s);
Stack createStack(int maxElement);
void disposeStack(Stack s);
void makeEmpty(Stack s);
void push(ElementType x, Stack s);
ElementType Top(Stack s);
void pop(Stack s);
ElementType topAndPop(Stack s);
void TestStackByLink();

struct stack_record{
    int capacity;
    int size;
    node *item;
};

struct link_node{
    ElementType data;
    node *next;
};

#endif //C_TEST_STACKBYLINK_H
