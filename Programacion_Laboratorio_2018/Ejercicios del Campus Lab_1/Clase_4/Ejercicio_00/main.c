/**
    Diseñar un programa para jugar a adivinar un número entre 0 y 100.
    El juego tiene que dar pistas de si el número introducido por el jugador está por encima o por debajo.
    El juego termina cuando se adivina el número o se decide terminar de jugar ingresando un número negativo.
    Permitir jugar tantas veces como lo desee el jugador y al salir mostrar su mejor puntuación.
    Utilizar la biblioteca del punto 1.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{

    int numero, numeroSecreto, contador = 0, flag = 0, acumulador = 0, cantidadDePartidas = 1;
    char tecla = 's';

    while(tecla == 's')
    {
        numeroSecreto = calcularNumeroAleatorio(1,100,1);

        flag = 1;
        while(flag == 1)
        {
            printf("\nINGRESE UN NUMERO ENTRE [ 1 - 100 ]: ");
            if(getInt(&numero))
            {
                if(numero > 0 && numero <= 100)
                {
                    if(numero > numeroSecreto)
                    {
                        system("cls");
                        printf("\t\t----------------------------------------");
                        printf("\n\t        |EL NUMERO INGRESADO ES MAYOR AL SECRETO|\n");
                        printf("\t\t----------------------------------------\n\n");
                    }
                    if(numero < numeroSecreto)
                    {
                        system("cls");
                        printf("\t\t----------------------------------------");
                        printf("\n\t        |EL NUMERO INGRESADO ES MENOR AL SECRETO|\n");
                        printf("\t\t----------------------------------------\n\n");
                    }
                    if(numero == numeroSecreto)
                    {
                        system("cls");
                        acumulador += contador;
                        printf("\t\t----------------------------------------");
                        printf("\n\t        |HAZ GANADO EL JUEGO! NUMERO SECRETO: %d|\n",numeroSecreto);
                        printf("\t\t----------------------------------------\n\n");
                        printf("\t\t--------------");
                        printf("\n\t        |INTENTOS: %d |\n",contador);
                        printf("\t\t--------------\n\n");
                        printf("\t\t-------------------------------");
                        printf("\n\t        |CANTIDAD PARTIDAS JUGADAS: %d |\n",cantidadDePartidas);
                        printf("\t\t-------------------------------\n\n");
                        printf("\t\t--------------------------------");
                        printf("\n\t        |CANTIDAD TOTAL DE INTENTOS: %d |\n",acumulador);
                        printf("\t\t--------------------------------\n\n");
                        flag = 0;
                    }
                }
                else if(numero < 0)
                {
                    system("cls");
                    printf("\t\t---------------------------");
                    printf("\n\t        |EL NUMERO SECRETO ERA: %d|\n",numeroSecreto);
                    printf("\t\t---------------------------\n\n");
                    flag = 0;
                }
                contador++;
            }
        }
        printf("\n\tDESEA JUGAR NUEVAMENTE? [s/n] ");
        scanf("%c",&tecla);
        if(tecla == 's')
        {
            cantidadDePartidas++;
            contador = 0;
        }
        system("cls");
    }

    system("cls");
    printf("\n\n");
    printf("\t\t----------------------");
    printf("\n\t        |GRACIAS POR JUGAR :D|\n");
    printf("\t\t----------------------\n\n");
    return 0;
}
