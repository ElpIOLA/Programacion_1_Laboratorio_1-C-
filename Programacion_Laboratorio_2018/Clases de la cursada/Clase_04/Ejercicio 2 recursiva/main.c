#include <stdio.h>
#include <stdlib.h>

/**Una funcion recursiva es una funcion que se llama a si misma dentro de la implementacion
de una funcion 2 se vuelve a llamar a la funcion 2.
El factorial de un numero es igual a la multiplicacion de una sucecion de numeros comenzando desde
el numero elegido hasta el uno. Ejemplo: 5!=5*4*3*2*1=120 */

/** \brief Calcula el factorial de un numero.
 * \param int Un numero.
 * \return int El factorial del numero recibido como parametro.
 */
int factorial(int);

int main()
{
    int n = 0;
    int factor;

    factor = factorial(n);
    printf("Factorial: %d",factor);
    return 0;
}

int factorial(int n){
    int fact;
    if(n==0){
        fact = 1;
    }else{
        fact = n* factorial(n-1);
    }
    return fact; // Es recomendable tener solamente un return.
}

/*
int n,i,factor;

    for(i=n;i>=1;i--){
        factor = factor*i;
    }
*/

/**Trabajar con un flag para mostrar los datos en el operando a y b en el TP y el factorial tiene que usar
numeros enteros.*/
