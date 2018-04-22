#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include "libreria.h"
#define TAM 3

int main()
{
    int legajo[TAM] = {};
    char nombre[TAM][20];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];
    int opcion;
    int index;

    do{
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4. BAJA\n5. ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            index = cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1){
                printf("\n\tNO HAY LUGAR!\n");
            }
            break;
        case 2:
            mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);
            break;
        case 3:
            index = modificarAlumno(legajo,nombre,nota1,nota2,TAM);
            break;
        case 4:
            index = borrarAlumno(legajo,nombre,nota1,nota2,TAM);
            break;
        case 5:
            index = ordenarAlumnos(legajo,nombre,nota1,nota2,TAM);
        }


    }while(opcion!=9);

    return 0;
}

