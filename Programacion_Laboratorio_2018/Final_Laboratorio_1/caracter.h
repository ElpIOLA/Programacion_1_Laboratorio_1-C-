#include "ArrayList.h"

typedef struct{
    char caracter;
    char nombre[21];
    int vocal;
    int consonante;
    int numero;
}eCaracter;

eCaracter* new_caracter();

int buscarArchivo(char* direccion);

int cargar_Archivo(ArrayList* this, char* link);

int cargar_Datos(ArrayList* this, char caracter ,char* nombre, int vocal, int consonante, int numero);

int mostrar_Datos(eCaracter* this);

int listaDeDatos(ArrayList* this);

ArrayList* listaOrdenadaAscendente(ArrayList* this, ArrayList* this2);

int repetido(ArrayList* this, char letra);

ArrayList* listaDeNombresConUnCaracter(ArrayList* ListaVieja, ArrayList* ListaNueva);

int comprobarSiEsRepetida(ArrayList* ListaNueva, eCaracter* letra);

int filtroUnCaracter(void* item);

int filtroUnos_Ceros(void* item);

int comparar(void* primero,void* segundo);

int guardar_en_archivo(ArrayList* this, char* direccion);
