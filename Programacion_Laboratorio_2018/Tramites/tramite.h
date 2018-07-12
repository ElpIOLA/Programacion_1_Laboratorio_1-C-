#include "ArrayList.h"

typedef struct
{
    int idTramite;
    char dni[10];
}eTramite;

eTramite* new_tramite();

int setId(eTramite*,int);
int getId(eTramite*);

int setDni(eTramite*,char*);
char* getDni(eTramite*);

int mostrarTramite(eTramite*);

int ordenamientoPorDni(void*, void*);

int mostrarListaTramite(ArrayList* );

int cargarTramite(ArrayList*,int, char*);

int atenderTramite(ArrayList*,ArrayList*);
