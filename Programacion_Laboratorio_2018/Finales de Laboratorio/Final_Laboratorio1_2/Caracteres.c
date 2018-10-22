#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caracteres.h"

eCaracter* constructor()
{
    eCaracter* auxiliar;
    return auxiliar = (eCaracter*) malloc(sizeof(eCaracter));
}

int set_Nombre(eCaracter* caracter, char* nombre)
{
    int index = 0;
    if(caracter != NULL && nombre != NULL)
    {
        strcpy(caracter->nombre,nombre);
        index = 1;
    }
    return index;
}

char* get_Nombre(eCaracter* caracter)
{
    char* index = NULL;
    if(caracter != NULL)
    {
        index = caracter->nombre;
    }
    return index;
}

int set_Caracter(eCaracter* caracter, char caract)
{
    int index = 0;
    if(caracter != NULL)
    {
        caracter->caracter = caract;
        index = 1;
    }
    return index;
}

char get_Caracter(eCaracter* caracter)
{
    char index = 0;
    if(caracter != NULL)
    {
        index = caracter->caracter;
    }
    return index;
}

int set_Vocal(eCaracter* caracter, int vocal)
{
    int index = -1;
    if(caracter != NULL && (vocal >= 0 && vocal <= 1))
    {
        caracter->vocal = vocal;
        index = 1;
    }
    return index;
}

int get_Vocal(eCaracter* caracter)
{
    int index = -1;
    if(caracter != NULL)
    {
        index = caracter->vocal;
    }
    return index;
}

int set_Consonante(eCaracter* caracter, int consonante)
{
    int index = -1;
    if(caracter != NULL && consonante >= 0 && consonante <= 1)
    {
        caracter->consonante = consonante;
        index = 1;
    }
    return index;
}

int get_Consonante(eCaracter* caracter)
{
    int index = -1;
    if(caracter != NULL)
    {
        index = caracter->consonante;
    }
    return index;
}

int set_Numero(eCaracter* caracter, int numero)
{
    int index = -1;
    if(caracter != NULL && numero >= 0 && numero <= 1)
    {
        caracter->numero = numero;
        index = 1;
    }
    return index;
}

int get_Numero(eCaracter* caracter)
{
    int index = -1;
    if(caracter != NULL)
    {
        index = caracter->numero;
    }
    return index;
}

int set_Id(eCaracter* caracter, int id)
{
    int index = -1;
    if(caracter != NULL && id > 0)
    {
        caracter->id = id;
        index = 1;
    }
    return index;
}

int get_Id(eCaracter* caracter)
{
    int index = -1;
    if(caracter != NULL)
    {
        index = caracter->id;
    }
    return index;
}

int mostrar_Datos(eCaracter* this)
{
    int ret=-1;
    if(this != NULL)
    {
        printf("\n%-10d\t%-10c\t%-10s\t%-10d\t%-10d\t%-10d",get_Id(this),get_Caracter(this), get_Nombre(this), get_Vocal(this),get_Consonante(this), get_Numero(this));
        ret=0;
    }
    return ret;
}

int listaDeDatos(ArrayList* this)
{
    int index = 0, i, len;
    eCaracter* caracteres;
    if(this != NULL)
    {
        len = this->len(this);
        printf("\n%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t","ID","CARACTER","NOMBRE","VOCAL","CONSONANTE","NUMERO");
        for(i=0;i<len;i++)
        {
            caracteres = (eCaracter*) this->get(this,i);
            //filtroUnos_Ceros(caracteres);
            mostrar_Datos(caracteres);
        }
        index = 1;
    }
    return index;
}

int listaDeDatosUnosYCeros(ArrayList* this)
{
    int index = 0, i, len;
    eCaracter* caracteres;
    if(this != NULL)
    {
        len = this->len(this);
        printf("\n%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t","ID","CARACTER","NOMBRE","VOCAL","CONSONANTE","NUMERO");
        for(i=0;i<len;i++)
        {
            caracteres = (eCaracter*) this->get(this,i);
            filtroUnos_Ceros(caracteres);
            mostrar_Datos(caracteres);
        }
        index = 1;
    }
    return index;
}

int filtroUnos_Ceros(void* item)
{
    int index = -1;
    eCaracter* letras;
    if(item != NULL)
    {
        letras = (eCaracter*) item;
        if(letras->caracter == 'a' || letras->caracter == 'e' || letras->caracter == 'i' || letras->caracter == 'o' || letras->caracter == 'u')
        {
            letras->vocal = 1;
        }
        if(letras->caracter != 'a' && letras->caracter != 'e' && letras->caracter != 'i' && letras->caracter != 'o' && letras->caracter != 'u' && !(letras->caracter >= '0' && letras->caracter <= '9'))
        {
            letras->consonante = 1;
        }
        if(letras->caracter >= '0' && letras->caracter <= '9')
        {
            letras->numero = 1;
        }
    }
    return index;
}

void filtrarRepetidos(ArrayList* original, ArrayList* filtrada)
{
    ArrayList* guardar = al_newArrayList();
    int i;
    int cantidad = al_len(original);
    eCaracter* auxiliar;
    if(original != NULL && filtrada != NULL)
    {
        for(i = 0; i < cantidad; i++)
        {
            auxiliar = al_get(original,i);
            if(!guardar->contains(guardar, auxiliar->caracter))
            {
                filtrada->add(filtrada, auxiliar);
                guardar->add(guardar, auxiliar->caracter);
            }
        }
    }
}

int comparar(void* primero,void* segundo)
{
    int retorno = 0;
    eCaracter* primera = (eCaracter*) primero;
    eCaracter* segunda = (eCaracter*) segundo;

    if(get_Caracter(primera) > get_Caracter(segunda))
    {
        retorno = -1;
    }
    else if(get_Caracter(primera) < get_Caracter(segunda))
    {
        retorno = 1;
    }
    return retorno;
}

void filtrarDepurados(ArrayList* original, ArrayList* depurados, char caracter)
{
    ArrayList* guardadas = al_newArrayList();
    eCaracter* listaPrincipal;
    int i, j, flag = 0,
    len  = al_len(original);
    char auxNombre[10];

    if(original != NULL && depurados != NULL)
    {
        for(i = 0; i < len; i++)
        {
            listaPrincipal = al_get(original,i);
            strcpy(auxNombre,get_Nombre(listaPrincipal));

            for(j = 0; j < strlen(auxNombre); j++)
            {
                if(auxNombre[j] == caracter && auxNombre != '\0')
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }

            if(flag == 1 && !guardadas->contains(guardadas, listaPrincipal->nombre))
            {
                depurados->add(depurados, listaPrincipal);
                guardadas->add(guardadas, listaPrincipal->nombre);
            }
            else
                flag = 0;
        }
    }
}
