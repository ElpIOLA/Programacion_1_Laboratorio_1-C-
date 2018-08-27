#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracter.h"
#include "Set_Get.h"

int set_Nombre(eCaracter* caracter, char* nombre){
     int index = 0;
     if(caracter != NULL && nombre != NULL){
          strcpy(caracter->nombre,nombre);
          index = 1;
     }
     return index;
}

char* get_Nombre(eCaracter* caracter){
     char* index = NULL;
     if(caracter != NULL){
          index = caracter->nombre;
     }
     return index;
}

int set_Caracter(eCaracter* caracter, char caract){
     int index = 0;
     if(caracter != NULL){
          caracter->caracter = caract;
          index = 1;
     }
     return index;
}

char get_Caracter(eCaracter* caracter){
     char index = 0;
     if(caracter != NULL){
          index = caracter->caracter;
     }
     return index;
}

int set_Vocal(eCaracter* caracter, int vocal){
     int index = -1;
     if(caracter != NULL && (vocal >= 0 && vocal <= 1)){
          caracter->vocal = vocal;
          index = 1;
     }
     return index;
}

int get_Vocal(eCaracter* caracter){
     int index = -1;
     if(caracter != NULL){
          index = caracter->vocal;
     }
     return index;
}

int set_Consonante(eCaracter* caracter, int consonante){
     int index = -1;
     if(caracter != NULL && consonante >= 0 && consonante <= 1){
          caracter->consonante = consonante;
          index = 1;
     }
     return index;
}

int get_Consonante(eCaracter* caracter){
     int index = -1;
     if(caracter != NULL){
          index = caracter->consonante;
     }
     return index;
}

int set_Numero(eCaracter* caracter, int numero){
     int index = -1;
     if(caracter != NULL && numero >= 0 && numero <= 1){
          caracter->numero = numero;
          index = 1;
     }
     return index;
}

int get_Numero(eCaracter* caracter){
     int index = -1;
     if(caracter != NULL){
          index = caracter->numero;
     }
     return index;
}
