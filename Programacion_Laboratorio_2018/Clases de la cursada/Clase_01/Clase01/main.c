#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,resultado;

    printf("Ingrese primero numero: \n");
    scanf("%d", &num1);
    printf("Ingrese segundo numero: \n");
    scanf("%d", &num2);
    printf("Ingrese tercer numero: \n");
    scanf("%d", &num3);

    if(num1 > num2 && num1 > num3){
        resultado = num1;
    }else if(num2 > num1 && num2 > num3){
        resultado = num2;
    }else{
        resultado = num3;
    }

    printf("El mayor numero es: %d", resultado);
    return 0;
}
