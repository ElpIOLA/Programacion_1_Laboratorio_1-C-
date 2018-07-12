// Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, altura;
    float superficie;
    printf("Ingrese la base del triangulo: ");
    scanf("%d", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%d", &altura);
    superficie = (base * altura) / 2;
    printf("La superficie del triangulo es: %.2f", superficie);
    return 0;
}
