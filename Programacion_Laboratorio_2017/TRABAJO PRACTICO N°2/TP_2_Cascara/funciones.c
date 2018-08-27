#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 20

int init(EPersona persona[])
{
    int i;

    for(i=0; i<CANT; i++)
    {
        persona[i].estado = 0;
    }
    return 0;
}

int agregarEPersona(EPersona persona[])
{
    int i;

    for(i = 0; i < CANT; i++)
    {
        if(persona[i].estado == 0)
        {
            system("cls");

            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]", persona[i].nombre);

            printf("Ingrese su edad: ");
            scanf("%d", &persona[i].edad);

            printf("Ingrese su DNI: ");
            scanf("%d", &persona[i].dni);

            persona[i].estado = 1;
            printf("AGREGADO");
            break;
        }
    }
    return 0;
}

int borrarPersona(EPersona persona[])
{
    int i, dniAux;

    printf("Ingrese el DNI de la persona a eliminar: ");
    scanf("%d", &dniAux);

    for(i = 0; i<CANT; i++)
    {
        if(persona[i].dni == dniAux)
        {
            persona[i].estado = 0;
            printf("Persona %s eliminada\n",persona[i].nombre);
            break;
        }
        else
        {
            printf("Usuario no encontrado.\n");
        }
    }
    return 0;
}

int listaOrdenadaPorNombre(EPersona persona[])
{
    int i;
    int j;
    char nombreAux[80];

    for(i=0; i<CANT-1; i++)
    {
        for(j=i+1; j<CANT; j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre)>0)
            {
                strcpy(nombreAux,persona[i].nombre);
                strcpy(persona[i].nombre,persona[j].nombre);
                strcpy(persona[j].nombre,nombreAux);
            }
        }
    }
    printf("LISTA\n");
    for(i = 0; i<CANT; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("%s\n", persona[i].nombre);
        }
    }
    return 0;
}

int graficoEdades(EPersona persona[])
{
    int i;
    int j;
    int menor = 0;
    int mayor = 0;
    int viejo = 0;

    for(i = 0; i<CANT; i++)
    {
        if(persona[i].estado == 1)
        {
            if(persona[i].edad < 18)
                menor++;
            else if(persona[i].edad >= 19 && persona[i].edad < 35)
                mayor++;
            else
                viejo++;
        }
    }

    int vecEdad[2];
    vecEdad[0] = menor;
    vecEdad[1] = mayor;
    vecEdad[2] = viejo;

    int maximo = 0;

    for(i = 0; i < CANT; i++)
        if(vecEdad[i] > maximo)
            maximo = vecEdad[i];

    for(i = maximo; i > 0; i--)
    {
        for(j = 0; j<3; j++)
            if(vecEdad[j] >= i)
                printf("    * ");
            else
                printf("      ");

        putchar('\n');
    }

    printf("<18   19-35   >35");
    putchar('\n');

    return 0;
}

