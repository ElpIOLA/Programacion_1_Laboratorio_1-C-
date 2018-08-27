#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1

void inicializarmovie(EMovie* movie, int tam){
    int i;
    if(tam > 0 && movie != NULL){
       for(i=0;i<tam;i++){
            (movie+i)->estado = LIBRE;
            (movie+i)->id_pelicula = 0;
       }
    }
}

void datos_hard_pelicula(EMovie* movie, int tam){

    int id_pro[]= {1,2,3},i;
    char titulo[][30]= {"Titanic","La Gran Pelea","Darse Cuenta"};
    char genero[][20]= {"Romance","Accion","Drama"};
    int duracion[]= {195,96,104};
    char descripcion[][700]= {"Una joven (Kate Winslet) de sociedad abandona a su arrogante pretendiente (Billy Zane) por un artista (Leonardo DiCaprio) humilde en el transatlántico que se hundió durante su viaje inaugural.","Un peleador herido de la rodilla sube devuelta a el cuadrilatero en las peleas de carceles.","Un médico intenta salvar la vida de un muchacho herido en un accidente."};
    int puntaje[] = {89,77,81};
    char linkImagen[][150] = {"Portadas/titanic.jpg","Portadas/pelea.jpg","Portadas/darse.jpg"};

    inicializarmovie(movie,tam);

    for(i=0;i<3;i++){
        (movie+i)->id_pelicula = id_pro[i];
        strcpy((movie+i)->titulo,titulo[i]);
        strcpy((movie+i)->genero,genero[i]);
        (movie+i)->duracion = duracion[i];
        strcpy((movie+i)->descripcion,descripcion[i]);
        (movie+i)->puntaje = puntaje[i];
        strcpy((movie+i)->linkImagen,linkImagen[i]);
        (movie+i)->estado = OCUPADO;
    }
    GuardarEnArchivoBinario(movie,tam);
}

void listarPeliculas(EMovie* movie, int tam){
    int i;

    for(i=0;i<tam;i++){
        if((movie+i)->estado == OCUPADO){
            printf("\n -ID: %d -Titulo: %s -Genero: %s -Duracion: %d -Puntaje: %d\n",(movie+i)->id_pelicula,(movie+i)->titulo,(movie+i)->genero,(movie+i)->duracion,(movie+i)->puntaje);
        }
    }
}

