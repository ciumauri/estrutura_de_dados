#include <stdio.h>

/*Chamada de função passando parâmetro por valor*/

float areaRetangulo (float b,float a) {
    float resultado;
    resultado = b*a;
    printf ("\nArea do retangulo eh: %.1f\n",resultado);
}

int main () {
    float base, altura;
    printf ("\nInforme o valor da base: ");
    scanf ("%f",&base);
    printf ("\nInforme o valor da altura: ");
    scanf ("%f",&altura);
    areaRetangulo (base,altura);
    return 0;
}
