// Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado.
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main()
{
    int numero;
    float longitud, area;
    printf("Ingrese un numero para calcular la Longitud y area de un circulo: ");
    scanf("%d", &numero);
    longitud = numero * PI;
    printf("La longitud de este circulo es: %.2f \n", longitud);
    area = (numero*numero) * PI;
    printf("El area de este circulo es: %.2f", area);
    return 0;
}
