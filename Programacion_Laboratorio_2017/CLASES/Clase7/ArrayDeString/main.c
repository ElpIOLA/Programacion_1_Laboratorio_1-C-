#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define CANT 20

int main()
{
    char dni[CANT],clave[CANT];
    int x;

    printf("Ingrese su DNI: ");
    gets(dni);
    x = strlen(dni);

    printf("\nIngrese la clave: ");
    gets(clave);

    if(strcmp(clave, "1234") == 0)
    {
        printf("\nHola su DNI es: %d, y la clave es correcta.",x);
    }
    else
    {
        printf("\nClave incorrecta.");
    }

    getch();
    return 0;
}
