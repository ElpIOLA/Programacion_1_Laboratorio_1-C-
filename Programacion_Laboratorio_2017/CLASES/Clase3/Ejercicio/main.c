#include <stdio.h>
#include <stdlib.h>
int suma(int, int);
int resta(int, int);
int multi(int, int);
int divi(int, int);

int main(int numeroUno, int numeroDos, int resultado)
{
    char respuesta = '1';
    char nombre[20];
    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    system("cls");
    printf("Hola %s, ¿desea hacer una operacion?\n[1] Si\n[0] No\n");
    scanf("%s", &respuesta);
    system("cls");
    while (respuesta != '0')
    {
        printf("Ingrese numero uno: ");
        scanf("%d", &numeroUno);
        printf("Ingrese numero dos: ");
        scanf("%d", &numeroDos);
        printf("¿Que operacion desea hacer?");
        printf("\n[1] = Sumar");
        printf("\n[2] = Resta");
        printf("\n[3] = Multiplicacion");
        printf("\n[4] = Division");
        printf("\nIngrese su respuesta: ");
        scanf("%d", &resultado);
        system("cls");
        switch(resultado)
            {
            case 1:
                resultado = suma(numeroUno, numeroDos);
                break;
            case 2:
                resultado = resta(numeroUno, numeroDos);
                break;
            case 3:
                resultado = multi(numeroUno, numeroDos);
                break;
            case 4:
                resultado = divi(numeroUno, numeroDos);
                break;
            default:
                printf("Invalido");
        }
        printf("El resultado total es: %d\n", resultado);
        printf("¿Desea hacer otra operacion?\n[1] Si\n[0] No\n");
        scanf("%s", &respuesta);
        system("cls");
        if (respuesta == '0')
        {
            printf("Fin de programa.");
        }
    }

    return 0;
}

int suma(int num1, int num2)
    {
        int resultado;
        resultado = num1 + num2;
        return resultado;
    }

int resta(int num1, int num2)
    {
        int resultado;
        resultado = num1 - num2;
        return resultado;
    }

int multi(int num1, int num2)
{
    int resultado;
    resultado = num1 * num2;
    return resultado;
}

int divi(int num1, int num2)
{
    int resultado;
    resultado = num1 / num2;
    return resultado;
}
