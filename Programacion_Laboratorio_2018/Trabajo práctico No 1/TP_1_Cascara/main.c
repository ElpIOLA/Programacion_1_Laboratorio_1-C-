#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s', aux[20];
    int opcion=0;
    float x = 0,y = 0;

    printf("\n\t\t\t\tBienvenido!\n");
    printf("\t\t¿Desea hacer algun calculo matematico?\n\t[s] = Si\n\t[n] = No\n\tRespuesta: ");
    scanf("%c",&seguir);

    /*Verificamos para que el usuario solo ingrese 's' o 'n'*/

    do{
        if(seguir == 'n' || seguir == 's'){
            break;
        }else{
            printf("\n\t\tERROR!\n\t\tDebe ingresar el caracter [s] o [n]: ");
            while (getchar() != '\n'); //Limpiamos el buffer
            scanf("%c",&seguir);
        }
    }while(seguir != 0);

    while(seguir=='s'){
        printf("\n\t1- Ingresar 1er operando (A=%.2f)\n",x);
        printf("\t2- Ingresar 2do operando (B=%.2f)\n",y);
        printf("\t3- Calcular la suma (A+B)\n");
        printf("\t4- Calcular la resta (A-B)\n");
        printf("\t5- Calcular la division (A/B)\n");
        printf("\t6- Calcular la multiplicacion (A*B)\n");
        printf("\t7- Calcular el factorial (A!)\n");
        printf("\t8- Calcular todas las operacione\n");
        printf("\t9- Salir\n");
        printf("\tEliga una accion entre [1-9]: ");

         /*Verificamos que el usuario ingrese un string o un valor menor a 1 o mayor a 9*/

        do{
            scanf("%s",aux);
            opcion = atoi(aux);
            if(opcion==0){
                system("clear");
                printf("\n\t\t\tERROR!!!\n\tSu respuesta debe ser un numero entre [1-9]: ");
                while (getchar() != '\n'); //Limpiamos el buffer
                scanf("%d",&opcion);
            }
            if(opcion >= 1 && opcion <= 9 && opcion!=0){
                break;
            }else{
                system("clear");
                printf("\n\t\t\tERROR!!!\n\tSu respuesta debe ser un numero entre [1-9]: ");
                while (getchar() != '\n'); //Limpiamos buffer
                scanf("%d",&opcion);
            }
        }while(opcion==0);

        /* Inicio del anidamiento */

        switch(opcion){
        case 1:
            x = validarFloat("\n\tIngrese el operando A: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",x);
            break;
        case 2:
            y = validarFloat("\n\tIngrese el operando B: ","\n\tERROR! Por favor ingrese nuevamente a continuacion...",y);
            break;
        case 3:
            system("clear");
            sumar(x,y);
            break;
        case 4:
            system("clear");
            resta(x,y);
            break;
        case 5:
            system("clear");
            division(x,y);
            break;
        case 6:
            system("clear");
            multiplicacion(x,y);
            break;
        case 7:
            system("clear");
            factorial(x);
            break;
        case 8:
            system("clear");
            printf("\n\t\tTODAS LAS FUNCIONES MATEMATICAS\n");
            sumar(x,y);
            resta(x,y);
            division(x,y);
            multiplicacion(x,y);
            factorial(x);
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
