#ifndef MERGE_SORT_H
#define MERGE_SORT_H


namespace ED2 {
template <class tipo>
void merge(tipo vetor[], long long inicio, long long meio, long long fim)
{
    tipo *aux1 = new tipo [meio-inicio+1];
    tipo *aux2 = new tipo [fim-meio];

    for(long long j=0,i=inicio; i <= meio; j++,i++) //atribuição de valores vetor auxiliar 1
        aux1[j]=vetor[i];

    for(long long j=0, i=meio+1; i <= fim; j++,i++) //atribuição de valores vetor auxiliar 2
        aux2[j]=vetor[i];

    long long  i=inicio,j=0,k=0; //intercalação
    for( ;i<=fim&&(j<meio-inicio+1)&&(k<fim-meio);i++)
    {
        if(aux1[j]<aux2[k])
            vetor[i]=aux1[j++];
        else
            vetor[i]=aux2[k++];
    }

    if(k==fim-meio){
        for(;i<=fim;i++)
            vetor[i]=aux1[j++];
    }if(j==meio-inicio+1){
        for(;i<=fim;i++)
            vetor[i]=aux2[k++];

    }

}

template <class tipo>
void MergeSort(tipo vetor[], long long inicio, long long fim)
{
    if(inicio<fim)
    {
        long long meio = (inicio+fim)/2;
        MergeSort(vetor,inicio,meio);
        MergeSort(vetor,meio+1,fim);
        merge(vetor,inicio,meio,fim);
    }
}

}//fim namespace

#endif // MERGE_SORT_H
