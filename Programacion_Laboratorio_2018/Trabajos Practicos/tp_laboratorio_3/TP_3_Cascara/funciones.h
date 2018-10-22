
typedef struct{
    char titulo[30];
    char genero[20];
    int duracion;
    char descripcion[1500];
    int puntaje;
    char linkImagen[100];
    int id_pelicula;
    int estado;
}EMovie;

/**
 *  @brief Inicializa los estados en LIBRE y las ID en 0
 *  @param movie El puntero a la estructura de la pelicula a ser agregada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 */
void inicializarmovie(EMovie* movie, int tam);

/**
 *  @brief Hardcodea datos de la pelicula
 *  @param movie El puntero a la estructura de la pelicula a ser agregada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 */
void datos_hard_pelicula(EMovie* movie, int tam);

/**
 *  @brief Lista todas las peliculas que esten en OCUPADO
 *  @param movie El puntero a la estructura de la pelicula a ser agregada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 */
void listarPeliculas(EMovie* movie, int tam);

/**
 *  @brief Recorre la estructura de la pelicula y retorna el primer espacio LIBRE que tenga.
 *  @param movie El puntero a la estructura de la pelicula
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna la primer posicion que tenga espacio LIBRE.
 */
int buscarLugarLibre(EMovie* movie,int tam);

/**
 *  @brief Recorre la estructura de la pelicula, busca el primer espacio OCUPADO y le incrementa su ID en 1.
 *  @param movie El puntero a la estructura de la pelicula
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna la ID incrementada en 1
 */
int siguienteId(EMovie* movie,int tam);

/**
 *  @brief Recibe una ID y recorre la estructura pelicula. Si encuentra una ID igual a la recibida, retorna su posicion.
 *  @param movie El puntero a la estructura de la pelicula
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna la posicion donde se encuentra la ID.
 */
int buscarPorId(EMovie* movie ,int tam, int id_peli);

/**
 *  @brief Recorre la estructura pelicula y agrega al archivo todas las peliculas que tengan el estado OCUPADO.
 *  @param movie El puntero a la estructura de la pelicula a ser agregada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna 1 si la pelicula es agregada correctamente. Sino retorna -1 en caso de error.
 */
int GuardarEnArchivoBinario(EMovie* movie, int tam);

/**
 *  @brief Agrega una pelicula al archivo binario
 *  @param movie El puntero a la estructura de la pelicula a ser agregada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna 1 si la pelicula es agregada. Sino retorna un valor negativo segun el error que haya ocurrido.
 */
int agregarPelicula(EMovie* movie, int tam);

/**
 *  @brief Borra una pelicula del archivo binario
 *  @param movie El puntero a la estructura de la pelicula a ser borrada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna 1 si la pelicula es borrada. Sino retorna un valor negativo segun el error que haya ocurrido.
 */
int borrarPelicula(EMovie* movie, int tam);

/**
 *  @brief Modifica una pelicula del archivo binario
 *  @param movie El puntero a la estructura de la pelicula a ser modificada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
 *  @return retorna 1 si la pelicula es modificada. Sino retorna un valor negativo segun el error que haya ocurrido.
 */
int modificarPelicula(EMovie* movie, int tam);

/**
 *  @brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie El puntero a la estructura de la pelicula a ser modificada al archivo
 *  @param tam El cantidad de elementos que contiene la estructura
  *  @return retorna 1 si la pagina web es generada. Sino retorna un valor negativo segun el error que haya ocurrido.
 */
int generarPagina(EMovie* movie, int tam);

