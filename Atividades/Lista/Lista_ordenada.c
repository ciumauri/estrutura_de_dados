#include <stdio.h>
#include <string.h>

#define MaxItems 5
#define TamItem 10

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

typedef char listType[MaxItems][TamItem];

void insertItem (listType l, char i[TamItem]){
    int j;
    for (j=0;j < MaxItems && strlen(l[j]) > 0;j++);
    if (j < MaxItems){
        strcpy (l[j],i);
        printf ("\nItem inserido com sucesso!\n");
        printf ("\n==========//==========\n");    
    } else
        printf ("\nLista cheia, item '%s' nao pode ser inserido!",i);
}

void removeItem (listType l, char i[TamItem]){
    int j;
    for (j=0;j < MaxItems && strlen(l[j]) > 0 && (strcmp(l[j],i)) != 0;j++);
    if (strcmp(l[j],i) == 0){
        if (j == (MaxItems-1))
            l[MaxItems-1][0] = '\0';
        else {
            for (;j < (MaxItems-1) && strlen(l[j]) > 0;j++)
                strcpy(l[j],l[j+1]);
            l[MaxItems-1][0] = '\0';
        }
        printf ("\nItem removido com sucesso!\n");
        printf ("\n==========//==========\n");    
    } else
        printf ("\nItem '%s' nao encontrado!",i);
}

void createList (listType l){
    int j;
    for (j=0;j < MaxItems;j++)
        l[j][0] = '\0';
}

int countElement (listType l){
    int j;
    for (j=0;j < MaxItems && strlen(l[j]) > 0;j++);
    return j;
}

void viewContent (listType l){
    int j;
    printf ("\n===ITEMS DA LISTA===\n");
    for (j=0;j < MaxItems && strlen(l[j]) > 0;j++){
        printf ("\n%s\n",l[j]);
    }
}

int main(){
    int menu;
    char item[TamItem];
    listType List;
    createList (List);
    do {
        printf ("\n1- Inserir novo item na Lista.\n2- Remover item da Lista.\n3- Contar itens da Lista.\n4- Exibir conteudo da Lista.\n5- Sair\n");
        printf ("\nSelecione uma das opcoes exibidas: ");
        scanf ("%d",&menu);
        flush_in();
        printf ("\n==========//==========\n");
        switch (menu) {

            case 1:
                printf ("\nInforme o item que deseja inserir na Lista: ");
                fgets (item,20,stdin);
                insertItem (List,item);
                break;
            case 2:
                printf ("\nInforme o item que deseja remover da Lista: ");
                fgets (item,20,stdin);
                removeItem (List,item);
                break;
            case 3:
                printf ("\nA Lista contem %d itens!\n",countElement(List));
                printf ("\n==========//==========\n");
                break;
            case 4:
                viewContent (List);
                printf ("\n==========//==========\n");
                break;
            case 5:
                break;
            default:
                printf ("\nOpcao invalida!\n");
                printf ("\n==========//==========\n");
        }
    
    } while (menu != 5);

    return 0;
}
