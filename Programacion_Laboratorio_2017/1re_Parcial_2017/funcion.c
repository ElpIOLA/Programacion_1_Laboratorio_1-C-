#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "funcion.h"
#define LIBRE 1
#define OCUPADO 0

int menu(){
    int opcion = 0, retorno = -1;
    char aux_Opc[10];

        printf("\n\t1-.Alta Usuario\n");
        printf("\n\t2-.Modificar Usuario\n");
        printf("\n\t3-.Baja Usuario\n");
        printf("\n\t4-.Publicar Producto\n");
        printf("\n\t5-.Modificar Producto\n");
        printf("\n\t6-.Cancelar Producto\n");
        printf("\n\t7-.Comprar Producto\n");
        printf("\n\t8-.Listar Publicaciones de Usuario\n");
        printf("\n\t9-.Listar Publicaciones\n");
        printf("\n\t10-.Listar Usuarios\n");
        printf("\n\t11-.Terminar Programa\n");

        if(!getStringNumeros("\n\tIngrese Opcion: ",aux_Opc)){
            retorno = -2;
        }
        opcion = atoi(aux_Opc);
        if(opcion > 0){
            retorno = opcion;
        }

    return retorno;
}

/**-----------------------------------------------------------------------------------------------------*/

int eProg_init(eProvedor listaUser[], eProducto listaProd[], int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && listaUser != NULL && listaProd != NULL){
        retorno = 0;
        for(i=0; i<limite; i++){
            listaUser[i].estado = LIBRE;
            listaUser[i].id_Provedor = 0;
        }
        for(i=0; i<limite; i++){
            listaProd[i].estado = LIBRE;
            listaProd[i].id_Producto = 0;
        }
    }
    return retorno;
}

int eProve_buscarLugarLibre(eProvedor listaUser[], int limite){
    int retorno = -1;
    int i;
    if(limite > 0 && listaUser != NULL){
        retorno = 0;
        for(i=0;i<limite;i++){
            if(listaUser[i].estado == LIBRE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProduc_buscarLugarLibre(eProducto listaProd[], int limite){
    int retorno = -1;
    int i;
    if(limite > 0 && listaProd != NULL){
        for(i=0;i<limite;i++){
            if(listaProd[i].estado == LIBRE){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProve_siguienteId(eProvedor listaUser[],int limite){
    int retorno = 0;
    int i;
    if(limite > 0 && listaUser != NULL){
        for(i=0; i<limite; i++){
            if(listaUser[i].estado == OCUPADO){
                if(listaUser[i].id_Provedor>retorno){
                     retorno=listaUser[i].id_Provedor;
                }
            }
        }
    }

    return retorno+1;
}

int eProduc_siguienteId(eProducto listaProd[],int limite){
    int retorno = 0;
    int i;
    if(limite > 0 && listaProd != NULL){
        for(i=0; i<limite; i++){
            if(listaProd[i].estado == OCUPADO){
                if(listaProd[i].id_Producto>retorno){
                     retorno=listaProd[i].id_Producto;
                }
            }
        }
    }

    return retorno+1;
}

int eProve_buscarPorId(eProvedor listaUser[] ,int limite, int id){
    int retorno = -1;
    int i;
    if(limite > 0 && listaUser != NULL){
        retorno = -2;
        for(i=0;i<limite;i++){
            if(listaUser[i].estado == OCUPADO && listaUser[i].id_Provedor == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProduc_buscarPorId(eProducto listaProd[] ,int limite, int id){
    int retorno = -1;
    int i;
    if(limite > 0 && listaProd != NULL){
        retorno = -2;
        for(i=0;i<limite;i++){
            if(listaProd[i].estado == OCUPADO && listaProd[i].id_Producto == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProduc_buscarPorIdUsuario(eProducto listaProd[] ,int limite, int id){
    int retorno = -1;
    int i;
    if(limite > 0 && listaProd != NULL){
        retorno = -2;
        for(i=0;i<limite;i++){
            if(listaProd[i].estado == OCUPADO && listaProd[i].id_usuario == id){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**------------------------------FUNCIONES DE LISTAR-------------------------------------------------*/

void lista_usuarios(eProvedor listaUser[], int tamUser){
    int i;

    for(i=0;i<tamUser;i++){
        if(listaUser[i].estado == OCUPADO){
            printf("\n\t-ID: %d\n\t-Nombre: %s\n\t-Calificacion: %.2f\n",listaUser[i].id_Provedor,listaUser[i].nombre,listaUser[i].calificacion);
        }
    }
}

void listar_productos(eProducto listaProd[], int tamProd){
    int i;

    for(i=0;i<tamProd;i++){
        if(listaProd[i].estado == OCUPADO){
            printf("\n\t-ID: %d\n\t-Nombre: %s\n\t-Precio: %.2f\n\t-Stock: %d\n",listaProd[i].id_Producto,listaProd[i].nombre,listaProd[i].precio,listaProd[i].stock);
        }
    }
}

void lista_UsuarioConSuProducto(eProvedor listaUser[],int tamUser, eProducto listaProd[], int tamProd, int id_user){

    int i,j;

    for(i=0;i<tamUser;i++){
        if(listaUser[i].estado == OCUPADO){
            if(listaUser[i].id_Provedor == id_user){
                for(j=0;j<tamProd;j++){
                    if(listaUser[i].id_Provedor == listaProd[j].id_usuario){
                        if(listaProd[j].estado == OCUPADO){
                            printf("\n\t-ID: %d\n\t-Producto: %s\n\t-Precio: %.2f\n\t-Ventas: %d\n\t-Stock: %d\n",listaProd[j].id_Producto,listaProd[j].nombre,listaProd[j].precio,listaProd[j].cantidad_vendida,listaProd[j].stock);
                        }
                    }
                }
            }
        }
    }
}

/**---------------------------------FUNCIONES MATEMATICAS--------------------------------------------------*/

float promedio(eProvedor listaUser[],float numero, int tamUser, int id){
    float total = 0, promedio = 0;
    int i, cont = 0, retorno = -1;

    for(i=0;i<tamUser;i++){
        if(listaUser[i].id_Provedor == id){
            total = total + numero;
            cont++;
        }
    }
    promedio = total / cont;

    for(i=0;i<tamUser;i++){
        if(listaUser[i].estado == OCUPADO){
            retorno = 0;
            listaUser[i].calificacion += promedio;
        }
    }
    //printf("\n\tTotal de ventas: %.2f\n", total);
    //printf("\n\tPromedio de ventas: %.2f\n", promedio);
    return retorno;
}

