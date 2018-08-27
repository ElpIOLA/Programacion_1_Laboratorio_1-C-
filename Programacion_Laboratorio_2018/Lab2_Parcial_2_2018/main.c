#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
int main()
{
    char* Direccion_Archivo="lista_empleados.txt";
    int opcion, index;

    ArrayList* listaEmpleados;
    listaEmpleados = al_newArrayList();

    ArrayList* listaMayores;
    listaMayores = al_newArrayList();

    while(opcion != 4)
    {
        printf("\n\t1.CARGAR ARCHIVO!");
        printf("\n\t2.MOSTRAR EMPLEADOS!");
        printf("\n\t3.LISTA MAYORES DE 30!");
        printf("\n\tRESPUESTA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:

                index = cargar_Archivo(listaEmpleados,Direccion_Archivo);
                if(index == 1)
                {
                    printf("\n\tDATOS CARGADOS!\n");
                }
                break;
            case 2:
                listadoDePersonas(listaEmpleados);
                break;
            case 3:
                listaMayoresDeTreinta(listaEmpleados,listaMayores);
                break;
            case 4:
                opcion = 4;
                break;
            default:
                printf("\n\tERROR!\n");
        }
    }

    return 0;
}