int buscarLugarLibre(EMovie* movie,int tam){
    int retorno = -1;
    int i;
    if(tam > 0 && movie != NULL){
        retorno = -2;
        for(i=0;i<tam;i++){
            if((movie+i)->estado == LIBRE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteId(EMovie* movie,int tam){
    int retorno = 0;
    int i;
    if(tam > 0 && movie != NULL){
        for(i=0; i<tam; i++){
            if((movie+i)->estado == OCUPADO){
                if((movie+i)->id_pelicula>retorno){
                     retorno=(movie+i)->id_pelicula;
                }
            }
        }
    }
    return retorno+1;
}

int buscarPorId(EMovie* movie, int tam, int id_peli){
    int retorno = -1;
    int i;
    if(tam > 0 && movie != NULL){
        retorno = -2;
        for(i=0;i<tam;i++){
            if((movie+i)->estado == OCUPADO && (movie+i)->id_pelicula == id_peli){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int GuardarEnArchivoBinario(EMovie* movie, int tam){
    int index = -1,i;
    FILE* archivo;
    archivo = fopen("archivo.bat","wb");

    if(archivo != NULL){
        for(i=0;i<tam;i++){
            if((movie+i)->estado == OCUPADO){
                fwrite(movie,sizeof(EMovie),tam,archivo);
                index = 1;
            }
        }
    }else{
        return index;
    }
    fclose(archivo);
    return index;
}

int agregarPelicula(EMovie* movie, int tam){
    int retorno = -1, index, id_peli, puntaje;
    char genero[21], duracion[21], aux_puntaje[21];

    if(tam > 0 && movie != NULL){
        retorno = -2;
        index = buscarLugarLibre(movie,tam);
        if(index >= 0){
            retorno = -3;
            id_peli = siguienteId(movie,tam);
            if(id_peli > 0){
                retorno = 1;
                printf("\n\tINGRESE EL TITULO DE LA PELICULA: ");
                fflush(stdin);
                gets((movie+index)->titulo);

                if(!getStringLetras("\n\tINGRESE GENERO: ",genero)){retorno = -4;}
                fflush(stdin);
                strcpy((movie+index)->genero,genero);

                if(!getStringNumeros("\n\tINGRESE DURACION: ",duracion)){retorno = -5;}
                fflush(stdin);
                (movie+index)->duracion = atoi(duracion);

                printf("\n\tINGRESE DESCRIPCION DE LA PELICULA: ");
                fflush(stdin);
                gets((movie+index)->descripcion);

                if(!getStringNumeros("\n\tINGRESE PUNTAJE: ",aux_puntaje)){retorno = -6;}
                fflush(stdin);
                puntaje = atoi(aux_puntaje);
                if(puntaje > 0 && puntaje < 101){
                    (movie+index)->puntaje = puntaje;
                }else{
                    retorno = -7;
                }

                printf("\n\tINGRESE LINK DE LA IMAGEN: ");
                fflush(stdin);
                gets((movie+index)->linkImagen);

                if(retorno == 1){
                    (movie+index)->id_pelicula = id_peli;
                    (movie+index)->estado = OCUPADO;
                    GuardarEnArchivoBinario(movie,tam);
                }
            }
        }
    }
    return retorno;
}

int borrarPelicula(EMovie* movie, int tam){
    int retorno = -1, index, id;
    char resp[21], id_peli[21];

    if(tam > 0 && movie != NULL){

        if(!getStringNumeros("\n\tINGRESE ID DE LA PELICULA A ELIMINAR: ",id_peli)){retorno = -2;}
        id = atoi(id_peli);
        index = buscarPorId(movie,tam,id);
        retorno = -3;
        if(index >= 0){
            printf("\n\tESTA SEGURO QUE DESEA ELIMINAR LA PELICULA?\n\tSI = [s] y NO = [n]\n");
            if(!getStringLetras("\n\tRESPUESTA:",resp)){ retorno = -4;}
                if(strcmp(resp,"s")==0){
                    retorno = 1;
                    (movie+index)->estado = LIBRE;
                }else if(strcmp(resp,"n")==0){
                    retorno = -5;
                }else{
                    retorno = -6;
                }
            if(retorno == 1){
                GuardarEnArchivoBinario(movie,tam);
            }
        }
    }
    return retorno;
}

int modificarPelicula(EMovie* movie, int tam){
    int retorno = -1, id_peli, index, puntaje;
    char aux_id[21], resp[21], aux_genero[31], aux_duracion[21], aux_puntaje[21];

    if(tam > 0 && movie != NULL){
        if(!getStringNumeros("\n\tINGRESA EL ID DE LA PELICULA A MODIFICAR: ",aux_id)){retorno = -2;}
        id_peli = atoi(aux_id);
        index = buscarPorId(movie,tam,id_peli);
        retorno = -3;
        if(index >= 0){
            if(!getStringLetras("\n\tESTA SEGURO QUE DESEA MODIFICAR LA PELICULA?\n\t SI = [s] Y NO = [n]\n\tRESPUESTA: ",resp)){retorno = -4;}
            if(strcmp(resp,"s")==0){
                retorno = 1;
                printf("\n\tTITULO ACTUAL: %s",(movie+index)->titulo);
                printf("\n\tINGRESE EL NUEVO TITULO: ");
                fflush(stdin);
                gets((movie+index)->titulo);

                printf("\n\tGENERO ACTUAL: %s",(movie+index)->genero);
                if(!getStringLetras("\n\tINGRESE GENERO NUEVO: ",aux_genero)){retorno = -5;}
                fflush(stdin);
                strcpy((movie+index)->genero,aux_genero);

                printf("\n\tDURACION ACTUAL: %d",(movie+index)->duracion);
                if(!getStringNumeros("\n\tINGRESE DURACION NUEVA: ",aux_duracion)){retorno = -6;}
                (movie+index)->duracion = atoi(aux_duracion);

                printf("\n\tDESCRIPCION ACTUAL: %s",(movie+index)->descripcion);
                printf("\n\tINGRESE NUEVA DESCRIPCION: ");
                fflush(stdin);
                gets((movie+index)->descripcion);

                printf("\n\tPUNTAJE ACTUAL: %d",(movie+index)->puntaje);
                if(!getStringNumeros("\n\tINGRESE NUEVO PUNTAJE: ",aux_puntaje)){retorno = -7;}
                puntaje = atoi(aux_puntaje);
                if(puntaje > 0 && puntaje < 101){
                    (movie+index)->puntaje = puntaje;
                }else{
                    retorno = -8;
                }

                printf("\n\tINGRESE LINK DE IMAGEN NUEVA: ");
                fflush(stdin);
                gets((movie+index)->linkImagen);

                if(retorno == 1){
                    GuardarEnArchivoBinario(movie,tam);
                }
            }if(strcmp(resp,"n")==0){
                retorno = -9;
            }
        }
    }
    return retorno;
}

int generarPagina(EMovie* movie, int tam){
    int i, retorno = -1;
    FILE* archivo;
    archivo = fopen("archivo.bat","rb");

    if(archivo != NULL){
        while(!feof(archivo)){
            fread(movie,sizeof(EMovie),tam,archivo);
            if(feof(archivo)){
                break;
            }
            i++;
        }
        fclose(archivo);

        archivo = fopen("index.html","w");

        for(i=0;i<tam;i++){
            retorno = 1;
            if((movie+i)->estado == OCUPADO){
                fprintf(archivo,"<html lang='en'><head>"
                                "<meta charset='utf-8'>"
                                "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                                "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                                "<title>PAGINA WEB</title></head><body style=background-color:#17202A;>");
                fprintf(archivo,"<div style='background-color:#E74C3C; margin:5px; border-radius: 23px 23px 23px 23px;"
                                "-moz-border-radius: 23px 23px 23px 23px;"
                                "-webkit-border-radius: 23px 23px 23px 23px;"
                                "border: 2px solid #000000;' class='container'>"
                                "<div style='overflow:auto;' class='row'>"
                                "<!-- Repetir esto para cada pelicula -->"
                                "<article class='col-md-4 article-intro'>"
                                "<a href='#'>");
                fprintf(archivo,"<img style='width:200px; height:200px; padding:10px;' class='img-responsive img-rounded' src='%s' alt=''>",(movie+i)->linkImagen);
                fprintf(archivo,"</a>");
                fprintf(archivo,"<h3 style='padding:7px;'>");
                fprintf(archivo,"<a style=' background-color:#FDEDEC; padding:6px; border-radius: 10px 10px 10px 10px;"
                                "-moz-border-radius: 10px 10px 10px 10px;"
                                "-webkit-border-radius: 10px 10px 10px 10px;"
                                "border: 2px solid #000000;' href='#'>%s</a>",(movie+i)->titulo);
                fprintf(archivo,"</h3>");
                fprintf(archivo,"<ul>");
                fprintf(archivo,"<li style='background-color:#FDEDEC; padding:2px; width:140px; margin:2px; border-radius: 10px 10px 10px 10px;"
                                "-moz-border-radius: 10px 10px 10px 10px;"
                                "-webkit-border-radius: 10px 10px 10px 10px;"
                                "border: 1px solid #000000;'>Genero:%s</li>",(movie+i)->genero);
                fprintf(archivo,"<li style='background-color:#FDEDEC; padding:2px; width:140px; margin:2px; border-radius: 10px 10px 10px 10px;"
                                "-moz-border-radius: 10px 10px 10px 10px;"
                                "-webkit-border-radius: 10px 10px 10px 10px;"
                                "border: 1px solid #000000;'>Puntaje:%d</li>",(movie+i)->puntaje);
                fprintf(archivo,"<li style='background-color:#FDEDEC; padding:2px; width:140px; margin:2px; border-radius: 10px 10px 10px 10px;"
                                "-moz-border-radius: 10px 10px 10px 10px;"
                                "-webkit-border-radius: 10px 10px 10px 10px;"
                                "border: 1px solid #000000;' >Duracion:%d</li>",(movie+i)->duracion);
                fprintf(archivo,"</ul>");
                fprintf(archivo,"<p style='background-color:#FDEDEC; padding:10px; margin:2px; border-radius: 10px 10px 10px 10px;"
                                "-moz-border-radius: 10px 10px 10px 10px;"
                                "-webkit-border-radius: 10px 10px 10px 10px;"
                                "border: 1px solid #000000;'>%s</p>",(movie+i)->descripcion);
                fprintf(archivo,"</article>"
                                "<!-- Repetir esto para cada pelicula -->"
                                "</div>"
                                "<!-- /.row -->"
                                "</div>"
                                "<!-- /.container -->"
                                "</body></html>");
            }
        }
    }else{
        retorno = -2;
    }
    fclose(archivo);
    return retorno;
}
