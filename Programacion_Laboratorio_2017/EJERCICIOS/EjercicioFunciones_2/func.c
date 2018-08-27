#include <stdio.h>
#include <stdlib.h>


char intvalidaS_N(void)
{
    char respuesta = 's';

    printf("\nDesea ingresar mas numeros?\n[s] = Si\n[n] = No\n");
    fflush(stdin);
    scanf("%c", &respuesta);

    if(respuesta == 'n')
    {
        respuesta = 'n';
    }
    else if(respuesta == 's')
    {
        respuesta = 's';
    }
    return respuesta;
}
