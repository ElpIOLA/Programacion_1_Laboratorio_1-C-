#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[30], apellido[30], nombreYapellido[30];

    printf("\n\tIngrese Nombre: ");
    gets(nombre);
    printf("\n\tIngrese Apellido: ");
    gets(apellido);

    if(strcmp(nombre,apellido)!=0){
        strcpy(nombreYapellido,strcat(nombre,apellido)); /**STRCAT: CONCATENA DIFERENTES VECTORES*/
        printf("\n\tNombre y Apellido: [ %s ]\n",nombreYapellido);
    }else{
        printf("\n\tEl nombre y apellido deben ser diferentes.\n");
    }

    return 0;
}
