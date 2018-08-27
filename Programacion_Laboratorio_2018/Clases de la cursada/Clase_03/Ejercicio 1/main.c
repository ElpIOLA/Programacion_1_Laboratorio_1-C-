#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[], int, int);

int main()
{
    int edad, legajo;

    edad = pedirEntero("Ingrese su edad: ", 18, 60);
    legajo = pedirEntero("Ingrese su legajo: ", 1, 2000);
    printf("\nEdad: %d",edad);
    printf("\nLegajo: %d",legajo);
    return 0;
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
