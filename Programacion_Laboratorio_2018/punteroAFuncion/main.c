#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void funcionBienvenida(char* nombre,char* apellido);
void funcionDespedida(char* nombre,char* apellido);
void fdeLegada(void(*punteroFuncion)(char* elDato,char* elDato2),char*nombre,char*apellido);

int main()
{
    fdeLegada(funcionBienvenida,"Hernan","Franco");
    getche();
    fdeLegada(funcionDespedida,"Hernan","Franco");
    getche();
    return 0;
}

void funcionBienvenida(char* nombre, char* apellido)
{
    printf("Bienvenido %s %s, a la empresa.",nombre,apellido);
}
void funcionDespedida(char* nombre, char* apellido)
{
    printf("Vos %s %s estas despedido ------->.",nombre,apellido);
}

void fdeLegada(void(*punteroFuncion)(char* elDato, char* elDato2),char*nombre,char*apellido)
{
    punteroFuncion(nombre,apellido);
}
