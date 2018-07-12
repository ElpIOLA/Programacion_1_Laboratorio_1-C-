#include <stdio.h>
#include <stdlib.h>

unsigned int verifica(void)
{
    char letra;
    printf("\nIngrese opcion...S/N?");
    letra=toupper(getche());
    while(!((letra=='S')||(letra=='N')))
    {
        printf("\nHa ingresado opci¢n no valida...Reintente el ingreso(S/N)... ");
        letra=toupper(getche());
    }
    return (letra=='S');
}
