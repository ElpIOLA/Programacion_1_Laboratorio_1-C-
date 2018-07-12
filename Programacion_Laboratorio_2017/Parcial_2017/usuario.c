#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "usuario.h"
#define OCUPADO 0
#define LIBRE 1

int eUsua_init(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eUsua_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsua_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idGenerica>retorno)
                    {
                         retorno=listado[i].idGenerica;
                    }

            }
        }
    }

    return retorno+1;
}


int eUsua_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsua_mostrarUno(eUsuario parametro){
    printf("\n\tNombre: %s - ID: %d\n\n",parametro.nombre,parametro.idGenerica);
    return 0;
}

int eUsua_mostrarListado(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eUsua_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eUsua_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUsua_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

/**------------------------A B M-------------------------------------*/

int eUsua_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUsua_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsua_siguienteId(listado,limite);

            if(!getStringLetras("\n\tIngrese nombre: ",nombre)){
                printf("\n\tERROR! El nombre debe contener solo letras.");
            }
            fflush(stdin);
            retorno = 0;
            strcpy(listado[indice].nombre,nombre);
            listado[indice].idGenerica = id;
            listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}

int eUsua_baja(eUsuario listado[] ,int limite, int id){
    int retorno = -1, lista, index;
    char aux_id[21];

    if(limite > 0 && listado != NULL){

        lista = eUsua_mostrarListado(listado,limite);
        if(lista == 0){
            if(getStringNumeros("\n\tIngrese ID del usuario a eliminar: ",aux_id)){
                printf("\n\tEl ID debe ser numerico.");
            }
            id = atoi(aux_id);
        }
        retorno = -2;
        index = eUsua_buscarPorId(listado,limite,id);
        if(index >= 0){
            retorno = 0;
            listado[index].estado = LIBRE;
        }
    }
    return retorno;
}

int eUsua_modificacion(eUsuario listado[] ,int limite, int id){
    int retorno = -1, lista, index;
    char aux_id[21], auxNom[31];

    if(limite > 0 && listado != NULL){

        lista = eUsua_mostrarListado(listado,limite);
        if(lista == 0){
            if(getStringNumeros("\n\tIngrese ID del usuario a eliminar: ",aux_id)){
                printf("\n\tEl ID debe ser numerico.");
            }
            id = atoi(aux_id);
        }
        retorno = -2;
        index = eUsua_buscarPorId(listado,limite,id);
        if(index >= 0){
            retorno = 0;
            if(!getStringLetras("\n\tIngrese nuevo nombre: ",auxNom)){
                printf("\n\tERROR!El nombre debe contener solo letras.");
            }
            fflush(stdin);
            strcpy(listado[index].nombre,auxNom);
        }
    }
    return retorno;
}


