#include "ArrayList.h"
typedef struct
{
    char name[41];
    char email[51];
    int estado;
}eDestino;

eDestino* new_distinatario();

int setName(eDestino* this, char* name);
char* getName(eDestino* this);

int setEmail(eDestino* this, char* email);
char* getEmail(eDestino* this);

int setEstado(eDestino* this, int estado);
int getEstado(eDestino* this);

int cargar_Destinatario(ArrayList* listado, char* direccion);

int comparar_Destinatarios(void* destinatarioA,void* destinatarioB);

int depurar_Destinatarios(ArrayList*, ArrayList*, ArrayList*,char*);
