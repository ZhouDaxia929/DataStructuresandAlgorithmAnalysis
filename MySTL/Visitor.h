//
// Created by ggggg on 2017/3/24.
//

#ifndef C_TEST_VISITOR_H
#define C_TEST_VISITOR_H


#include "Object.h"

class Visitor {
public:
    virtual void Visit(Object&) = 0;
    /**
     * 用来确定访问者是否已完成工作的存取器。
     * 意义：有时一个访问者不必访问容器中的所有对象。也就是说，在某些情况下，访问者仅需访问一部分对象就可完成任务。
     * IsDone成员函数被容器用来终止Accept函数的继续运行。
     * @return
     */
    virtual bool IsDone() const{
        return false;
    }
};


#endif //C_TEST_VISITOR_H

/*
 * 应用举例

void SomeContainer::Accept(Visitor& visitor) const{
    for each Object i in this container{
        if(visitor.IsDone())
            return;
        visitor.Visit(i);
    }
}

class MatchingVisitor : public Visitor{
    Object const& target;
    Object* found;
public:
    MatchingVisitor(Object const& object) : target(object), found(0){}

    void Visit(Object& object){
        if(found == 0 && object == target)
            found = &object;
    }

    bool IsDone(){
        return found != 0;
    }
};

*调用举例
SomeContainer c;
SomeObject x;
MatchingVisitor v(x);
c.Accept(v);
*/
