struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);