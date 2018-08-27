#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "producto.h"
#define OCUPADO 0
#define LIBRE 1

int eProd_init(eProductos listado[],int limite){
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idProducto = 0;
        }
    }
    return retorno;
}

int eProd_buscarLugarLibre(eProductos listado[],int limite){
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

int eProd_siguienteId(eProductos listado[] ,int limite){
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idProducto>retorno)
                    {
                         retorno=listado[i].idProducto;
                    }

            }
        }
    }

    return retorno+1;
}

int eProd_buscarPorId(eProductos listado[] ,int limite, int id){
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idProducto == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

