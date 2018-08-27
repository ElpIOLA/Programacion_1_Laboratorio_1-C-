#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>

#include "lib.h"
#define P 5

char menu()
{
    char c;
    system("cls");
    printf("MENU\n1. AGREGAR PELICULA\n2. ELIMINAR PELICULA\n3. MODIFICAR PELICULA\n4. GENERAR PAGINA WEB\n5. LISTAR\n");
    printf("Elija una opcion: ");
    c=getche();
    return c;
}

int buscarLibre(EMovie *movies)
{
    int index=-1;
    int i;
    for( i=0; i < P; i++)
        if(movies[i].legajo==0)
        {
            index=i;
            break;
        }
    return index;
}

int agregarPelicula(EMovie *movies)
{
    int index, i, legajo;
    char titulo[20];
    char genero[20];
    char descripcion[51];
    char auxDuracion[20];
    char auxPuntaje[20];
    char auxLegajo[20];

    int encontro=0;

    /*Buscamos cual es el primer indice libre dentro del array*/
    index=buscarLibre(movies);
    if(index!=-1)//si hay lugar:
    {

        printf("INGRESO DE DATOS:\n");
		printf("Ingrese legajo: ");
		scanf("%d", &legajo);
        /*Buscamos si el legajo ya existe*/
        for(i=0; i<P; i++)
        {
            if(legajo==movies[i].legajo)
            {
                encontro=1;//encontro en true
                break;
            }
        }
        if(!encontro)//entra si encontro==0
        {
            system("cls");
            printf("\nLEGAJO DISPONIBLE!\n");
            if(!getStringLetras("Ingrese Titulo: ", titulo))
            {
                printf("\nEl titulo debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(movies[index].titulo,titulo);

            if(!getStringLetras("Ingrese Genero: ", genero))
            {
                printf("\nEl genero debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(movies[index].genero,genero);

            if(!getStringNumeros("Ingrese Duracion: ", auxDuracion))
            {
                printf("\nLa duracion debe contener solo numeros.\n");
            }
            movies[index].duracion = atoi(auxDuracion);

            if(!getStringLetras("Ingrese Descripcion: ", descripcion))
            {
                printf("\nLa descripcion debe contener solo letras.\n");
            }
            fflush(stdin);
            strcpy(movies[index].descripcion,descripcion);

            if(!getStringNumerosFlotantes("Ingrese Puntaje: ", auxPuntaje))
            {
                printf("\nEl puntaje debe contener solo numeros.\n");
            }
            movies[index].puntaje = atof(auxPuntaje);

            if(!getStringNumeros("Ingrese Legajo: ", auxLegajo))
            {
                printf("\nEl legajo debe contener solo numeros.\n");
            }
            movies[index].legajo = atoi(auxLegajo);

            system("cls");
        }
        else
        {
            printf("\n­­La pelicula ya existe!!\n");
            getch();
        }
    }
    else
    {
        printf("\nNo queda espacio\n");
        getch();
    }
    return 0;
}

int borrarPelicula(EMovie *movies)
{
	int legajo, flag=0,i;
	char opcion;
	printf("Ingrese legajo de la pelicula a eliminar: ");
	scanf("%d", &legajo);

	for(i=0; i<P; i++)
	{
		if(legajo==movies[i].legajo)
		{
			printf("Pelicula a eliminar:\n");

			toString(movies + i);

			printf("\nPelicula encontrada. ¨Seguro desea dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				movies[i].legajo=0;
				printf("Pelicula eliminada!!");
			}
			else
			{
				printf("La pelicula no fue eliminado!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
	return 0;
}

int ModificarPelicula(EMovie *movies)
{
	int legajo, flag=0,i;
	char opcion;
	char titulo[21];
    char genero[21];
    char descripcion[51];
    char auxDuracion[21];
    char auxPuntaje[21];
	system("cls");
	printf("Ingrese legajo de la pelicula a modificar: ");
	scanf("%d",& legajo);
	for( i=0; i<P; i++)
	{
		if(legajo==movies[i].legajo)
		{
			printf("Pelicula encontrada:\n");

			toString((movies + i));

			if(!getStringLetras("Ingrese nuevo Titulo: ",titulo))
            {
                printf("El titulo debe contener solo letras.\n");
                break;
            }

            if(!getStringLetras("Ingrese nuevo Genero: ",genero))
            {
                printf("El genero debe contener solo letras.\n");
                break;
            }

            if(!getStringLetras("Ingrese nueva Descripcion: ",descripcion))
            {
                printf("La descripcion debe contener solo letras.\n");
                break;
            }

            if(!getStringNumeros("Ingrese la nueva duracion: ",auxDuracion))
            {
                printf("La duracion debe contener solo numeros.\n");
            }

            if(!getStringNumerosFlotantes("Ingrese el nuevo Puntaje: ",auxPuntaje))
            {
                printf("El puntaje debe contener solo numeros.\n");
            }

			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{
                strcpy(movies[i].titulo,titulo);
                strcpy(movies[i].genero,genero);
                strcpy(movies[i].descripcion,descripcion);
                movies[i].duracion = atoi(auxDuracion);
                movies[i].puntaje = atof(auxPuntaje);
				printf("Pelicula modificada");
			}
			else
			{
				printf("El registro no fue modificado");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
	return 0;
}

void toString(EMovie *movies)
{
	printf("%d\t%s\t%s\t%.2f\t%s\t%d\n", movies->legajo, movies->titulo, movies->genero, movies->puntaje, movies->descripcion, movies->duracion);
}

void listar(EMovie *movies)
{
	int i,j;
	EMovie auxMovie;

	for(i=0; i<P-1;i++)
	{
		for(j=i+1; j<P; j++)
		{
			if(strcmp(movies[i].titulo,movies[j].titulo)>0)
			{
				auxMovie=movies[i];
				movies[i]=movies[j];
				movies[j]=auxMovie;
			}
		}
	}

	printf("Legajo\tTitulo\tGenero\tPuntaje\tDescripcion\tDuracion\n");
	for(i=0; i<P; i++)
	{
		if(movies[i].legajo!=0)
		   toString((movies + i));

	}
	getch();
}

int guardarEnArchivo(EMovie *x)
{

	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(x,sizeof(EMovie),P,f);

	fclose(f);

	return 0;
}

int cargarDesdeArchivo(EMovie *x)
{
    int flag = 0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }

        flag=1;

    }

    if(flag ==0)
    {
        fread(x, sizeof(EMovie), P, f);
    }

    fclose(f);
    return 0;

}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;

        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
