#include <stdio.h>
#include <stdlib.h>

float ingresarNumero();
float calcularAreaCirculo(float radio);

int main()
{
    float numero = ingresarNumero();
    printf("\n\tEl Area de un circulo de %.2f es de: %.2f\n\n",numero,calcularAreaCirculo(numero));
    return 0;
}

/** \brief Solicita un numero y lo retorna.
 * \return El numero ingresado por el usuario.
 */
float ingresarNumero()
{
    float numero;
    printf("\nIngrese numero: ");
    scanf("%f",&numero);
    return numero;
}

/** \brief Calcula el area de un circulo.
 * \param radio - Recibe el radio del circulo.
 * \return float - Retorna el area del circulo.
 */
float calcularAreaCirculo(float radio)
{
    float resultado;
    resultado = 3.14 * radio * radio;
    return resultado;
}
