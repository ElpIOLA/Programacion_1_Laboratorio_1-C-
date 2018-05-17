#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id_usuario; /** CAMPO CLAVE PRIMARIA PK(PRIMARY KEY)*/
    char nombre[21];
    int id_serie; /**FK*/
    int estadoUsuario;
}eUsuario;

typedef struct{
    int id_serie;
    char nombre[21];
    char genero[21];
    int cantTemporadas;
    int estadoSerie;
}eSerie;

int main()
{

    return 0;
}
