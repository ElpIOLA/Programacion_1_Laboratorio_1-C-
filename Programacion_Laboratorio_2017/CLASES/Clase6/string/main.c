#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27
#define CANT 20
int main()
{
    char nombre[CANT];
    char aux[CANT * 10];
    int letras;
    char tecla;

    do
    {
        system("cls");
        do
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]s", aux);
            letras = strlen(aux);
        }while(letras >= 20);

        printf("El nombre es correcto!!\n");

        strcpy(nombre, aux);
        printf("Bienvenido %s\n", nombre);

        printf("Aprete cualquier tecla para continuar.... ESC para salir!!");

        tecla = getch();
    }while(tecla != ESC);
    return 0;
}
