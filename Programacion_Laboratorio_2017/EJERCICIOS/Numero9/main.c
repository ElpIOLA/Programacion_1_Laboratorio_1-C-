//Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont;
    int caracter = 0, acum = 0, contA = 0, contE = 0, contI = 0, contO = 0, contU = 0;

    for(cont = 1; cont <= 20; cont ++)
    {
        printf("Ingrese el caracter numero %d: ", cont);
        scanf("%s", &caracter);
        acum += caracter;

        switch(caracter)
        {
            case 'a':
                contA++;
                break;
            case 'e':
                contE++;
                break;
            case 'i':
                contI++;
                break;
            case 'o':
                contO++;
                break;
            case 'u':
                contU++;
                break;
        }
    }

    printf("La cantidad de A son: %d \n", contA);
    printf("La cantidad de E son: %d \n", contE);
    printf("La cantidad de I son: %d \n", contI);
    printf("La cantidad de O son: %d \n", contO);
    printf("La cantidad de U son: %d \n", contU);

    return 0;
}
