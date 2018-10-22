#include <stdio.h>
#include <stdlib.h>
#include "funcionValidar.h"

int menu(){
    int opcion = 0;

    char aux_opcion[21];
    printf("\n\t-----------------------------------------------------");
    printf("\n\t\t\tMENU PRINCIPAL\n");
    printf("\t\t\t--------------");
    printf("\n\t1-AGREGAR PELICULA"); printf("\t\t2-BORRAR PELICULA\n");
    printf("\n\t3-MODIFICAR PELICULA"); printf("\t\t4-GENERAR PAGINA WEB\n");
    printf("\n\t5-SALIR");
    printf("\n\t-----------------------------------------------------");
    if(!getStringNumeros("\n\n\tINGRESE OPCION: ",aux_opcion)){
        opcion = -1;
    }
    opcion = atoi(aux_opcion);
    system("cls");
    return opcion;
}
