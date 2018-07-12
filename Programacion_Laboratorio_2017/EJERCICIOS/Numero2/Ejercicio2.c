//Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, suma;

    printf("Ingrese el numero uno: ");
    scanf("%d", &numero1);
    printf("Ingrese el numero dos: ");
    scanf("%d", &numero2);

    suma = numero1 + numero2;
    printf("La suma da: %d", suma);

}
