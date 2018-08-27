// Hacer el programa que nos permita introducir un número por teclado y nos informe si es positivo o negativo.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    if(num1 > 0)
    {
        printf("El numero es positivo.");
    }
        else
        {
            printf("El numero es negativo.");
        }
    return 0;
}
