#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tasa = 100;
    int p_tasa;

    p_tasa = tasa;
    printf("Posicion de memoria: %p", &p_tasa);
    return 0;
}
