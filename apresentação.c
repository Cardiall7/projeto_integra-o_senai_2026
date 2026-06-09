#include <stdio.h>
#include <string.h>

#define MAX 100

char nomes[MAX][50];
int quantidade = 0;

void cadastrar() {
    if (quantidade < MAX) {
        printf("Nome: ");
        scanf(" %[^\n]", nomes[quantidade]);
        quantidade++;
        printf("Cadastro realizado!\n");
    }
}

void consultar() {
    char busca[50];
    printf("Digite o nome: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            printf("Encontrado: %s\n", nomes[i]);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

void alterar() {
    char busca[50];

    printf("Nome a alterar: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(nomes[i], busca) == 0) {
            printf("Novo nome: ");
            scanf(" %[^\n]", nomes[i]);
            printf("Alterado com sucesso!\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

void excluir() {
    char busca[50];

    printf("Nome a excluir: ");
    scanf(" %[^\n]", busca);

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(nomes[i], busca) == 0) {

            for (int j = i; j < quantidade - 1; j++) {
                strcpy(nomes[j], nomes[j + 1]);
            }

            quantidade--;
            printf("Excluido com sucesso!\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

void listar() {
    printf("\n--- LISTA DE REGISTROS ---\n");

    for (int i = 0; i < quantidade; i++) {
        printf("%d - %s\n", i + 1, nomes[i]);
    }
}

int main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Listar\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrar();
                break;
            case 2:
                consultar();
                break;
            case 3:
                alterar();
                break;
            case 4:
                excluir();
                break;
            case 5:
                listar();
                break;
            case 0:
                printf("Programa encerrado com seguranca.\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
