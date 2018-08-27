#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "libreria.h"



int obtenerEspacioLibre(EPersona *lista, int tem){
    int retorno = 0, i;

    if(tem > 0 && lista != NULL)
        retorno = 1;
        for(i=0;i<tem;i++)
            (lista+i)->estado = 0;
    return retorno;
}

int buscarPorDni(EPersona *lista, int dni, int tem){
    int i;

    for(i=0;i<tem;i++){
        if(dni == (lista+i)->dni){
            printf("\n\tEl DNI esta registrado.\n");
            break;
        }else{
            printf("\n\tEl DNI ingresado no esta registrado.\n");
            break;
        }
    }
    return dni;
}

void agregarPersona(EPersona *lista, int tem){
    int i;
    char auxNom[21], auxDni[21], auxEdad[21];
    obtenerEspacioLibre(lista,tem);

    for(i=0;i<tem;i++){
        if((lista+i)->estado == 0){

            if(!getStringLetras("\n\tIngrese nombre: ",auxNom)){
                printf("\n\tError! El nombre debe contener solo letras.\n");
                break;
            }
            fflush(stdin);
            strcpy((lista+i)->nombre,auxNom);

            if(!getStringNumeros("\n\tIngrese Edad: ",auxEdad)){
                printf("\n\tError! La edad debe contener solo numeros y sin coma.\n");
                break;
            }
            (lista+i)->edad = atoi(auxEdad);

            if(!getStringNumeros("\n\tIngrese DNI: ",auxDni)){
                printf("\n\tError! El dni debe contener solo numeros y sin coma.\n");
                break;
            }
            (lista+i)->dni = (double)atoi(auxDni);

            (lista+i)->estado = 1;

            printf("\n\t%s -- %d -- %d\n",(lista+i)->nombre,(lista+i)->edad,(lista+i)->dni);
        }else{
            printf("\n\tNo hay espacio.\n");
        }
    }
}

void borrarPersona(EPersona *lista, int tem){
    int i, aux;
    char auxDni[21];

    if(!getStringNumeros("\n\tIngrese DNI de la persona que desea borrar: ",auxDni)){
        printf("\n\tError! El DNI debe ser un numero y sin coma.\n");
    }
    aux = (double)atoi(auxDni);
    buscarPorDni(lista,aux,tem);

    for(i=0;i<tem;i++){
        if(aux == (lista+i)->dni){
            (lista+i)->estado = 0;
            printf("\n\tPERSONA ELIMINADO.\n");
        }
    }
}

void listaOrdenadaPorNombre(EPersona *lista, int tem){
    int i, j, auxEdad, auxDni;
    char aux[21];

    for(i=0;i<tem-1;i++){
        if((lista+i)->estado == 1){
            for(j=i+1;j<tem;j++){
                if(stricmp((lista+i)->nombre,(lista+j)->nombre)>0){

                strcpy(aux,(lista+i)->nombre);
                strcpy((lista+i)->nombre,(lista+j)->nombre);
                strcpy((lista+j)->nombre,aux);

                auxEdad = (lista+i)->edad;
                (lista+i)->edad = (lista+j)->edad;
                (lista+j)->edad = auxEdad;

                auxDni = (lista+i)->dni;
                (lista+i)->dni = (lista+j)->dni;
                (lista+j)->dni = auxDni;
                }
            }
        }
    }

    for(i=0;i<tem;i++){
        if((lista+i)->estado == 1){
            printf("\n\tNombre: %s - Edad: %d - DNI: %d\n",(lista+i)->nombre,(lista+i)->edad,(lista+i)->dni);
        }
    }
}

void graficoEdades(EPersona *lista, int tem){
    int i,j;
    int menor = 0, adulto = 0, mayor = 0, cont = 0;

    for(i=0;i<tem;i++){
        if((lista+i)->estado == 1){
            if((lista+i)->edad<=18){
                menor ++;
            }else if((lista+i)->edad>35){
                mayor ++;
            }else{
                adulto ++;
            }
            cont ++;
        }
    }

    for(j=cont;j>=0;j--){
        if(menor<=j){
                printf("     ");
            }
            else{
                printf("  *  ");
            }
            if(adulto<=j){
                printf("     ");
            }
            else{
                printf("   *  ");
            }
            if(mayor<=j){
                printf("     \n");
            }
            else{
                printf("  *  \n");
            }
    }
    printf("x<18 18>x<35 x>35\n\n");
}
