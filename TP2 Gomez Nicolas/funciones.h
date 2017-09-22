typedef struct {

    char nombre[50];
    int edad;
    int estado; //flag
    long int dni;  //long o array

}EPersona;


/** \brief Imprime menu con opciones para elegir.
 *
 * \param Cadena Char con texto a imprimir.
 * \return Retorna un entero con la opcion elegida.
 *
 */
int menu(char opciones[]);


/** \brief Obtiene Nombre, Edad y DNI y almacena en el array de la estructura EPersona, validando su contenido.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \return Almacenamiento de datos en el array dado.
 *
 */
void alta(EPersona persona[]);


/** \brief Inicia los estados de todos los indices del array en cero.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \return Inicializacion en cero de la variable persona.estado en todos sus indices.
 *
 */
void inicia(EPersona persona[]);


/** \brief Eliminar de la base de datos del programa una persona ya cargada, ingresando DNI.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \param CANT: Tamaño del array.
 * \return Cambio de la variable persona.estado elegida por CERO.
 *
 */
void borrar(EPersona persona[], int CANT);


/** \brief Ordenar por nombre el array de estructura.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \param CANT: Tamaño del array.
 * \return Modifica el lugar donde se encuentra cada dato, manteniendo los datos relacionados.
 *
 */
void ordenar(EPersona persona[], int CANT);


/** \brief Lista (imprime) el array de estructura.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \param CANT: Tamaño del array.
 * \return Muestra en pantalla todas las variables cargadas en la estructura.
 *
 */
void listar(EPersona persona[], int CANT);


/** \brief Lista (imprime) un grafico mostrando cantidades de personas por rango de edades. <18, 19-35, >35.
 *
 * \param EPersona persona[]: Array de estructura EPersona.
 * \param CANT: Tamaño del array.
 * \return Muestra en pantalla un grafico con asteriscos por cada unidad que poseen los rangos establecidos.
 *
 */
void graficar(EPersona persona[],int CANT);
