#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    lineEdit(true),
    TabelaHash(NULL),
    NarqLidos(0)
{
    ui->setupUi(this);
    QPixmap fundo("C:/Users/joaop/Desktop/Computer Science/ED2/MotorDeBusca/yago.jpg");
    ui->label_Fundo->setPixmap(fundo);
    ui->pushButton_pesquisar->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    try{
        ui->actionAbrir->setEnabled(false);
        QString nomeNoDisco = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(nomeNoDisco.isEmpty()) throw QString("Arquivo nao foi selecionado");

        ED2::Persistencia teste(nomeNoDisco);
        ED2::DadosPersistidos *aux = teste.carregar_dados();
        TabelaHash = aux->getTabelaHash();
        NarqLidos = aux->getNarquivosLidos();

        ui->label_pageIndex->setText(QString::number(NarqLidos));
        ui->pushButton_pesquisar->setEnabled(true);

    }catch(QString &erro){QMessageBox::information(this,"ERRO",erro);}
}

void MainWindow::on_pushButton_pesquisar_clicked()
{
    try{
        QString lido = ui->lineEdit_pesquisa->text().toUpper();

        QStringList palavras = lido.split(" ");
       for(int i=0;i<palavras.size();i++){//limpar espaços
            QString temp = palavras[i];
            if(!((temp[0]>=65&&temp[0]<=90)&&temp.size()>=3)){
                palavras.removeAt(i);
            i--;}
        }

        ED1::LDEC<ED2::Palavra*> *wordsFound = this->existePalavras(palavras);
        if(wordsFound->empty())throw QString("Não existem resultados para a busca");

        if(ui->comboBox_tipo_pesquisa->currentText()=="And"){
            if(palavras.size()!=wordsFound->max_size()) throw QString("Não existem resultados para a busca");
            this->resultadoAnd(wordsFound);}
        else
            this->resultadoOr(wordsFound);
    }catch(QString &erro){QMessageBox::information(this,"ERRO",erro);}
}

void MainWindow::on_lineEdit_pesquisa_cursorPositionChanged()
{
    if(lineEdit)
        ui->lineEdit_pesquisa->clear();
    lineEdit=false;
}

ED1::LDEC<ED2::Palavra*>*MainWindow::existePalavras(QStringList lista)
{
    ED1::LDEC<ED2::Palavra*> *PalavrasAchadas = new ED1::LDEC<ED2::Palavra*>;

    for(int i = 0;i<lista.size();i++)
    {
        if(TabelaHash->existe(lista[i]))
        {
            PalavrasAchadas->insert_Back(TabelaHash->get(lista[i]));
        }
    }

    return PalavrasAchadas;
}

void MainWindow::resultadoAnd(ED1::LDEC<ED2::Palavra*> *wordsFound)
{
    try{
        ED1::LDEC<ED2::ResultadoPesq> *listaSaida = new ED1::LDEC<ED2::ResultadoPesq>;
        int F,D,Q,tamAux=0,tam = wordsFound->pos_Access(1)->getTamArray();

        for(int i=0;i<tam;i++)//coloca a primeira coleção de arquivos pra listaSaida
        {   QString nome = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPont_TipoArquivo()->getNome_do_arquivo();
            F = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPalavraRepeticao();
            D = wordsFound->pos_Access(1)->getArray()->return_used();
            Q = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPont_TipoArquivo()->getQtdPal_Dif();
            ED2::ResultadoPesq Arq(nome,(F*std::log10(double(NarqLidos)))/double(D*Q));
            listaSaida->insert_Back(Arq);
        }//fim cópia

        tam = wordsFound->max_size();
        for(int i = 2;i<=tam;i++)
        {   tamAux = wordsFound->pos_Access(i)->getTamArray();
            ED1::LDEC<ED2::ResultadoPesq> listaArq;

            for(int j=0;j<tamAux;j++)//prencher lista de arquivos da palavra "I"
            {   ED2::ResultadoPesq Arq(wordsFound->pos_Access(i)->getArray()->get_data(j)->getPont_TipoArquivo()->getNome_do_arquivo(),0);
                listaArq.insert_Back(Arq);
            }

            for(int k=1;k<=listaSaida->max_size();k++)//correr lista saida
            {   int pos = listaArq.search(listaSaida->pos_Access(k));
                if(!pos)//caso nao exista na lista da palavra "i"
                {   listaSaida->remove_Middle(k);
                    k--;
                }else{//arrayList começa em 0, LDEC começa em 1, por isso Pos -1;
                    F = wordsFound->pos_Access(i)->getArray()->get_data(pos-1)->getPalavraRepeticao();
                    D = wordsFound->pos_Access(i)->getArray()->return_used();
                    Q = wordsFound->pos_Access(i)->getArray()->get_data(pos-1)->getPont_TipoArquivo()->getQtdPal_Dif();
                    ED2::ResultadoPesq Arq(listaSaida->pos_Access(k).getArquivo(),listaSaida->pos_Access(k).calculorelevancia+((F*std::log10(double(NarqLidos)))/double(D*Q)));
                    listaSaida->remove_Middle(k);
                    if(k<=listaSaida->max_size())
                    listaSaida->insert_Middle(Arq,k);
                    else
                        listaSaida->insert_Back(Arq);
                }
            }
        }
        if(!listaSaida->max_size()) throw QString("Sua busca não retornou dados nessa\nnessa modalidade de pesquisa");
        this->ordenaSaidaImprime(listaSaida);
    }catch(QString &erro){QMessageBox::information(this,"ERRO",erro);}
}

