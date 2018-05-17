#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionValidar.h"
#include "Serie.h"

void inicializarSeriesEstado(eSerie series[], int cant){
    int i;

    for(i=0; i<cant; i++){
        series[i].estado = 0;
    }
}

void alta_serie(eSerie serie[], int cantSerie){
    int j;
    int id_series[5] = {100,101,102,103,104};
    char nombre_serie[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    inicializarSeriesEstado(serie,cantSerie);

    for(j=0; j<cantSerie; j++){
        if(serie[j].estado == 0){
            serie[j].idSerie=id_series[j];
            serie[j].cantidadTemporadas=cantidad[j];
            serie[j].estado = 1;
            strcpy(serie[j].nombre, nombre_serie[j]);
            strcpy(serie[j].genero, genero[j]);
        }
    }

    printf("\n\tSERIES DADAS DE ALTA!\n");
}

void baja_serie(eSerie serie[], int cantSerie){
    int i, aux_id;
    char auxId[21];

    if(!getStringNumeros("\n\tIngrese ID Serie: ",auxId)){
        printf("\n\tERROR! La ID debe contener solo numeros.");
    }
    aux_id = atoi(auxId);

    for(i=0;i<cantSerie;i++){
        if(serie[i].estado == 1){
            if(aux_id == serie[i].idSerie){
                serie[i].estado = 0;
                system("cls");
                printf("\n\tSERIE DADA DE BAJA!\n");
                break;
            }else{
                system("cls");
                printf("\n\tSERIE INEXISTENTE!\n");
                break;
            }
        }
    }
}

void modificar_Serie(eSerie serie[], int cantSerie){
    int i, auxID, auxTEM;
    char aux_id[21], aux_nom[31], aux_gen[31], aux_tem[21];

    if(getStringNumeros("\n\tIngrese ID de la serie a modificar: ",aux_id)){
        printf("\n\tERROR! La ID debe contener solo numeros.\n");
    }
    auxID = atoi(aux_id);

    for(i=0;i<cantSerie;i++){
        if(serie[i].estado == 1){
            if(auxID == serie[i].idSerie){

                system("cls");
                printf("\n\tSERIE ENCONTRADA!\n\n");

                printf("\n\tNOMBRE ACTUAL: %s\n",serie[i].nombre);
                if(!getStringLetras("\n\tIngrese nuevo nombre: ",aux_nom)){
                    printf("\n\tERROR! El nombre debe contener solo letras.");
                    break;
                }
                fflush(stdin);
                strcpy(serie[i].nombre,aux_nom);

                printf("\n\tGENERO ACTUAL: %s\n",serie[i].genero);
                if(!getStringLetras("\n\tIngrese nuevo genero: ",aux_gen)){
                    printf("\n\tERROR! El genero debe contener solo letras.");
                    break;
                }
                fflush(stdin);
                strcpy(serie[i].genero,aux_gen);

                printf("\n\tTEMPORADAS ACTUALES: %d\n",serie[i].cantidadTemporadas);
                if(!getStringNumeros("\n\tIngrese nueva cantidad de temporadas: ",aux_tem)){
                    printf("\n\tERROR! Las temporadas deben ser solo numeros.");
                    break;
                }
                auxTEM = atoi(aux_tem);
                serie[i].cantidadTemporadas = auxTEM;

                system("cls");
                printf("\n\tSERIE MODIFICADA!\n");
            }
        }
    }
}
/**-------------------------FUNCIONES DE LISTAS----------------------------------*/

void mostrarListaSeries(eSerie serie[], int cant){

    int i;

    for(i=0;i<cant;i++){
        if(serie[i].estado == 1){
            printf("\n\t%d -- %s -- %s -- %d\n",serie[i].idSerie,serie[i].nombre,serie[i].genero,serie[i].cantidadTemporadas);
        }
    }
}

