typedef struct{
    int numero;
    char nombre[CANTCARACTERES];
    int par;
    int impar;
    int primo;
    int estado; //
}eNumero;



/** \brief Pide memoria para cargar nuevo numero
 *
 * \param void
 * \return eNumero*: retorna un puntero del tipo eNumero, con sus datos inicializados.
 *
 */
eNumero* numero_new(void);


int numero_SetNombre(eNumero* nuevoNumero, char* nombre);


int numero_SetNumero(eNumero* nuevoNumero, char* numero);


int numero_SetPar(eNumero* nuevoNumero, char* par);


int numero_SetImpar(eNumero* nuevoNumero, char* impar);


int numero_SetPrimo(eNumero* nuevoNumero, char* primo);


void numero_CalculaParImpar(eNumero* numero);


void numero_CalculaPrimo(eNumero* numero);
