#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "lib.h"

#define CANT_cLiente 5
#define CANT_aLquiler 5
#define CANT_cLienteaLquiler 10


int inicializar_prog(cLiente cliente[])
{
    int i;

    for(i = 0; i < CANT_cLiente; i++)
    {
        cliente[i].clie_id = 0;
    }

    return 0;
}

int validarIdAlquiler(int ID_Alqui, aLquiler alquiler[])
{
    int i,flag=0;

    for(i=0; i<CANT_cLienteaLquiler; i++)
    {
        if(ID_Alqui == alquiler[i].id_alquiler)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("El ID ingresado no corresponde con un alquiler activo.\n");
    }
    return flag;
}

int validarID(int valor, cLiente cliente[])
{
    int i,flag=0;

    for(i=0; i<CANT_cLiente; i++)
    {
        if(valor == cliente[i].clie_id)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("El ID ingresado no corresponde con un cliente.\n");
    }
    return flag;
}

int alta(cLiente cliente[])
{
    int i, flag = 0;
    char nomAux[51];
    char apeAux[51];
    char dniAux[51];

    for(i = 0; i < CANT_cLiente; i++)
    {
        if(cliente[i].clie_id == 0)
        {
            flag = 1;

            if(!getStringLetras("Ingrese su nombre: ", nomAux))
            {
                printf("EL NOMBRE DEBE CONTENER SOLAMENTE LETRAS!\n");
                break;
            }
            fflush(stdin);
            strcpy(cliente[i].clie_nom,nomAux);

            if(!getStringLetras("Ingrese su apellido: ", apeAux))
            {
                printf("EL APELLIDO DEBE CONTENER SOLAMENTE LETRAS!\n");
                break;
            }
            fflush(stdin);
            strcpy(cliente[i].clie_ape,apeAux);

            if(!getStringNumeros("Ingrese su DNI: ", dniAux))
            {
                printf("EL DNI DEBE SER NUMERICO\n");
                break;
            }
            cliente[i].clie_dni = atol(dniAux);

            cliente[i].clie_id = i + 1;

            system("cls");

            printf("El cliente %s %s con dni %ld ha sido dado de alta, con el id %d.\n", cliente[i].clie_nom, cliente[i].clie_ape, cliente[i].clie_dni, cliente[i].clie_id);

            break;
        }
    }

    if(flag == 0)
    {
        printf("Se llego al tope maximo de clientes.");
    }

    return 0;
}

int modificar(cLiente cliente[])
{
    int i;
    char nomAux[50];
    char apeAux[50];
    int idAux;
    int flag = 0;
    char idAuxStr[50];

    if(!getStringNumeros("Ingrese el id del cliente ha modificar: ", idAuxStr))
    {
        printf("EL CODIGO DEBE SER NUMERICO!\n");
    }
    idAux = atoi(idAuxStr);
    validarID(idAux, cliente);

    for(i = 0; i < CANT_cLiente; i++)
    {
        if(idAux == cliente[i].clie_id)
        {
            flag = 1;

            printf("\nEl nombre actual es: %s\n", cliente[i].clie_nom);
            if(!getStringLetras("Ingrese nuevo nombre: ", nomAux))
            {
                printf("EL NOMBRE DEBE CONTENER SOLAMENTE LETRAS!\n");
                break;
            }
            fflush(stdin);
            strcpy(cliente[i].clie_nom,nomAux);

            printf("\nEl apellido actual es: %s\n", cliente[i].clie_ape);
            if(!getStringLetras("Ingrese nuevo apellido: ", apeAux))
            {
                printf("EL APELLIDO DEBE CONTENER SOLAMENTE LETRAS!\n");
                break;
            }
            fflush(stdin);
            strcpy(cliente[i].clie_ape,apeAux);

            system("cls");
            printf("\nEl cliente %d ha sido modificado. %s %s con dni %ld.\n", cliente[i].clie_id, cliente[i].clie_nom, cliente[i].clie_ape, cliente[i].clie_dni);
            break;
        }
    }

    if(flag == 0)
    {
        printf("El ID ingresado no existe.");
    }
    return 0;
}

