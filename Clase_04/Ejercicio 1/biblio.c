#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

void sumar1(void){
    int a, b, resultado = 0;
    a = pedirEntero("\nIngrese un numero: ",1,1000);
    b = pedirEntero("\nIngrese un numero: ",1,1000);
    resultado = a + b;
    printf("\nTotal: %d", resultado);
}

void sumar2(int a, int b){
    int resultado = 0;
    resultado = a + b;
    printf("\nTotal: %d",resultado);
}

int sumar3(void){
    int a, b, resultado = 0;
    a = pedirEntero("\nIngrese un numero: ",1,1000);
    b = pedirEntero("\nIngrese un numero: ",1,1000);
    resultado = a + b;
    return resultado;
}

int sumar4(int a, int b){
    int resultado = 0;
    resultado = a + b;
    return resultado;
}

int pedirEntero(char mensaje[], int min, int max){
    int n;
    printf("%s", mensaje);
    scanf("%d",&n);
    while(n < min || n > max){
        printf("ERROR! Por favor ingrese nuevamente: ");
        scanf("%d",&n);
    }
    return n;
}
