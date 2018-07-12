#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct fecha
{
    int dia,mes,anio;
};
struct gente
{
    char nombre[20];
    struct fecha f_nacimiento;
};
void main(void)
{
    struct gente pers;
    struct fecha fn;
    printf("Ingrese nombre: ");
    gets(pers.nombre);
    printf("Ingrese dia de nacimiento: ");
    scanf("%d",&fn.dia);
    printf("Ingrese mes de nacimiento: ");
    scanf("%d",&fn.mes);
    printf("Ingrese a¤o de nacimiento: ");
    scanf("%d",&fn.anio);
    pers.f_nacimiento=fn;

    printf("Hola, %s. Usted nacio el %d/%d/%d", pers.nombre,pers.f_nacimiento.dia,pers.f_nacimiento.mes,pers.f_nacimiento.anio);
}
