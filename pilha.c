#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha * criar_pilha() {
  Pilha *p = malloc(sizeof(Pilha));

  p->topo = NULL;
  p->quantidade = 0;

  return p;
}

void liberar_pilha(Pilha *p) {
  // liberar os nós
  No *atual, *proximo;

  atual = p->topo;

  while (atual != NULL) {
    proximo = atual->prox;
    free(atual);
    atual = proximo;
  }

  // liberar a pilha
  free(p);
}

int empilhar(Pilha *p, char valor) {
  No *temp = malloc(sizeof(No));

  if (temp == NULL) {
    return -1;
  }

  temp->valor = valor;
  temp->prox = NULL;  

  // se a pilha tá vazia
  if (p->topo == NULL) {
    p->topo = temp;

  // se tiver algum elemtno na pilha
  } else {
    temp->prox = p->topo;
    p->topo = temp;
  }

  p->quantidade++;

  return 0;
}

int desempilhar(Pilha *p) {
  No *atual;

  if (esta_vazia(p)) {
    return -1;
  }

  atual = p->topo;
  p->topo = atual->prox;
  free(atual);

  p->quantidade--;

  return 0;
}

char topo(Pilha *p) {
  char c;
  No *no_topo;

  if (esta_vazia(p)) {
    return '\0';
  }

  // salva endereço do nó do topo da pilha
  no_topo = p->topo;

  // recupera o valor que está nesse nó
  c = no_topo->valor;

  return c;
}

int esta_cheia(Pilha *p) {
  return FALSE;
}

int esta_vazia(Pilha *p) {
  if (p->topo == NULL) {
    return TRUE;
  }

  return FALSE;
}

void imprimir_pilha(Pilha *p) {
  No *atual = p->topo;

  printf(" ");

  while (atual != NULL) {
    printf(" %c ", atual->valor);

    atual = atual->prox;
  }

  printf(" ]\n");
}