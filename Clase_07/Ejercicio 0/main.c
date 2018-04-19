#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 3

float calcularPromedio(int not1, int not2, int not3);
void mostrarAlumno(char [][30], int [], float [], int);


int main()
{
    int legajo[CANT], nota1[CANT], nota2[CANT], nota3[CANT], i;
    char nombre[CANT][30]; //MATRIZ
    float promedio[CANT];

    for(i=0;i<CANT;i++){

        printf("\n\tIngrese nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\n\tIngrese legajo: ");
        scanf("%d",&legajo[i]);

        printf("\n\tIngrese nota 1: ");
        scanf("%d",&nota1[i]);

        printf("\n\tIngrese nota 2: ");
        scanf("%d",&nota2[i]);

        printf("\n\tIngrese nota 3: ");
        scanf("%d",&nota3[i]);

        promedio[i] = calcularPromedio(nota1[i],nota2[i],nota3[i]);
    }

    mostrarAlumno(nombre,legajo,promedio,CANT);

    return 0;
}

float calcularPromedio(int not1, int not2, int not3){
    float promedio = 0;
    int i;

    for(i=0;i<CANT;i++){
        promedio = (float)(not1 + not2 + not3) / CANT;
    }
    return promedio;
}

void mostrarAlumno(char nom[][30], int leg[], float prom[], int cantidad){
    int i;
    for(i=0;i<cantidad;i++){
        printf("\n\tAlumno: %s\n\tLegajo: %d\n\tPromedio %.2f\n",nom[i],leg[i],prom[i]);
    }
}


