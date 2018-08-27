#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionValidar.h"
#include "funcion.h"
#define LIBRE 1
#define OCUPADO 0

int alta_usuario(eProvedor listaUser[], int tamUser){
    int retorno = -1, index, id_user;
    char aux_nom[21];

    if(tamUser > 0 && listaUser != NULL){
        retorno = -2;

        index = eProve_buscarLugarLibre(listaUser,tamUser);
        if(index >= 0){
            retorno = -3;

            id_user = eProve_siguienteId(listaUser,tamUser);
            if(id_user > 0){

                retorno = 0;
                if(!getStringLetras("\n\tIngrese su nombre: ",aux_nom)){
                    retorno = -4;
                }
                fflush(stdin);

                if(retorno == 0){
                    listaUser[index].id_Provedor = id_user;
                    strcpy(listaUser[index].nombre,aux_nom);
                    listaUser[index].calificacion = 0;
                    listaUser[index].estado = OCUPADO;
                }
            }
        }
    }
    return retorno;
}

int modificar_usuario(eProvedor listaUser[], int tamUser){
    int retorno = -1, id_usuario, index;
    char aux_id[21], aux_nombre[21];

    if(tamUser > 0 && listaUser != NULL){

        retorno = -2;
        lista_usuarios(listaUser,tamUser);

        if(!getStringNumeros("\n\tIngrese ID del usuario a modificar: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_usuario = atoi(aux_id);

        retorno = -3;
        index = eProve_buscarPorId(listaUser,tamUser,id_usuario);

        if(index >= 0){

            retorno = 0;
            printf("\n\tNombre actual: %s\n",listaUser[index].nombre);
            if(!getStringLetras("\n\tIngrese nuevo nombre: ",aux_nombre)){
                retorno = -4;
            }
            fflush(stdin);

            if(retorno == 0){
                strcpy(listaUser[index].nombre,aux_nombre);
                system("cls");
                printf("\n\tNuevo nombre: %s\n",listaUser[index].nombre);
            }
        }

    }
    return retorno;
}

int baja_usuario(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){
    int retorno = -1, id_usuario, index_user, index_prod;
    char aux_id[21];
    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        lista_usuarios(listaUser,tamUser);

        printf("\n\tEl provedor debe tener registrado al menos un producto para ser eliminado.\n\n");
        if(!getStringNumeros("\n\tIngrese ID del provedor a eliminar: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_usuario = atoi(aux_id);

        retorno = -3;
        index_user = eProve_buscarPorId(listaUser,tamUser,id_usuario);

        if(index_user >= 0){

            retorno = -4;
            index_prod = eProduc_buscarPorIdUsuario(listaProd,tamProd,id_usuario);

            if(listaProd[index_prod].id_Producto == listaUser[index_user].id_Provedor){

                retorno = 0;

                listaUser[index_user].estado = LIBRE;
                listaProd[index_prod].estado = LIBRE;
            }
        }
    }
    return retorno;
}

int publicar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){

    int retorno = -1, id_usuario, index_user, index_prod, id_producto;
    char aux_id[21], aux_nom[31], aux_precio[21], aux_stock[21];

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_usuario = atoi(aux_id);

        retorno = -3;
        index_user = eProve_buscarPorId(listaUser,tamUser,id_usuario);
        if(index_user >= 0){

            printf("\n\tUsuario encontrado: %s\n",listaUser[index_user].nombre);
            retorno = -4;
            index_prod = eProduc_buscarLugarLibre(listaProd,tamProd);

            if(index_prod >= 0){

                retorno = 0;
                id_producto = eProduc_siguienteId(listaProd,tamProd);

                if(!getStringLetras("\n\tIngrese el nombre del producto: ",aux_nom)){
                    retorno = -5;
                }
                fflush(stdin);
                if(!getStringNumerosFloat("\n\tIngrese el precio del producto: ",aux_precio)){
                    retorno = -6;
                }
                if(!getStringNumeros("\n\tIngrese el stock del producto: ",aux_stock)){
                    retorno = -7;
                }

                if(retorno == 0){
                    listaProd[index_prod].id_Producto = id_producto;
                    listaProd[index_prod].id_usuario = id_usuario;
                    strcpy(listaProd[index_prod].nombre,aux_nom);
                    listaProd[index_prod].precio = atof(aux_precio);
                    listaProd[index_prod].stock = atoi(aux_stock);
                    listaProd[index_prod].cantidad_vendida = 0;
                    listaProd[index_prod].estado = OCUPADO;
                }
            }
        }
    }
    return retorno;
}

int modificar_publicacion(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){

    int retorno = -1, id_usuario, index_user, index_prod, id_producto;
    char aux_id[21], aux_precio[21], aux_stock[21];

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_usuario = atoi(aux_id);

        retorno = -3;
        index_user = eProve_buscarPorId(listaUser,tamUser,id_usuario);
        if(index_user >= 0){

            retorno = -4;
            index_prod = eProduc_buscarPorIdUsuario(listaProd,tamProd,id_usuario);

            if(index_prod >= 0){

                lista_UsuarioConSuProducto(listaUser,tamUser,listaProd,tamProd,id_usuario);

                printf("\n\tIngrese ID del producto a modificar: ");
                scanf("%d",&id_producto);

                retorno = -5;
                if(listaProd[index_prod].id_Producto == id_producto){

                    retorno = 0;

                    if(!getStringNumerosFloat("\n\tIngrese nuevo precio: ",aux_precio)){
                        retorno = -6;
                    }

                    if(!getStringNumeros("\n\tIngrese nuevo stock: ",aux_stock)){
                        retorno = -7;
                    }

                    if(retorno == 0){
                        listaProd[index_prod].precio = atof(aux_precio);
                        listaProd[index_prod].stock = atoi(aux_stock);

                        system("cls");
                        printf("\n\tPRODUCTO MODIFICADO!\n");
                    }
                }
            }

        }
    }
    return retorno;
}

