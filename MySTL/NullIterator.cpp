//
// Created by ggggg on 2017/3/24.
//

#include "NullIterator.h"
#include "NullObject.h"

NullIterator::NullIterator() {}
void NullIterator::Reset() {}
bool NullIterator::IsDone() const {
    return true;
}
Object& NullIterator::operator* () const {
    return NullObject::Instance();
}
void NullIterator::operator++() {}