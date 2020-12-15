/*PILHAS
    -sequência de elem do mesmo tipo, como as 'listas' e 'filas'
    -seus elem possuem estrutura interna abstratata, ouseja, sua complexidade
        é arbitrária e não afeta o seu funcionamento
    -Acesso(inserir e remover) sempre pelo TOPO DA PILHA
APLICAÇÕES:
-análise de uma expressõa matemática
-avalização de expressao pós-fixa
-converter uma expressão in-fx para pós-fixa
-converter um numero decimal para binário...
==========ALOCAÇÃO ESTÁTICA=====================
-Espaço de memória é alocada no momento da compilação 
-Exige a definiçõa do num MAX de elemntos da plha
-Acesso sequencial : elm consecutivos na memória
===========ALOCAÇÃO DINÂMICA-===================
-O espaço de mem é alocado em tempo de execução 
-A pilha cresce à medida q novos elem são armazenados, e diminui à medida que elem são removios
-Acesso encadeado: cada elm pode estar em uma área distinta da memória.ara acessar um elem é necessario percorrer TODOS os seus antecessore na pilha
*/
#include<stdio.h>
#include<stdlib.h>
#include"pilha01.h"

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha *criaPilha()
{
    Pilha *p= (Pilha *)malloc(sizeof(struct pilha));// strut pilha é a quant de elemntos e o vetor
    if(p != NULL)//Verifica se a alocação funcionou
        p->qtd = 0;//inicializa a quant de elem da pilha
    return p;
}

void liberaPilha(Pilha *p)
{
    free(p);
}

int tamanhoPilha(Pilha *p)
{
    if(p == NULL)//Verifica se ocorreu erro na alocação
        return -1;
    else
        return p->qtd;       
}

int pilhaCheia(Pilha *p)
{
    if(p == NULL)//Verifica se teve erro na alocação/ criação da pilha
        return -1;
    return(p->qtd == MAX);//se qtd for = a MAX vai retornar 1 senão retorna 0
}

int pilhaVazia(Pilha *p)
{
    if(p == NULL)
        return -1;
    return (p->qtd == 0);
}

int insere (Pilha *p, struct aluno al)
{
    if(p == NULL)
        return 0;
    if(pilhaCheia(p))//não pode inserir em uma pilha cheia
        return 0;
    p->dados[p->qtd] = al;//copia os dados da struct na posição valida
    p->qtd++;//atualiza a qtd
    return 1;
}

int remove(Pilha *p)
{
    if(p == NULL || p->qtd == 0)
        return 0;
    p->qtd--;//ele simplesmente remove , não te da o valor do elem
    return 1;
}

int consulta(Pilha *p, struct aluno *al)//SEMPRE NO NICIO DA PILHA
{
    if(p == NULL || p->qtd == 0)
        return 0;
    *al = p->dados[p->qtd-1];//qtd-1 eh o ult elem inserido
    return 1;
}

int main()
{
    Pilha *p;

    p = criaPilha();
    liberaPilha(p);
    int x = tamanhoPilha(p);
    int x = pilhaCheia(p);
    int x = pilhaVazia(p); 
    //int x = insere(p, dados_alunos);
    int x = remove(p);
    //int x = consulta(p, &dados_aluno);
   return 0;
}