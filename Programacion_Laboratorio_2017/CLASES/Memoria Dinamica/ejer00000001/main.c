#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S_Person
{
    char nombre[20];
    int edad;
};
typedef struct S_Person persona;

int enterPersona(persona *p);
void printPersona(persona *p);

int main()
{
    persona p;

    while(enterPersona(&p)==0)
        printPersona(&p);

    system("PAUSE");
    return 0;
}

int enterPersona(persona *p)
{
    printf("Ingrese el nombre:\n");
    scanf("%s", p->nombre);
    if(strncmp(p->nombre,"salir",5) == 0)
        return 1;
    printf("Ingrese la edad:\n");
    scanf("%d",&(p->edad));
    return 0;
}

void printPersona(persona *p)
{
    printf("Nombre: %s \nEdad: %d\n",p->nombre,p->edad);
}
