#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"
#include "libreria.h"
#define TAM 3

int buscarLibre(int legajos[], int tam){
    int index = -1, i, leg;
    char auxLeg[20];

    for(i=0;i<tam;i++){

        if(!getStringNumeros("\n\tIngrese legajo: ",auxLeg)){
            printf("\n\tERROR! El legajo debe ser solo numeros.\n");
            break;
        }
        leg = atoi(auxLeg);
        if(leg == legajos[i]){
            break;
        }else{
            index = leg;
            break;
        }
    }
    return index;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam){
    int i;

    for(i=0; i<tam; i++){
        printf("\n\tLegajo: %d\n\tNombre: %s\n\tNota 1: %d\n\tNota 2: %d\n\tPromedio: %.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i]);
    }
}

/**--------------FUNCIONES DEL ABM--------------------*/

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam){
    int index, i;
    char auxNom[20], auxNotUno[20], auxNotDos[20];


    for(i=0;i<tam;i++){
        index = buscarLibre(legajos, tam);
        if(index!=-1){
                legajos[i] = index;

                if(!getStringLetras("\n\tIngrese nombre: ", auxNom)){
                    printf("\n\tERROR! El nombre debe contener solo letras.\n");
                    break;
                }
                fflush(stdin);
                strcpy(nombres[i],auxNom);

                if(!getStringNumeros("\n\tIngrese primer nota: ",auxNotUno)){
                    printf("\n\tERROR! La nota debe tener solo numeros.\n");
                    break;
                }
                nota1[i] = atoi(auxNotUno);

                if(!getStringNumeros("\n\tIngrese segunda nota: ",auxNotDos)){
                    printf("\n\tERROR! La nota debe tener solo numeros.\n");
                    break;
                }
                nota2[i] = atoi(auxNotDos);

                promedio[i] = calcularPromedio(nota1[i],nota2[i]);

                printf("\n\tALUMNO DADO DE ALTA!\n");

        }else{
            break;
        }
    }
            return index;
}

int modificarAlumno(int legajo[], char nombre[][20], int not1[], int not2[], float promedio[], int tam){
    int i, index = 0, leg;
    char auxNom[20], legAux[20], not1Aux[20], not2Aux[20], auxLeg[20];

    if(!getStringNumeros("\n\tIngrese nuevo legajo: ",auxLeg)){
            printf("\n\tERROR! El legajo debe tener solo numeros.\n");
        }
    leg = atoi(auxLeg);

    for(i=0;i<tam;i++){

        if(leg == legajo[i]){
            index = 1;
            printf("\n\tLEGAJO ENCONTRADO!\n");

            printf("\n\tEl nombre actual es: %s",nombre[i]);
            if(!getStringLetras("\n\tIngrese nuevo nombre: ", auxNom)){
                printf("\n\tERROR! El nombre debe contener solo letras.\n");
                break;
            }
            fflush(stdin);
            strcpy(nombre[i],auxNom);

            printf("\n\tEl legajo es: %d",legajo[i]);
            if(!getStringNumeros("\n\tIngrese nuevo legajo: ",legAux)){
                printf("\n\tERROR! El legajo debe tener solo numeros.\n");
                break;
            }
            legajo[i] = atoi(legAux);

            printf("\n\tLa nota 1 es: %d",not1[i]);
            if(!getStringNumeros("\n\tIngrese la primer nota: ",not1Aux)){
                printf("\n\tERROR! La nota debe tener solo numeros.\n");
                break;
            }
            not1[i] = atoi(not1Aux);

            printf("\n\tLa nota 2 es: %d",not2[i]);
            if(!getStringNumeros("\n\tIngrese la segunda nota: ",not2Aux)){
                printf("\n\tERROR! La nota debe tener solo numeros.\n");
                break;
            }
            not2[i] = atoi(not2Aux);

            promedio[i] = calcularPromedio(not1[i],not2[i]);

            printf("\n\tALUMNO MODIFICADO!\n\tNombre: %s\n\tLegajo: %d\n\tPrimer nota: %d\n\tSegunda nota: %d\n\tPromedio: %.2f\n",nombre[i],legajo[i],not1[i],not2[i],promedio[i]);

        }
    }
    if(index == 0){
        printf("\n\tNO EXISTE EL ALUMNO!\n");
    }

    return 0;
}

int borrarAlumno(int legajo[], char nombre[][20], int not1[], int not2[], int tam){
    int index = 0, i, leg;
    char auxLeg[20];

    if(!getStringNumeros("\n\tIngrese legajo: ",auxLeg)){
            printf("\n\tERROR! El legajo debe tener solo numeros.\n");
    }
    leg = atoi(auxLeg);
    for(i=0;i<tam;i++){
        if(leg == legajo[i]){
            index = 1;
            legajo[i] = 0;
            printf("\n\tALUMNO DADO DE BAJA!\n");
            break;
        }
    }
    if(index == 0){
        printf("\n\tNO EXISTE EL ALUMNO\n");
    }
    return index;
}

void ordenarAlumnos(int legajo[], char nombre[][20], int not1[], int not2[], float promedio[],int tam){
    int i, j, auxLeg = 0, auxNot1 = 0, auxNot2 = 0;
    char aux[20];

    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(stricmp(nombre[i],nombre[j])>0){
                strcpy(aux,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],aux);

                auxLeg = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxLeg;

                auxNot1 = not1[i];
                not1[i] = not1[j];
                not1[j] = auxNot1;

                auxNot2 = not2[i];
                not2[i] = not2[j];
                not2[j] = auxNot2;
            }
        promedio[i] = calcularPromedio(not1[i],not2[i]);
        }
    }

    for(i=0;i<tam;i++){
        printf("\n\tNombre: %s -- Legajo: %d -- Nota 1: %d -- Nota 2: %d -- Promedio: %.2f\n",nombre[i],legajo[i],not1[i],not2[i],promedio[i]);
    }
}
/**--------------FUNCIONES MATEMATICAS--------------------*/

float calcularPromedio(int not1, int not2){
    float promedio;
    promedio = (float)(not1+not2)/2;
    return promedio;
}
