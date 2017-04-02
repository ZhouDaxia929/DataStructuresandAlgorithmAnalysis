//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_OBJECT_H
#define C_TEST_OBJECT_H

#include <string>


class Object {
    typedef unsigned int HashValue;
protected:
    virtual int CompareTo(Object const&) const = 0;
public:
    virtual ~Object();
    virtual bool IsNull() const;
    virtual int Compare(Object const&) const;

    virtual void Put(ostream&) const = 0;

    inline bool operator == (Object const& left, Object const& right){
        return left.Compare(right) == 0;
    }

    inline bool operator != (Object const& left, Object const& right){
        return left.Compare(right) != 0;
    }

    inline bool operator <= (Object const& left, Object const& right){
        return left.Compare(right) <= 0;
    }

    inline bool operator < (Object const& left, Object const& right){
        return left.Compare(right) < 0;
    }

    inline bool operator >= (Object const& left, Object const& right){
        return left.Compare(right) >= 0;
    }

    inline bool operator > (Object const& left, Object const& right){
        return left.Compare(right) > 0;
    }
    inline ostream& operator << (ostream& s, Object const& object){
        object.Put(s);
        return s;
    }


    virtual HashValue Hash() const = 0;
    HashValue Hash(char c) const;
    HashValue Hash(int i) const;
    HashValue Hash(double d) const;

    unsigned int const shift = 6;
    HashValue const mask = -0U << (sizeof(HashValue) - shift);
    HashValue Hash(std::string const& s){
        HashValue result = 0;
        for(unsigned int i = 0; s[i] != 0; i++)
            result = (result & mask) ^ (result << shift) ^ s[i];
        return result;
    }
};


#endif //C_TEST_OBJECT_H
