#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "letra.h"

eLetra* nuevaLetra()
{
    eLetra* nuevo = (eLetra*) malloc(sizeof(eLetra));
    return nuevo;
}

int setId(eLetra* letra, int entero)
{
    int retorno = -1;
    if(letra != NULL && entero > 0)
    {
        letra->id = entero;
        retorno = 1;
    }
    return retorno;
}

int getId(eLetra* letra)
{
    int retorno = -1;
    if(letra != NULL)
    {
        retorno = letra->id;
    }
    return retorno;
}

int setNombre(eLetra* letra, char* string)
{
    int retorno = -1;
    if(letra != NULL && string != NULL)
    {
        strcpy(letra->nombre, string);
        retorno = 1;
    }
    return retorno;
}

char* getNombre(eLetra* letra)
{
    char* retorno = NULL;
    if(letra != NULL)
    {
        retorno = letra->nombre;
    }
    return retorno;
}

int setLetra(eLetra* letra, char c)
{
    int retorno = -1;
    if(letra != NULL)
    {
        //strcpy(letra->letra, c);
        letra->letra = c;
        retorno = 1;
    }
    return retorno;
}

char getLetra(eLetra* letra)
{
    char retorno;
    if(letra != NULL)
    {
        //strcpy(retorno, letra->letra);
        retorno = letra->letra;
    }
    return retorno;
}

int setVocal(eLetra* letra, int entero)
{
    int retorno = -1;
    if(letra != NULL && (entero == 0 || entero == 1))
    {
        letra->vocal = entero;
        retorno = 1;
    }
    return retorno;
}

int getVocal(eLetra* letra)
{
    int retorno = -1;
    if(letra != NULL)
    {
        retorno = letra->vocal;
    }
    return retorno;
}

int setConsonante(eLetra* letra, int entero)
{
    int retorno = -1;
    if(letra != NULL && (entero == 0 || entero == 1))
    {
        letra->consonante = entero;
        retorno = 1;
    }
    return retorno;
}

int getConsonante(eLetra* letra)
{
    int retorno = -1;
    if(letra != NULL)
    {
        retorno = letra->consonante;
    }
    return retorno;
}

void imprimir(eLetra* letra)
{
    if(letra != NULL)
    {
        printf("%-10d %-10c %-10s %-10d %-10d\n", getId(letra),getLetra(letra), getNombre(letra), getVocal(letra), getConsonante(letra));
    }
}

void imprimirTodos(ArrayList* lista)
{
    int i;
    if(lista != NULL)
    {
        printf("%-10s %-10s %-10s %-10s %-10s\n", "ID","LETRA", "NOMBRE", "VOCAL", "CONSONANTE");
        for(i = 0; i < lista->len(lista); i++)
        {
            imprimir(lista->get(lista, i));
        }
    }
}

void completarVocal(eLetra* letra)
{
    if(letra != NULL)
    {
        if(isalpha(getLetra(letra)))
        {
            if(tolower(getLetra(letra)) == 'a' || tolower(getLetra(letra)) == 'e' || tolower(getLetra(letra)) == 'i' || tolower(getLetra(letra)) == 'o' || tolower(getLetra(letra)) == 'u')
                setVocal(letra, 1);
        }
    }
}
void completarConsonante(eLetra* letra)
{
    if(letra != NULL)
    {
        if(getVocal(letra) == 0)
            setConsonante(letra, 1);
    }
}

void completarLetra(ArrayList* lista)
{
    int i;
    eLetra* aux;
    if(lista != NULL)
    {
        for(i = 0; i < lista->len(lista); i++)
        {
            aux = lista->get(lista, i);
            completarVocal(aux);
            completarConsonante(aux);
        }
    }

}

void filtrarRepetidos(ArrayList* original, ArrayList* filtrada, char* string)
{
    ArrayList* guardadas = al_newArrayList();
    eLetra* aux;
    int i, j;
    for(i = 0; i < strlen(string); i++)
    {
        if(guardadas->contains(guardadas, string[i]))
        {
            continue;
        }
        guardadas->add(guardadas, string[i]);
        for(j = 0; j < original->len(original); j++)
        {
            aux = original->get(original, j);
            if(string[i] == getLetra(aux))
            {
                filtrada->add(filtrada, aux);
            }
        }
    }
}

void filtrarDepurados(ArrayList* lista, ArrayList* filtrada, char* string)
{
    ArrayList* guardadas = al_newArrayList();
    int flag = 0;
    eLetra* aux;
    char letra;
    int i, j;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        letra = getLetra(aux);
        for(j = 0; j < strlen(string); j++)
        {
            if(string[j] == letra)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0 && !guardadas->contains(guardadas, aux->letra))
        {
            filtrada->add(filtrada, aux);
            guardadas->add(guardadas, aux->letra);
        }
        else
            flag = 0;
    }
}

int comparar(void* primero,void* segundo)
{
    int retorno = 0;
    eLetra* primera = (eLetra*) primero;
    eLetra* segunda = (eLetra*) segundo;

    if(getLetra(primera) > getLetra(segunda))
    {
        retorno = -1;
    }
    else if(getLetra(primera) < getLetra(segunda))
    {
        retorno = 1;
    }

    return retorno;
}
