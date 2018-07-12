#include <stdio.h>
#include <stdlib.h>
#include "ElpIOLA.h"

int main()
{
    struct alumno alumnos[5];
    int i;

    for(i=0;i<5;i++)
    {
        printf("Ingrese su legajo: ");
        scanf("%d", &alumnos[i].legajo);
        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(alumnos[i].nombre);
    }

    for(i=0;i<5;i++)
    {
        printf("Bienvenido %s, su legajo es: %d\n", alumnos[i].nombre,alumnos[i].legajo);
    }
    return 0;
}