int baja(cLiente cliente[])
{
    int i;
    int idAux;
    int flag = 0;
    char idAuxStr[21];

    if(!getStringNumeros("Ingrese el id del cliente a dar de baja: ", idAuxStr))
    {
        printf("EL ID DEBE SER NUMERICO!\n");
    }
    idAux = atoi(idAuxStr);
    validarID(idAux, cliente);

    for(i = 0; i < CANT_cLiente; i++)
    {
        if(idAux == cliente[i].clie_id)
        {
            flag = 1;
            cliente[i].clie_id = 0;
            system("cls");
            printf("FUE DADO DE BAJA.\n");
            break;
        }
    }
    if(flag == 0)
    {
        printf("El cliente no existe.");
    }

    return 0;
}

int nuevoAlquiler(cLiente cliente[], aLquiler alquiler[])
{
    int i;
    int flag = 1;
    int id_cliente;
    char auxStrId[21];
    char auxStrEquipo[21];
    char auxStrTiempo[21];
    char auxStrOperador[21];

    if(!getStringNumeros("Ingrese ID del cliente: ", auxStrId))
    {
        printf("EL ID DEBE SER NUMERICO!\n");
    }
    id_cliente = atoi(auxStrId);

    validarID(id_cliente, cliente);

    for(i = 0; i < CANT_cLienteaLquiler; i++)
    {
        if(alquiler[i].id_alquiler == 0)
        {
            flag = 0;
            alquiler[i].id_cliente = id_cliente;
            alquiler[i].id_alquiler = i + 1;

            printf("EQUIPOS: \n1: AMOLADORA\n2: MEZCLADORA\n3: TALADRO\n");
            if(!getStringNumeros("ELIGA UN EQUIPO: ", auxStrEquipo))
            {
                printf("EL EQUIPO DEBE SER NUMERICO!\n");
                break;
            }
            alquiler[i].equipo = atoi(auxStrEquipo);

            if(!getStringNumeros("Tiempo estimado en dias: ", auxStrTiempo))
            {
                printf("EL TIEMPO DEBE SER NUMERICO!\n");
                break;
            }
            alquiler[i].tiempo_estimado = atoi(auxStrTiempo);

            printf("OPERADORES: \n1: HERNAN\n2: JULIAN\n3: LAUTARO\n");
            if(!getStringNumeros("ELIGA OPERADOR: ", auxStrOperador))
            {
                printf("EL OPERADOR DEBE SER SOLO NUMEROS!\n");
                break;
            }
            alquiler[i].operador = atoi(auxStrOperador);

            strncpy(alquiler[i].estado, "ALQUILADO", 40);

            system("cls");
            printf("\nAlquiler numero: %d\nDias alquilado: %d dias\nEstado: %s\n", alquiler[i].id_alquiler, alquiler[i].tiempo_estimado, alquiler[i].estado);
            break;
        }
    }
    if(flag == 1)
    {
        printf("No se pueden ingresar mas alquileres.");
    }

    return 0;
}

int finDeAlquiler(aLquiler alquiler[])
{
    int i, flag = 0, id_alquiler;
    char auxStrId[21];
    char auxStrTiempo[21];

    if(!getStringNumeros("Ingrese ID del alquiler: ", auxStrId))
    {
        printf("EL ID DEBE SER NUMERICO!\n");
    }
    id_alquiler = atoi(auxStrId);

    validarIdAlquiler(id_alquiler, alquiler);

    for(i = 0; i < CANT_aLquiler; i++)
    {
        if(alquiler[i].id_alquiler == id_alquiler)
        {
            flag = 1;

            if(!getStringNumeros("Tiempo de alquiler en dias: ", auxStrTiempo))
            {
                printf("EL TIEMPO DEBE SER NUMERICO!\n");
                break;
            }
            alquiler[i].tiempo_real = atoi(auxStrTiempo);

            strncpy(alquiler[i].estado, "FINALIZADO", 40);

            system("cls");
            printf("\nEstado del alquiler %d es: %s\n", alquiler[i].id_alquiler, alquiler[i].estado);
            break;
        }
    }
    if(flag == 0)
    {
        printf("No se pueden ingresar mas alquileres.");
    }
    return 0;
}

