#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float factorial(float a);
int main()
{
    system("color 39");
    char seguir='s';
    int opcion=0;
    float a, b, resultado;

    printf("Bienvenido, desea hacer una operacion?\n[s] = Si\n[n] = No\n");
    scanf("%c", &seguir);
    system("cls");
    while(seguir == 's')
    {
        printf("ELIGA UNA OPCION: \n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("QUE OPCION ELIGE? ");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 9)
        {
            printf("Opcion incorrecta.\n");
            printf("Por favor ingrese una opcion del 1 al 9.\n");
            break;
        }

        switch(opcion)
        {
        case 1:
            printf("Operando A: ");
            scanf("%f", &a);
            break;
        case 2:
            printf("Operando B: ");
            scanf("%f", &b);
            break;
        case 3:
            calcuSuma(a, b);
            break;
        case 4:
            calcuRestar(a, b);
            break;
        case 5:
            calcuDiv(a, b);
            break;
        case 6:
            calcuMulti(a, b);
            break;
        case 7:
            factorial(a);
            break;
        case 8:
            calcuSuma(a, b);
            calcuRestar(a, b);
            calcuDiv(a, b);
            calcuMulti(a, b);
            factorial(a);
            break;
        case 9:
            printf("Fin de programa.");
            seguir = 'n';
            break;
        }
    }
    return 0;
}
