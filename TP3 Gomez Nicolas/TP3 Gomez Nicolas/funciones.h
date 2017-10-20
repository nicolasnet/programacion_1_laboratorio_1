#define CANTCARACTERES 25


typedef struct{
    int codigo;
    char titulo[CANTCARACTERES];
    char genero[CANTCARACTERES];
    int duracion;
    char descripcion[CANTCARACTERES*3];
    float puntaje;
    char linkImagen[CANTCARACTERES*10];
}EMovie;



/** \brief Validacion de numeros enteros entre dos limites.
 *
 * \param Char dato: cadena de char.
 * \param int limiteInferior: numero entero dado como valor minimo aceptado.
 * \param int limiteSuperior: numero entero dado como valor maximo aceptado.
 * \return El numero ingresado en formato INT validado
 *
 */
int validaOpcionesInt(char *auxdato, int limiteInferior, int limiteSuperior);



/** \brief Validaicon de numeros decimales.
 *
 * \param dato char*: dato ingresado sujeto a validacion.
 * \return float: El numero decimal validado y convertido a float.
 *
 */
float validaFloat(char *auxdato);



/** \brief Validacion de numeros decimales, entre 2 limites.
 *
 * \param dato char*: dato ingresado sujeto a validacion
 * \param limiteInferior float: numero real dado como valor minimo aceptado.
 * \param limiteSuperior float: numero real dado como valor maximo aceptado.
 * \return float: El numero decimal validado y convertido a float.
 *
 */
float validaPuntaje(char *dato, float limiteInferior, float limiteSuperior);



/** \brief Validacion para cadena de letras.
 *
 * \param auxDato char*: cadena de char sujeta a validacion.
 * \param cantCaracteres int: Cantidad maxima de caracteres permitidos.
 * \return void La funcion modifica la cadena dada, validando que no posea valores numericos y que el tamaño se ajuste al valor dado.
 *
 */
void validaCadenaDeLetras(char *auxDato, int cantCaracteres);



/** \brief Validacion para cadena alfanumerica.
 *
 * \param auxDato char*: cadena de char sujeta a validacion.
 * \param cantCaracteres int: Cantidad maxima de caracteres permitidos.
 * \return void La funcion modifica la cadena dada, validando que el tamaño se ajuste al valor dado.
 *
 */
void validaAlfaNumerico(char *auxDato, int cantCaracteres);



/** \brief Despliega un menu de opciones
 *
 * \param opciones[] char: Cadena de caracteres que brinda a la funcion las opciones imprimibles.
 * \param limiteInferior int: limite minimo aceptado como opcion.
 * \param limiteSuperior int: limite maximo aceptado como opcion.
 * \return int: El numero entero elegido como opcion.
 *
 */
int menu(char *opciones, int limiteInferior, int limiteSuperior);








/** \brief muestra en pantalla las peliculas cargadas en un archivo binario
 *
 * \param pelicula EMovie: estructura que se lee del archivo.
 * \param bin FILE*: puntero del archivo en cuestion.
 * \return void
 *
 */
void imprimePeliculas(EMovie pelicula, FILE *bin);

/**
 *  Agrega una pelicula al archivo binario
 *  @param pelicula la estructura a ser agregada al archivo
 *  @return void
 */
void agregarPelicula(EMovie pelicula, int cantCaracteres, FILE *bin);

/**
 *  Borra una pelicula del archivo binario
 *  @param pelicula la estructura a ser eliminada al archivo
 *  @return cambia a 0 (cero) el codigo de la pelicula elegida.
 */
void borrarPelicula(EMovie pelicula, FILE *bin);



/** \brief Modificar datos de una pelicula ya dada de alta en archivo binario.
 *
 * \param pelicula EMovie: estructura a modificar.
 * \param cantCaracteres int: dato entero con cantidad de caracteres para algunas variables.
 * \param bin FILE*: puntero del archivo binario donde se almacena la informacion.
 * \return void
 *
 */
void modificaPelicula(EMovie pelicula, int cantCaracteres, FILE *bin);



/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 * \param pelicula EMovie: estructura que se lee del archivo.
 * \param nombreDeArchivo char*: Una cadena de caracteres utilizada para dar nombre al archivo html que se crea.
 * \param bin FILE*: Puntero del archivo binario.
 * \return void
 *
 */
void generarPagina(EMovie pelicula, char *nombreDeArchivo, FILE *bin);
