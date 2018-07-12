#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char cadena[100], *p_cadena;
    int tem;

    printf("\n\tIngrese alguna palabra: ");
    gets(cadena);

    tem = strlen(cadena);

    p_cadena = (char *)malloc((tem+1)*sizeof(char));

    if(p_cadena != NULL){
        strcpy(p_cadena,cadena);
        printf("\n\n\t%s\n",p_cadena);
    }

    return 0;
}

/**
char nombre[21], *p_Nombre;
    int tem;

    strcpy(nombre,"Hernan"); //Hernan\0 = 7

    tem = strlen(nombre); //Obtenemos la cantidad de caracteres que tiene nombre

    p_Nombre = (char *)malloc((tem+1)*sizeof(char)); //Calculamos la memoria que usara la variable

    strcpy(p_Nombre,nombre);

    printf("\n\tNombre: %s\n",p_Nombre);
*/

/**
int *a;

    a = (int *)malloc(sizeof(int));

    *a = 5;
    printf("%p - %d",&a,*a);
*/
