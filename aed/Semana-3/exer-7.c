/*Faça um programa que lê n números decimais (NÃO FORNECIDO PELO USUARIO)
, armazenando-os em um vetor. Logo após, uma função deve
retirar os números duplicados que eventualmente possam existir neste
vetor, deixando apenas uma ocorrência de cada número. Ao final, o vetor
resultante deve ser impresso na tela.
*/
#include<stdio.h> 
#include<stdlib.h>

int* cria_vetor (int quant_num);
int* repetidos (int *vet);
void mostrar (int *vet);

int main(){

    int quant_num;

    printf("Quantos numeros deseja que o vetor tenha: ");
    scanf('%d', &quant_num);
    cria_vetor(quant_num);

    
    
    return 0;
}

int* cria_vetor (int quant_num)
{
    int i;
    int *vet = (int *)malloc(sizeof(int));
    
    for(i=0; i <=quant_num; i++)
    {

    }
}