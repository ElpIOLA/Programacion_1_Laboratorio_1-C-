
typedef struct{
    char nombre[50];
    float precio;
    int cantidad_ventas = 0;
    int idProducto;
    int stock;
    int estado;
}eProductos;


int eProd_init(eProductos listado[],int limite);
int eProd_buscarPorId(eProductos listado[] ,int limite, int id);
int eProd_siguienteId(eProductos listado[] ,int limite);
int eProd_buscarLugarLibre(eProductos listado[],int limite);
