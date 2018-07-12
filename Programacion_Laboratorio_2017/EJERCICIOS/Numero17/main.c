// Hacer el programa que nos permita introducir un número por teclado y nos informe si es par o impar
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    printf("Ingrese el numero: ");
    scanf("%d", &num1);

    if(num1%2 == 0)
    {
        printf("El numero es par.");
    }
        else
        {
            printf("El numero es impar.");
        }
    return 0;
}
