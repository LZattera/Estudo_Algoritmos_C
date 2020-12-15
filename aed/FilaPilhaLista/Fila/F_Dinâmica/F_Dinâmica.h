struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila *criaFila();
void liberaFila (Fila *f);
int tamanhoFila(Fila *f);
int filaCheia(Fila *f);
int filaVazia(Fila *f);
int inserir(Fila *f, struct aluno al);
int remover(Fila *f);
int consulta(Fila *f, struct aluno *al);