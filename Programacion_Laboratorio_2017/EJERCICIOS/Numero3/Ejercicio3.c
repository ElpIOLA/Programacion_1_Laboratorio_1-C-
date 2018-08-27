// Escribir  un programa que realice las siguientes acciones.
//  Limpie la pantalla.
//  Asigne a 2 variables numero1 y numero2 valores distintos de cero.
//  Efectúe el producto de dichas variables.
//  Muestre el resultado pos pantalla.
//  Obtenga el cuadrado de numero1 y lo muestre por pantalla.

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int numero1, numero2, suma, cuadrado;

    printf("Ingrese el numero uno: ");
    scanf("%d", &numero1);
    printf("Ingrese el numero dos: ");
    scanf("%d", &numero2);

        if(numero1 != 0 && numero2 != 0)
        {
            suma = numero1 + numero2;
            printf("La suma de ambos numeros da: %d\n", suma);
        }

    cuadrado = numero1 * numero1;
    printf("El cuadrado del numero uno es: %d", cuadrado);
    return 0;
    system("clear");
}

