#include "FileName.h"
namespace ED2 {
FileName::FileName():
    nome_do_arquivo(""),
    QtdPal_Dif(0)
{

}
FileName::FileName(QString nome_do_arquivo):
    nome_do_arquivo(nome_do_arquivo),
    QtdPal_Dif(0)
{

}

bool FileName::operator ==(FileName &objeto) const
{
    if(this->getNome_do_arquivo()==objeto.getNome_do_arquivo())
        return true;
    return false;

}

bool FileName::operator !=(FileName &objeto) const
{
    if(this->operator ==(objeto))
        return false;
    return true;
}


}// fim namespace
