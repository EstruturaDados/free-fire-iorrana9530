#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define N 30
#define T 20

typedef struct {
    char nome[N], tipo[T];
    int qtd, prio;
} Item;

Item m[MAX];
int n = 0;
bool ordenado = false;

void ins() {
    if (n == MAX) { printf("Cheio.\n"); return; }
    printf("Nome: "); scanf("%s", m[n].nome);
    printf("Tipo: "); scanf("%s", m[n].tipo);
    printf("Qtd: "); scanf("%d", &m[n].qtd);
    printf("Prioridade (1-5): "); scanf("%d", &m[n].prio);
    n++; ordenado = false;
}

void rem() {
    char x[N]; printf("Nome p/ remover: "); scanf("%s", x);
    for (int i = 0; i < n; i++) {
        if (!strcmp(m[i].nome, x)) {
            for (int j = i; j < n - 1; j++) m[j] = m[j + 1];
            n--; printf("Removido.\n"); return;
        }
    }
    printf("Nao achou.\n");
}

void list() {
    if (!n) { printf("Vazio.\n"); return; }
    for (int i = 0; i < n; i++)
        printf("%s | %s | Qtd:%d | P:%d\n",
               m[i].nome, m[i].tipo, m[i].qtd, m[i].prio);
}

void ordenarNome() {
    for (int i = 1; i < n; i++) {
        Item k = m[i];
        int j = i - 1;
        while (j >= 0 && strcmp(m[j].nome, k.nome) > 0) {
            m[j + 1] = m[j]; j--;
        }
        m[j + 1] = k;
    }
    ordenado = true;
    printf("Ordenado por nome.\n");
}

void ordenarTipo() {
    for (int i = 1; i < n; i++) {
        Item k = m[i];
        int j = i - 1;
        while (j >= 0 && strcmp(m[j].tipo, k.tipo) > 0) {
            m[j + 1] = m[j]; j--;
        }
        m[j + 1] = k;
    }
    printf("Ordenado por tipo.\n");
}

void ordenarPrio() {
    for (int i = 1; i < n; i++) {
        Item k = m[i];
        int j = i - 1;
        while (j >= 0 && m[j].prio < k.prio) {
            m[j + 1] = m[j]; j--;
        }
        m[j + 1] = k;
    }
    printf("Ordenado por prioridade.\n");
}

void buscaBin() {
    if (!ordenado) { printf("Ordene por nome antes.\n"); return; }
    char x[N]; printf("Buscar: "); scanf("%s", x);
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int mI = (ini + fim) / 2;
        int cmp = strcmp(m[mI].nome, x);
        if (cmp == 0) {
            printf("ACHOU: %s | %s | %d | P:%d\n",
                   m[mI].nome, m[mI].tipo, m[mI].qtd, m[mI].prio);
            return;
        }
        if (cmp < 0) ini = mI + 1;
        else fim = mI - 1;
    }
    printf("Nao encontrado.\n");
}

int main() {
    int op;
    do {
        printf("\n1-Ins 2-Rem 3-List\n4-Ord Nome 5-Ord Tipo\n6-Ord Prio 7-Busca Bin\n0-Sair\nOp: ");
        scanf("%d", &op);
        switch (op) {
            case 1: ins(); break;
            case 2: rem(); break;
            case 3: list(); break;
            case 4: ordenarNome(); break;
            case 5: ordenarTipo(); break;
            case 6: ordenarPrio(); break;
            case 7: buscaBin(); break;
        }
    } while (op != 0);
}