#include <stdio.h>
#include <stdlib.h>
#include "funcionValidar.h"

int menu(){

    char aux_resp[21];
    int resp;

    printf("-------------------------------------------------------------------------------");
    printf("\n1-.ALTA PROPIETARIO"); printf("\t\t4-.ALTA AUTOMOVIL\n");
    printf("\n2-.MODIFICAR PROPIETARIO"); printf("\t5-.BAJA AUTOMOVIL\n");
    printf("\n3-.BAJA PROPIETARIO\n\n");
    printf("-------------------------------------------------------------------------------");
    printf("\n\n6-.RECAUDACION TOTAL"); printf("\t7-.RECAUDACION TOTAL POR MARCA\n");
    printf("\n");
    printf("-------------------------------------------------------------------------------");
    printf("\n8-.LISTADO DE PROPIETARIOS CON SUS AUTOS\n");
    printf("\n9-.LISTADO POR AUDI\n");
    printf("\n10-.LISTADO POR PATENTE\n\n");
    printf("-------------------------------------------------------------------------------");
    printf("\n11-.LISTADO DE PROPIETARIOS"); printf("\t12-.LISTADO DE AUTOS"); printf("\t13-.Salir\n");


    if(!getStringNumeros("\n\tINGRESE OPCION: ",aux_resp)){

    }
    resp = atoi(aux_resp);
    system("cls");
    return resp;
}

void menu_precios(){
    printf("\n\t MARCA"); printf("\t\t\tPRECIO POR HORA\n");
    printf("\t---------------------------------------------------");
    printf("\n\t -ALPHA_ROMEO\t\t$150");
    printf("\n\t -FERRARI\t\t$175");
    printf("\n\t -AUDI\t\t\t$200");
    printf("\n\t -OTROS\t\t\t$250");
    printf("\n\t---------------------------------------------------\n");
}
