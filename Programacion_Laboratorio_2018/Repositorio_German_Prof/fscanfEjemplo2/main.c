#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    int categoria;
    char descripcion[20];
    float precio;
} eProducto;

int main()
{
    char codigo[500], descripcion[500], categoria[500],precio[500];
    eProducto producto;
    eProducto lista[51];
    int cont=0;
    int flag=0;
    FILE * pFile;

    pFile = fopen ("productos.csv", "r");
fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", codigo, descripcion, categoria, precio);

    while(!feof(pFile))
    {
        if(feof(pFile))
            break;


        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", codigo, descripcion, categoria, precio, estado);

        if(strcmp(estado,"true")==0)
        {
            producto.codigo = atoi(codigo);
        producto.categoria = atoi(categoria);
        strcpy(producto.descripcion, descripcion);
        producto.precio = atof(precio);

        //  printf("TEXTO : %s - %s - %s - %s\n", codigo, descripcion, categoria, precio);
        lista[cont] = producto;
        //printf("STRUCT: %d - %s - %d - %.2f\n", producto.codigo, producto.descripcion, producto.categoria, producto.precio);
        cont++;
        }

    }
    int i;
    fclose(pFile);
    for(i=0; i<51; i++)
    {
        printf("%d - %s - %d - %.2f\n", lista[i].codigo, lista[i].descripcion, lista[i].categoria, lista[i].precio);
    }


    return(0);
}
