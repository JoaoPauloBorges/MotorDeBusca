#ifndef PALAVRA_H
#define PALAVRA_H
#include <QString>
#include <ArrayList.h>
#include <RelPalavra_FileName.h>

namespace ED2 {
class Palavra
{
private:
    QString palavra;
    TP2::ArrayList<RelPalavra_FileName*> *array;
    bool buscar(QString nomeDoArquivo);
public:
    Palavra():palavra(""){array = new TP2::ArrayList<RelPalavra_FileName*>;}
    Palavra(QString palavra):palavra(palavra){array = new TP2::ArrayList<RelPalavra_FileName*>;}
    void inserir(FileName *arquivo);
    int getTamArray()const {return array->return_used();}
    TP2::ArrayList<RelPalavra_FileName *> *getArray() const{return array;}
    QString getPalavra() const{return palavra;}
};
}//fim namespace

#endif // PALAVRA_H
