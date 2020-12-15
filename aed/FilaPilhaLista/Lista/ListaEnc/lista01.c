#include<stdio.h>
#include<stdlib.h>
#include"lista01.h"

 struct elemento{
    struct aluno dados;
    struct elemento *pprox;//ponteiro para o proximo elemnto da lista
};
typedef struct elemnto Elem;

int main()
{
    Lista *L;//ponteiro para ponteiro onde lista é um ponteiro da struct elemento
    Elem dados;

    L = criaLista();
    int x = inserirInicio(L, dados);
    int x = inserirFinal(L, dados);
    int x =inserirOrdenado(L, dados);
    int x = removerInicio(L);
    int x = removerFinal(L);
    int x = remover(L, mat);
    int x = consultaPosicao(L, pos, &dados_aluno);
    int x = consultaMatricula(L, mat, &dados_aluno);
    int x = tamanhoLista(L);
    /*int x = listaCheia(L);
    if(listaCheia(L))*/
    int y = listaVazia(L);
    //if(lista(L)) - continuar com algum codigos
    liberaLista(L);
    
    return 0;
}

Lista *criaLista()
{ 
    Lista *L = (Lista *)malloc(sizeof(Lista));//inicio da Lista
    if(L != NULL)
        *L = NULL;//Lista vazia
    
    return L;
}

void liberaLista (Lista *L)
{
    if(L != NULL) // Se a Lista for válida (!=NULL)
    {
        Elem *no;
        while ((*L) != NULL) //esse (*L) é o primeiro elemento da lista INICIO 
        {
            no = *L; // no recebe o inicio da Lista
            *L = (*L)->pprox;  // O inicio da lista vai pontar para o PRÓXIMO elemento
            free(no);//Libera o antigo inicio da lista
        }//Repete até a Lista estiver vazia
        free(L);   //Libera a cabeã da lista (ultimo ponteiro a ser liberado)     
    }
}

int tamanhoLista (Lista *L)
{
    if(L == NULL)//testa se tem algum elemnto na lista
        return 0;//Retorna que o tamanh dela é 0

    int cont = 0;//tamanho
    Elem* no = *L;//Recebe o primeiro elemneto da lista

    while (no != NULL)
    {
        cont++;
        no = no>pprox;//anda pro prox elemento
                      //NÃO SE ANDA COM A CABEÇA DA LISTA senao se perde o inicio da Lista
                      //SEMPRE SE ANDA COM UM PONTEIRO AUXILIAR
    }
    return cont;//retorna o tamanho
}

int listaCheia(Lista *L)//A lista só fiará CHEIA quando acabar a memória do computador pois 
{                        //ela não temum tamanho definido
    return 0;
}

int listaVazia(Lista *L)
{
    if(L == NULL)//se A LISTA for null entao ela esta vazia
        return 1;
    if(*L == NULL)//se O CONTEUDO for null então ela esta vazia(ñ tem elementos)
        return 1;
    return 0;//lista nao está vazia
    // O return termina uma função por isso que o 'return 0' ñ sera executado se um dos if for V
}

Lista inserirInicio(Lista *L, struct aluno al)//struct com dados a serem inseridos
{
    if(L == NULL)//Verifica se aLista existe
        return 0;
    
    Elem *no = (Elem *)malloc(sizeof(Elem));//cria um novo elemnto pra lista
    
    if(no == NULL)//Verifica se o no é null
        return 0;//Não consegui alocar a memoroia para o novo elemento da lista
   
    no->dados = al;//Copia os dados para o novo elemnto
    no->pprox = (*L);//aponta para o valor do inicio da lista (Ou null caso a lista for vazia || o proximo elemento)
    *L = no;//O inicio passa a ser o novo no
    return 1;
}

Lista inserirFinal(Lista *L, struct aluno al)
{
    if(L == NULL)//VERIFICA SE ALISTA EXISTE
        return 0;
    
    Elem *no = (Elem *)malloc(sizeof(Elem));//Novo elemto da Lista

    if(no == NULL)//Verifica se foi possivel alocar memoria  
        return 0;

    no->dados = al;//copia os dados para o novo elemnto alocado
    no->pprox = NULL;//vai estar no final da lista e depois do final só tem NULL
    if((*L) == NULL)//Se aLista estiver vazia: insere no inicio
    {
        *L = no;//Se alista for vazia- o inicio da Lista é o novo no
    }else
     {
         Elem *aux = *L;//aux para percorrer a lista
         while(aux->pprox != NULL)//percorrer a lista até achar o ultimo elemento
         {
             aux = aux->pprox;//aux recebe o proximo elemento
         }
         aux->pprox = no;//inserindo novo nó no final da lista
     }
     return 1; 
}

