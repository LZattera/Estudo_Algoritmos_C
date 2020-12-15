struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento *Lista;

Lista *criaLista(); 
void liberaLista(Lista *L); 
int tamanhoLista (Lista *L);
int listaCheia(Lista *L);
int listaVazia(Lista *L);  
Lista inserirInicio(Lista *L, struct aluno al);
Lista inserirFinal(Lista *L, struct aluno al);
Lista inserirOrdenado(Lista *L, struct aluno al);//DMAIS IMPORTANTE
Lista removerInicio(Lista *L); 
Lista removerFinal(Lista *L);
Lista remover(Lista *L);//Remove qualquer elemnto da lista
int consultaPosicao(Lista *L, int pos, struct aluno *al);
int consultaMatricula(Lista *L, int mat, struct auno *al);