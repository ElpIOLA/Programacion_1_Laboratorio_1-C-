#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
    Reservar espacio en memoria dinamica para un nombre, y luego liberar la memoria utilizada con free().
*/

int main()
{
    char nombre[20], *p_nombre;
    int tem;

    strcpy(nombre,"Aylen");
    tem = strlen(nombre);
C:\Users\Hernan\Desktop\realloc_Ejercicio_00\realloc_Ejercicio_00.cbp
    p_nombre = (char *)malloc((tem+1)*sizeof(char));

    if(p_nombre == NULL){
        printf("\n\tNO HAY ESPACIO EN MEMORIA\n");
    }else{
        strcpy(p_nombre,nombre);
        printf("\n\t%s\n",p_nombre);
    }

    free(p_nombre);
    printf("\n\t%s\n",p_nombre);
    return 0;
}
