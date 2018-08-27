#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM 20
int main()
{
    char nombre1[TAM], nombre2[TAM];

    printf("INGRESE SU NOMBRE: ");
    gets(nombre1);

    strcpy(nombre2,nombre1);

    printf("SU NOMBRE ES: %s\n", nombre2);
    return 0;
}
