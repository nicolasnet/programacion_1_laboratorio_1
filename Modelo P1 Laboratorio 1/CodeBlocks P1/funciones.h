#define CANTCARACTERES 40


typedef struct {
    int codigo;
    char descripcionProd[CANTCARACTERES];
    float importe;
    int cantidad;
    int estado;

}eProducto;

typedef struct {
    int codigo;
    char descripcionProv[CANTCARACTERES];
}eProveedor;

typedef struct {
    int CodProducto;
    int CodProveedor;
    int estado;
}MixProductoProveedor;



/** \brief Validacion de numeros enteros entre dos limites.
 *
 * \param Char dato: cadena de char.
 * \param int limiteInferior: numero entero dado como valor minimo aceptado.
 * \param int limiteSuperior: numero entero dado como valor maximo aceptado.
 * \return El numero ingresado en formato INT validado
 *
 */
int validaOpcionesInt(char dato[], int limiteInferior, int limiteSuperior);



/** \brief Validaicon de numeros decimales.
 *
 * \param dato[] char: dato ingresado sujeto a validacion
 * \return float: El numero decimal validado y convertido a float
 *
 */
float validaFloat(char dato[]);



/** \brief Validacion para cadena de letras.
 *
 * \param [] char auxDato: cadena de char sujeta a validacion.
 * \param cantCaracteres int: Cantidad maxima de caracteres permitidos.
 * \return void La funcion modifica esa cadena dada, validando que no posea valores numericos y que el tamaño se ajuste al valor dado.
 *
 */
void validaCadenaDeLetras(char auxDato [], int cantCaracteres);



/** \brief Despliega un menu de opciones
 *
 * \param opciones[] char: Cadena de caracteres que brinda a la funcion las opciones imprimibles.
 * \param limiteInferior int: limite minimo aceptado como opcion.
 * \param limiteSuperior int: limite maximo aceptado como opcion.
 * \return int: El numero entero elegido como opcion.
 *
 */
int menu(char opciones[], int limiteInferior, int limiteSuperior);



/** \brief Inicializacion en cero de los estados de los productos
 *
 * \param producto[] eProducto: cadena de estructura a modificar.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Cambia a cero todas las variables estado de la estructura dada.
 *
 */
void iniciaProducto(eProducto producto[], int CANTPROD);



/** \brief Inicializacion en cero de los estados y codigos de la estructura con la codificacion
 *
 * \param codificacion[] MixProductoProveedor: Cadena de estructura a modificar.
 * \return void: Cambia a cero las variables estado y CodProveedor de la estructura dada.
 *
 */
void iniciaMix(MixProductoProveedor codificacion[]);



/** \brief Impresion de datos cargados en estructura
 *
 * \param producto[] eProducto: Cadena de estructura dada factible de ser impresa en pantalla.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Muestra aquellos productos cargados (estado==1).
 *
 */
void imprimeProductos(eProducto producto[], int CANTPROD);



/** \brief Inicializacion de datos para la estructura eProducto.
 *
 * \param producto[] eProducto: cadena de estructura sujeta a modificacion.
 * \param proveedor[] eProveedor: cadena de estructura usada como base de datos.
 * \param codificacion[] MixProductoProveedor: Cadena de estructura con union de codificacion entre productos y proveedores.limite minimo aceptado como opcion.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Estructuras eProducto y MixProductoProveedor cargadas con datos por el usuario.
 *
 */
void alta(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);


/** \brief Modificacion de datos para la estructura eProducto previamente cargados.
 *
 * \param producto[] eProducto: cadena de estructura sujeta a modificacion.
 * \param proveedor[] eProveedor: cadena de estructura usada como base de datos.
 * \param codificacion[] MixProductoProveedor: Cadena de estructura con union de codificacion entre productos y proveedores.limite minimo aceptado como opcion.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Estructuras eProducto y MixProductoProveedor modificada con nuevos datos por el usuario.
 *
 */
void modificar(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);


/** \brief Borrados de datos para la estructura eProducto previamente cargados.
 *
 * \param producto[] eProducto: cadena de estructura sujeta a modificacion.
 * \param proveedor[] eProveedor: cadena de estructura usada como base de datos.
 * \param codificacion[] MixProductoProveedor: Cadena de estructura con union de codificacion entre productos y proveedores.limite minimo aceptado como opcion.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Estructuras eProducto y MixProductoProveedor cambiado de variables estado a cero.
 *
 */
void borrarProducto(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);



/** \brief Muestra minimos y maximos segun cantidades.
 *
 * \param producto[] eProducto: cadena de estructura usada como base de datos.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Imprime en pantalla los productos que poseen las cantidades minimas y maximas cargadas.
 *
 */
void informaMinMax(eProducto producto[], int CANTPROD);



/** \brief Muestra listado ordenado por proveedores
 *
 * \param producto[] eProducto: cadena de estructura usada como base de datos.
 * \param proveedor[] eProveedor: cadena de estructura usada como base de datos.
 * \param codificacion[] MixProductoProveedor: cadena de estructura usada como base de datos.
 * \param CANTPROD int: Cantidad maxima de productos.
 * \return void: Imprime en pantalla aquellos proveedores y los productos que provee respectivamente.
 *
 */
void listaOrdenado(eProducto producto[], eProveedor proveedor[], MixProductoProveedor codificacion[], int CANTPROD);
