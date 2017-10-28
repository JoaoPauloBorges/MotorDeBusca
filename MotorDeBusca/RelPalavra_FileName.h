#ifndef RELPALAVRA_FILENAME_H
#define RELPALAVRA_FILENAME_H
#include <FileName.h>

namespace ED2 {

class RelPalavra_FileName
{
private:
    FileName* Pont_TipoArquivo;
    int PalavraRepeticao;
public:
    RelPalavra_FileName():Pont_TipoArquivo(NULL),PalavraRepeticao(0){}
    RelPalavra_FileName(FileName* Pont_TipoArquivo):Pont_TipoArquivo(Pont_TipoArquivo), PalavraRepeticao(1){}
    FileName* getPont_TipoArquivo() const {return Pont_TipoArquivo;}
    void setPont_TipoArquivo(FileName *Pont_TipoArquivo){this->Pont_TipoArquivo = Pont_TipoArquivo;}
    int getPalavraRepeticao() const{return PalavraRepeticao;}
    void PlusPlus_Palav_repeticao() {PalavraRepeticao++;}
};

}//fim namespace

#endif // RELPALAVRA_FILENAME_H
