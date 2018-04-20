#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"
#define CANT 3

int main()
{
    int legajo[CANT], nota1[CANT], nota2[CANT], nota3[CANT], i, leg, auxLeg;
    char nombre[CANT][30]; //MATRIZ
    float promedio[CANT];

    for(i=0;i<CANT;i++){

        printf("\n\tIngrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        legajo[i] = validarInt("\n\tIngrese un legajo: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",legajo[i]);

        nota1[i] = validarInt("\n\tIngrese nota 1: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",nota1[i]);

        nota2[i] = validarInt("\n\tIngrese nota 2: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",nota1[i]);

        nota3[i] = validarInt("\n\tIngrese nota 3: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",nota1[i]);
        printf("\n\t---------------------------------------------------------------\n");
        promedio[i] = calcularPromedio(nota1[i],nota2[i],nota3[i]);
    }

    mostrarAlumno(nombre,legajo,promedio,CANT);

    printf("\n\tQue legajo desea buscar?\n\tRespuesta: ");
    scanf("%d",&leg);
    auxLeg = funcionLegajo(legajo,CANT,leg);

    if(auxLeg == -1){
        printf("\n\tNO EXISTE ESTE LEGAJO!\n");
    }else{
        printf("\n\tLEGAJO ENCONTRADO: %d\n",auxLeg);
    }

    ordenamientoString(nombre,CANT);

    printf("\n\tORDENAMIENTO DE NOMBRES\n");
    for(i=0;i<CANT;i++){
        printf("\n\t%s\n",nombre[i]);
    }

    return 0;
}



