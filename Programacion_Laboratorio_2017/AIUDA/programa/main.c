#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabj.h"
#include "C:\Users\ELpIOLA\Desktop\REPOSITORIO\AIUDA\Funciones\funCpIOLA.h"
#define MAX_QTY 200


int main()
{
    Product productArray[MAX_QTY];
    Product productAux;

    char descriptionAux[51];
    int codeAux;
    int qtyAux;
    float priceAux;

    char codeAuxStr[50];
    char qtyAuxSty[50];
    char priceAuxStr[50];

    int freePlaceIndex;
    int foundIndex;
    int opcion = 0;

    int i, j;

    setStatus(productArray,MAX_QTY,0);

    while(opcion != 6)
    {

        opcion = getInt("\n\n1- ALTA \n2- BAJA \n3- MODIFICACION \n4- LISTAR \n5- ORDENAR \n6- SALIR\n\n\n");
        switch(opcion)
        {
            case 1:
                printf("\nALTA\n");
                freePlaceIndex = findEmptyPlace(productArray,MAX_QTY);
                if(freePlaceIndex == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese el codigo: ", codeAuxStr))
                {
                    printf("EL CODIGO DEBE SER NUMERICO!\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);

                if(findProductByCode(productArray,MAX_QTY,codeAux) != -1)
                {
                    printf("EL CODIGO YA EXISTE!!!\n");
                    break;
                }

                if(!getStringLetras("Ingrese la descripcion: ", descriptionAux))
                {
                    printf("LA DESCRIPCION DEBE ESTAR COMPUESTA SOLO POR LETRAS!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese la cantidad: ", qtyAuxSty))
                {
                    printf("LA CANTIDAD DEBE SER NUMERICA!!\n");
                    break;
                }
                qtyAux = atoi(qtyAuxSty);

                if(!getStringNumeros("Ingrese el valor: ", priceAuxStr))
                {
                    printf("LA CANTIDAD DEBE SER NUMERICA!!\n");
                    break;
                }
                priceAux = atof(priceAuxStr);

                productArray[freePlaceIndex].code = codeAux;
                strcpy(productArray[freePlaceIndex].description,descriptionAux);
                productArray[freePlaceIndex].price = priceAux;
                productArray[freePlaceIndex].qty = qtyAux;
                productArray[freePlaceIndex].status = 1;

                break;

            case 2:
                printf("\nBAJA\n");
                if(!getStringNumeros("Ingrese el codigo del producto a dar de baja: ", codeAuxStr))
                {
                    printf("EL CODIGO DEBE SER NUMERICO!\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);
                foundIndex = findProductByCode(productArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\nNO SE ENCUENTRA EL CODIGO\n");
                    break;
                }
                productArray[foundIndex].status = 0;
                break;

            case 3:
                printf("\nMODIFICAR\n");
                if(!getStringNumeros("Ingrese codigo del producto a Modificar: ", codeAuxStr))
                {
                    printf("EL CODIGO DEBE SER NUMERICO!\n");
                    break;
                }
                codeAux = atoi(codeAuxStr);
                foundIndex = findProductByCode(productArray,MAX_QTY,codeAux);
                if(foundIndex == -1)
                {
                    printf("\nNO SE ENCUENTRA EL CODIGO\n");
                    break;
                }

                if(!getStringLetras("Ingrese la descripcion: ", descriptionAux))
                {
                    printf("LA DESCRIPCION DEBE ESTAR COMPUESTA SOLO POR LETRAS!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese la cantidad: ", qtyAuxSty))
                {
                    printf("LA CANTIDAD DEBE SER NUMERICA!!\n");
                    break;
                }
                qtyAux = atoi(qtyAuxSty);

                if(!getStringNumeros("Ingrese el valor: ", priceAuxStr))
                {
                    printf("LA CANTIDAD DEBE SER NUMERICA!!\n");
                    break;
                }
                priceAux = atof(priceAuxStr);

                strcpy(productArray[freePlaceIndex].description,descriptionAux);
                productArray[freePlaceIndex].price = priceAux;
                productArray[freePlaceIndex].qty = qtyAux;
                productArray[freePlaceIndex].status = 1;

                break;

            case 4:
                printf("\nLISTAR\n");
                for(i = 0; i < MAX_QTY; i++)
                {
                    if(productArray[i].status != 0)
                    {
                        printf("%d - %s - %d - %.2f\n", productArray[i].code, productArray[i].description, productArray[i].qty, productArray[i].price);
                    }
                }
                break;

            case 5:
                printf("\nORDENAR\n");
                for(i = 0; i < MAX_QTY - 1; i++)
                {
                    if(productArray[i].status == 0)
                    {
                        continue;
                    }
                    for(j=i+1; j < MAX_QTY; j++)
                    {
                        if(productArray[i].status == 0)
                        {
                            continue;
                        }
                        if(strcmp(productArray[j].description,productArray[i].description))
                        {
                            productAux = productArray[j];
                            productArray[j] = productArray[i];
                            productArray[i] = productAux;
                        }
                    }
                }
                break;


            }
        }

    return 0;
}
