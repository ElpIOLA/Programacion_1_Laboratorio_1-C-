// Escribir un programa que por medio de una función calcule la superficie de un rectángulo.
// El programa continúa calculando superficies hasta que se ingresen ambos lados con valor cero.
#include <stdio.h>
#include <stdlib.h>
int funcions(int, int);

int main()
{
    int base, altura, resultado;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese la altura: ");
    scanf("%d", &altura);

    while(base != 0 && altura != 0)
    {
        resultado = funcions(resultado);
        printf("La superficie es: %d", resultado);

        while(base == 0 && altura == 0)
        {
            printf("Termino el programa.");
            break;
        }
    }
    return 0;
}

int funcions(int base, int altura)
{
    int resultado;
    resultado = base * altura;
    return resultado;
}
