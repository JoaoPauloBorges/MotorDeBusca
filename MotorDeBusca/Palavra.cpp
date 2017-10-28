#include "Palavra.h"

namespace ED2 {

bool Palavra::buscar(QString nomeDoArquivo)
{
    int pos = array->return_used();
    if(!pos) return false;
    if((*array)[pos-1]->getPont_TipoArquivo()->getNome_do_arquivo() == nomeDoArquivo)
        return true;
    return false;
}


void Palavra::inserir(FileName* arquivo)
{
    if(this->buscar(arquivo->getNome_do_arquivo()))
    {
       int pos = array->return_used()-1;
       (*array)[pos]->PlusPlus_Palav_repeticao();// se já ta lá, só ++ na repetição da palavra
    }
    else
    {
        array->push_back(new RelPalavra_FileName(arquivo));
        arquivo->plusQtdPal_Dif();//++ palavra nova do arquivo
    }

}

}//fim namespace
