#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
int main()
{
    char* Direccion_Archivo="lista_empleados.txt";
    char* Direccion_Archivo_Filtrados="lista_filtrados.txt";
    int opcion, index, index2;

    ArrayList* listaEmpleados;
    listaEmpleados = al_newArrayList();

    ArrayList* listaMayores;
    listaMayores = al_newArrayList();

    while(opcion != 9)
    {
        printf("\n\t1.CARGAR ARCHIVO!");
        printf("\n\t2.MOSTRAR EMPLEADOS!");
        printf("\n\t3.FILTRAR EMPLEADOS!");
        printf("\n\t4.ALTA EMPLEADO!");
        printf("\n\t5.BAJA EMPLEADO!");
        printf("\n\t7.GUARDAR CAMBIOS EN ARCHIVO EMPLEADOS!");
        printf("\n\t9.SALIR!");
        printf("\n\tRESPUESTA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                index = cargar_Archivo(listaEmpleados,Direccion_Archivo);
                index2 = cargar_Archivo(listaMayores,Direccion_Archivo_Filtrados);
                if(index == 1 && index2 == 1)
                {
                    system("cls");
                    printf("\n  ********************** EMPLEADOS CARGADOS *********************************\n");
                }
                break;
            case 2:
                system("cls");
                printf("\n     ******************** LISTA DE EMPLEADOS *****************************\n");
                listadoDePersonas(listaEmpleados);
                break;
            case 3:
                listaMayores = listaMayoresDeTreinta(listaEmpleados);
                if(listaMayores != NULL)
                {
                    system("cls");
                    printf("\n     ******************** EMPLEADOS FILTRADOS *****************************\n");
                }
                else
                {
                    printf("\n\tERROR!!!!\n");
                }
                break;
            case 4:
                index = altaEmpleado(listaEmpleados);
                system("cls");
                if(index == 1)
                {
                    printf("\n  ********************** EMPLEADO DADO DE ALTA *********************************\n");
                }
                else if(index == -1)
                {
                    printf("\n\tERROR! LISTA NULL!\n");
                }
                else if(index == -2)
                {
                    printf("\n\tERROR! ID INVALIDA!\n");
                }
                else if(index == -3)
                {
                    printf("\n\tERROR! NOMBRE INVALIDO!\n");
                }
                else if(index == -4)
                {
                    printf("\n\tERROR! SUELDO INVALIDO!\n");
                }
                else if(index == -5)
                {
                    printf("\n\tERROR! EDAD INVALIDA!\n");
                }
                else if(index == -6)
                {
                    printf("\n\tERROR! PROFESION INVALIDA!\n");
                }
                break;
            case 5:
                index = bajaEmpleado(listaEmpleados);
                if(index == 1)
                {
                    system("cls");
                    printf("\n  ********************** EMPLEADO DADO DE BAJA *********************************\n");
                }
                else
                {
                    system("cls");
                    printf("\n\t   SE CANCELO LA BAJA DEL USUARIO.\n\n");
                }
                break;
            case 7:
                index = guardar_en_archivo(listaEmpleados,Direccion_Archivo);
                index2 = guardar_en_archivo(listaMayores,Direccion_Archivo_Filtrados);
                if(index == 1 && index2 == 1)
                {
                    system("cls");
                    printf("\n  ********************** EMPLEADOS GUARDADOS *********************************\n\n");
                }
                break;
            case 9:
                opcion = 9;
                break;
            default:
                printf("\n\tERROR!\n");
        }
    }

    return 0;
}
