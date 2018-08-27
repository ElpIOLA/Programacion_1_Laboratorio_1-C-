#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionValidar.h"

int nuevo_Menu(){
    int opcion, index = 0;
    char auxOpcion[21];

    char buffer1[] = "BIENVENIDO AL MENU DE OPCIONES";
    char buffer2[] = "1.ALTA PERSONA";
    char buffer3[] = "2.BAJA PERSONA";
    char buffer4[] = "3.MODIFICAR PERSONA";
    char buffer5[] = "4.MOSTRAR PERSONAS";
    char buffer6[] = "5.GUARDAR CAMBIOS EN EL ARCHIVO";
    char buffer7[] = "6.CREAR ARCHIVO";
    char buffer8[] = "7.RESTAURAR PERSONA";
    char buffer9[] = "8.SALIR";

    printf("\n\t******** %10s ********\n",buffer1);

    printf("\n\t\t\t %10s \n\t\t\t %10s \n\t\t\t %10s \n\t\t\t %10s \n\t\t\t %10s \n\t\t\t %10s \n\t\t\t %10s \n\t\t %15s",buffer2,buffer3,buffer4,buffer5,buffer6,buffer7,buffer8,buffer9);
    if(!getStringNumeros("\n\t\t\tRESPUESTA: ",auxOpcion)){index = -1;}
    opcion = atoi(auxOpcion);

    if((opcion < 1 && opcion > 8) && (index == -1 || index == 0)){
        return index;
    }
    return opcion;
}
