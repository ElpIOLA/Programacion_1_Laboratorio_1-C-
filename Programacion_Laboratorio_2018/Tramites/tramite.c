#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tramite.h"

eTramite* new_tramite()
{
    eTramite* aux;
    aux = (eTramite*) malloc(sizeof(eTramite));
    return aux;
}

int setId(eTramite* this,int id)
{
    int returnAux = -1;
    if(this != NULL)
    {
        this->idTramite = id;
        returnAux = 0;
    }
    return returnAux;
}

int getId(eTramite* this)
{
    int id = -1;
    if(this != NULL)
    {
        id = this->idTramite;
    }
    return id;
}

int setDni(eTramite* this,char* dni)
{
    int returnAux = -1;
    if(this != NULL && dni != NULL)
    {
        strcpy(this->dni,dni);
        returnAux = 0;
    }
    return returnAux;
}

char* getDni(eTramite* this)
{
    char* dni = NULL;
    if(this != NULL)
    {
        dni = this->dni;
    }
    return dni;
}

int mostrarTramite(eTramite* this)
{
    int mostro = -1;
    if(this != NULL)
    {
        printf("\n\t%d--%s\n",getId(this),getDni(this));
        mostro = 0;
    }
    return mostro;
}

int ordenamientoPorDni(void* tramiteA, void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;

    tramite1 = (eTramite*) tramiteA;
    tramite2 = (eTramite*) tramiteB;

    return strcmp(tramite1->dni,tramite2->dni);
}

int mostrarListaTramite(ArrayList*listado)
{
    int returnAux = -1, i;
    int len;
    eTramite* tramiteActual;
    if(listado!=NULL)
    {
        len = listado->len(listado);
        for(i=0;i<len;i++)
        {
            tramiteActual = (eTramite*)listado->get(listado,i);
            mostrarTramite(tramiteActual);
        }
        returnAux = 0;
    }
    return returnAux;
}

int cargarTramite(ArrayList* listado,int id, char* dni)
{
    int cargo = -1;
    eTramite* tramiteActual;

    if(listado != NULL && id > 0 && dni != NULL)
    {
        tramiteActual = new_tramite();

        setId(tramiteActual,id);
        setDni(tramiteActual,dni);

        listado->add(listado,tramiteActual);
        cargo = 0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listaPendientes,ArrayList* listaAtendidos)
{
    int atendio = -1;
    eTramite* tramiteActual;
    if(listaPendientes != NULL && listaAtendidos != NULL)
    {
        tramiteActual = (eTramite*)listaPendientes->pop(listaPendientes,0);

        listaAtendidos->add(listaAtendidos,tramiteActual);
        mostrarTramite(tramiteActual);
        atendio = 0;
    }
    return atendio;
}