void informar(cLiente cliente[],aLquiler alquiler[])
{
    int opcion;

    printf("1- Promedio de Alquileres\n");
    printf("2- Cliente con mas alquileres\n");
    printf("3- Equipos mas alquilados\n");

    printf("Opcion seleccionada: ");
    scanf("%d",&opcion);
    switch (opcion)
    {
    case 1:
        pRomedios(cliente, alquiler);
        break;
    case 2:
        client_Max_Alqui(cliente, alquiler);
        break;
    case 3:
        equiP_mAx_Alqui(alquiler);
        break;
    }
}

void pRomedios(cLiente cliente[], aLquiler alquiler[])
{
    int i, cant = 0, tiempo = 0, promedio = 0;

    for(i = 0; i <CANT_aLquiler; i++)
    {
        fflush(stdin);
        if(strcmp(alquiler[i].estado,"FINALIZADO") == 0)
        {
            cant++;
            tiempo += alquiler[i].tiempo_real;
        }
    }
    promedio = tiempo / cant;

    printf("El promedio es: %d", promedio);
}

void client_Max_Alqui(cLiente cliente[], aLquiler alquiler[])
{
    int i, j, id_cliente_maxAlqui, cantAlquiMax, cantAlqui = 0;

    for(i = 0; i < CANT_cLiente; i++)
    {
        for(j = 0; j < CANT_cLiente; j++)
        {
            if(alquiler[j].id_cliente == cliente[i].clie_id)
            {
                cantAlqui++;
            }
        }

        if(cantAlqui > cantAlquiMax)
        {
            cantAlquiMax = cantAlqui;
            id_cliente_maxAlqui = i;
        }
    }

    printf("Cliente con mas alquileres: %s %s", cliente[id_cliente_maxAlqui].clie_nom, cliente[id_cliente_maxAlqui].clie_ape);
}

void equiP_mAx_Alqui(aLquiler alquiler[])
{
    int i, j, a, cantMaxAlqui;
    int equipoMaxAlqui[3] = {0,0,0};
    int equiposMasAlquilados[3] = {2,3,0};

    for(i = 0; i<CANT_aLquiler ; i++)
    {
        if(alquiler[i].equipo == 1)
            equipoMaxAlqui[0] = equipoMaxAlqui[0] + 1;
        else if(alquiler[i].equipo == 2)
            equipoMaxAlqui[1] = equipoMaxAlqui[1] + 1;
        else if(alquiler[i].equipo == 3)
            equipoMaxAlqui[2] = equipoMaxAlqui[2] + 1;
    }

    for (j = 1; j <= 3; j++)
    {
        if(equipoMaxAlqui[j] >= cantMaxAlqui)
        {
            cantMaxAlqui = equipoMaxAlqui[j];

            /**LIMPIO ARRAY CON MAS ALQUILERES, Y SE MANTIENEN LOS PRODUCTOS QUE FUERON IGUAL DE VECES ALQUILADOS*/
            for(a = 1; a <= 3; a++)
            {
                if(equiposMasAlquilados[a] != cantMaxAlqui)
                {
                    equipoMaxAlqui[a] = 0;
                }
            }

            /**AGREGA PRODUCTO AL PRIMER ESPACIO VACIO*/
            for(a = 1; a <= 3; a++)
            {
                if(equipoMaxAlqui[a] == 0)
                {
                    equipoMaxAlqui[a] = j;
                    break;
                }
            }
        }
    }
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
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

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;

        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
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

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
