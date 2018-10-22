/**
    Solicite al usuario 10 números
    Calcule cuántos son negativos y cuantos son positivos
    Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, contMax = 0, contMin = 0, numero;

    for(i = 1; i <= 10; i++)
    {
        printf("\n%d-.Ingrese numero: ",i);
        scanf("%d",&numero);

        if(numero >= 0)
        {
            contMax++;
        }
        else
        {
            contMin++;
        }
    }

    printf("\nCantidad de positivos: %d\n",contMax);
    printf("\nCantidad de minimos: %d\n",contMin);
    return 0;
}
