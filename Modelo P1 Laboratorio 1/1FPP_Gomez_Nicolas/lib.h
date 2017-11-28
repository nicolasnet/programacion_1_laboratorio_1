#define CANTCARACTERES 30


typedef struct {
    int ID;
    long int DNI;
    char nombre[CANTCARACTERES];
    char apellido[CANTCARACTERES];
    int estado;
}eCliente;

typedef struct {
    int codigo;
    int equipo;
    int estado;
    int operadorID;
    int tiempoEstimado;
    int tiempoReal;
}eAlquiler;

typedef struct {
    int IDcliente;
    int CodAlquiler;
    int estado;
}eMixClienteAlquiler;








/** \brief Validacion de numeros enteros entre dos limites.
 *
 * \param Char dato: cadena de char.
 * \param int limiteInferior: numero entero dado como valor minimo aceptado.
 * \param int limiteSuperior: numero entero dado como valor maximo aceptado.
 * \return El numero ingresado en formato INT validado
 *
 */
int validaOpcionesInt(char dato[], int limiteInferior, int limiteSuperior);



/** \brief Validacion de numeros enteros largos entre dos limites.
 *
 * \param Char dato: cadena de char.
 * \param int limiteInferior: numero entero dado como valor minimo aceptado.
 * \param int limiteSuperior: numero entero dado como valor maximo aceptado.
 * \return El numero ingresado en formato LONG INT validado
 *
 */
int validaLongInt(char dato[], int limiteInferior, long int limiteSuperior);



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


/** \brief Inicia en cero los estados de los clientes.
 *
 * \param cliente[] eCliente: cadena de estructura a modificar en variable estado.
 * \param CANTCLIENTES int: Cantidad maxima de clientes.
 * \return void
 *
 */
void iniciaClientes(eCliente cliente[], int CANTCLIENTES);



/** \brief Inicia en cero los estados de los alquileres.
 *
 * \param alquilere[] eAlquiler: cadena de estructura a modificar en variable estado.
 * \param CANTALQUILERES int: Cantidad maxima de alquileres.
 * \return void
 *
 */
void iniciaAlquileres(eAlquiler alquilere[], int CANTALQUILERES);


/** \brief inicia en cero los estados, codigos de alquileres y ID de clientes de la estructura
 *
 * \param codificacion[] eMixClienteAlquiler: cadena de estructura a modificar en variable estado, IDcliente y CodAlquiler.
 * \param cantidadmix int: cantidad maxima de codificaiones
 * \return void
 *
 */
void iniciaCodificacion(eMixClienteAlquiler codificacion[], int cantidadmix);


/** \brief Lista los clientes y sus datos cargados.
 *
 * \param cliente[] eCliente: cadena de estructura dada para analizar y listar.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \return void
 *
 */
void imprimeCliente(eCliente cliente[], int CANTCLIENTES);



/** \brief Lista los alquileres en estado alquilado
 *
 * \param alquiler[] eAlquiler: cadena de estructura dada para analizar y listar.
 * \param cliente[] eCliente: cadena de estructura dada para analizar y listar.
 * \param codificacion[] eMixClienteAlquiler: cadena de estructura dada para analizar y listar.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \param CANTALQUILERES int: cantidad maxima de alquileres.
 * \return void
 *
 */
void imprimeAlquilados(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES);



/** \brief Inicializacion de las variables de la estructura eCliente, carga de datos.
 *
 * \param cliente[] eCliente: cadena de estructura dada para analizar e inicializar.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \return void
 *
 */
void alta(eCliente cliente[], int CANTCLIENTES);



/** \brief Modifica datos de clientes previamente cargados.
 *
 * \param cliente[] eCliente: cadena de estructura dada para analizar y modificar.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \return void
 *
 */
void modificar(eCliente cliente[], int CANTCLIENTES);



/** \brief Eleccion de y cliente y baja del mismo (anteriormente cargado), cambio de variable estado a cero
 *
 * \param [] eCliente cliente: cadena de estructura dada para analizar y modificar.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \return void
 *
 */
void baja(eCliente cliente [], int CANTCLIENTES);



/** \brief Alta de un nuevo alquiler.
 *
 * \param cliente[] eCliente: cadena de estructura dada para analizar y usar sus datos.
 * \param alquiler[] eAlquiler: cadena de estructura dada para analizar y modificar.
 * \param codificacion[] eMixClienteAlquiler: cadena de estructura dada para analizar y modificar.
 * \param CANTALQUILERES int: cantidad maxima de alquileres.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \return void
 *
 */
void nuevaLLamada(eCliente cliente[], eAlquiler alquiler[], eMixClienteAlquiler codificacion[], int CANTALQUILERES, int CANTCLIENTES);



/** \brief Dar por finalizado un alquiler, cambio de variable estado a 2 y agregar tiempo real de alquiler.
 *
 * \param alquiler[] eAlquiler: cadena de estructura dada para analizar y modificar.
 * \param cliente[] eCliente: cadena de estructura dada para analizar y usar sus datos.
 * \param codificacion[] eMixClienteAlquiler: cadena de estructura dada para analizar y usar sus datos.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \param CANTALQUILERES int: cantidad maxima de alquileres.
 * \return void
 *
 */
void finLLamada(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES);



/** \brief imprime promedio de los tiempos reales por cada equipo y equipo con mayor alquiler.
 *
 * \param alquiler[] eAlquiler: cadena de estructura dada para analizar y usar sus datos.
 * \param cliente[] eCliente: cadena de estructura dada para analizar y usar sus datos.
 * \param codificacion[] eMixClienteAlquiler: cadena de estructura dada para analizar y usar sus datos.
 * \param CANTCLIENTES int: cantidad maxima de clientes.
 * \param CANTALQUILERES int: cantidad maxima de alquileres.
 * \return void
 *
 */
void informar(eAlquiler alquiler[], eCliente cliente[],  eMixClienteAlquiler codificacion[], int CANTCLIENTES, int CANTALQUILERES);
