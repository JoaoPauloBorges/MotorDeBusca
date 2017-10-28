#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <Entry.h>

namespace ED2 {
template <class TypeKey, class TypeValue>
class HashTable
{
    int tamVetor;
    int uso;
    Entry<TypeKey,TypeValue>* *VetHash;
    int funcHash1(TypeKey Key);
    int funcHash2(TypeKey Key);

public:
    HashTable();
    HashTable(int tamanhoVetor);

    void put(TypeKey key,TypeValue value);
    TypeValue get(TypeKey key);
    bool existe(TypeKey key);
    void keys();//retorna a coleção de chaves existentes;
    int size(){return uso;}

};//fim head classe


//Construtor 1
template <class TypeKey, class TypeValue>
HashTable<TypeKey,TypeValue>::HashTable():
    tamVetor(300),//tamanho 300 se usar construtor default
    uso(0)
{
    VetHash = new Entry<TypeKey,TypeValue>*[tamVetor];
    for(int i =0;i<tamVetor;i++)
        VetHash[i]=NULL;
}



//Construtor 2
template <class TypeKey, class TypeValue>
HashTable<TypeKey,TypeValue>::HashTable(int tamanhoVetor):
    uso(0)
{
    if(tamanhoVetor<8) throw QString("Tamanho mínimo para o vetor hash é de 8 posições!");
    tamVetor=tamanhoVetor;
    VetHash = new Entry<TypeKey,TypeValue>*[tamVetor];
    for(int i =0;i<tamVetor;i++)
        VetHash[i]=NULL;
}

//função hash 1
template <class TypeKey, class TypeValue>
int HashTable<TypeKey,TypeValue>::funcHash1(TypeKey Key)
{
    int tam = Key.size(), soma =0;
    //pega valor em inteiro
    for(int i=0;i<tam;i++)
    {
        soma += Key[i].toLatin1();
    }

    //soma possui valor em inteiro


    return std::abs(soma%tamVetor);
}


//função hash 2
template <class TypeKey, class TypeValue>
int HashTable<TypeKey,TypeValue>::funcHash2(TypeKey Key)
{
    int tam = Key.size(), soma =0;
    //pega valor em inteiro
    for(int i=0;i<tam;i++)
    {
        soma += Key[i].toLatin1();
    }

    //soma possui valor em inteiro

    return std::abs(soma%(tamVetor-1));
}

//inserir
template <class TypeKey, class TypeValue>
void HashTable<TypeKey,TypeValue>::put(TypeKey key, TypeValue value)
{
    if(this->size()==this->tamVetor) throw QString ("Hash Lotada, não é possível inserir nova chave");
    if(this->existe(key)) throw QString ("Chave não inserida, já existente na tabela");
    uso++;
    int i=0, pos =0;
    do{
        pos = (this->funcHash1(key) + i*this->funcHash2(key))%tamVetor;
        i++;
    }while(VetHash[pos] != NULL);

    VetHash[pos]=new Entry<TypeKey,TypeValue>(key,value);
}


//Consultar
template <class TypeKey, class TypeValue>
TypeValue HashTable<TypeKey,TypeValue>::get(TypeKey key)
{   
    if(!this->existe(key)) throw QString ("Chave não existente na tabela");
    int i=0,pos=0;
    do{
        pos = (this->funcHash1(key) + i*this->funcHash2(key))%tamVetor;
        i++;
    }while(VetHash[pos]->getKey() != key);

    return VetHash[pos]->getValue();
}

//existe
template <class TypeKey, class TypeValue>
bool HashTable<TypeKey,TypeValue>::existe(TypeKey key)
{
    int i=0, pos =0;
    do{
        pos = (this->funcHash1(key) + i*this->funcHash2(key))%tamVetor;
        if(VetHash[pos] == NULL)return false;//primeiro tem que ver se é NULL
        if(VetHash[pos]->getKey() == key) return true;
        if(i==tamVetor+1) return false;
        i++;
    }while(1);
}



}//fim namespace
#endif // HASHTABLE_H
