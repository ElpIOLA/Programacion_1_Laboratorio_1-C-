#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"


int main()
{
    eDato dato;
    eDato* d;

    d=&dato;

    eDato_set_a(d,1800);

    eDato_set_b(d,"hola");

    printf("%d--%s", eDato_get_a(d),eDato_get_b(d));

    return 0;
}

