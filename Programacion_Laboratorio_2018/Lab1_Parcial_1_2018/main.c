#include <stdio.h>
#include <stdlib.h>
#include "propietario.h"
#include "automovil.h"
#include "funcionValidar.h"
#include "estacionamiento.h"
#include "menu.h"

#define CANT_PROPIETARIO 20
#define CANT_AUTOMOVIL 30

int main()
{
    ePropietario propietario[CANT_PROPIETARIO];
    inicializar_propietario(propietario,CANT_PROPIETARIO);
    eAuto automoviles[CANT_AUTOMOVIL];
    inicializar_auto(automoviles,CANT_AUTOMOVIL);

    datos_hard_propietario(propietario,CANT_PROPIETARIO);
    datos_hard_autos(automoviles,CANT_AUTOMOVIL);
    datos_hard_egresos(CANT_AUTOMOVIL);

    char seguir = 's';
    int opcion = 0, index;

    printf("\n\t\t\tDATOS CARGADOS!\n");

    while(seguir == 's'){

        opcion = menu();

        switch(opcion){
            case 1:
                index = alta_propietario(propietario,CANT_PROPIETARIO);
                if(index == 0){
                    printf("\n\tPROPIETARIO DADO DE ALTA!\n");
                }else if(index == -2){
                    printf("\n\tERROR! NO HAY ESPACIO EN LA MEMORIA!\n");
                }else if(index == -3){
                    printf("\n\tERROR! NO SE PUEDEN INGRESAR MAS PROPIETARIOS!\n");
                }else if(index == -4){
                    printf("\n\tERROR! EL NOMBRE INGRESADO NO ES VALIDO!\n");
                }else if(index == -5){
                    printf("\n\tERROR! EL APELLIDO INGRESADO NO ES VALIDO!\n");
                }else if(index == -6){
                    printf("\n\tERROR! LA DIRECCION NO ES VALIDA!\n");
                }else if(index == -7){
                    printf("\n\tERROR! LA TARJETA NO ES VALIDA!\n");
                }
                break;
            case 2:
                index = modificar_propietario(propietario,CANT_PROPIETARIO);
                if(index == 0){
                    printf("\n\tTARJETA MODIFICADA!\n");
                }else if(index == -2){
                    printf("\n\tERROR! LA ID INGRESADA NO ES VALIDA!\n");
                }else if(index == -3){
                    printf("\n\tERROR! NO EXISTE EL PROPIETARIO!\n");
                }else if(index == -4){
                    printf("\n\tERROR! SU RESPUESTA NO ES VALIDA!\n");
                }else if(index == -5){
                    printf("\n\tERROR! LA TARJETA INGRESADA NO ES VALIDA!\n");
                }else if(index == -6){
                    printf("\n\tUSTED CANCELO LA MODIFICACION!\n");
                }else if(index == -7){
                    printf("\n\tERROR! SU RESPUESTA NO ES VALIDA\n");
                }
                break;
            case 3:
                index = baja_propietario(propietario,CANT_PROPIETARIO,automoviles,CANT_AUTOMOVIL);
                if(index == 0){
                    printf("\n\tPROPIETARIO DADO DE BAJA!\n");
                }else if(index == -2){
                    printf("\n\tERROR! EL ID INGRESADO NO ES VALIDO\n");
                }else if(index == -3){
                    printf("\n\tERROR! EL PROPIETARIO NO ESTA REGISTRADO\n");
                }else if(index == -4){
                    printf("\n\tERROR! EL PROPIETARIO NO TIENE NINGUN AUTO ESTACIONADO\n");
                }else if(index == -5){
                    printf("\n\tERROR! LA RESPUESTA NO ES VALIDA\n");
                }else if(index == -4){
                    printf("\n\tUSTED CANCELO LA BAJA DE PROPIETARIO\n");
                }
                break;
            case 4:
                index = alta_automovil(automoviles,CANT_AUTOMOVIL,propietario,CANT_PROPIETARIO);
                if(index == 0){
                    printf("\n\tAUTOMOVIL DADO DE ALTA!\n");
                }else if(index == -2){
                    printf("\n\tERROR! EL ID INGRESADO NO ES VALIDO!\n");
                }else if(index == -3){
                    printf("\n\tERROR! EL PROPIETARIO NO ESTA REGISTRADO!\n");
                }else if(index == -4){
                    printf("\n\tERROR! NO HAY ESPACIO EN EL VECTOR DE AUTOS!\n");
                }else if(index == -5){
                    printf("\n\tERROR! NO SE PUEDEN ESTACIONAR MAS AUTOS!\n");
                }else if(index == -6){
                    printf("\n\tERROR! LA PATENTE NO ES VALIDA!\n");
                }else if(index == -7){
                    printf("\n\tERROR! LA MARCA NO ES VALIDA!\n");
                }else if(index == -8){
                    printf("\n\tERROR! LA MARCA INGRESADA NO ESTA ENTRE [1 - 4]\n");
                }
                break;
            case 5:
                index = baja_auto(automoviles,CANT_AUTOMOVIL,propietario,CANT_PROPIETARIO);
                if(index == -2){
                    printf("\n\tERROR! EL ID INGRESADO NO ES VALIDO\n");
                }else if(index == -3){
                    printf("\n\tERROR! LA RESPUESTA NO ES VALIDA\n");
                }else if(index == -4){
                    printf("\n\tUSTED CANCELO EL AGRESO DEL AUTO\n");
                }
                break;
            case 6:
                index = recaudacion_Total();
                printf("\n\tLA RECAUDACION TOTAL ES: %d\n",index);
                break;
            case 7:
                recaudacion_por_marca();
                break;
            case 8:
                index = listado_Propietario_ConAutos(propietario,CANT_PROPIETARIO,automoviles,CANT_AUTOMOVIL);
                if(index == -2){
                    printf("\n\tERROR! INGRESO MAL EL ID\n");
                }else if(index == -3){
                    printf("\n\tERROR! NO ESTA REGISTRADO EL PROPIETARIO!\n");
                }else if(index == -4){
                    printf("\n\tERROR! EL PROPIETARIO NO TIENE AUTOS\n");
                }
                break;
            case 9:
                listado_Audi(automoviles,CANT_AUTOMOVIL,propietario,CANT_PROPIETARIO);
                break;
            case 10:
                listado_por_patente(automoviles,CANT_AUTOMOVIL,propietario);
                break;
            case 11:
                lista_propietario(propietario,CANT_PROPIETARIO);
                break;
            case 12:
                lista_autos(automoviles,CANT_AUTOMOVIL);
                break;
            case 13:
                seguir = 'n';
                break;
            default:
                printf("\n\tERROR! INGRESE UNA OPCION ENTRE [1-13]\n");
        }
    }
    return 0;
}
