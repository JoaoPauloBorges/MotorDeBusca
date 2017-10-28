#ifndef RESULTADOPESQ_H
#define RESULTADOPESQ_H
#include <QString>
namespace ED2 {

class ResultadoPesq
{
private:
    QString arquivo;
public:
    double calculorelevancia;
    ResultadoPesq();
    ResultadoPesq(QString arquivo,double calculorelevancia);
    QString getArquivo() const{return arquivo;}
    void setArquivo(const QString &value){arquivo = value;}
    double getCalculorelevancia() const{ return calculorelevancia;}
    void setCalculorelevancia(double value){calculorelevancia = value;}
    bool operator ==(ResultadoPesq objeto);
    bool operator !=(ResultadoPesq objeto);
    void operator =(ResultadoPesq objeto);
    bool operator >(ResultadoPesq objeto);
    bool operator <(ResultadoPesq objeto);
    bool operator >=(ResultadoPesq objeto);
    bool operator <=(ResultadoPesq objeto);

};

}//fim namespace

#endif // RESULTADOPESQ_H
