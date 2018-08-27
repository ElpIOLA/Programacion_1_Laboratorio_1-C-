
#include "usuario.h"
#include "producto.h"

int eProd_mostrarUno(eProductos listado);
int eProd_mostrarListado(eProductos listado[],int limite);

int publicar_producto(eProductos [], int limite, eUsuario [], int id);
int modificar_publicacion(eProductos [], int limite, eUsuario[], int id);
int cancelar_publicacion(eProductos listaProd[], int limite, eUsuario listaUser[], int id);
int comprar_producto(eProductos listaProd[], int limite, eUsuario listaUser[], int id);
