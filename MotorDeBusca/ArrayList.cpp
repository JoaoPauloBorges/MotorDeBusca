/*#include "ArrayList.h"

namespace TP2 {


ArrayList::ArrayList():
    used(0),
    size(0),
    array(0)
{   
    try{
        array = new int[5];
        this->size = 5;
    }catch(std::bad_alloc){throw QString("Bad_Alloc");}
}

ArrayList::ArrayList(int size):
    used(0),
    size(0),
    array(0)
{
    try{
        if (size <1) throw QString("Tamanho deve ser postivo");
        array = new int[size];
        this->size = size;
    }catch(std::bad_alloc){throw QString ("Bad_Alloc");}
}

void ArrayList::increase_size()
{   if (size>1){
        tipo *aux = new int[int(size+size*0.5)];
        for (int i=0; i < size; i++)
            aux[i]=array[i];
        delete array;
        array = aux;
        size = int(size+size*0.5);
    }else{
        int *aux = new int[5];
        for (int i=0; i < size; i++)
            aux[i]=array[i];
        delete array;
        array = aux;
        size = 5;
    }
}

void ArrayList::push_front(int data)
{
    if (!used){
        array[0]=data;
        used++;
    }else{
        if(used<size){
            for(int i=used;i>0; i--)
                {array[i] = array[i-1];}
            array[0]= data;
            used++;
        }else{
         this->increase_size();
         for(int i=used ;i>0; i--)
             {array[i] = array[i-1];}
         array[0]= data;
         used++;

        }
    }
}

void ArrayList::push_back(int data)
{
    if (!used){
        array[0]=data;
        used++;
    }else{
        if (used<size){
            array[used] = data;
            used++;
        }else{
            this->increase_size();
            array[used] = data;
            used++;
        }
    }

}

void ArrayList::push_middle(int pos, int data)
{
    if (pos<1) throw QString("Posição deve ser positiva");
    if (pos-1>used) throw QString("Não é posível realizar inserção deixando lacunas entre elementos");
    if (pos==1) this->push_front(data);
    else{
        if (pos-1==used) this->push_back(data);
        else{
         if (used==size) this->increase_size();
         for(int i=used;i>pos-1; i--)
             {array[i] = array[i-1];}
         array[pos-1]= data;
         used++;
        }
    }
}

void ArrayList::operator [](int pos)
{
 int aux = this->get_data(pos);
 return aux;
}

QString ArrayList::search_data( int data ) const
{
    if (!used) return QString("Não existem informações na lista");
    QString output="";
    for (int i =0; i < used; i++){
        if (array[i] == data){
        output += QString::number(i+1)+ "  ";
        }
    }
    return output;
}

int ArrayList::get_data(int pos) const
{
    if(pos<1) throw QString("Posição deve ser positiva");
    if(pos>used) throw QString("Posição não criada e/ou não contem informação");
    return array[pos-1];
}

int ArrayList::remove_pos( int pos)
{
    if(pos<1) throw QString("Posição deve ser positiva");
    if(pos>used) throw QString("Posição não criada e/ou não contem informação");
    int aux = array[pos-1];
    for(int i=pos-1;i<used; i++)
        {array[i] = array[i+1];}
    used--;
    return aux;
}

QString ArrayList::remove_data(int data)
{   QString output = this->search_data(data);
    for (int i =0; i < used; i++){
        if (array[i] == data){
            this->remove_pos(i+1);
            i--;
        }
    }
    return output;
}

int ArrayList::replace_by_position(int pos, int data)
{
    if(pos<1) throw QString("Posição deve ser positiva");
    if(pos>used) throw QString("Posição não criada e/ou não contem informação");
    int aux = array[pos-1];
    array[pos-1] = data;
    return aux;
}




QString ArrayList::get_list() const
{   if (!used) throw QString ("Não é possível retornar a lista, não possui elementos ainda");
    QString output="";
    for (int i=0; i<used;i++)
        output+= QString::number(array[i])+'\t';

    return output ;
}

}//fim namespace
*/
