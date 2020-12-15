/*Fila é um tipo especial e 'lista'
 INSERÇÕES E EXCLUSÕES de elesmentos ocorrem nas EXTEMIDAES  da 'lista'
 APLICAÇÕES:
 -Controle de Fluxo
 -Recuros compartlhados(impressoras, trasançõess de bancp de dados, etc)
OPREAÇÕES
-inserção de um elem no FINAL
-remoção de um elm no INCIO
-acesso ao elem no INICIO
Parar ACESSAR um elem tem que passar por todos os outrs integrantes da fila
====FILA ESTÁTICA=====
-Sucessor de um elm ocupa a posição física seguinte do mesmo(uso de vetor)
*/
#include<stdio.h>
#include<stdlib.h>
#include"fila01.h"

struct fila{
    int ini, fim, qtd;
    struct aluno dados [MAX];
};

int main()
{
    Fila *f;
    f= criaFila();
    liberaFila(f);
    int x =tamanhoFila(f);
    int x =filaCheia(f);
    int x =filaVazia(f);
    //int x =insere(f, dados_aluno);
    int x = remover(f);
    //int x = consultaFila(f, &dados-aluno);
    return 0;   
}

Fila *criaFila()
{
    Fila *f =(Fila *)malloc(sizeof(struct fila));
    if(f != NULL)//inicializa   ndo a fila
    {
        f->ini = 0;
        f->fim = 0;
        f->qtd = 0;
    }
    return f;
}

void liberaFila(Fila *f)
{
    free(f);
}

int tamanhoFila(Fila *f)
{
    if(f == NULL)//se fila for valida
        return -1;
    return f->qtd;
}

int filaCheia(Fila *f)
{
    if(f == NULL)//Se a fila for valida
        return -1;

    if(f->qtd == MAX)//em relação a tamanho da fila sempre olhar a qtd pq eh mais garantido pois o incio e o fim podem se movimentar
        return 1;
    else
        return 0;
}

int filaVazia(Fila *f)
{
     if(f == NULL)
        return -1;   
    if(f->qtd == 0)
        return 1;
    else
        return 0;  
}

int insere(Fila *f, struct aluno al)//INSERIR SEMPRE NO FINAL & não pode inserir em fila CHEIA
{
    if(f == NULL)//Ero na criação da fila
    return -1;

    if(filaCheia(f))//não pode inserir em fila cheia
    return 0;

    f->dados[f->fim] = al; // final sempre aponta para a posição vaga da fila onde se pode inserir
    f->fim = (f->fim + 1) % MAX;// se chegar no ultimo elemento ele volta para o primeiro elemneto pq MAX % MAX = 0 que a posição do primeiro elemento da fila
    f->qtd++;//atualiza a qtd da fila
    return 1;
}

int remover(Fila *f)//Não se pode remover em uma fila VAZIA
{
    if(f == NULL || filaVazia(f))
        return 0;
    f->ini = (f->ini + 1) % MAX;
    /*f->ini++
      if (f->ini ==  MAX) 
      f->ini=0;*/
    f->qtd--;//atualiza qtd
    return 1;
}
//Só posso consultar o elem que esta no INICIO
int consultaFila(Fila *f, struct aluno *al)
{
    if(f == NULL || filaVazia(f))
        return 0;
    *al = f->dados[f->ini];// recebe os dados da fila que estao no inicio
    return 1;
}
