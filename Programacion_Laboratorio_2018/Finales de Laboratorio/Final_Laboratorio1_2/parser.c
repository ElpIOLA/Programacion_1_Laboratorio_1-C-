#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "Caracteres.h"

int buscarArchivo(char* direccion)
{
    int index = -1;
    if(direccion != NULL)
    {
        FILE* archivo = fopen(direccion,"r");
        if(archivo == NULL)
        {
            index = 0;
        }
        else
        {
            index = 1;
        }
    }
    return index;
}

int lectura(ArrayList* lista, char* direccion)
{
    char string[50];
    eCaracter* aux;
    int retorno = -1;
    FILE* archivo = fopen(direccion, "r");
    if(lista != NULL && archivo != NULL)
    {
        while(!feof(archivo))
        {
            aux = constructor();

            fgets(string, 50, archivo);

            set_Id(aux, lista->len(lista) + 1);
            set_Caracter(aux, strtok(string, ",")[0]);
            set_Nombre(aux, strtok(NULL, ","));
            set_Vocal(aux, atoi(strtok(NULL, ",")));
            set_Consonante(aux, atoi(strtok(NULL, ",")));
            set_Numero(aux, atoi(strtok(NULL, ",")));
            lista->add(lista, aux);
        }
        retorno = 1;
        fclose(archivo);
    }
    return retorno;
}

void escritura(ArrayList* lista, char* path)
{
    eCaracter* aux;
    int i;
    int flag = -1;
    if(path != NULL && lista != NULL)
    {
        FILE* archivo = fopen(path,"w");
        if(archivo != NULL)
        {
            fprintf(archivo, "Caracter,Nombre,Vocal,Consonante,Numero\n");
            for(i = 0; i < lista->len(lista); i++)
            {
                aux = lista->get(lista, i);
                fprintf(archivo, "%-12c,%-12s,%-12d,%-12d,%-12d\n", get_Caracter(aux), get_Nombre(aux), get_Vocal(aux), get_Consonante(aux), get_Numero(aux));
            }
            flag = 1;
            fclose(archivo);
        }
    }

    if(flag == 1)
        printf("\n\tArchivo %s guardado exitosamente\n", path);
    else
        printf("Error: No se pudo guardar el archivo");
}
