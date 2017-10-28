#ifndef STACKDIN_H
#define STACKDIN_H

#include <QString>
#include <NodeStack.h>
namespace ED1 {
template <class tipo>
class StackDin{

    //STACKDIN Pilha dinâmica duplamente encadeada circular,
    //com ponteiro para o primeiro elemento da pilha

private:
    NodeStack<tipo> *linkBegin;//ponteiro para início pilha dinâmica
    int size;


public:
    StackDin();
    ~StackDin();
    void push(tipo data);
    tipo pop();
    int getSize() const{return size;}
    tipo top()const{ return linkBegin->getPreLink()->getData();}//retorna dados do elemento do topo
    bool empty()const;




};// fim declaração de classe


template <class tipo>
StackDin<tipo>::StackDin():
    linkBegin(NULL),
    size(0)
{
}
template <class tipo>
StackDin<tipo>::~StackDin()
{
    while (size) {
        this->pop();
    }
}

template <class tipo>
void StackDin<tipo>::push(tipo data)
{
    try{
    if(!size){
        linkBegin = new NodeStack<tipo>(data,NULL,NULL);
        linkBegin->setPreLink(linkBegin);
        linkBegin->setPostLink(linkBegin);
        size++;
    }else{
        linkBegin->getPreLink()->setPostLink(new NodeStack<tipo>(data,linkBegin->getPreLink(),linkBegin));
        linkBegin->setPreLink(linkBegin->getPreLink()->getPostLink());
        size++;
    }
    }catch(std::bad_alloc){throw QString("Erro de alocação");}
}

template <class tipo>
tipo StackDin<tipo>::pop()
{
    if(!size) throw QString("Pilha Vazia");
    NodeStack<tipo> *aux = linkBegin->getPreLink();
    tipo output = aux->getData();
    if(aux==linkBegin){
        delete linkBegin;
        linkBegin=NULL;
        size=0;
    }else{
    aux->getPreLink()->setPostLink(linkBegin);
    linkBegin->setPreLink(aux->getPreLink());
    delete aux;
    size--;
    }
    return output;

}

template <class tipo>
bool StackDin<tipo>::empty() const
{
    if(!size) return true;
        return false;
}





}//fim namespace
#endif // STACKDIN_H
