#ifndef LDEC_H
#define LDEC_H
#include <NodeLDEC.h>

// LISTA DUPLAMENTE ENCADEADA CIRCULAR
namespace ED1 {

template < class tipo>
class LDEC
{
private:
    int size;
    NodeLDEC<tipo> *front;
    NodeLDEC<tipo> *back;

public:
    LDEC();
    ~LDEC();
    int  max_size()const{return size;}
    void insert_Front(tipo element);
    void insert_Back( tipo element);
    void insert_Middle(tipo element, int pos);
    tipo remove_Front();
    tipo remove_Back();
    tipo remove_Middle(int pos);
    QString remove_Data(tipo element);
    int search(tipo element) const;
    tipo pos_Access(int pos) const;
    bool empty() const{ return (!size);}


};//Fim declaração da classe

template < class tipo>
LDEC<tipo>::LDEC():
    size(0),
    front(0),
    back(0)
{

}

template < class tipo>
LDEC<tipo>::~LDEC()
{   if (size){
        this->remove_Front();
    }
}

template < class tipo>
void LDEC<tipo>::insert_Front(tipo element)
{  try{
        if (!size)
        {   front = new NodeLDEC<tipo>(element);
            front->setPostLink(front);
            front->setPreLink(front);
            back=front;
            size++;
        }
        else
        {   front = new NodeLDEC<tipo>(element,front,back);
            front->getPostLink()->setPreLink(front);
            back->setPostLink(front);
            size++;
        }
    }catch(std::bad_alloc){throw QString ("Bad_Alloc");}
}

template < class tipo>
void LDEC<tipo>::insert_Back(tipo element)
{   try{
        if(size == 0) this->insert_Front(element);
        else{
            back->setPostLink(new NodeLDEC<tipo>(element,front,back));
            back=back->getPostLink();
            front->setPreLink(back);
            size++;}
    }catch(std::bad_alloc){throw QString("Bad_Alloc");}

}

template < class tipo>
void LDEC<tipo>::insert_Middle(tipo element, int pos)
{  try{
        if(pos>size) throw QString("Posição não existente na lista (maior que o tamanho atual)");
        if(pos<1) throw QString ("Posição deve ser maior que 0");
        if(pos==1)
            this->insert_Front(element);
            else
            {
                NodeLDEC<tipo> *aux = front;
                for (int i=1; i<pos;i++)
                    aux = aux->getPostLink();
                aux->getPreLink()->setPostLink(new NodeLDEC<tipo>(element,aux,aux->getPreLink()));
                aux->setPreLink(aux->getPreLink()->getPostLink());
                size++;
            }

    }catch(std::bad_alloc){throw QString ("Bad_Alloc");}
}

template < class tipo>
tipo LDEC<tipo>::remove_Front()
{   if (!size) throw QString ("lista vazia");
    tipo output = front->getData();
    if (size == 1)
    {   delete front;
        front=0;
        back=0;
        size=0;
    }
    else{
        front = front->getPostLink();
        delete front->getPreLink();
        front->setPreLink(back);
        back->setPostLink(front);
        size--;
    }
    return output;
}

template < class tipo>
tipo LDEC<tipo>::remove_Back()
{
    if (!size) throw QString ("lista vazia");
    tipo output;
    if(size == 1)
        output = remove_Front();
    else{
        output = back->getData();
        back->getPreLink()->setPostLink(front);
        front->setPreLink(back->getPreLink());
        delete back;
        back=front->getPreLink();
        size--;
        }
        return output;
}

template < class tipo>
tipo LDEC<tipo>::remove_Middle(int pos)
{   if (!size) throw QString ("lista vazia");
    if(pos<1) throw QString ("Posição deve ser maior que 0");
    if (pos > size) throw QString ("Posição não existente na lista (maior que o tamanho atual)");
    tipo output;
    if(pos == 1) this->remove_Front();
    else{
        if(pos == size) this->remove_Back();
        else{
            NodeLDEC<tipo> *aux = front;
            for (int i=1; i<pos;i++)
                aux = aux->getPostLink();
            output = aux->getData();
            aux->getPreLink()->setPostLink(aux->getPostLink());
            aux->getPostLink()->setPreLink(aux->getPreLink());
            size--;
            delete aux;
        }
    }
    return output;
}

template < class tipo>
QString LDEC<tipo>::remove_Data(tipo element)
{   if (!size) throw QString ("lista vazia");
    QString output = search(element);
    if(size==1 && front->getData()==element)
    remove_Front();
    else{
    NodeLDEC<tipo> *aux = front->getPostLink(),*aux2=0;
    while(aux->getPostLink()!=front)
    {
        if (aux->getData() == element)
        {   aux->getPreLink()->setPostLink(aux->getPostLink());
            aux->getPostLink()->setPreLink(aux->getPreLink());
            size--;
            aux2=aux;
            aux=aux->getPostLink();
            delete aux2;
        }
        else
            aux=aux->getPostLink();
    }
    if(front->getData()==element) remove_Front();
    if(back->getData()==element) remove_Back();
    }
    return output;
}
template < class tipo>
int LDEC<tipo>::search(tipo element) const
{     NodeLDEC<tipo> *aux = front;
      for (int i=1; i<=size;i++)
      {   if (aux->getData()== element)
              return i;
          aux = aux->getPostLink();
      }
     return 0;
}

template < class tipo>
tipo LDEC<tipo>::pos_Access(int pos) const
{
    if(pos<1) throw QString ("Posição deve ser maior que 0");
    if (pos>size) throw QString ("posição fora do intervalo de uso");
    NodeLDEC<tipo> *aux = front;
    for (int i=1; i<pos;i++)
        aux = aux->getPostLink();
    return aux->getData();
}

}//fim namespace
#endif // LDEC_H
