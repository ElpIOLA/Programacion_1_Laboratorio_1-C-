#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define CANT_cLiente 4
#define CANT_aLquiler 5
#define CANT_cLienteaLquiler 10

int main()
{
    cLiente cliente[CANT_cLiente];
    aLquiler alquiler[CANT_aLquiler];

    int opcion = 0, flagClie = 0, flagAlqui = 0;

    inicializar_prog(cliente);

    while(opcion != 6)
    {
        opcion = getInt("\n1-Alta del cliente \n2-Modificar datos del cliente \n3-Baja del cliente \n4-Nuevo alquiler \n5-Fin de alquiler \n6-Informar \n");
        switch(opcion)
        {
            case 1:
                printf("\nALTA\n");
                alta(cliente);
                flagClie = 1;
                break;
            case 2:
                printf("\nModificar\n");
                if(flagClie == 1)
                {
                    modificar(cliente);
                    break;
                }
                else
                {
                    printf("No se han ingresado clientes.\n");
                }
                break;
            case 3:
                printf("\nBAJA\n");
                if(flagClie == 1)
                {
                    baja(cliente);
                    break;
                }
                else
                {
                    printf("No se han ingresado clientes.\n");
                }
                break;
            case 4:
                printf("\nNuevo Alquiler\n");
                if(flagClie == 1)
                {
                    nuevoAlquiler(cliente,alquiler);
                    flagAlqui = 1;
                    break;
                }
                else
                {
                    printf("No se han ingresado clientes.\n");
                }
                break;
            case 5:
                printf("Fin del alquiler\n");
                if(flagClie == 1 && flagAlqui == 1)
                {
                    finDeAlquiler(alquiler);
                }
                else if (flagClie == 0)
                {
                    printf("No se han ingresado clientes.\n");
                }
                else
                {
                    printf("Aun no se han ingresado alquileres\n");
                }
                break;
            case 6:
                printf("\nInformar\n");
                if(flagClie == 1 && flagAlqui == 1)
                {
                    informar(cliente,alquiler);
                    break;
                }
                else if (flagClie == 0)
                {
                    printf("No se han ingresado clientes.\n");
                }
                 else
                {
                    printf("Aun no se han ingresado alquileres\n");
                }
                break;
        }
    }
    return 0;
}
