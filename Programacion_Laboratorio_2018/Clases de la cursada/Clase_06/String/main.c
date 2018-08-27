#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**
    *STRCMP COMPARA CADENAS DE CARACTERES.
    */
    char texto[20];

    printf("Ingrese contraseña: ");
    gets(texto);

    if(strcmp(texto,"1234")==0){
        printf("Contraseña Correcta!");
    }else{
        printf("Contraseña Incorrecta!");
    }

    /**--------------------------------------------------------------------------
    *STRCPY COPIA UNA CADENA DE CARACTERES (TEXTO1) A OTRA CADENA (TEXTO2)
    */

    char texto1[20];
    char texto2[20];

    printf("Ingrese una palabra: ");
    gets(texto1);

    strcpy(texto2,texto1);
    printf("Original: %s\nCopia: %s",texto1,texto2);

    /**------------------------------------------------------------------------------
    *STRLEN LEE LA CANTIDAD DE CARACTERES QUE CONTIENE LA CADENA
    */

    char letras[20];
    int x;

    printf("Ingrese letras: ");
    gets(letras);

    x = strlen(letras);

    printf("Cantidad: %d",x);
    return 0;
}
