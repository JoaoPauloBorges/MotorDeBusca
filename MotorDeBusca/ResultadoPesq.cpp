#include "ResultadoPesq.h"

namespace ED2 {
ResultadoPesq::ResultadoPesq():
    arquivo(""),
    calculorelevancia(0)
{
    
}

ResultadoPesq::ResultadoPesq(QString arquivo, double calculorelevancia):
    arquivo(arquivo),
    calculorelevancia(calculorelevancia)
{

}

bool ResultadoPesq::operator ==(ResultadoPesq objeto)
{
    if(this->getArquivo()==objeto.getArquivo())
        return true;
    return false;
}

bool ResultadoPesq::operator !=(ResultadoPesq objeto)
{
    if(!(this->getArquivo()==objeto.getArquivo()))
        return true;
    return false;
}

void ResultadoPesq::operator =(ResultadoPesq objeto)
{
    this->arquivo = objeto.arquivo;
    this->calculorelevancia = objeto.calculorelevancia;
}

bool ResultadoPesq::operator >(ResultadoPesq objeto)
{
    if(this->calculorelevancia>objeto.calculorelevancia)
        return true;
    return false;
}

bool ResultadoPesq::operator <(ResultadoPesq objeto)
{
    if(!(this->calculorelevancia>objeto.calculorelevancia))
        return true;
    return false;
}

bool ResultadoPesq::operator >=(ResultadoPesq objeto)
{
    if(this->calculorelevancia>=objeto.calculorelevancia)
        return true;
    return false;

}

bool ResultadoPesq::operator <=(ResultadoPesq objeto)
{
    if(this->calculorelevancia<=objeto.calculorelevancia)
        return true;
    return false;

}

}//fm namespace
