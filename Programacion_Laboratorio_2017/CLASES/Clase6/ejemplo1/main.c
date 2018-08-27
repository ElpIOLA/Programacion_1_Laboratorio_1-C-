#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESC 27
int main()
{
    char nombre[11];
    char tecla;
    do{
    printf("Ingrese su nombre: ");
    fflush(stdin);
    scanf("%[^\n]s", nombre);
    printf("Hola %s\n", nombre);

    printf("Precione cualquier letra para continuar... ESC para salir!");
    tecla = getch();
    }while(ESC != 27);
    return 0;
}
