#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float validarFloat(char mensaje[],char mensajeError[],float ope){
    char aux[20];
    do{
        printf("%s",mensaje);
        scanf("%s",aux);
        ope = atof(aux);
        if(ope!=0){
            break;
        }else{
            printf("%s",mensajeError);
        }
    }while(ope==0);
    return ope;
}

float verificacion(float a, float b)
{
    if(a == 0 && b == 0)
        return 0;
    else
        return 1;
}

void sumar(float a,float b){
    float resultado = 0;
    if(verificacion(a,b)){
        resultado = a + b;
        printf("\n\t\tLa suma total entre (%.2f + %.2f) es: %.2f\n",a,b, resultado);
    }else if(a == 0 || b == 0){
        system("clear");
        printf("\n\t\tERROR!\n\tDebe ingresar al menos un operando. \n");
    }
}

void resta(float a, float b){
    float resultado = 0;
    if(verificacion(a,b)){
        resultado = a - b;
        printf("\n\t\tLa resta total entre (%.2f - %.2f) es: %.2f\n",a,b, resultado);
    }else if(a == 0 || b == 0){
        system("clear");
        printf("\n\t\tERROR!\n\tDebe ingresar al menos un operando. \n");
    }
}

void division(float a, float b){
    float resultado = 0;
    if(a == 0 && b == 0){
        system("clear");
        printf("\n\t\tERROR!\n\tDebe ingresar al menos un operando. \n");
    }else if(b == 0){
        system("clear");
        printf("\n\t\tERROR!\n\tNo se puede dividir por 0.\n");
    }else{
        resultado = a / b;
        printf("\n\t\tLa division total entre (%.2f / %.2f) es: %.2f\n",a,b, resultado);
    }
}

void multiplicacion(float a, float b){
    float resultado = 0;
    if(verificacion(a,b)){
        resultado = a*b;
        printf("\n\t\tLa multiplicacion total entre (%.2f * %.2f) es: %.2f\n",a,b, resultado);
    }else if(a == 0 || b == 0){
        system("clear");
        printf("\n\t\tERROR!\n\tDebe ingresar al menos un operando. \n");
    }
}


int factorial(int a){
    long int fact = 1;
    int i;
    if(a > 0){
        for(i=2;i<=a;i=i+1)
        fact = fact * i;
        printf("\n\t\tEl factorial de !%d es: %ld\n",a,fact);
    }else{
        printf("\n\t\tERROR!\n\tEl operando A debe ser mayor a 0.\n");
    }
    return fact;
}
