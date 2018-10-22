/**
    Solicitar al usuario 5 números, permitir listarlos por pantalla indicando el máximo, el mínimo y el promedio.
    Permitir Modificar el valor de cualquiera de los números cargados indicando el índice del mismo y su nuevo valor.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"

void listar(int vector[]);

int main()
{
    float promedio = 0;
    int vec[5], i,
    acumulador = 0,
    maximo = 0,
    minimo = 0,
    numero = 0,
    flag = 1,
    opcion = 0,
    indice = 0;

    for(i = 0; i < 5; i++)
    {
        printf("\n\t%d- Ingrese numero: ",i+1);
        numero = set_integer(numero);
        vec[i] = numero;
    }

    printf("\n\tPresione Enter...\n");
    getchar();
    system("cls");

    printf("\n\t%-10s\n","LISTA DE NUMEROS");
    listar(vec);

    printf("\n\tPresione Enter...\n");
    getchar();

    printf("\n\tDesea modificar un numero? Si = [1] - No = [0]\n\tIngrese opcion: ");
    opcion = set_integer(opcion);
    if(opcion == 1)
    {
        printf("\n\tIngrese indice: ");
        indice = set_integer(indice);
        if(indice >= 0 && indice <= 4)
        {
            printf("\n\tIngrese numero nuevo: ");
            numero = set_integer(numero);
            vec[indice] = numero;
        }
    }

    printf("\n\tPresione Enter...\n");
    getchar();
    system("cls");
    printf("\n\t%-10s\n","NUEVA LISTA DE NUMEROS");
    listar(vec);

    for(i = 0; i < 5; i++)
    {
        acumulador += vec[i];
        if(flag)
        {
            maximo = vec[0];
            minimo = vec[0];
            flag = 0;
        }

        if(maximo < vec[i])
        {
            maximo = vec[i];
        }
        if(minimo > vec[i])
        {
            minimo = vec[i];
        }
    }

    promedio = (float)acumulador / 5;

    printf("\n\tPromedio: %.2f",promedio);
    printf("\n\tMaximo: %d",maximo);
    printf("\n\tMinimo: %d",minimo);

    printf("\n\tPresione Enter...\n");
    getchar();
    printf("\n\tFIN DEL PROGRAMA\n\n");
    return 0;
}

void listar(int vector[])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("\n\tIndice: [%d] - Numero: [%d]\n",i,vector[i]);
    }
}
