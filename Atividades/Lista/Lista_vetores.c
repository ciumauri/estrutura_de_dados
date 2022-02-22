#include <stdio.h>
#include <stdlib.h>

struct element {
    int content;
    struct element *prox;
};

typedef struct element nodo;
typedef nodo *list;

list createList(){
    return NULL;
}

void printList(list l){
    list p;
    printf ("\n=====ITEMS DA LISTA=====\n");
    p = l;
    while (p != NULL){
        printf ("\n%d\n",p->content);
        p = p->prox;
    }
}

list insertElement(list l, int e){
    list novo;
    novo = malloc(sizeof(struct element));
    novo -> content = e;
    novo -> prox = l;
    return (novo);
}

int countElement(list l){
    list p;
    int cont=0;
    p = l;
    while(p != NULL){
        cont++;
        p = p->prox;
    }
    return cont;
}

list searchElement (list l, int e){
    list p;
    p = l;
    while(p != NULL && p->content != e){

        p = p->prox;
    }
    return (p);
}

list removeElement (list l, int e){
    list p,ant;
    p = l;
    ant = l;
    while (p != NULL && p->content != e){
        ant = p;
        p = p->prox;
    }
    if (p != NULL) {
        if (p == ant) {
            l = p->prox;
            free(p);        
        } else {
            ant->prox = p->prox;
            free(p);
        }
    }
    return (l);
}

int main (){
    list L1, pointer;
    int num,menu;
    L1 = createList();
    do{
        printf("\n1 - Inserir novo item na lista.\n2 - Remover item da lista.\n3 - Buscar item na lista.\n4 - Imprimir conteudo da lista.\n5 - Exibir numero de itens da lista.\n6 - Sair.\n");
        printf("\nSelecione uma das opcoes exibidas: ");
        scanf("%d",&menu);

        printf ("\n==========//==========\n");


        
        switch (menu) {

            case 1:                
                printf ("\nDigite o elemento que deseja inserir na lista: ");
                scanf ("%d",&num);
                L1 = insertElement (L1,num);
                printf ("\nO elemento '%d' inserido!\n",num);
                printf ("\n==========//==========\n");
                break;
            case 2:                
                printf ("\nDigite o elemento que deseja remover da lista: ");
                scanf ("%d",&num);
                L1 = removeElement (L1,num);
                printf ("\nO elemento '%d' removido!\n",num);
                printf ("\n==========//==========\n");
                break;
            case 3:
                printf ("\nDigite o elemento que deseja buscar na lista: ");
                scanf ("%d",&num);
                pointer = searchElement (L1,num);
                if (pointer == NULL)
                    printf ("\nO Elemento '%d' nao foi encontrado!\n",num);
                else
                    printf ("\nO Elemento '%d' foi encontrado!\n",num);                
                printf ("\n==========//==========\n");
                break;
            case 4:
                printList (L1);
                printf ("\n==========//==========\n");
                break;
            case 5:
                num = countElement(L1);
                printf ("\nA lista tem %d elementos!\n",num);                
                printf ("\n==========//==========\n");
                break;
            case 6:
                break;
            default:
                printf ("\nOpcao invalida!\n");
                printf ("\n==========//==========\n");
        }
    
    } while (menu != 6);

    return 0;
}
