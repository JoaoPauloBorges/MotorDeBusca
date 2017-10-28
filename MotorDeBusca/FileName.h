#ifndef FILENAME_H
#define FILENAME_H
#include<QString>

namespace ED2 {
class FileName
{
    QString nome_do_arquivo;
    int QtdPal_Dif;
public:
    FileName();
    FileName(QString nome_do_arquivo);
    QString getNome_do_arquivo() const{return nome_do_arquivo;}
    void setNome_do_arquivo(const QString nome_do_arquivo){this->nome_do_arquivo=nome_do_arquivo;}
    int getQtdPal_Dif() const{return QtdPal_Dif;}
    void plusQtdPal_Dif(){this->QtdPal_Dif++;}
    bool operator ==(FileName &objeto) const;
    bool operator !=(FileName &objeto) const;

};

}// fim namespace

#endif // FILENAME_H
