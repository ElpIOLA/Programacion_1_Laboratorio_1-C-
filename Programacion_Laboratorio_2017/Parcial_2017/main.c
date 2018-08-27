#include <stdio.h>
#include <stdlib.h>
#include "publicacion.h"
#include "funcionValidar.h"
#define CANTIDAD 10

int main()
{
    char seguir = 's', respuesta[21];
    int opcion = 0, index = 0;

    eUsuario listadoGenerico[CANTIDAD];
    eUsua_init(listadoGenerico,CANTIDAD);

    eProductos listadoProducto[CANTIDAD];
    eProd_init(listadoProducto,CANTIDAD);

    while(seguir == 's'){

        printf("\n\t1-.ALTA\n");
        printf("\n\t2-.MODIFICAR\n");
        printf("\n\t3-.BAJA\n");
        printf("\n\t4-.PUBLICAR PRODUCTO\n");
        printf("\n\t5-.MODIFICAR PUBLICACION\n");
        printf("\n\t6-.CANCELAR PUBLICACION\n");


        if(!getStringNumeros("\n\tRespuesta: ",respuesta)){
            printf("\n\tERROR! Su respuesta debe ser un numero.");
        }
        opcion = atoi(respuesta);

        switch(opcion){
            case 1:
                index = eUsua_alta(listadoGenerico,CANTIDAD);
                if(index == 0){
                    system("cls");
                    printf("\n\tUSUARIO DADO DE ALTA!\n\n");
                }else if(index == -2){
                    system("cls");
                    printf("\n\tERROR! NO HAY ESPACIO.\n\n");
                }
                break;
            case 2:
                index = eUsua_modificacion(listadoGenerico,CANTIDAD,index);
                if(index == 0){
                    system("cls");
                    printf("\n\tUSUARIO MODIFICADO!\n\n");
                }else if(index == -2){
                    system("cls");
                    printf("\n\tERROR! NO SE ENCONTRO ID.\n\n");
                }
                break;
            case 3:
                index = eUsua_baja(listadoGenerico,CANTIDAD,index);
                if(index == 0){
                    system("cls");
                    printf("\n\tUSUARIO DADO DE BAJA!\n\n");
                }else if(index == -2){
                    system("cls");
                    printf("\n\tERROR! NO SE ENCONTRO ID.\n\n");
                }
                break;
            case 4:
                index = publicar_producto(listadoProducto,CANTIDAD,listadoGenerico,index);
                if(index == 0){
                    system("cls");
                    printf("\n\tPUBLICACION LOGRADA!\n");
                    printf("%d",index);
                }else if(index == -2){
                    system("cls");
                    printf("\n\tNO EXISTE EL USUARIO!\n");
                }else if(index == -3){
                    system("cls");
                    printf("\n\tNO HAY ESPACIO LIBRE PARA EL PRODUCTO!\n");
                }else if(index == -4){
                    system("cls");
                    printf("\n\tEL VECTOR PRODUCTOS ESTA LLENO!\n");
                }
                break;
            case 5:
                index = modificar_publicacion(listadoProducto,CANTIDAD,listadoGenerico,index);
                if(index == 0){
                    system("cls");
                    printf("\n\tMODIFICACION LOGRADA!\n");
                }else if(index == -2){
                    system("cls");
                    printf("\n\tNO EXISTE EL USUARIO!\n");
                }else if(index == -3){
                    system("cls");
                    printf("\n\tNO HAY ESPACIO LIBRE PARA EL PRODUCTO!\n");
                }else if(index == -4){
                    system("cls");
                    printf("\n\tEL VECTOR PRODUCTOS ESTA LLENO!\n");
                }
                break;
            case 6:
                index = cancelar_publicacion(listadoProducto,CANTIDAD,listadoGenerico,index);
                if(index == 0){
                    system("cls");
                    printf("\n\tPUBLICACION CANCELADA!\n");
                }else if(index == -2){
                    system("cls");
                    printf("\n\tNO EXISTE EL USUARIO!\n");
                }else if(index == -3){
                    system("cls");
                    printf("\n\tEL PRODUCTO NO SE ENCUENTRA EN LA LISTA\n");
                }else if(index == -4){
                    system("cls");
                    printf("\n\tNO EXISTE EL PRODUCTO!\n");
                }
                break;
        }
    }
    return 0;
}
