#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivos.h"
#include "funciones.h"
#include "libreria.h"

int escribirPersonas(EPersona *lista, int tam, FILE *archivo){
    int retorno = 0,i;
    if(tam > 0 && lista != NULL){

        archivo = fopen("archivo.txt","w");

        for(i=0;i<tam;i++){
            retorno = 1;
            fprintf(archivo, "\n%s ", (lista+i)->nombre);
            fprintf(archivo, " %d ", (lista+i)->edad);
            fprintf(archivo, " %d ", (lista+i)->dni);
        }

        fclose(archivo);
    }
    return retorno;
}

int leerPersona(FILE *archivo){
    int retorno = 0;
    char bufferIn[100];

    archivo = fopen("archivo.txt","r");

    if(archivo != NULL){
        retorno = 1;
        while(!feof(archivo)){
            fgets(bufferIn,100,archivo);
            puts(bufferIn);
        }
    }
    fclose(archivo);
    return retorno;
}

int borrarArchivo(FILE *archivo){
    int retorno = -1;
    char resp[20];

    if(archivo != NULL){
        if(!getStringLetras("\n\tESTA SEGURO QUE DESEA ELIMINAR EL ARCHIVO?\n\t\t-SE PERDERAN TODOS LOS DATOS-\n\t[s] = SI\n\t[n] = NO\n\tRespuesta: ",resp)){}

        retorno = -3;
        if(strcmp(resp,"s")==0 || strcmp(resp,"n")==0){
            if(strcmp(resp,"s")==0){
                if(remove("archivo.txt")==0)
                    retorno = 0;
            }else{
                retorno = -4;
            }
        }
    }
    return retorno;
}






