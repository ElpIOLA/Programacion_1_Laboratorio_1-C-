#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int numero, ret;

    while(reintentos > 0)
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\tCANTIDAD DE INTENTOS: %d",reintentos);
        printf(mensaje);
        if(getInt(&numero))
        {
            if(numero <= maximo && numero >= minimo)
                break;
        }
        fflush(stdin);

        reintentos --;
        printf(mensajeError);
    }
    if(reintentos == 0)
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\tCANTIDAD DE INTENTOS: %d",reintentos);
        printf("\nFIN DEL PROGRAMA. LLEGO AL LIMITE DE INTENTOS!\n");
        ret = -1;
    }
    else
    {
        ret = 0;
        *pResultado = numero;
    }
    return ret;
}

char calcularNumeroAleatorio(int desde,int hasta, int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand() % (hasta + 1 - desde));
}

/***********************************************************************************************************************/

int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];
    fgets(buffer,sizeof(buffer),stdin); //EVITAMO QUE LA CANTIDAD DE CARACTERES SUPERE EL BUFFER.
    buffer[strlen(buffer)-1]='\0'; //ELIMINAMOS EL ENTER DE FGETS.
    if(esNumerica(buffer)) //SI LA CADENA DE CARACTERES CONTIENE SOLO NUMERO AVANZA.
    {
        *pResultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}

int esNumerica(char* cadena)
{
    int retorno=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            retorno=1;
    }
    return retorno;
}

float getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[64];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(esFlotante(buffer))
    {
        *pResultado = atof(buffer);
        retorno = 1;
    }
    return retorno;
}

float esFlotante(char* cadena)
{
    int i=0;
    int cantidadPuntos=0;
    while(cadena[i] != '\0')
    {
        if (i == 0 && cadena[i] == '-')
        {
            i++;
            continue;
        }
        if (cadena[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;
        }
        if(cadena[i] < '0' || cadena[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int getString(char* input)
{
    char buffer[256];
    fgets(buffer,sizeof(buffer),stdin);
    if(esSoloLetras(buffer))
    {
        strcpy(input,buffer);
        return 1;
    }
    return 0;
}

int esSoloLetras(char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getNumeroConSigno(int* pResultado)
{
    int retorno = -1;
    char buffer[64];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(esNumeroConSigno(buffer))
    {
        *pResultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}

int esNumeroConSigno(char* cadena)
{
    int retorno = -1;
    int i = 0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if((cadena[i]<'0' || cadena[i]>'9') && cadena[i] != '-')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            retorno=1;
    }
    return retorno;
}
