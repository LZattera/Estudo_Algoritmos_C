#define MAX 100

struct aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct pilha Pilha; 

Pilha *criaPilha();
void liberaPilha(Pilha *p);
int tamanhoPilha(Pilha *p);
int pilhaCheia(Pilha *p);
int pilhaVazia(Pilha *p);
int insere(Pilha *p, struct aluno al);
int remove (Pilha *p);
int consulta(Pilha *p, struct aluno *al);