#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main()
{
    //sumar1();

    //sumar2(5,3);

    /*int x = sumar3();
    printf("\n%d",x);*/

    int a, b;
    a = pedirEntero("\nIngrese un numero: ", 1, 1000);
    b = pedirEntero("\nIngrese un numero: ", 1, 1000);
    int resultado = sumar4(a,b);
    printf("Total: %d", resultado);
    return 0;
}
