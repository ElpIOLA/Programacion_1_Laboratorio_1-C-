//  Escribir el programa necesario para calcular y mostrar el cuadrado de un número.
//El número debe ser mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cuadrado;

    printf("Ingrese el numero: ");
    scanf("%d", &numero);

    if(numero > 0)
    {
        cuadrado = numero * numero;
        printf("El cuadrado del numero es: %d", cuadrado);
    }
        else if(numero < 0)
        {
            printf("ERROR, el numero debe ser mayor a cero.");
        }

    return 0;
}
