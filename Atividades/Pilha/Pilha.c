#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct elemento {
    int content;
    struct elemento *prox;
};

typedef struct elemento *Pil;

Pil createPil(){
    return NULL;
}

int testEmpty(Pil p){
    if (p == NULL)
        return TRUE;
    else
        return FALSE;
}

Pil stackUp(Pil p, int e){
    Pil pa;
    pa = malloc(sizeof(struct elemento));
    pa->content = e;
    pa->prox = p;
    return pa;
}

Pil unstack(Pil p, int *e){
    Pil pa;
    if (testEmpty(p) == FALSE){
        *e = p->content;
        pa = p;
        p = p->prox;
        free (pa);    
    } else{
        *e = -1;
        printf ("\nPilha vazia!\n");
    }
    return p;
}

void printPil(Pil p){
    Pil pa;
    pa = p;
    printf ("\n=====ITENS DA LISTA=====\n");
    while (pa != NULL){
        printf ("\n%d\n",pa->content);
        pa = pa->prox;
    }
}

int main(){
    int menu,e1;
    Pil p1;
    p1 = createPil();
    do{
        printf ("\n1 - Empilhar um item.\n2 - Desempilhar um item.\n3 - Imprimir conteudo.\n4 - Sair.\n");
        printf ("\nEscolha uma das opcoes: ");
        scanf ("%d",&menu);
        printf ("\n==========//==========\n");

        switch(menu){
            case 1:
                printf("\nDigite o item que voce deseja empilhar: ");
                scanf("%d",&e1);
                p1 = stackUp(p1,e1);
                printf ("\nItem empilhado!\n");
                printf ("\n==========//==========\n");
                break;
            case 2:
                printf ("\nDigite o item que voce quer desempilhar: ");
                scanf ("%d",&e1);
                p1 = unstack(p1,&e1);
                printf ("\nItem removido da pilha!\n");
                printf ("\n==========//==========\n");
                break;
            case 3:
                printPil(p1);
                printf ("\n==========//==========\n");
                break;
            case 4:
                break;
            default:
                printf ("\nOpcao invalida!\n");
                printf ("\n==========//==========\n");
        }
    } while (menu != 4);

    return 0;
}
