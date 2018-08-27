#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p_nro, *p_nro2;
    int auxA, auxB;

    p_nro = &auxA;
    p_nro2 = &auxB;

    if(p_nro < p_nro2)
    {
        printf("El puntero A es menor, posicion: %p", p_nro);
    }
    else if(p_nro > p_nro2)
    {
        printf("El puntero B es menor, posicion: %p", p_nro2);
    }
    return 0;
}
