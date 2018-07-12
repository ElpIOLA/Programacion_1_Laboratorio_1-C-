#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona
{
    char nombre[10];
    int edad;
};

int main()
{

    struct Persona auxiliar;

    int cantidadEscrita, cantidadLeida;

    FILE *aRchivo;
    strcpy(auxiliar.nombre, "Hernan");
    auxiliar.edad = 21;

    aRchivo = fopen("archivo.bin","rb"); /**ABRIMOS EL ARCHIVO*/
    if(aRchivo == NULL)
    {
        printf("\nEl archivo no se puede abrir.\n");
        exit(0);
    }

    cantidadEscrita = fwrite(&auxiliar, sizeof(struct Persona), 1, aRchivo);
    if(cantidadEscrita < 1)
        printf("\nError al escribir el archivo.\n");

    while(!feof(aRchivo)) /**FEOF PREGUNTA SI LLEGAMOS AL FINAL DEL ARCHIVO*/
    {
        cantidadLeida = fread(&auxiliar, sizeof(struct Persona), 1, aRchivo);
        if(cantidadLeida == 1)
            printf("Nombre: %s - Edad: %d",auxiliar.nombre, auxiliar.edad);
    }

    fclose(aRchivo); /**CERRAMOS EL ARCHIVO*/

    return 0;
}
