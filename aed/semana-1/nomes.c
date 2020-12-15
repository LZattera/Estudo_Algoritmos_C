#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int op, num_nomes = 0;
    char name[30];

    char *nome = (char *)malloc(sizeof(char)+1);
    if(!nome){printf("--ERRO sem espaço na memoria---"); exit(1);}

    char *removido = (char *)malloc(sizeof(char)+1);
    if(!removido){printf("--ERRO sem espaço na memoria---"); exit(1);}

    do
    {
        printf("\n-----Menu-----\n");
        printf("1. Adicionar\n");
        printf("2. Remover\n");
        printf("3. Listar\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("ADICIONAR NOME\n");
                printf("Digite o nome: ");
                scanf("%s", name);

                nome = (char *)realloc(nome, sizeof(strlen(name)) +1); 
                if(!nome){printf("--ERRO sem espaco na memoria---"); exit(1);}

                num_nomes++;
                break;
            
            /*case 2:
                printf("REMOVER NOME\n");
                printf("Digite o nome: ");
                scanf("%s", removido);

                for(int i=0; i<num_nomes; i++)
                {
                    if(strcmp(*removido, *nome))
                    {

                    }
                    nome+i;
                }
                break;*/

            case 3:
            
                for(int i=0; i<num_nomes; i++)
                {
                    printf("%s\n", nome);
                    nome++;
                }
                free(removido);
                break;
                
            case 4: 
                 free(nome);
                break;
            
            default:
                printf("Opcao Invalida");
                break;
        }
    }while(op!=4);
    return 0;
}