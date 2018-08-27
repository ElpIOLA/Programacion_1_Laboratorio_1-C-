#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\alumno\Desktop\Ejercicio 2\misFunciones.h>

int main()
{
    int n;
    n = pedirNumero("\nIngrese su edad: ","\nError! Ingrese una edad entre [100-1]",100,1);
    printf("\nSu edad es: %d",n);
    return 0;
}

