#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    char a[20];
    int i;

    printf("Ingrese su nombre: ");
    gets(a); // ALMACENA EL DATO STRING DEL USUARIO.

    printf("%s", a);
    getch();
    return 0;
}
