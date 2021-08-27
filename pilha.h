
#define TRUE 1
#define FALSE 0

/* implementacao encadeada */
typedef struct _no {
  char valor;
  struct _no *prox;
} No;

typedef struct _pilha {
  No *topo;
  int quantidade;
} Pilha;

Pilha * criar_pilha();

void liberar_pilha(Pilha *p);

int empilhar(Pilha *p, char valor);

int desempilhar(Pilha *p);

char topo(Pilha *p);

int esta_cheia(Pilha *p);

int esta_vazia(Pilha *p);

void imprimir_pilha(Pilha *p);
