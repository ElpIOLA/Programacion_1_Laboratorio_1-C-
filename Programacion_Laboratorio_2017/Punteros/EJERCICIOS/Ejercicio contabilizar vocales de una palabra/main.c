#include <stdio.h>
#include <stdlib.h>

int cuentaVocales(char *);
int main()
{
    char nombre[20];

    printf("Ingrese su nombre: ");
    gets(nombre);

    printf("El numero de vocales es: %d", cuentaVocales(nombre));
    return 0;
}

int cuentaVocales(char *s)
{
    int cont = 0;

    while(*s) /** Mientras s no sea nulo */
    {
        switch(*s)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cont ++;
        }
        s++;
    }
    return cont;
}
