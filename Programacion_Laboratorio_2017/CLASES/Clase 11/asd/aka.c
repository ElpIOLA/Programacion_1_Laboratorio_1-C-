#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "aka.h"

#define CANTPROD 5
#define CANTPROVEE 5
#define CANTPRODPROVE 25
#define LETRAS 51

int init(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i;

    for(i = 0; i < CANTPROD; i++)
    {
        producto[i].estado = 0;
    }

    for(i = 0; i < CANTPROVEE; i++)
    {
        proveedor[i].estado = 0;
    }

    for(i = 0; i < CANTPRODPROVE; i++)
    {
        codigos[i].estado = 0;
    }
    return 0;
}

int menu(void)
{
    char opcion[21];
    int resultado;
    printf("\n1- Ingresar producto\n2- Modificar\n3- Borrar\n4- Informar\n5- Lista\n6- Salir\n");
    printf("\n");
    printf("\nRespuesta: ");
    scanf("%s", opcion);
    resultado = validarMenu(opcion);
    return resultado;
}

int agregarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i, valor, contador = 0;
    char auxCodi[11];
    char auxNom[LETRAS];

    system("cls");
    for(i = 0;i < CANTPROD; i++)
    {
        if(contador == CANTPROD)
        {
            if(producto[i].estado == 0)
            {
                printf("\n");
                printf("____PRODUCTO____\n");
                printf("\n");

                do
                {
                    printf("Nombre producto: ");
                    scanf("%s", auxNom);
                    valor = validarString(auxNom);
                }
                while(valor == 0);
                strcpy(producto[i].nombre,auxNom);

                printf("\n");

                do
                {
                    printf("Codigo producto: ");
                    scanf("%s", auxCodi);
                    valor = validarEntero(auxCodi);
                }
                while(valor == 0);
                producto[i].codigo = atoi(auxCodi);

                printf("\n");

                do
                {
                    printf("Cantidad producto: ");
                    scanf("%s", auxCodi);
                    valor = validarEntero(auxCodi);
                }
                while(valor == 0);
                producto[i].cantidad = atoi(auxCodi);

                printf("\n");

                do
                {
                    printf("Importe producto: ");
                    scanf("%s", auxCodi);
                    valor = validarFloat(auxCodi);
                }
                while(valor == 0);
                producto[i].importe = atof(auxCodi);

                printf("\n");
                printf("____PROVEEDOR____\n");
                printf("\n");

                do
                {
                    printf("Nombre proveedor: ");
                    scanf("%s", auxNom);
                    valor = validarString(auxNom);
                }
                while(valor == 0);
                strcpy(proveedor[i].nombre,auxNom);

                do
                {
                    printf("Codigo proveedor: ");
                    scanf("%s", auxCodi);
                    valor = validarEntero(auxCodi);
                }
                while(valor == 0);
                proveedor[i].codigo = atoi(auxCodi);

                producto[i].estado = 1;
                codigos[i].codigoProduc = producto[i].codigo;
                codigos[i].estado = 1;
                printf("SUBIDO CORRECTAMENTE!");
                printf("\n");
                break;
            }
             if(producto[i].estado == 1)
            {
                contador++;
            }
        }
        else
        {
            printf("\nNo se pueden ingresar mas productos.\n");
        }
    }
    return 0;
}

int modificarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i, auxCodigo, valor, flag = 0;
    char auxCodi[11];
    char auxNom[LETRAS];
    printf("Ingrese el codigo del producto a modificar: ");
    scanf("%d", &auxCodigo);

    for(i = 0; i < CANTPROD; i++)
    {
        if(auxCodigo == producto[i].codigo && producto[i].estado == 1)
        {
            flag = 1;
            printf("\nCODIGO ENCONTRADO.\n");

            do
            {
                printf("Ingrese nuevo nombre: ");
                scanf("%s", auxCodi);
                valor = validarString(auxCodi);
            }
            while(valor == 0);
            strcpy(producto[i].nombre, auxCodi);

            printf("\n");

            do
            {
                printf("Ingrese nuevo codigo del proveedor: ");
                scanf("%s", auxCodi);
                valor = validarEntero(auxCodi);
            }
            while(valor == 0);
            proveedor[i].codigo = atoi(auxCodi);

            do
            {
                printf("Ingrese nueva cantidad del producto: ");
                scanf("%s", auxCodi);
                valor = validarEntero(auxCodi);
            }
            while(valor == 0);
            producto[i].cantidad = atoi(auxCodi);

            printf("\n");

            do
            {
                printf("Ingrese nuevo importe del producto: ");
                scanf("%s", auxCodi);
                valor = validarFloat(auxCodi);
            }
            while(valor == 0);
            producto[i].importe = atof(auxCodi);

            codigos[i].codigoProduc = producto[i].codigo;
        }
    }
    if(flag == 0)
    {
        printf("El codigo ingresado no coincide con un producto existente.\n");
    }

    return 0;
}

int borrarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i;
    int auxCodi;
    int flag = 0;
    char vacio[] = {" "};

    printf("Ingrese codigo del producto: ");
    scanf("%d", &auxCodi);

    for(i = 0; i < CANTPROD; i++)
    {
        if(auxCodi == producto[i].codigo)
        {
            printf("\nPRODUCTO ELIMINADO!\n");
            flag = 1;

            strcpy(producto[i].nombre, vacio);
            producto[i].cantidad = 0;
            producto[i].importe = 0;
            producto[i].codigo = 0;
            producto[i].estado = 0;
        }
    }
    if(flag == 0)
    {
        printf("\nEL PRODUCTO NO EXISTE.\n");
    }
    return 0;
}

int imformarProducto(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i, mayor = producto[i].cantidad, menor = producto[i].cantidad;

    for(i=0; i<CANTPROD; i++)
    {
        if(producto[i].cantidad>mayor)
        {
            mayor = producto[i].cantidad;
        }
        if(producto[i].cantidad<menor)
        {
            menor = producto[i].cantidad;
        }
    }
    for(i=0; i<CANTPROD; i++)
    {
        if(producto[i].cantidad == mayor)
        {
            printf("PRODUCTO CON MAYOR CANTIDAD!");
            printf("Codigo del producto: %d",producto[i].codigo);
            printf("Codigo del proveedor: %d",proveedor[i].codigo);
            printf("Nombre del producto: %s",producto[i].nombre);
            printf("Importe del producto: %.2f",producto[i].importe);
        }
        if(producto[i].cantidad == menor)
        {
            printf("PRODUCTO CON MAYOR CANTIDAD!");
            printf("Codigo del producto: %d",producto[i].codigo);
            printf("Codigo del proveedor: %d",proveedor[i].codigo);
            printf("Nombre del producto: %s",producto[i].nombre);
            printf("Importe del producto: %.2f",producto[i].importe);
        }
    }
    return 0;
}

int listaOrdenada(eProducto producto[], eProvedoor proveedor[], pIOLA codigos[])
{
    int i;
    int j;
    int codiAux;
    char nombreAux[80];

    for(i=0; i<CANTPRODPROVE-1; i++)
    {
        for(j=i+1; j<CANTPRODPROVE; j++)
        {
            if(strcmp(producto[i].nombre,producto[j].nombre)>0)
            {
                strcpy(nombreAux,producto[i].nombre);
                strcpy(producto[i].nombre,producto[j].nombre);
                strcpy(producto[j].nombre,nombreAux);
            }
            if(strcmp(codigos[i].codigoProvee,codigos[j].codigoProvee)>0)
            {
                strcpy(codiAux,codigos[i].codigoProvee);
                strcpy(codigos[i].codigoProvee,codigos[j].codigoProvee);
                strcpy(codigos[j].codigoProvee,codiAux);
            }
        }
    }
    printf("\nLISTA\n");
    for(i = 0; i<CANTPRODPROVE; i++)
    {
        if(producto[i].estado == 1)
        {
            printf("Producto: %s\nCodigo proveedor: %d",producto[i].nombre,codigos[i].codigoProvee);
        }
    }
    return 0;
}

/**************************************************************************************************************
********************************************_VALIDACIONES_****************************************************
*************************************************************************************************************/

int validarMenu(char valorMenu[])
{
    int tamanio;
    int valor;
    int flag = 0;
    int i;

    tamanio = strlen(valorMenu);

    for(i=0; i<tamanio; i++)
    {
        if(!isdigit(valorMenu[i]))
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("\nERROR! NO ES UN NUMERO.\n");
        printf("\n");
        menu();

    }
    else
    {
        valor = atoi(valorMenu);
        if(valor < 1 || valor > 6)
        {
            printf("ERROR! La opcion ingresada no es correcta.\n");
            printf("\n");
            menu();
        }
    }
    return valor;
}

int validarString(char productoDescripcion[])
{
    int flag=0,i;

    for (i=0; i<=LETRAS; i++)
    {
        if(productoDescripcion[i] == '\0')
        {
            flag==1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("La descripcion de producto excede los 50 caracteres. Vuelva a intentar.\n");
    }
    return flag;
}

int validarEntero(char validarCodigo[])
{
    int i,flag=1,largo;

    largo = strlen(validarCodigo);
    for(i=0; i<largo; i++)
    {
        if(!isdigit(validarCodigo[i]))
        {
            flag=0;
            printf("El dato ingresado no es entero. Por favor ingrese un numero entero.\n");
            break;
        }
    }
    return flag;
}

int validarFloat(char validarImporte[])
{
    int i,flag=0,largo;

    largo = strlen(validarImporte);
    for(i=0; i<largo; i++)
    {
        if(isdigit(validarImporte[i])||validarImporte[i]=='.')
        {
            flag=0;
            printf("El dato ingresado no es valido. Por favor ingrese un importe valido.\n");
            break;
        }
    }
    return flag;
}
