#include <stdio.h>

#include "Dato.h"

int eDato_set_a(eDato* dato, int valor)
{
    int ret = 0;
    if(dato!=NULL && valor>1500)
    {
        dato->a = valor;
        ret = 1;
    }

    return ret;
}

int eDato_set_b(eDato* dato, char* valor)
{
    int ret = 0;
    if(dato!=NULL && valor!=NULL)
    {
        strcpy(dato->b , valor);
        ret = 1;
    }

    return ret;
}

int eDato_get_a(eDato* dato)
{
    int valor = -1;

    if(dato!=NULL)
    {
        valor = dato->a;
    }

    return valor;
}

char* eDato_get_b(eDato* dato)
{
    char* valor;
    if(dato!=NULL)
    {
       valor=dato->b;
    }

    return valor;
}

