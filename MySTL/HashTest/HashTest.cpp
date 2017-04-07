//
// Created by ggggg on 2017/4/7.
//

#include "../HashTable.h"
#include "../Association.h"
#include <iostream>
#include <string>
using namespace std;

class Counter : public Int{
public:
    Counter(int i) : Int(i){}
    void operator ++(){
        datum++;
    }
};

void CountWords(HashTable& table){
    std::string word;
    while(cin >> word, !cin.eof()){
        Object& obj = table.Find(Association(*new String(word)));
        if(obj.IsNull())
            table.Insert(*new Association(*new String(word), *new Counter(1)));
        else{
            Association& assoc = dynamic_cast<Association&> (obj);
            Counter& i = dynamic_cast<Counter&>(assoc.Value());
            i++;
        }
    }
    cout << table << endl;
}