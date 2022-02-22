#include <stdio.h>

/*Calculadora de quatro operações básicas.*/

void flush_in(){ 
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int soma(int a, int b){
    int resultado;
    resultado = a+b;
    return resultado;
}

int mult(int a, int b){
    int resultado;
    resultado = a*b;
    return resultado;
}

int sub(int a, int b){
    int resultado;
    resultado = a-b;
    return resultado;
}

int div(int a, int b){
    int resultado;
    resultado = a/b;
    return resultado;
}

int calculo (int x, int y,char op){
    int resultado;
    if(op == '+'){
        resultado = soma(x,y);
        printf("\nResultado da soma: %d\n", resultado);    
    } else if (op == '*'){       
        resultado = mult(x,y);
        printf("\nResultado da multiplicacao: %d\n", resultado);    
    } else if (op == '-'){        
        resultado = sub(x,y);
        printf("\nResultado da subtracao: %d\n", resultado);
    
    } else if (op == '/'){        
        resultado = div(x,y);
        printf("\nResultado da divisao: %d\n", resultado);
    }
    printf("\n****************//****************\n");
}

int main(){

    int num1, num2, resultado;
    char menu;
    do {
        printf("\n+ para Somar\n* para Multiplicar\n- paraSubtrair\n/ para Dividir\n0 para Sair\n");
        printf("\nSelecione uma das opcoes exibidas: ");
        scanf ("%c",&menu);
        printf ("\n****************//****************\n");
        if (menu != '+' && menu != '*' && menu != '-' && menu != '/' && menu != '0') {
            printf ("\nOpcao invalida!\n");
            printf ("\n****************//****************\n");
        }
        else if (menu == '0')
            break;        
        else {
            printf("\nInforme o primeiro numero: ");
            scanf ("%d",&num1);
            printf("\nInforme o segundo numero: ");
            scanf ("%d",&num2);
            printf ("\n****************//****************\n");
            calculo(num1, num2, menu);
        }

        flush_in ();        
        } while (menu != '0');
        
    return 0;
}
