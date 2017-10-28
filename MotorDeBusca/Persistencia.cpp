#include "Persistencia.h"

namespace ED2 {

ED1::StackDin<QString> *Persistencia::SubPersistencia(QString nome2) const
{
    try{
        std::ifstream arquivo;
        arquivo.open(nome2.toStdString().c_str());
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser aberto | nome do arquivo: "+nome2); }
        std::string linha;
        QString Qlinha;
        ED1::StackDin<QString> *Pilha_De_Palavras = new ED1::StackDin<QString>;

        while(!arquivo.eof())
        {   std::getline(arquivo,linha);
            Qlinha = QString::fromStdString(linha);

            QRegExp rx("(\\ |\\,|\\.|\\?|\\!|\\;|\\:|\\t|\\-|\\, )"); //RegEx for ' ' or ',' or '.' or ':' or '\t' or '-'
            QStringList listaPalavras = Qlinha.split(rx);

            while(!listaPalavras.isEmpty()){
                QString palavra = listaPalavras.front();
                palavra = palavra.toUpper();
                listaPalavras.pop_front();
                if((palavra[0]>=65&&palavra[0]<=90)&&palavra.size()>=3)
                Pilha_De_Palavras->push(palavra);
            }

        }

        // fechando o arquivo de entrada
        arquivo.close();

        return Pilha_De_Palavras;
    }catch(std::bad_alloc&){ throw QString("Bad_Alloc");}
    catch(QString &erro){ throw erro;}
}

DadosPersistidos *Persistencia::carregar_dados() const
{  try{
    std::ifstream arquivo;
    arquivo.open(nome_no_disco.toStdString().c_str());
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto"); }
    std::string linha;

    QRegExp rx("(\\/)");//bloco para pegar o diretorio dos arquivos
    QStringList listaNomeEnd = nome_no_disco.split(rx);
    QString complementoNomeDisco;
    listaNomeEnd.pop_back();//tira o nome do arquivo e deixa so o diretorio
    while (!listaNomeEnd.empty()){
        complementoNomeDisco+=listaNomeEnd.front()+"/";//monta o nome
    listaNomeEnd.pop_front();
    }//complementoNomeDisco tem o diretório dos arquivos


    ED1::StackDin<ED1::StackDin<QString>*> PilhaArquivos;//guardas as palavras dos arquivos
    ED1::StackDin<QString> PilhaNomeDeArquivos;//guarda os nomes dos arquivos
    int NPalavras=0;//número total de palavras

    while(!arquivo.eof())
    {
        std::getline(arquivo,linha);
        QString Qlinha = QString::fromStdString(linha);
        if((Qlinha[0]!=' ')&&Qlinha.size()>=3)
        {PilhaNomeDeArquivos.push(Qlinha);
        PilhaArquivos.push(this->SubPersistencia(complementoNomeDisco+PilhaNomeDeArquivos.top()));
        NPalavras+=PilhaArquivos.top()->getSize();}
    }


    // fechando o arquivo de entrada
    arquivo.close();

    HashTable<QString,Palavra*> *TabelaHash = new HashTable<QString,Palavra*>(NPalavras+200);
    DadosPersistidos *Saida = new DadosPersistidos(TabelaHash,PilhaNomeDeArquivos.getSize());



    while(!PilhaNomeDeArquivos.empty())
    {
        FileName *arquivoLido = new FileName(PilhaNomeDeArquivos.pop());//cria objeto arquivo;
        ED1::StackDin<QString> *pilhaAux = PilhaArquivos.pop();//pilha de palavras desse arquivo;

        while (!pilhaAux->empty())
        {
            QString chave = pilhaAux->pop();
            if(TabelaHash->existe(chave)){//pergunta se chave já existe;
                TabelaHash->get(chave)->inserir(arquivoLido);//se existe, insere arquivo na chave;

            }
            else
            {
                Palavra *word = new Palavra(chave);//Cria objeto palavra;
                word->inserir(arquivoLido);//insere arquivo na lista da palavra;
                TabelaHash->put(chave,word);//insere palavra na hash;
            }

        }//inseriu todas as palavras do n-éssimo arquivo


    }//FIM BLOCO;


    return Saida;

    }catch(std::bad_alloc&){throw QString("Bad_Alloc");}
    catch(QString &erro){throw erro;}
}


}//fim namespace
