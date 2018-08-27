#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define CANT 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona[CANT];

    init(persona);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Funcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarEPersona(persona);
                break;
            case 2:
                borrarPersona(persona);
                break;
            case 3:
                listaOrdenadaPorNombre(persona);
                break;
            case 4:
                graficoEdades(persona);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
