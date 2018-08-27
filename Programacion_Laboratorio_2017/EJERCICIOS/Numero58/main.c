// Leer 10 elementos de un vector de enteros y mostrar su contenido.
#include <stdio.h>
#include <stdlib.h>
#define cant 10

int main()
{
    int i,num[cant];

    for(i = 0; i < cant; i++)
    {
        printf("Ingrese numero: ");
        scanf("%d", &num[i]);
    }
    for(i = 0; i < cant; i++)
    {
        printf("Numero: %d\n", num[i]);
    }
    return 0;
}
