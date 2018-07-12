#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "lib.h"

#define P 5

int main()
{
    EMovie movies[P];
    char seguir='s';
    char guardar= 's';
    int i;

    for( i=0; i<P; i++)
		movies[i].legajo=0;

	if(cargarDesdeArchivo(movies))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

    system("cls");
    do
    {
        switch(menu())
        {
        case '1':
            system("cls");
            agregarPelicula(movies);
            break;
        case '2':
            system("cls");
            borrarPelicula(movies);
            break;
        case '3':
            system("cls");
            ModificarPelicula(movies);
            break;
        case '4':
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getche());

				if(guardar == 's')
				{
					if(guardarEnArchivo(movies))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
                }
				seguir='n';
				break;
        case '5':
            system("cls");
            listar(movies);
            break;
        }
    }while(seguir == 's');

    return 0;
}

