#include<stdio.h>
#include<stdlib.h>
#include"exerFila02.h"

int main()
{
    opcao(Menu());
    return 0;
}
int Menu()
{
    int op;

    printf("====MENU====\n");
    printf("1. Inserir\n");
    printf("2. Buscar\n");
    printf("3. Remover\n");
    printf("4. Tamanho da Fila\n");
    printf("5. Lista fila\n");
    printf("6. Sair");
    scanf("%d", &op);

    return op;
}

void opcao(int op)
{   
    Fila *f;
    do{
        switch (op)
        {
        case 1:
            f = criaFila();
            alocaNovoElemento();
            inserir(alocaNovoElemento());
            break;
        case 2:
            libera(f);
        default:
            break;
        }
    }while(op!=2);
}

Fila *criaFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if(!f)
    {
        f->ini = NULL;
        f->fim = NULL;
        tamanhoFila = 0;
    }
}

void liberaFila(Fila *f)
{
   if(f != NULL)
   {
       Fila *aux;
       while (aux != NULL)
       {
           aux = f->ini;
           f->ini =  f->ini->prox;
           free(aux);
           tamanhoFila--;
       }
       free(f);
   }
}

Fila alocaNovoElemento()
{
    Fila *f;
    
}