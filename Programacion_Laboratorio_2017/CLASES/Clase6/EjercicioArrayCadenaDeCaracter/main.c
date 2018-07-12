#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i, numero, varon = 0, mujer = 0;
    char alumnos[30];

    printf("Digite el total de alumnos de la clase: ");
    scanf("%d", &numero);

    for(i=1;i<=numero;i++)
    {
        fflush(stdin);
        printf("\n %d. Digite el sexo del alumn@: ", i);
        gets(alumnos);

        if(strcmp(alumnos,"masculino") == 0)
        {
            varon ++;
        }
        else if(strcmp(alumnos,"femenino") == 0)
        {
            mujer++;
        }
    }

    printf("\n El total de varones es: %d", varon);
    printf("\n El total de mujeres es: %d", mujer);
    return 0;
}
