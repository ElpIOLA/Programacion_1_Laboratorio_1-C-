#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "ABM.h"
int main()
{
    int index, opcion;
    ArrayList* ListaPersona;
    ListaPersona = al_newArrayList();

    ArrayList* ListaEliminados;
    ListaEliminados = al_newArrayList();

    while(opcion != 5)
    {
        printf("\n\t1.AGREGAR PERSONA!\n");
        printf("\n\t2.BORRAR PERSONA!\n");
        printf("\n\t3.MODIFICAR PERSONA!\n");
        printf("\n\t4.LISTA PERSONA!\n");
        printf("\n\t5.SALIR!\n");
        printf("\n\tRESPUESTA: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                index = add_Persona(ListaPersona);
                if(index == 1)
                {
                    printf("\n\tPERSONA AGREGADA!\n");
                }
                break;
            case 2:
                index = delete_Persona(ListaPersona,ListaEliminados);
                if(index == 1)
                {
                    system("cls");
                    printf("\n\tPERSONA BORRADA!\n");
                }
                break;
            case 3:
                index = modificar_Persona(ListaPersona);
                if(index == 1)
                {
                    system("cls");
                    printf("\n\tPERSONA MODIFICADA!");
                }
                break;
            case 4:
                index = listadoDePersonas(ListaPersona);
                if(index == 1)
                {
                    printf("\n\tLISTADO DE PERSONAS!\n");
                }
                break;
            case 5:
                opcion = 5;
                break;
        }
    }

    return 0;
}
