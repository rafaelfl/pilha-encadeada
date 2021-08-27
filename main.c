#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
  Pilha *p = criar_pilha();
  char texto[100];
  int tamanho, i;

  // VERIFICAR PARENTESES
  printf("Digite uma expressão para ser verificada:\n");

  scanf("%[^\n]s", texto);
  tamanho = strlen(texto);

  for (i = 0; i < tamanho; i++) {
    if (texto[i] == '(') {
      empilhar(p, '(');
    } else if (texto[i] == ')') {
      if (desempilhar(p) == -1) {
        printf("Parenteses DESBALANCEADOS!\n");
        return 0;
      }
    }
  }

  if (esta_vazia(p)) {
    printf("Parenteses balanceados!\n");
  } else {
    printf("Parenteses DESBALANCEADOS!\n");
  }

  // INVERTER STRINGS
  // printf("Digite um texto a ser invertido:\n");

  // scanf("%[^\n]s", texto);
  // tamanho = strlen(texto);

  // for (i = 0; i < tamanho; i++) {
  //   empilhar(p, texto[i]);
  // }

  // while(esta_vazia(p) == FALSE) {
  //   char c = topo(p);
  //   printf("%c", c);

  //   desempilhar(p);
  // }
  // printf("\n");
  
  liberar_pilha(p);

  return 0;
}