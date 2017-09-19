typedef struct {

    char nombre[50];
    int edad;
    int estado; //flag
    long int dni;  //long o array

}EPersona;

int menu(char opciones[], int limiteInferior, int limiteSuperior);

void alta(EPersona persona[]);

void inicia(EPersona persona[]);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
//int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(EPersona lista[], int dni);


