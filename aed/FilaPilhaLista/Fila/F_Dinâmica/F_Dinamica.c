/*Cada elemnto aponta para oseu sucessor na fila 
Usa um 'nó descritor' parar respresentar o inicio e dinal da fila e uma indicaçao de final de fila*/
#include<stdio.h>
#include<stdlib.h>
#include"F_Dinâmica.h"

struct fila{
    struct elemento *ini;
    struct elemento *fim;
};
struct elemento{
    struct aluno dados;
    struct elemento *prox;// proximo elemnto da fila
};//tipo de dado que representa um elemento/nó da fila
typedef struct elemento Elem;

Fila *criaFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));// cabeça da fila
    if(f != NULL)
    {
        f->fim = NULL;
        f->ini = NULL;
    }
}

void liberaFila (Fila *f)
{
    if(f != NULL)
    {
        Elem *no;//aux
        while(f->ini != NULL)
        {
            no = f->ini;
            f->ini = f->ini->prox;//inicio recebe o proximo elemnto
            free(no);// libera o inicio anterior
        }//vai liberando os elemntos ate o no ser = a NULL
        free(f);//libera a cabeça da fila
    }
}

int tamanhoFila(Fila *f)
{
    if(f == NULL)// se for null deu problema na criaçao da fila
        return 0;
    
    int cont = 0;// contar quantas variaveis tem na fila
    Elem *no = f->ini;
        
    while(no != NULL)
    {
        cont++;
        no = no->prox;//anda pro proximo el ate chegar no null
    }
     return cont;
}

int filaCheia(Fila *f)
{
    return 0; // como eh feita com alocação dinâmica a fila so vai ficar cheia quando não tiver mais memória disponivel
}

int filaVazia(Fila *f)
{
    if(f == NULL)//Problema na alocação da fila (vazia)
        return 1;
    if(f->ini == NULL)//Valor da cabeça da fila NULL fila vazia não tem elemntos conectados
        return 1;
    return 0;//Fila nao esta vazia
}

int inserir (Fila *f, struct aluno al)//Pode fazer inserção em uma fila vazia, Mas não pode fazer em uma fila CHEIA
{
    if(f == NULL)
        return 0;
    
    Elem *no = (Elem *)malloc(sizeof(Elem));//alocando espaço para o novo elemnto da fila
    if(no != NULL)
        return 0;
    
    no->dados = al;//copia dados da struct
    no->prox = NULL;

    if(f->fim == NULL)//se for ele eh uma fila vazia
        f->ini = no;
    else
        f->fim->prox = no;//inserindo no fnal da fila
    f->fim = no;
    return 1;
}

int remover(Fila *f)
{
    if(f == NULL)
    return 0;

    if(f->ini == NULL)//FILA VAZIA
        return 0;
    
    Elem *no = f->ini;
    f->ini = f->ini->prox;//passa a apontar para o proximo elemnto da fila

    if(f->ini == NULL)//fila ficou vazia
        f->fim = NULL;
    free(no);//libera o elemnto que estava no inicio da fila
    return 1;
}

int consulta(Fila *f, struct aluno *al)
{
    if(f == NULL)//ERRO na alocação
        return 0;
    if(f->ini == NULL)//fila Vazia
        return 0;
    *al =f->ini->dados;
    return 1;
}
int main()
{
    Fila *f;

    f = craFila(); 
    liberaFila(f);
    int x = tamanhoFila(f);
    int x = filaCheia(f);
    int x = filaVazia(f);
    int x = remover(f);
    //int x = insere(f, dados_aluno);
    //int x = consulta(f, &dados_aluno);
    return 0;
}