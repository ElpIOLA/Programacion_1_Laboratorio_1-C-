#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#include "Set_Get.h"

int set_Nombre(ePersona* persona, char* nombre){
     int index = 0;
     if(persona != NULL && nombre != NULL){
          strcpy(persona->nombre,nombre);
          index = 1;
     }
     return index;
}

char* get_Nombre(ePersona* persona){
     char* index = NULL;
     if(persona != NULL){
          index = persona->nombre;
     }
     return index;
}

int set_Apellido(ePersona* persona, char* apellido){
     int index = 0;
     if(persona != NULL && apellido != NULL){
          strcpy(persona->apellido,apellido);
          index = 1;
     }
     return index;
}

char* get_Apellido(ePersona* persona){
     char* index = NULL;
     if(persona != NULL){
          index = persona->apellido;
     }
     return index;
}

int set_Direccion(ePersona* persona, char* direccion){
     int index = 0;
     if(persona != NULL && direccion != NULL){
          strcpy(persona->direccion,direccion);
          index = 1;
     }
     return index;
}

char* get_Direccion(ePersona* persona){
     char* index = NULL;
     if(persona != NULL){
          index = persona->direccion;
     }
     return index;
}

int set_Edad(ePersona* persona, int edad){
     int index = 0;
     if(persona != NULL && edad > 0 && edad < 110){
          persona->edad = edad;
          index = 1;
     }
     return index;
}

int get_Edad(ePersona* persona){
     int index = 0;
     if(persona != NULL){
          index = persona->edad;
     }
     return index;
}

int set_Legajo(ePersona* persona, int legajo){
     int index = 0;
     if(persona != NULL && legajo > 0){
          persona->legajo = legajo;
          index = 1;
     }
     return index;
}

int get_Legajo(ePersona* persona){
     int index = 0;
     if(persona != NULL){
          index = persona->legajo;
     }
     return index;
}

int set_Sueldo(ePersona* persona, float sueldo){
     int index = 0;
     if(persona != NULL && sueldo > 0){
          persona->sueldo = sueldo;
          index = 1;
     }
     return index;
}

float get_Sueldo(ePersona* persona){
     float index = 0;
     if(persona != NULL){
          index = persona->sueldo;
     }
     return index;
}
