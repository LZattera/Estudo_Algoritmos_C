struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento  *Pilha;

Pilha *criaPilha();
void liberaPilha(Pilha *p);
int tamanhoPilha (Pilha *p);
int pilhaCheia(Pilha *p);
int pilhaVazia(Pilha *p);
int inserir(Pilha *p, struct aluno al);
int remover(Pilha *p);
int consultar(Pilha *p, struct aluno *al);