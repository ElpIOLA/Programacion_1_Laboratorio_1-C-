#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "menu.h"
#define CANT_MOVIE 10
int main()
{
    EMovie movie[CANT_MOVIE];
    EMovie* pMovie;
    pMovie = movie;
    inicializarmovie(movie,CANT_MOVIE);
    datos_hard_pelicula(pMovie,CANT_MOVIE);

    char seguir='s';
    int opcion=0, index = 1;

    while(seguir == 's'){

        opcion = menu();
        if(opcion > 0){
            switch(opcion)
            {
                case 1:
                    index = agregarPelicula(pMovie,CANT_MOVIE);
                    if(index == 1){
                        printf("\n\tPELICULA AGREGADA!\n");
                    }else if(index == -2){
                        printf("\n\tERROR! NO HAY MAS LUGARES LIBRES!\n");
                    }else if(index == -3){
                        printf("\n\tERROR! NO SE PUEDEN AGREGAR MAS ID!\n");
                    }else if(index == -4){
                        printf("\n\tERROR! EL GENERO DEBE CONTENER SOLO LETRAS!\n");
                    }else if(index == -5){
                        printf("\n\tERROR! LA DURACION DEBE CONTENER SOLO NUMEROS!\n");
                    }else if(index == -6){
                        printf("\n\tERROR! EL PUNTAJE DEBE CONTENER SOLO NUMEROS!\n");
                    }else if(index == -7){
                        printf("\n\tERROR! EL PUNTAJE DEBE SER ENTRE [1 Y 100]!\n");
                    }
                    break;
                case 2:
                    listarPeliculas(pMovie,CANT_MOVIE);
                    index = borrarPelicula(pMovie,CANT_MOVIE);
                    if(index == 1){
                        printf("\n\tPELICULA BORRADA!\n");
                    }else if(index == -2){
                        printf("\n\tERROR! ARCHIVO NULL!\n");
                    }else if(index == -3){
                        printf("\n\tERROR! ESTA PELICULA NO ESTA REGISTRADA!\n");
                    }else if(index == -4){
                        printf("\n\tERROR! INGRESO UN DATO QUE NO ES LETRA!\n");
                    }else if(index == -5){
                        printf("\n\tCANCELO LA ELIMINACION DE LA PELICULA!\n");
                    }else if(index == -6){
                        printf("\n\tERROR! INGRESO UNA LETRA QUE NO ES [S] O [N]!\n");
                    }
                    break;
                case 3:
                    listarPeliculas(pMovie,CANT_MOVIE);
                    index = modificarPelicula(pMovie,CANT_MOVIE);
                    if(index == 1){
                        printf("\n\tPELICULA MODIFICADA!\n");
                    }else if(index == -2){
                        printf("\n\tERROR! LA ID INGRESADA DEBE CONTENER SOLO NUMEROS!\n");
                    }else if(index == -3){
                        printf("\n\tERROR! NO EXISTE UNA PELICULA CON ESA ID!\n");
                    }else if(index == -4){
                        printf("\n\tERROR! LA RESPUESTA DEBE CONTENER SOLO LETRAS!\n");
                    }else if(index == -5){
                        printf("\n\tERROR! EL GENERO DEBE CONTENER SOLO LETRAS!\n");
                    }else if(index == -6){
                        printf("\n\tERROR! LA DURACION DEBE CONTENER SOLO NUMEROS!\n");
                    }else if(index == -7){
                        printf("\n\tERROR! EL PUNTAJE DEBE CONTENER SOLO NUMEROS!\n");
                    }else if(index == -8){
                        printf("\n\tERROR! EL PUNTAJE DEBE SER UN NUMERO ENTRE [1 - 100]!\n");
                    }else if(index == -9){
                        printf("\n\tCANCELO LA MODIFICACION DE LA PELICULA!\n");
                    }
                    break;
                case 4:
                    index = generarPagina(pMovie,CANT_MOVIE);
                    if(index == 1){
                        printf("\n\tPAGINA WEB GENERADA CON EXITO!!\n");
                    }else if(index == -2){
                        printf("\n\tERROR! EL ARCHIVO NO EXISTE!\n");
                    }
                   break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    printf("\n\tERROR! ELIJA UNA OPCION ENTRE [1-5]\n");
            }
        }else{
            printf("\n\tERROR! USTED INGRESO UNA LETRA, SIGNO O NUMERO NEGATIVO\n");
        }
    }

    return 0;
}