Lista inserirOrdenado(Lista *L, struct aluno al)
{
    if(L == NULL)
        return 0;
    Elem *no= (Elem *)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    n->dados = al;
    if(listaVazia(L))
    {
        no->pprox = (*L);
        *L = no;
        return 1;
    }else
     {/*procura onde inserir*/
        Elem *ant, *atual = *L;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->pprox;
        }//ele vai percorrendo a lista até uma das condições serem falsas

        if(atual == *L)//Se o endereço atual é o inicio da lista - insere no INICIO
        {
            no->pprox = (*L);
            *L = no;
        }else//Insere ou no final ou no meio da Lista
         {
             no->pprox = ant->pprox;// O no vai passar a apontar para o proximo elemto que o anterior apontava
             ant->pprox = no;//O anterior (q antes apontava pro atual) agora aponta para o no
         }
         return 1;
     }
}

Lista removerInicio(Lista *L)
{
    if(L == NULL)//Verifica se a lista EXISTE
        return 0;

    if((*L) == NULL)// O valor do elemnro apontado pelo inicio é NULL = Lista VAZIA
        return 0;
    
    Elem *no = *L;//cria elemnto no que recebe o VALOR do inicio da lista
    *L = no->prox;//o inicio da lista passa a apontar ao elemnto SEGUINTE ao no
    free(no);//Libera o elemnto no que tinha os dados
    /*Se o no é o ultimo elemento da Lista o inicio da lista estara apontando para NULL tornando-se uma lista vazia*/
    return 1;
}

Lista removerFinal(Lista *L)
{
    if(L == NULL)//Se alista existe
        return 0;
    
    if((*L) == NULL)//Se alista está vazia
        return 0;

    Elem *ant, *no = *L;

    while (no->pprox != NULL)//percorre a lista até o final dela 
    {
        ant = no ;
        no =no->pprox;
    }

    if(no == (*L))//Se o no for = ao valor do inicio da lista ele vai remover o primeiro elemnto portanto a lista só tinha um elem
    {    *L = no->prox;/*no caso o proximo é null*/    }
    else{ ant->pporx = no->pprox; }

    free(no);
    return 1;   
}

Lista remover(Lista *L, int mat)
{
    if(L == NULL)
        return 0;

    Elem *ant, *no = *L;

    while(no != NULL &&no->dados.matricula != mat) 
    {
        ant = no;
        no = no->pprox;
    }//percorre a lista pelos parametros do while

    if(no == NULL)//Elemneto NÃO ENCONTRADO ou a lista ja era vazia
        return 0;

    if(no == *L)//se = ao valor do inicio da lista REMOVE o primeiro
        *L = no->pprox;
    else   
        ant->prox = no->prox;// o anterior apona paa o elemnto seguinte do no
        
    free(no);
    return 1;
}

int consultaPosicao(Lista *L, int pos, struct aluno *al)
{
    if(L == NULL || pos <= 0) //Se a lista existe ou se a pos é um nuemro valido para procurar na lista
        return 0;
    
    Elem *no =*L;//poneiro aux para percorrer a lista
    int i = 1;

    while(no != NULL && i < pos)//A lista começa no 1 (não 0 igual aos vetores)
    {
        no =no->pprox;
        i++;
    }

    if(no == NULL)//Lista vazia
        return 0;
    else
    {
        *al = no->dados;//ponteiro da struct recebe os elementos dessa posição
        return 1;
    }
}

int consultaMatricula(Lista *L, int mat, struct aluno *al)
{
    if(L == NULL)
        return 0;
    
    Elem *no = *L; //pont aux p/ percorrer a lista

    while(no != NULL && no->dados.matricula != mat)
    {
        no =bo->pprox;
    }

    if(no == NULL)//Lista vazia
        return 0;
    else
    {
        *al = no->dados;
        return 1;
    }
}