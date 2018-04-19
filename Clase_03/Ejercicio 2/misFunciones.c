
/**
 *\brief Divide dos enteros y da un resultado.
 *\param Parametro n1 recibe un entero.
 *\param Parametro n2 recibe un entero.
 *\return Retorna el resultado de la division de los dos enteros.
 */
float dividirEnteros(int n1,int n2){
    float resultado = 0;
    resultado = (float)n1 / n2; //CASTEAMOS UN VALOR PARA QUE EL RESULTADO DE FLOAT.
    return resultado;
}

/**
 *\brief Suma dos enteros y da un resultado.
 *\param Parametro n1 recibe un entero.
 *\param Parametro n2 recibe un entero.
 *\return Retorna el resultado de la suma de los dos enteros.
 */
int suma(int n1, int n2){
    int resultado = 0;
    resultado = n1 + n2;
    return resultado;
}

/**
 *\brief Pide un numero entero
 *\return Retorna 0 si el valor es par y -1 si el valor es impar.
 */
int pedirNumeroPar(){
    int n = -1;
    printf("Ingrese un numero: ");
    scanf("%d",&n);
    if(n%2==0){
        n = 0;
        return n;
    }
    return n;
}

/**
 *\brief Pide un dato entero y analiza si el dato esta entre los limites indicados y devuelve la edad.
 *\param mensaje Muestra un string,
 *\param errorMensaje Muestra un error en string.
 *\param maximo El valor maximo en entero.
 *\param minimo El valor minimo en entero.
 *\return Retorna La edad que el usuario ingreso.
 */
int pedirNumero(char* mensaje, char* errorMensaje, int maximo, int minimo){
    int n = -1;
    do{
        printf(mensaje);
        scanf("%d",&n);
        if(n<maximo && n>minimo){
            break;
        }
        printf(errorMensaje);
    }while(1==1);

    return n;
}
