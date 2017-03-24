//
// Created by ggggg on 2017/3/23.
//

#ifndef C_TEST_OBJECT_H
#define C_TEST_OBJECT_H



class Object {
protected:
    virtual int CompareTo(Object const&) const = 0;
public:
    virtual ~Object();
    virtual bool IsNull() const;
    virtual int Compare(Object const&) const;
    virtual HashValue Hash() const = 0;
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
};


#endif //C_TEST_OBJECT_H
