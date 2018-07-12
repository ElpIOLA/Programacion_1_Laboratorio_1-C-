#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ABM.h"
#include "funcionValidar.h"

ePerson* new_Persona()
{
    ePerson* aux;
    aux = (ePerson*) malloc(sizeof(ePerson));
    return aux;
}

int set_Legajo(ePerson* this, char* palabra)
{
    int ret = -1, leg;
    char legAux[21];
    if(this != NULL && palabra != NULL)
    {
        if(!getStringNumeros(palabra,legAux))
        {
            ret = -2;
        }
        fflush(stdin);
        leg = atoi(legAux);
        if(leg > 0 && ret != -2){
            this->legajo = leg;
            ret = 1;
        }
    }
    return ret;
}

int get_Legajo(ePerson* this)
{
    int ret = -1;
    if(this != NULL)
    {
        ret = this->legajo;
    }
    return ret;
}

int set_Nombre(ePerson* this, char* palabra)
{
    int ret = -1;
    char nombre[21];
    if(this != NULL && nombre != NULL)
    {
        if(!getStringLetras(palabra,nombre))
        {
            ret = -2;
        }
        fflush(stdin);
        if(ret != -2)
        {
            strcpy(this->nombre,nombre);
            ret = 1;
        }
    }
    return ret;
}

char* get_Nombre(ePerson* this)
{
    char* ret = NULL;
    if(this != NULL)
    {
        ret = this->nombre;
    }
    return ret;
}

int set_Apellido(ePerson* this, char* palabra)
{
    int ret = -1;
    char apellido[21];
    if(this != NULL && palabra != NULL)
    {
        if(!getStringLetras(palabra,apellido))
        {
            ret = -2;
        }
        fflush(stdin);
        if(ret != -2)
        {
            strcpy(this->apellido,apellido);
            ret = 1;
        }
    }
    return ret;
}

char* get_Apellido(ePerson* this)
{
    char* ret = NULL;
    if(this != NULL)
    {
        ret = this->apellido;
    }
    return ret;
}

int set_FechaNacimiento(ePerson* this, char* palabra)
{
    int ret = -1;
    char fecha[31];
    if(this != NULL && palabra != NULL)
    {
        if(!getStringFechaNacimiento(palabra,fecha))
        {
            ret = -2;
        }
        fflush(stdin);
        if(ret != -2)
        {
            strcpy(this->fechaNacimiento,fecha);
            ret = 1;
        }

    }
    return ret;
}

char* get_FechaNacimiento(ePerson* this)
{
    char* ret = NULL;
    if(this != NULL)
    {
        ret = this->fechaNacimiento;
    }
    return ret;
}

int mostrarPersona(ePerson* this)
{
    int ret = -1;
    if(this != NULL)
    {
        printf("\n\t-Legajo: %d \n\t-Nombre: %s \n\t-Apellido: %s \n\t-Fecha de Nacimiento: %s\n",get_Legajo(this),get_Nombre(this),get_Apellido(this),get_FechaNacimiento(this));
        ret = 1;
    }
    return ret;
}

int listadoDePersonas(ArrayList* this)
{
    int returnAux = -1, i;
    int len;
    ePerson* persona;
    if(this!=NULL)
    {
        len = this->len(this);
        for(i=0;i<len;i++)
        {
            persona = (ePerson*)this->get(this,i);
            mostrarPersona(persona);
        }
        returnAux = 1;
    }
    return returnAux;
}

int add_Persona(ArrayList* lista)
{
    int ret = -1, indexLeg, indexNom, indexApe, indexFecha;
    ePerson* persona;
    if(lista != NULL)
    {
        persona = new_Persona();

        indexLeg = set_Legajo(persona,"\n\tINGRESE LEGAJO: ");
        while(indexLeg != 1)
        {
            system("cls");
            indexLeg = set_Legajo(persona,"\n\n\tERROR! LEGAJO INVALIDO!!\n\n\tINGRESE LEGAJO NUEVAMENTE: ");
            if(indexLeg == 1)
            {
                printf("\n\tLEGAJO INGRESADO: %d\n",get_Legajo(persona));
            }
        }

        indexNom = set_Nombre(persona,"\n\tINGRESE NOMBRE: ");
        while(indexNom != 1)
        {
            system("cls");
            indexNom = set_Nombre(persona,"\n\n\tERROR! NOMBRE INVALIDO!!\n\n\tINGRESE NOMBRE NUEVAMENTE: ");
            if(indexNom == 1)
            {
                printf("\n\tNOMBRE INGRESADO: %s\n",get_Nombre(persona));
            }
        }

        indexApe = set_Apellido(persona,"\n\tINGRESE APELLIDO: ");
        while(indexApe != 1)
        {
            system("cls");
            indexApe = set_Apellido(persona,"\n\n\tERROR! APELLIDO INVALIDO!!\n\n\tINGRESE APELLIDO NUEVAMENTE: ");
            if(indexApe == 1)
            {
                printf("\n\tAPELLIDO INGRESADO: %s\n",get_Apellido(persona));
            }
        }

        indexFecha = set_FechaNacimiento(persona,"\n\tINGRESE FECHA DE NACIMIENTO: ");
        while(indexFecha != 1)
        {
            system("cls");
            indexFecha = set_FechaNacimiento(persona,"\n\n\tERROR! FECHA DE NACIMIENTO INVALIDO!!\n\n\tINGRESE FECHA DE NACIMIENTO NUEVAMENTE: ");
            if(indexFecha == 1)
            {
                printf("\n\tFECHA DE NACIMIENTO INGRESADA: %s\n",get_FechaNacimiento(persona));
            }
        }
        system("cls");printf("\n\n");
        lista->add(lista,persona);
        mostrarPersona(persona);
        ret = 1;

    }
    return ret;
}

int delete_Persona(ArrayList* lista, ArrayList* listaBorrar)
{
    int ret = -1, legajo, len, i;
    char legAux[21];
    ePerson* persona;
    if(lista != NULL && listaBorrar != NULL)
    {
        if(!getStringNumeros("\n\tINGRESE LEGAJO: ",legAux))
        {
            ret = -2;
        }
        legajo = atoi(legAux);

        len = lista->len(lista);

        persona = (ePerson*)lista->get(lista,legajo);
        for(i=0;i<len;i++)
        {
            if((persona->legajo+i) == legajo)
            {
                lista->pop(lista,legajo);
                listaBorrar->add(listaBorrar,persona);
                break;
            }
        }
        ret = 1;
    }
    return ret;
}

int modificar_Persona(ArrayList* lista)
{
    ePerson* persona;
    int ret = -1, legajo;
    char legAux[21];
    if(lista != NULL)
    {
        if(!getStringNumeros("\n\tINGRESE LEGAJO: ",legAux))
        {
            ret = -2;
        }
        legajo = atoi(legAux);
        persona = (ePerson*)lista->pop(lista,legajo);
    }
    return ret;
}
