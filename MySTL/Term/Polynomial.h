//
// Created by ZhouDaxia on 2017/3/27.
//

#ifndef C_TEST_POLYNOMIAL_H
#define C_TEST_POLYNOMIAL_H


#include "../ListAsLinkedList.h"
#include "Term.h"

class Polynomial : public ListAsLinkedList{
public:
    void Differentiate();
};

class DifferentiationgVisitor : public Visitor{
public:
    void Visit(Object& object){
        Term& term = dynamic_cast<Term&>(object);
        term.Differentiate();
    }
};

void Polynomial::Differentiate() {
    DifferentiationgVisitor visitor;
    Accept(visitor);
    Object& zeroTerm = Find(Term(0, 0));
    if(!zeroTerm.IsNull()){
        Withdraw(zeroTerm);
        delete &zeroTerm;
    }
}


#endif //C_TEST_POLYNOMIAL_H
