#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "aka.h"

#define CANTPROD 5
#define CANTPROVEE 5
#define CANTPRODPROVE 25

int main()
{
    int opcion,flag = 0;
    char seguir = 's';
    eProducto producto[CANTPROD];
    eProvedoor proveedor[CANTPROVEE];
    pIOLA codigos[CANTPRODPROVE];

    init(producto, proveedor, codigos);

    while(seguir != 'n')
    {

    opcion = menu();

    switch(opcion)
    {
        case 1:
            agregarProducto(producto,proveedor,codigos);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                modificarProducto(producto,proveedor,codigos);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                borrarProducto(producto, proveedor, codigos);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                imformarProducto(producto, proveedor, codigos);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 5:
            if(flag == 1)
            {
                listaOrdenada(producto, proveedor, codigos);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        printf("\nDesea realizar otra operacion? [s/n]: ");
        fflush(stdin);
        scanf ("%c",&seguir);
    }
}
    return 0;
}
