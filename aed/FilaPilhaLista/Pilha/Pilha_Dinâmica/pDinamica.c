/*=========Pilha Dinâmica=================
    Tipo de pilha onde cada elem aponta para o seu sucessor n apilha
    usa um pontero para ponteiro para o primeiro elem da pilha e una indicação de final de pilha (NULL)*/
#include<stdio.h>
#include<stdlib.h>
#include"pDinamica.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento E;

Pilha *criaPilha()
{
    Pilha * p = (Pilha *)malloc(sizeof(Pilha));//criado o topo da pilha

    if(p != NULL)//Alocação deu certo
        *p = NULL;
    return p;
}

void liberaPilha(Pilha *p)
{
    if(p != NULL)
        E *no;//ponteiro aux
        while((*p) != NULL)
        {
            no = *p;
            *p = (*p)->prox;//vai para a proxima posição
            free(no);//Liberar a posiçao anterior (antigo topo)
        }
        free(p);//libera o topo da pilha
}

int tamanhoPilha(Pilha *p)
{
    if(p == NULL)
        return 0;
    int cont = 0;//contagem dos elementos
    E *no  = *p; //ponterio aux recebe topo
    
    while(no != NULL)
    {
        cont++;
        no = no->prox;//anda para o proximo elemento da pilha
    }
    return cont;
}

int pilhaCheia(Pilha *p)
{
    return 0; //só ficaria cheia se usar toda a memória do comp
}

int pilhaVazia(Pilha *p)
{
    if(p == NULL)// verifica se tem pilha
        return 1;
    if(*p == NULL)//conteudo do topo da pilha
        return 1;
    return 0;//Tem elementos da pilha
}

int inserir(Pilha *p, struct aluno al)
{
    if(p == NULL)//Verifica se tem pilha
        return 0;
    
    E *no = (E*)malloc(sizeof(E));//aloca um espaço na memoria para o nvo elem da pilha

    if(no != NULL)//Verifica se foi alocado
        return 0;

    no->dados = al;
    no->prox = (*p);// o novo elemnto aponta para o topo da pilha
    *p = no;//o antigo topo aponta para o novo elem
    return 1;
}

int remover(Pilha *p)
{
    if(p == NULL)//Verifica se tem pilha
        return 0;
    if((*p) == NULL)//Verifica se o valor apontado peo topo eh nulo (pilha vazia)
        return 0;

    E *no = *p;//aux q recebe o topo da pilha
    *p = no->prox;// o topo da pilha eh o prox elemento do no
    free(no);//libera o antigo topo

    return 1;
}

int consultar(Pilha *p, struct aluno *al)
{
    if(p == NULL)// VErifica se apilha existe
        return 0;
    if((*p) == NULL)//Verifica se a pilha não esta VAZIA 
        return 0;
    *al = (*p)->dados;//Ele pega os dados do PRIMEIRO (TOPO/ ULTIMO ADD) elemento da pilha
    return 1;
    
}
int main()
{
    Pilha *p;

    p = criaPilha();
    libera(p);
    int x = tamanhoPilha(p);
    int x = pilhaCheia(p);
    int x = pilhaVazia(p);
    //int x = inserir(p, dados_aluno);
    int x = remover(p);
    //int x = consltar(p, &dados_aluno);
    return 0;
}