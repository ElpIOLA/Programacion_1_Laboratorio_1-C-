#include <stdio.h>
#include <stdlib.h>

/**FUNCION QUE DA LA CANTIDAD DE PARES DE UN VECTOR*/
int contarPares(int[], int); //PARAMETROS FORMALES

/**FUNCION QUE BUSCA UN CARACTER DENTRO DE UN VECTOR*/
int buscarChar(char[], int, char);

int main()
{
    int vec[5] = {5,4,2,6,1};
    char letras[5] = {'f','j','q','h','a'};
    int indexLetra;
    int cantidad;

    cantidad = contarPares(vec,5);
    printf("\nCantidad: %d",cantidad);

    indexLetra = buscarChar(letras, 5, 'a');
    if(indexLetra == -1){
        printf("No se encuentra caracter.");
    }else{
        printf("\nIndex = %d",indexLetra);

    }

    return 0;
}

int contarPares(int array[], int cant){
    int contPares = 0;
    int i;

    for(i=0;i<cant;i++){
        if(array[i]%2==0){
            contPares++;
        }
    }
    return contPares;
}

int buscarChar(char array[], int cant, char caracter){
    int index = -1;
    int i;
    for(i=0;i<cant;i++){
        if(array[i] == caracter){
            index = i;
            break;
        }
    }
    return index;
}
