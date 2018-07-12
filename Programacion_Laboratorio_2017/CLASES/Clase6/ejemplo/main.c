#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cant 21
#define ESC 27
int main()
{
    char nombre1[cant];
    char nombre2[cant];
    char aux1[cant * 10];
    char aux2[cant * 10];
    int letras;
    char tecla;
    do
    {
        system("cls");
        do
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]s", aux1);
            letras = strlen(aux1);
        }while(letras >= aux1);

        do
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]s", aux2);
            letras = strlen(aux2);
        }while(letras >= aux2);

        printf("LOS NOMBRES SON CORRECTOS!!!\n");
        strcpy(nombre1, aux1);
        strcpy(nombre2, aux2);

        if(strcmp(nombre1, nombre2) == 0)
        {
            printf("LOS NOMBRES SON IGUALES!!.\n");
        }
        else if(strcmp(nombre1, nombre2) > 0)
        {
            printf("EL PRIMER NOMBRE ES MAYOR!!\n");
        }
        else if(strcmp(nombre1, nombre2) < 0)
        {
            printf("EL SEGUNDO NOMBRE ES MAYOR!!\n");
        }

        printf("\nEl Nombre es: %s", nombre1);

        printf("\nEl Nombre2 es: %s", nombre2);

        printf("\n\nPresione cualquier tecla para continuar... ESC para salir");

        letras = getch();

    }while(letras != ESC);
    return 0;
}
