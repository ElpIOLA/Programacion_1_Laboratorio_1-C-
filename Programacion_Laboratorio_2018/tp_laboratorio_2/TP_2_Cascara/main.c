#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "funciones.h"
#include "libreria.h"

#define CANT_USUARIO 3

int main()
{
    char seguir='s', auxOpcion[21];
    int opcion=0, index;

    FILE *archivo;
    EPersona lista[CANT_USUARIO];

    obtenerEspacioLibre(lista,CANT_USUARIO);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Crear archivo txt\n");
        printf("6- Leer en archivo de txt\n");
        printf("7- Eliminar archivo de txt\n");
        printf("8- Salir\n");

        if(!getStringNumeros("\n\tIngrese opcion: ",auxOpcion)){
            printf("\n\tERROR! La opcion debe contener solo numeros.");
        }
        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista,CANT_USUARIO);
                break;
            case 2:
                borrarPersona(lista,CANT_USUARIO);
                break;
            case 3:
                listaOrdenadaPorNombre(lista,CANT_USUARIO);
                break;
            case 4:
                graficoEdades(lista,CANT_USUARIO);
                break;
            case 5:
                if(escribirPersonas(lista,CANT_USUARIO,archivo)){
                    system("pause");
                    system("cls");
                    printf("\n\tARCHIVO CREADO!\n");
                }else{
                    printf("\n\tNO SE PUDO CREAR EL ARCHIVO\n");
                }
                break;
            case 6:
                if(!leerPersona(archivo)){
                    printf("\n\tNO SE PUEDE LEER EL ARCHIVO\n");
                }
                break;
            case 7:
                index = borrarArchivo(archivo);
                if(index == 0){
                    printf("\n\tARCHIVO BORRADO!\n");
                }else if(index == -1){
                    printf("\n\tNO SE PUEDE BORRAR EL ARCHIVO\n");
                }else if(index == -2){
                    printf("\n\tNO INGRESO UNA LETRA\n");
                }else if(index == -3){
                    printf("\n\tNO INGRESO UNA LETRA ENTRE 'S' O 'N'\n");
                }else if(index == -4){
                    printf("\n\tUSTED CANCELO LA ELIMINACION DEL ARCHIVO\n");
                }
                break;
            case 8:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
