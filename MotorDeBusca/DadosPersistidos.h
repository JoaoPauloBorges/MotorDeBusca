#ifndef DADOSPERSISTIDOS_H
#define DADOSPERSISTIDOS_H
#include <HashTable.h>
#include <Palavra.h>

namespace ED2 {

class DadosPersistidos
{
private:
    HashTable<QString,Palavra*> *TabelaHash;
    int NarquivosLidos;
public:
    DadosPersistidos(HashTable<QString,Palavra*>* TabelaHash, int NarquivosLidos):TabelaHash(TabelaHash),NarquivosLidos(NarquivosLidos){}
    HashTable<QString, Palavra *> *getTabelaHash() const{ return TabelaHash;}
    int getNarquivosLidos() const{ return NarquivosLidos;}
};
}//fim namespace

#endif // DADOSPERSISTIDOS_H
