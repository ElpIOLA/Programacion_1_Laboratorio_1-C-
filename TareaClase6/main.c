#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 20

int main()
{
    char nombre[CANT], apellido[CANT], nombreYapellido[CANT];

    printf("\n\tIngrese Nombre: ");
    gets(nombre);
    printf("\n\tIngrese Apellido: ");
    gets(apellido);

    if(stricmp(nombre,apellido)!=0){
        strcpy(nombreYapellido,strcat(nombre,apellido)); /**STRCAT: CONCATENA DIFERENTES VECTORES*/
        printf("\n\tNombre y Apellido: [ %s ]\n",nombreYapellido);
    }else{
        printf("\n\tEl nombre y apellido deben ser diferentes.\n");
    }

    return 0;
}
