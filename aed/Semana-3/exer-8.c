/*Faça um programa que leia uma string (de 80 caracteres) chamada linha
e, com uma função, identifique cada palavra (substring) desta linha
copiando-a para um novo vetor. Ao final, o programa deve imprimir as
palavras separadas, uma palavra por linha.
Dicas: i) faça uma função para identificar o fim e/ou o início de cada substring em linha*/

#include<stdio.h>

int main(){

    int i=3, j=5;
    int *p, *q;
    p=&i;
    q=&j;
    printf("%d", *p-*q); 
    return 0;
}