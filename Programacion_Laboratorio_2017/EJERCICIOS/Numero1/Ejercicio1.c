//Ingresar 5 números y calcular su medida.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, num4, num5;

    printf("Ingrese numero uno: ");
    scanf("%d", &num1);
    printf("Ingrese numero dos: ");
    scanf("%d", &num2);
    printf("Ingrese numero tres: ");
    scanf("%d", &num3);
    printf("Ingrese numero cuatro: ");
    scanf("%d", &num4);
    printf("Ingrese numero cinco: ");
    scanf("%d", &num5);

    printf("Los numeros ingresados fueron: %d, %d, %d, %d, %d", num1, num2, num3, num4, num5);
}
