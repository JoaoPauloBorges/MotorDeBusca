#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Persistencia.h>
#include <QFileDialog>
#include <QMessageBox>
#include <LDEC.h>
#include <DadosPersistidos.h>
#include <ResultadoPesq.h>
#include <cmath>
#include <Merge_Sort.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_pushButton_pesquisar_clicked();

    void on_lineEdit_pesquisa_cursorPositionChanged();

    ED1::LDEC<ED2::Palavra*> *existePalavras(QStringList lista);

    void resultadoAnd(ED1::LDEC<ED2::Palavra*> *wordsFound);

    void resultadoOr(ED1::LDEC<ED2::Palavra*> *wordsFound);

    void ordenaSaidaImprime(ED1::LDEC<ED2::ResultadoPesq> *listaSaida);


private:
    Ui::MainWindow *ui;
    bool lineEdit;
    ED2::HashTable<QString,ED2::Palavra*> *TabelaHash;
    int NarqLidos;
};

#endif // MAINWINDOW_H
