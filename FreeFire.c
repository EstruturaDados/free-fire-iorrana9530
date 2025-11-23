#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10
#define TAM_NOME 30
#define TAM_TIPO 20

// Nível Novato
// Estrutura de item com nome, tipo e quantidade
typedef struct {
    char nome[TAM_NOME];
    char tipo[TAM_TIPO];
    int qtd;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;

// Inserir item
void inserir() {
    if (numItens == MAX_ITENS) { printf("Mochila cheia.\n"); return; }
    printf("Nome: "); scanf("%s", mochila[numItens].nome);
    printf("Tipo: "); scanf("%s", mochila[numItens].tipo);
    printf("Qtd: "); scanf("%d", &mochila[numItens].qtd);
    numItens++;
    printf("Item inserido.\n");
}

// Remover item
void remover() {
    char n[TAM_NOME];
    printf("Nome p/ remover: "); scanf("%s", n);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, n) == 0) {
            for (int j = i; j < numItens - 1; j++)
                mochila[j] = mochila[j + 1];
            numItens--;
            printf("Item removido.\n");
            return;
        }
    }
    printf("Item nao disponivel.\n");
}

// Listar itens
void listar() {
    if (numItens == 0) { printf("Mochila vazia.\n"); return; }

    printf("\n--- Itens ---\n");
    for (int i = 0; i < numItens; i++)
        printf("%s | %s | Qtd: %d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].qtd);
}

int main() {
    int op;
    do {
        printf("\n1.Inserir  2.Remover  3.Listar 4.Buscar  0.Sair\nOpcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: listar(); break;
            case 4: listar(); break;
        }
    } while (op != 0);

    return 0;
}