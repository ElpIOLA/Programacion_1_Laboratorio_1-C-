#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"
#include "parser.h"
#include "letra.h"

int lectura(ArrayList* lista)
{
    char string[50];
    eLetra* aux;
    int retorno = -1;
    FILE* archivo = fopen("datos.csv", "r");
    if(lista != NULL && archivo != NULL)
    {
        while(!feof(archivo))
        {
            aux = nuevaLetra();

            fgets(string, 50, archivo);

            setId(aux, lista->len(lista) + 1);
            setLetra(aux, strtok(string, ",")[0]);
            setNombre(aux, strtok(NULL, ","));
            setVocal(aux, atoi(strtok(NULL, ",")));
            setConsonante(aux, atoi(strtok(NULL, ",")));

            lista->add(lista, aux);
        }
        retorno = 1;
        fclose(archivo);
    }
    return retorno;
}

void escritura(ArrayList* lista, char* path)
{
    eLetra* aux;
    int i;
    int flag = -1;
    if(path != NULL && lista != NULL)
    {
        FILE* archivo = fopen(path,"w");
        if(archivo != NULL)
        {
            for(i = 0; i < lista->len(lista); i++)
            {
                aux = lista->get(lista, i);
                fprintf(archivo, "%c,%s,%d,%d\n", getLetra(aux), getNombre(aux), getVocal(aux), getConsonante(aux));
            }
            flag = 1;
            fclose(archivo);
        }
    }

    if(flag == 1)
        printf("Archivo %s guardado exitosamente\n", path);
    else
        printf("Error: No se pudo guardar el archivo");
}
