#ifndef ENTRY_H
#define ENTRY_H
#include<QString>
#include<FileName.h>

namespace ED2 {

template <class tipo1, class tipo2>
class Entry
{
    tipo1 key;
    tipo2 value;

public:
    Entry(){}
    Entry(tipo1 key):key(key){}
    Entry(tipo1 key, tipo2 value):key(key),value(value){}
    QString getKey() const{return key;}
    tipo2 getValue() const {return value;}

};// fim header classe

}//fim namespace

#endif // ENTRY_H
