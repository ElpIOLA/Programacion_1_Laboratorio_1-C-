#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabj.h"


void setStatus(Product productArray[], int arrayLenght, int value)
{
    int i;
    for(i = 0;i < arrayLenght; i++)
    {
        productArray[i].status = value;
    }
}

int findEmptyPlace(Product productArray[], int arrayLenght)
{
    int i;
    for(i = 0;i < arrayLenght; i++)
    {
        if(productArray[i].status == 0)
        {
            return i;
        }
    }
    return -1;
}

int findProductByCode(Product productArray[], int arrayLenght, int code)
{
    int i;
    for(i = 0;i < arrayLenght; i++)
    {
        if(productArray[i].code == code && productArray[i].status == 1)
        {
            return i;
        }
    }
    return -1;
}