void MainWindow::resultadoOr(ED1::LDEC<ED2::Palavra *> *wordsFound)
{
    try{
        ED1::LDEC<ED2::ResultadoPesq> *listaSaida = new ED1::LDEC<ED2::ResultadoPesq>;
        int F,D,Q,tamAux=0,tam = wordsFound->pos_Access(1)->getTamArray();

        for(int i=0;i<tam;i++)//coloca a primeira coleção de arquivos pra listaSaida
        {   QString nome = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPont_TipoArquivo()->getNome_do_arquivo();
            F = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPalavraRepeticao();
            D = wordsFound->pos_Access(1)->getArray()->return_used();
            Q = wordsFound->pos_Access(1)->getArray()->get_data(i)->getPont_TipoArquivo()->getQtdPal_Dif();
            ED2::ResultadoPesq Arq(nome,(F*std::log10(double(NarqLidos)))/double(D*Q));
            listaSaida->insert_Back(Arq);
        }//fim cópia

        tam = wordsFound->max_size();
        for(int i = 2;i<=tam;i++)
        {   tamAux = wordsFound->pos_Access(i)->getTamArray();
            for(int j=0;j<tamAux;j++)//carrega arquivos da palavra "I"
            {   ED2::ResultadoPesq Arq;
                Arq.setArquivo(wordsFound->pos_Access(i)->getArray()->get_data(j)->getPont_TipoArquivo()->getNome_do_arquivo());
                F = wordsFound->pos_Access(i)->getArray()->get_data(j)->getPalavraRepeticao();
                D = wordsFound->pos_Access(i)->getArray()->return_used();
                Q = wordsFound->pos_Access(i)->getArray()->get_data(j)->getPont_TipoArquivo()->getQtdPal_Dif();
                int pos = listaSaida->search(Arq);
                if(pos){
                    Arq.calculorelevancia=listaSaida->pos_Access(pos).calculorelevancia + ((F*std::log10(double(NarqLidos)))/double(D*Q));
                    listaSaida->remove_Middle(pos);
                    listaSaida->insert_Back(Arq);}
                else{
                    Arq.setCalculorelevancia((F*std::log10(double(NarqLidos)))/double(D*Q));
                    listaSaida->insert_Back(Arq);}
            }
        }
        this->ordenaSaidaImprime(listaSaida);
    }catch(QString &erro){QMessageBox::information(this,"ERRO",erro);}
}

void MainWindow::ordenaSaidaImprime(ED1::LDEC<ED2::ResultadoPesq> *listaSaida)
{
    QString saida;
    int tam = listaSaida->max_size();
    ED2::ResultadoPesq vetor[tam];
    for (int i = 1; i <=tam;i++){
        vetor[i-1].setArquivo(listaSaida->pos_Access(1).getArquivo());
        vetor[i-1].calculorelevancia=listaSaida->pos_Access(1).calculorelevancia;
        listaSaida->remove_Front();
    }

    ED2::MergeSort<ED2::ResultadoPesq>(vetor,0,tam-1);

    for (int i =tam-1; i >=0 ;i--)
    {saida+= vetor[i].getArquivo()+"  Relevancia["+QString::number(vetor[i].calculorelevancia)+"]\n";}
    ui->textEdit->setText(saida);

}
