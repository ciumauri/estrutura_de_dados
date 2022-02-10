#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int mat;
    struct elemento *ant;
};
typedef struct elemento Elemento;

int veririficar_vazia(Elemento *pilha);
Elemento* inserir(Elemento *pilha, int valor);
Elemento* excluir(Elemento *pilha);
Elemento* buscar(Elemento *pilha, int valor);
void imprimir(Elemento *pilha);
void limpar_lista(Elemento *pilha);
int tamanho(Elemento *pilha);

main()
{
    Elemento *pilha = NULL;
    int opcao = -1;

    while (opcao != 0) {
        system("cls");
        printf("\n1 - Verificar se esta vazia");
        printf("\n2 - Inserir elemento");
        printf("\n3 - Excluir elemento");
        printf("\n4 - Buscar elemento");
        printf("\n5 - Imprimir");
        printf("\n6 - Limpar");
        printf("\n7 - Tamanho da pilha");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        int valor;
        switch (opcao) {
        case 1:
            printf("%d\n", veririficar_vazia(pilha));
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            pilha = inserir(pilha, valor);
            break;
        case 3:
            pilha = excluir(pilha);
            break;
        case 4:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            Elemento *aux = buscar(pilha, valor);
            if(aux != NULL) {
                printf("%d\n", aux->mat);
            } else {
                printf("Não encontrado");
            }
            break;
        case 5:
            imprimir(pilha);
            break;
        case 6:
            limpar_lista(pilha);
            pilha = NULL;
            break;
        case 7:
            printf("%d\n", tamanho(pilha));
            break;
        default:
            if(opcao != 0) {
                printf("\nOpçao inexistente, otario...\n");
            }
        }
        system("PAUSE");
    }
}

int veririficar_vazia(Elemento *pilha) {
    return pilha == NULL;
}

Elemento* inserir(Elemento *pilha, int valor) {
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->mat = valor;

    if (pilha == NULL) {
        novo->ant = NULL;
        pilha = novo;
    } else {
        novo->ant = pilha;
        pilha = novo;
    }
    return pilha;
}

Elemento* excluir(Elemento *pilha) {
    printf("\n***** EXCLUINDO UM! *****\n");
    Elemento *atual = pilha->ant;
    free(pilha);
    return atual;
}

Elemento* buscar(Elemento *pilha, int valor) {
    Elemento *atual = pilha;
    while (atual != NULL) {
        if(atual->mat == valor) {
            return atual;
        }
        atual = atual->ant;
    }
    return NULL;
}

void imprimir(Elemento *pilha) {
    printf("\n***** IMPRIMIR *****");
    Elemento *atual = pilha;
    while (atual != NULL) {
        printf("\n%d", atual->mat);
        atual = atual->ant;
    }
    printf("\n");
}

void limpar_lista(Elemento *pilha) {
    printf("\n***** LIMPAR *****");
    Elemento *atual = pilha;
    Elemento *aux = NULL;
    while (atual != NULL) {
        aux = atual->ant;
        free(atual);
        atual = aux;
    }
    printf("\n***** CONCLUIDO *****\n");
}

int tamanho(Elemento *pilha) {
    Elemento *atual = pilha;
    int i = 0;
    while (atual != NULL) {
        atual = atual->ant;
        i++;
    }
    return i;
}
