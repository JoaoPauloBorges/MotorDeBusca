#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include<fstream>
#include<QString>
#include<HashTable.h>
#include<FileName.h>
#include<Palavra.h>
#include<StackDin.h>
#include<QStringList>
#include<DadosPersistidos.h>

namespace ED2 {
class Persistencia{
private:
    QString nome_no_disco;

    ED1::StackDin<QString> *SubPersistencia(QString nome_no_disco) const;

public:
    DadosPersistidos *carregar_dados() const;
    Persistencia(QString nome_no_disco):nome_no_disco(nome_no_disco){}

};
}//fim namespace

#endif // PERSISTENCIA_H
