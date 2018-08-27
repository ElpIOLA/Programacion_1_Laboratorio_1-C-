#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont = 0, numero, acumMax = 0, acumMen = 0;

    while(cont < 5)
    {
        cont++;
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        while(cont == 0)
        {
            printf("El numero es incorrecto.");
            printf("Ingreselo nuevamente: ");
            scanf("%d", &numero);
        }
        if(numero > 0)
        {
            acumMax += numero;
        }
            else if(numero < 0)
            {
                acumMen += numero;
            }
    }
    printf("\nEl total de positivos son: %d", acumMax);
    printf("\nEl total de positivos son: %d", acumMen);
    return 0;
}
