#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#include "funcionValidar.h"
#include "ABM.h"
#define CANTIDAD 10

int main()
{
    eProvedor listaUser[CANTIDAD];
    eProducto listaProd[CANTIDAD];

    eProg_init(listaUser,listaProd,CANTIDAD);

    int opcion = 0, index = 0;
    char seguir = 's';

    while(seguir == 's'){

        opcion = menu();
        if(opcion > 0){
            switch(opcion){
                case 1:
                    index = alta_usuario(listaUser,CANTIDAD);
                    if(index == 0){
                        system("cls");
                        printf("\n\t\tUSUARIOS REGISTRADOS\n");
                        lista_usuarios(listaUser,CANTIDAD);
                    }else if(index == -2){
                        system("cls");
                        printf("\n\tError! No encuentra espacio libre en el vector.\n");
                    }else if(index == -3){
                        system("cls");
                        printf("\n\tError! No se pueden agregar mas ID.\n");
                    }else if(index == -4){
                        system("cls");
                        printf("\n\tError! Ingreso mal el nombre.\n");
                    }
                    break;
                case 2:
                    index = modificar_usuario(listaUser,CANTIDAD);
                    if(index == 0){
                        printf("%d",index);
                    }else if(index == -3){
                        system("cls");
                        printf("\n\tError! El provedor no esta registrado.\n");
                    }else if(index == -4){
                        system("cls");
                        printf("\n\tError! El nombre debe estar compuesto solo por letras.\n");
                    }
                    break;
                case 3:
                    index = baja_usuario(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("\n\tUSUARIO DADO DE BAJA\n");
                    }else if(index == -3){
                        system("cls");
                        printf("\n\tError! El provedor no esta registrado.\n");
                    }else if(index == -4){
                        system("cls");
                        printf("\n\tError! El provedor no tiene registrado ningun producto.\n");
                    }
                    break;
                case 4:
                    index = publicar_producto(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("\n\t\tPRODUCTOS REGISTRADOS!\n");
                        listar_productos(listaProd,CANTIDAD);
                    }else if(index == -3){
                        system("cls");
                        printf("\n\tError! El provedor no esta registrado.\n");
                    }else if(index == -4){
                        system("cls");
                        printf("\n\tError! No queda lugar para otro producto.\n");
                    }else if(index == -5){
                        system("cls");
                        printf("\n\tError! Has ingresad mal el nombre.\n");
                    }else if(index == -6){
                        system("cls");
                        printf("\n\tError! Has ingresad mal el precio.\n");
                    }else if(index == -7){
                        system("cls");
                        printf("\n\tError! Has ingresad mal el stock.\n");
                    }
                    break;
                case 5:
                    index = modificar_publicacion(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("%d",index);
                    }else if(index == -3){
                        system("cls");
                        printf("\n\tError! El provedor no esta registrado.\n");
                    }else if(index == -4){
                        system("cls");
                        printf("\n\tError! El producto no se encuentra registrado\n");
                    }else if(index == -5){
                        system("cls");
                        printf("\n\tError! No ha escogido un producto registrado!\n");
                    }else if(index == -6){
                        system("cls");
                        printf("\n\tError! El precio debe ser numerico.\n");
                    }else if(index == -7){
                        system("cls");
                        printf("\n\tError! El stock debe ser numerico.\n");
                    }
                    break;
                case 6:
                    index = cancelar_producto(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("%d",index);
                    }else if(index == -3){
                        printf("\n\tError! El provedor no se encuentra registrado!\n");
                    }else if(index == -4){
                        printf("\n\tError! El Producto no se encuentra registrado!\n");
                    }else if(index == -5){
                        printf("\n\tError! El ID no corresponde a un producto registrado!\n");
                    }
                    break;
                case 7:
                    index = comprar_producto(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("\n\tPRODUCTO COMPRADO!\n");
                    }else if(index == -3){
                        printf("\n\tError! El producto no se encuentra registrado!\n");
                    }else if(index == -4){
                        printf("\n\tError! El No quedan mas productos en stock!\n");
                    }else if(index == -5){
                        printf("\n\tError! El usuario no se encuentra registrado!\n");
                    }else if(index == -6){
                        printf("\n\tError! La calificacion debe ser numerica!\n");
                    }else if(index == -7){
                        printf("\n\tError! La calificacion debe ser entre [0 - 10]!\n");
                    }
                    break;
                case 8:
                    index = listar_publicaciones_de_usuario(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    if(index == 0){
                        printf("%d",index);
                    }else if(index == -3){
                        printf("\n\tError! El ID ingresado no pertenece a un usuario registrado!\n");
                    }else if(index == -4){
                        printf("\n\tError! El usuario no tiene registrado ningun producto!\n");
                    }
                    break;
                case 9:
                    listar_publicaciones(listaUser,CANTIDAD,listaProd,CANTIDAD);
                    break;
                case 10:
                    lista_usuarios(listaUser,CANTIDAD);
                    break;
                case 11:
                    seguir = 'n';
                    break;
                default:
                    printf("\n\tLa opcion ingresada debe ser entre [1 - 11]\n\n");
            }

        }else if(opcion == -2){
            system("cls");
            printf("\n\tLA OPCION DEBE SER UN NUMERO!\n\n");
        }

    }
    return 0;
}
