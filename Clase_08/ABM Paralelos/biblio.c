#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"
#define TAM 3

int buscarLibre(int legajos[], int tam){
    int index = -1, i, auxLeg;

    printf("\n\tIngrese legajo: ");
    scanf("%d",&auxLeg);

    for(i=0;i<tam;i++){
        if(auxLeg == legajos[i]){
            break;
        }else{
            index = auxLeg;
            break;
        }
    }
    return index;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam){
    int i;
    for(i=0; i<tam; i++){
        if(legajos[i]!=0){
            printf("\n\tLegajo: %d\n\tNombre: %s\n\tNota 1: %d\n\tNota 2: %d\n\tPromedio: %.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i]);
        }
    }
}

/**------------FUNCIONES DEL ABM------------------*/

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam){
    int index, i;

    for(i=0;i<tam;i++){
        index = buscarLibre(legajos, tam);
        if(index!=-1){
                legajos[i] = index;
                printf("\n\tIngrese nombre: ");
                fflush(stdin);
                gets(nombres[i]);
                printf("\n\tIngrese nota 1: ");
                scanf("%d",&nota1[i]);
                printf("\n\tIngrese nota 2: ");
                scanf("%d",&nota2[i]);
                promedio[i] = calcularPromedio(nota1[i],nota2[i]);
                break;
        }else{
            break;
        }
    }
            return index;
}

int modificarAlumno(int legajo[], char nombre[][20], int not1[], int not2[], int tam){
    int i, auxLeg, index = 0;
    char nomAux[20];
    int legAux, not1Aux, not2Aux;

    printf("\n\tIngrese legajo del alumno a modificar: ");
    scanf("%d",&auxLeg);

    for(i=0;i<TAM;i++){
        if(legajo[i] == auxLeg){
            index = 1;
            printf("\n\tLEGAJO ENCONTRADO!\n");

            printf("\n\tEl nombre actual es: %s",nombre[i]);
            printf("\n\tIngrese el nuevo nombre: ");
            fflush(stdin);
            gets(nomAux);
            strcpy(nombre[i],nomAux);

            printf("\n\tEl legajo es: %d",legajo[i]);
            printf("\n\tIngrese el nuevo legajo: ");
            scanf("%d",&legAux);
            legajo[i] = legAux;

            printf("\n\tLa nota 1 es: %d",not1[i]);
            printf("\n\tIngrese la nueva nota 1: ");
            scanf("%d",&not1Aux);
            not1[i] = not1Aux;

            printf("\n\tLa nota 2 es: %d",not2[i]);
            printf("\n\tIngrese la nueva nota 2: ");
            scanf("%d",&not2Aux);
            not2[i] = not2Aux;

            printf("\n\tALUMNO MODIFICADO!\n\tNombre: %s\n\tLegajo: %d\n\tPrimer nota: %d\n\tSegunda nota: %d\n",nombre[i],legajo[i],not1[i],not2[i]);
        }
    }
    if(index == 0){
        printf("\nNO EXISTE EL ALUMNO!\n");
    }

    return 0;
}
/**------FUNCIONES MATEMATICAS----------*/

float calcularPromedio(int not1, int not2){
    float promedio;
    promedio = (float)(not1+not2)/2;
    return promedio;
}


