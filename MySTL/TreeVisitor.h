//
// Created by ggggg on 2017/4/15.
//

#ifndef C_TEST_TREEVISITOR_H
#define C_TEST_TREEVISITOR_H

#include "Visitor.h"

class PrePostVisitor : public Visitor{
public:
    virtual void PreVisit(Object&){}
    virtual void Visit(Object&){}
    virtual void PostVisit(Object&){}
};

class PreOrder : public PrePostVisitor{
    Visitor& visitor;
public:
    PreOrder(Visitor& v) : visitor(v){}
    void PreVisit(Object& object){
        visitor.Visit(object);
    }
};

class InOrder : public PrePostVisitor{
    Visitor& visitor;
public:
    InOrder(Visitor& v) : visitor(v){}
    void Visit(Object& object){
        visitor.Visit(object);
    }
};

class PostOrder : public PrePostVisitor{
    Visitor& visitor;
public:
    PostOrder(Visitor& v) : visitor(v){}
    void PostVisit(Object& object){
        visitor.Visit(object);
    }
};
#endif //C_TEST_TREEVISITOR_H

//使用范例
//PuttingVisitor v;
//SomeTree t;
//t.DepthFirstTraversal(PreOrder(v));
//t.DepthFirstTraversal(InOrder(v));
//t.DepthFirstTraversal(PostOrder(v));
