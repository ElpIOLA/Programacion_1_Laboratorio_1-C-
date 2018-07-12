// Escribir un programa que realice las siguientes acciones:
//  Limpie la pantalla
//  Declare 2 variables y les asigne distintos valores
//  Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor que cero o "Resultado negativo" si es menor que cero

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2, resta;

    printf("Ingrese numero uno: ");
    scanf("%d", &numero1);
    printf("Ingrese numero dos: ");
    scanf("%d", &numero2);

    resta = numero1 - numero2;

    if(resta >= 0)
    {
        printf("El resultado es positivo: %d", resta);
    }
        else if( resta < 0)
        {
            printf("El resultado es negativo: %d", resta);
        }
}
