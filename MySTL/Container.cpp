//
// Created by ggggg on 2017/3/24.
//

#include "Container.h"
#include "Iterator.h"
#include "NullIterator.h"
#include <typeinfo>

Container::Container() : count(0) {}

unsigned int Container::Count() const {
    return count;
}

bool Container::IsEmpty() const {
    return Count() == 0;
}
bool Container::IsFull() const {
    return false;
}



class PuttingVisitor : public Visitor {
    ostream& stream;
    bool comma;
public:
    PuttingVisitor(ostream& s) : stream(s), comma(false){}

    void Visit(Object& object){
        if(comma)
            stream << ", ";
        stream << object;
        comma = true;
    }
};

void Container::Put(ostream& s) const {
    PuttingVisitor visitor(s);
    s << typeid(*this).name() << " {";
    Accept(visitor);
    s << " }";
}

Iterator& Container::NewIterator() const {
    return *new NullIterator();
}

class HashingVisitor : public Visitor{
    unsigned int value;
public:
    HashingVisitor(unsigned int _value) : value(_value){}
    void Visit(Object& object){
        value += object.Hash();
    }
    unsigned int Value() const{
        return value;
    }
};

unsigned int Container::Hash() const {
    HashingVisitor visitor(::Hash(typeid(*this).name()));
    Accept(visitor);
    return visitor.Value();
}