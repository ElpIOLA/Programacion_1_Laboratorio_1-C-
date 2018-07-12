//Leer 20 números enteros positivos, indicar cuál es el mayor y en qué orden fue leído (a que elemento pertenece).
//Mostrar el vector completo
#include <stdio.h>
#include <stdlib.h>
#define CANT 5
int main()
{
    int i, num[CANT], max, min;

    for(i = 0; i < CANT; i++)
    {
        printf("Ingrese numero: ");
        fflush(stdin);
        scanf("%d", &num[i]);
        while(num[i] < 0)
        {
            printf("No es un numero positivo.\n");
            printf("Ingrese otro.");
        }
    }
    for(i = 0; i < CANT; i++)
    {
        printf("Los vectores son: %d\n", num[i]);
    }
     if(i == 0 || num[i] > max)
        {
            max = num[i];
            printf("El vector mas grande es: %d\n", max);
        }
        else if(i == 0 || num[i] < min)
        {
            min = num[i];
            printf("El vector mas chico es: %d\n", min);
        }



    return 0;
}
