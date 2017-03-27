//
// Created by ZhouDaxia on 2017/3/27.
//

#ifndef C_TEST_TERM_H
#define C_TEST_TERM_H


#include "../Object.h"

class Term : public Object{
    double coefficient;
    unsigned int exponent;
public:
    Term(double, unsigned int);
    //...
    int CompareTo(Object const&) const;
    void Differentiate();
};

Term::Term(double _coefficient, unsigned int _exponent) : coefficient(_coefficient), exponent(_exponent) {}

int Term::CompareTo(Object const& object) const {
    Term const& term = dynamic_cast<Term const&> (object);
    if(exponent == term.exponent)
        return Object::Compare(coefficient, term.coefficient);
    else
        return exponent - term.exponent;
}

void Term::Differentiate() {
    if(exponent > 0){
        coefficient *= exponent;
        exponent -= 1;
    }
    else
        coefficient = 0;
}


#endif //C_TEST_TERM_H
