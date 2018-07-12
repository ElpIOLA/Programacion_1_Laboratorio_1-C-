#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "publicacion.h"
#define OCUPADO 0
#define LIBRE 1

int eProd_mostrarUno(eProductos listado){
    printf("\n\tProducto: %s - ID: %d - Precio: %.2f - Stock: %d - Ventas: %d\n\n",listado.nombre,listado.idProducto,listado.precio,listado.stock,listado.cantidad_ventas);
    return 0;
}

int eProd_mostrarListado(eProductos listado[], int limite){
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL){
        retorno = 0;
        for(i=0; i<limite; i++){
            if(listado[i].estado == OCUPADO){
                eProd_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}

int publicar_producto(eProductos listaProd[], int limite, eUsuario listaUser[], int id){
    int retorno = -1, index_user, index_produc, id_produc;
    char aux_id[21], nombre[31], aux_precio[21], aux_stock[21];

    if(limite >= 0 && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id)){
            printf("\n\tERROR! La ID debe contener solo numeros.\n");
        }
        id = atoi(aux_id);
        index_user = eUsua_buscarPorId(listaUser,limite,id);
            if(index_user >= 0){
                retorno = -3;
                index_produc = eProd_buscarLugarLibre(listaProd,limite);
                if(index_produc >= 0){
                retorno = -4;

                id_produc = eProd_siguienteId(listaProd,limite);
                if(!getStringLetras("\n\tIngrese nombre del producto: ",nombre)){
                    printf("\n\tERROR! El nombre debe contener solo caracteres.\n");
                }
                fflush(stdin);
                strcpy(listaProd[index_produc].nombre,nombre);

                if(!getStringNumerosFloat("\n\tIngrese precio: ",aux_precio)){
                    printf("\n\tERROR! El precio debe contener solo numeros.");
                }
                listaProd[index_produc].precio = atof(aux_precio);

                if(!getStringNumeros("\n\tIngrese cantidad en stock: ",aux_stock)){
                    printf("\n\tERROR! El stock debe contener solo numeros.");
                }
                listaProd[index_produc].stock = atoi(aux_stock);
                listaProd[index_produc].idProducto = id_produc;
                listaProd[index_produc].estado = OCUPADO;
                retorno = 0;
                }
            }
        }
        return retorno;
}

int modificar_publicacion(eProductos listaProd[], int limite, eUsuario listaUser[], int id){
    int retorno = -1, index_user, lista_productos, id_producto, index_prod;
    char aux_id_user[21], aux_id_prod[21], aux_Nuevo_Precio[21], aux_nuevo_stock[21];

    if(limite >= 0 && listaProd != NULL){
        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id_user)){
            printf("\n\tERROR! La ID debe contener solo numeros.\n");
        }
        id = atoi(aux_id_user);
        index_user = eUsua_buscarPorId(listaUser,limite,id);
            if(index_user >= 0){

                retorno = -3;
                lista_productos = eProd_mostrarListado(listaProd,limite);
                if(lista_productos == 0){

                    retorno = -4;
                    if(!getStringNumeros("\n\tIngrese ID del producto: ",aux_id_prod)){
                        printf("\n\tERROR! La ID debe contener solo numeros.\n");
                    }
                    id_producto = atoi(aux_id_prod);
                    index_prod = eProd_buscarPorId(listaProd,limite,id_producto);

                    if(index_prod >= 0){

                        retorno = 0;
                        if(!getStringNumerosFloat("\n\tIngrese nuevo precio: ",aux_Nuevo_Precio)){
                            printf("\n\t!ERROR! El precio debe ser contener solo numeros.");
                        }
                        listaProd[index_prod].precio = atof(aux_Nuevo_Precio);

                        if(!getStringNumeros("\n\tIngrese nuevo stock: ",aux_nuevo_stock)){
                            printf("\n\t!ERROR! El stock debe ser contener solo numeros.");
                        }
                        listaProd[index_prod].stock = atoi(aux_nuevo_stock);
                    }
                }
            }
        }
    return retorno;
}

int cancelar_publicacion(eProductos listaProd[], int limite, eUsuario listaUser[], int id){
    int retorno = -1, index_user, lista_productos, id_producto, index_prod;
    char aux_id_user[21];

    if(limite >= 0 && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id_user)){
            printf("\n\tERROR! La ID debe contener solo numeros.\n");
        }
        id = atoi(aux_id_user);
        index_user = eUsua_buscarPorId(listaUser,limite,id);
        if(index_user >= 0){

            retorno = -3;
            lista_productos = eProd_mostrarListado(listaProd,limite);
            if(lista_productos == 0){

                retorno = -4;
                if(!getStringNumeros("\n\tIngrese ID del producto: ",aux_id_prod)){
                    printf("\n\tERROR! La ID debe contener solo numeros.\n");
                }
                id_producto = atoi(aux_id_prod);
                index_prod = eProd_buscarPorId(listaProd,limite,id_producto);

                if(index_prod >= 0){

                    retorno = 0;
                    listaProd[index_prod].estado = LIBRE;
                }
            }
        }
    }
    return retorno;
}

int comprar_producto(eProductos listaProd[], int limite, eUsuario listaUser[], int id){
    int retorno = -1, index;
    char aux_id_prod[21];

    if(limite >= 0 && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del producto a comprar: ",aux_id_prod)){
            printf("\n\tERROR! La ID debe contener solo numeros.\n");
        }
        id = atoi(aux_id_prod);
        index = eProd_buscarPorId(listaProd,limite,id);
        if(index >= 0){
            (listaProd[index].stock >= 0){
                listaProd[index].cantidad_ventas ++;
            }
        }
    }
    return retorno;
}