int cancelar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){

    int retorno = -1, id_usuario, index_user, index_prod, id_producto;
    char aux_id[21];

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        if(!getStringNumeros("\n\tIngrese ID del usuario: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_usuario = atoi(aux_id);

        retorno = -3;
        index_user = eProve_buscarPorId(listaUser,tamUser,id_usuario);
        if(index_user >= 0){

            retorno = -4;
            index_prod = eProduc_buscarPorIdUsuario(listaProd,tamProd,id_usuario);

            if(index_prod >= 0){

                lista_UsuarioConSuProducto(listaUser,tamUser,listaProd,tamProd,id_usuario);

                printf("\n\tIngrese ID del producto a modificar: ");
                scanf("%d",&id_producto);

                retorno = -5;
                if(listaProd[index_prod].id_Producto == id_producto){

                    retorno = 0;
                    listaProd[index_prod].estado = LIBRE;

                    system("cls");
                    printf("\n\tPRODUCTO DADO DE BAJA!\n");
                }
            }
        }
    }
    return retorno;
}

int comprar_producto(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){

    int retorno = -1, id_producto, index_produc, index_user, calificacion;
    char aux_id[21], aux_cali[21];

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        listar_productos(listaProd,tamProd);
        if(!getStringNumeros("\n\tIngrese ID del producto: ",aux_id)){
            printf("\n\tError! La id debe estar compuesta solo por numeros.\n");
        }
        id_producto = atoi(aux_id);

        retorno = -3;
        index_produc = eProduc_buscarPorId(listaProd,tamProd,id_producto);
        if(index_produc >= 0){

            printf("\n\tProducto Encontrado: %s\n",listaProd[index_produc].nombre);

            retorno = -4;
            if(listaProd[index_produc].stock > 0){

                retorno = -5;
                index_user = eProduc_buscarPorIdUsuario(listaProd,tamProd,listaProd[index_produc].id_usuario);

                if(!getStringNumerosFloat("\n\tIngrese una calificacion: ",aux_cali)){
                    retorno = -6;
                }
                calificacion = atof(aux_cali);
                retorno = -7;

                if(calificacion >= 0 && calificacion <= 10){
                    retorno = 0;

                    if(retorno == 0){

                        promedio(listaUser,calificacion,tamUser,index_user);
                        listaProd[index_produc].cantidad_vendida ++;
                        listaProd[index_produc].stock --;
                    }
                }
            }
        }
    }
    return retorno;
}

int listar_publicaciones_de_usuario(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){

    int retorno = -1, i, j, id_user;

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        retorno = -2;
        printf("\n\tIngrese ID del usuario: ");
        scanf("%d",&id_user);

        for(i=0;i<tamUser;i++){
            if(listaUser[i].estado == OCUPADO){
                retorno = -3;
                if(listaUser[i].id_Provedor == id_user){
                    for(j=0;j<tamProd;j++){
                        retorno = -4;
                        if(listaUser[i].id_Provedor == listaProd[j].id_usuario){
                            if(listaProd[j].estado == OCUPADO){
                                retorno = 0;
                                if(retorno == 0){
                                    printf("\n\tID: %d\n\tProducto: %s\n\tPrecio: %.2f\n\tVentas: %d\n\tStock: %d\n",listaProd[j].id_Producto,listaProd[j].nombre,listaProd[j].precio,listaProd[j].cantidad_vendida,listaProd[j].stock);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

void listar_publicaciones(eProvedor listaUser[], int tamUser, eProducto listaProd[], int tamProd){
    int i, j;

    if(tamUser > 0 && tamProd > 0 && listaUser != NULL && listaProd != NULL){

        for(i=0;i<tamProd;i++){
            if(listaProd[i].estado == OCUPADO){
                for(j=0;j<tamUser;j++){
                    if(listaProd[i].id_usuario == listaUser[j].id_Provedor){
                        if(listaUser[j].estado == OCUPADO){
                            printf("\n\t-ID: %d\n\t-Producto: %s\n\t-Precio: %.2f\n\t-Ventas: %d\n\t-Stock: %d\n\t-Provedor: %s\n",listaProd[i].id_Producto,listaProd[i].nombre,listaProd[i].precio,listaProd[i].cantidad_vendida,listaProd[i].stock,listaUser[j].nombre);
                        }
                    }
                }
            }
        }
    }
}

void listar_usuarios(eProvedor listaUser[], int tamUser){
    int i;

    if(tamUser > 0 && listaUser != NULL){
        for(i=0;i<tamUser;i++){
            if(listaUser[i].estado == 0){
                listar_usuarios(listaUser,tamUser);
            }
        }
    }
}
