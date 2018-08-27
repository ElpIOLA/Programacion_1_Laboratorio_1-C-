#include "ArrayList.h"
typedef struct
{
    int id;
    char letra;
    char nombre[20];
    int vocal;
    int consonante;
}eLetra;

eLetra* nuevaLetra();

int setId(eLetra*, int);

int getId(eLetra*);

int setVocal(eLetra*, int);

int getVocal(eLetra*);

int setConsonante(eLetra*, int);

int getConsonante(eLetra*);

int setNombre(eLetra*, char*);

char* getNombre(eLetra*);

int setLetra(eLetra*, char);

char getLetra(eLetra*);

void imprimir(eLetra*);

void imprimirTodos(ArrayList*);

void completarVocal(eLetra*);

void completarConsonante(eLetra*);

void completarLetra(ArrayList*);

void filtrarRepetidos(ArrayList*, ArrayList*, char*);

void filtrarDepurados(ArrayList*, ArrayList*, char*);

int comparar(void* ,void*);
