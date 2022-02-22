#include <stdio.h>

/*Retorno de valor da função para o programa principal*/

float areaRetangulo (float b, float a) {
    float resultado;
    resultado = b*a;
    return resultado;
}

int main () {
    float area, base, altura;
    printf ("\nInforme o valor da base: ");
    scanf ("%f",&base);
    printf ("\nInforme o valor da altura: ");
    scanf ("%f",&altura);
    area = areaRetangulo (base,altura);
    printf("\nArea do retangulo eh: %.1f\n", area);
    return 0;
}
