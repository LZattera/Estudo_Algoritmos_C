#include<stdio.h>
/*------- MAIOR ENDEREÇO---------------
int main(){
    int a;
    int b;
    if(&a > &b){
        printf("O endereço de a variavel a %x eh maior que a da variavel b %x", &a,&b);
    }else
    {
         printf("O endereço de a variavel b: %x eh maior que a da variavel a: %x", &b,&a);
    }
    
}*/

//----IMPRIMINDO CADA POSIÇAO DO VETOR-------------
/*int main(){
    int *ptr, i;
    ptr= (int *)malloc(10*sizeof(ptr));

    printf("Digite os numeros: \n");
    for(i=0;i<10;i++)
    {
        scanf("%d", (ptr+i));
    }

    printf("Os numeros digitdos foram: \n");
   for(i=0;i<10;i++)
    {
        printf("%d\n", *(ptr+i));
    }
    free(ptr);
}*/

//----LER CINCO VALORES DE UM VETO E PRINTAR O SEU DOBRO---------
/*int main(){
   int *ptr, i;
   ptr= (int *)malloc(5*sizeof(ptr));

   //Ler Valores 
   printf("Digite CINCO valores: \n");
   for(i=0; i<5; i++)
   {
       scanf("%d", (ptr+i));
   }

   //Dobro de cada valor
   printf("O dobro dos valores digitados eh: \n");
   for(i=0; i<5; i++)
   {
       printf("%d\n", *(ptr+i) * 2);
   }
   free(ptr);
}*/

//