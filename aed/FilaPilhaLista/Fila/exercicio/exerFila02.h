struct fila{
    struct elemento *ini;
    struct elemento *fim;
};
struct elemento{
    struct aluno dados;
    struct elemento *prox;// proximo elemnto da fila
};
struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

int tamanhoFila;

int menu();
void opcao(int op);
Fila *criaFila();
Fila *inserir(Fila *f);
Fila *alocaNovoElemento();
