#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

float set_float(float flt)
{
    int flag=0;
    char auxFlt[15];
    float num;

    if(auxFlt != NULL && sizeof(auxFlt) > 0)
    {
        do
        {
            fflush(stdin);
            fgets(auxFlt,sizeof(auxFlt),stdin);
            if((flag=validar_flotante(auxFlt,sizeof(auxFlt))))
            {
                num=atof(auxFlt);
                flt= num;
            }
            else
            {
                printf("error. try again\n");
            }
        }
        while(flag!=1);
    }
    return flt;
}



int set_integer(int intg)
{
    int flag=0;
    char auxIntg[15];
    int num;

    if(auxIntg != NULL && sizeof(auxIntg) > 0)
    {
        do
        {
            fflush(stdin);
            fgets(auxIntg,sizeof(auxIntg),stdin);
            if((flag=validar_entero(auxIntg,sizeof(auxIntg))))
            {

                num=atoi(auxIntg);
                intg= num;
            }
            else
            {
                printf("error. try again\n");
            }
        }
        while(flag!=1);
    }
    return intg;
}


int set_name(char str[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(str != NULL && len > 0)
    {
        do
        {
            fflush(stdin);
            fgets(str,len,stdin);
            auxlen=strlen(str);
            if(!(flag=validar_alfabetico(str, len)))
            {

                printf("error. try again\n");
            }
        }
        while(flag== 0);
        token=strtok(str,"\n");
        strncpy(str,token,auxlen);
    }
    return flag;
}


int set_string(char str[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(str != NULL && len > 0)
    {
        do
        {
            fflush(stdin);
            fgets(str,len,stdin);
            auxlen=strlen(str);
            if(!(flag=validar_alfanumerico(str, len)))
            {

                printf("\n\tError. Reingrese dato: \n");

            }
        }
        while(flag == 0);
        token=strtok(str,"\n");
        strncpy(str,token,auxlen);
    }
    return flag;
}

int set_marginInt(int intg, int min, int max)
{

    do
    {
        intg=set_integer(intg);
        if(intg < min || intg > max)
        {
            printf("error. try again\n");
        }
    }
    while(intg < min || intg > max);

    return intg;
}


float set_marginFloat(float flt, float min, float max)
{

    do
    {
        flt=set_float(flt);
        if(flt < min || flt > max)
        {
           printf("error. try again'n");
        }
    }
    while(flt < min || flt > max);

    return flt;
}


int validar_flotante(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}


int validar_entero(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }
            i++;
        }
    }
    return flag;
}



int validar_alfabetico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len>0)
    {
        auxlen=strlen(str);

        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ' && str[i] != -61 && str[i] != -79 && str[i] != -111)
            {
                flag=0;
                break;
            }
            i++;
        }
    }
    return flag;
}


int validar_alfanumerico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;
    char auxstr[len];

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= len)
        {
            if( (str[i] != 10 ) && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ' && str[i] != -61 &&
                    str[i] != -79 && str[i] != -111 && (str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i]!=',' && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
        strncpy(auxstr,str,auxlen-1);
        strncpy(str,auxstr,auxlen);
    }
    return flag;
}
