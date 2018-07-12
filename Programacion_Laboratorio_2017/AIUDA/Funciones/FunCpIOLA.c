#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "FunCpIOLA.h"
/****************************************************************************************
 *********************** SOLICITAR INT, FLOAT, CHAR Y VALIDAMOS *************************
 ***************************************************************************************/

 float getFloat(char mensaje[])
 {
     float auxiliar;
     printf("%s", mensaje);
     scanf("%f", &auxiliar);
     return auxiliar;
 }


 int getInt(char mensaje[])
 {
     int auxiliar;
     printf("%s", mensaje);
     scanf("%d", &auxiliar);
     return auxiliar;
 }


 char getChar(char mensaje[])
 {
     char auxiliar;
     printf("%s", mensaje);
     fflush(stdin); //LIMPIA LA BASURA
     scanf("%c", &auxiliar);
     return auxiliar;
 }

 char getNumeroAleatorio(int desde, int hasta, int iniciar)
 {
     if(iniciar)
        srand(time(NULL));
     return desde + (rand() % (hasta + 1 - desde));
 }

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
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

int esAlfaNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i = 0;
    int contadorGuiones = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones == 1) //DEBE TENER UN GUION
        return 1;

    return 0;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
 /****************************************************************************************
 *************************** FIN DE FUNCIONES ********************************************
 ****************************************************************************************/
