typedef struct{
    char nombre[CANTCARACTERES];
    char email[CANTCARACTERES*20];
    int estado; //1 incluido, 0 no incluido, -1 esta en lista negra
}eDestinatario;



/** \brief Pide memoria para cargar nuevo destinatario
 *
 * \param void
 * \return eDestinatario*: retorna un puntero del tipo eDestinatario, con sus datos inicializados.
 *
 */
eDestinatario* destinatario_new(void);


/** \brief Controla e introduce en la estructura dada el nombre que se le pasa.
 *
 * \param nuevoDestinatario eDestinatario*: Puntero a estructura eDestinatario.
 * \param nombre char*. Cadena de char que se introduce en la estructura.
 * \return int -1 si no se seteo correctamente.
                0 si el seteo fue correcto
 *
 */
int destinatario_SetNombre(eDestinatario* nuevoDestinatario, char* nombre);


/** \brief Controla e introduce en la estructura dada el email que se le pasa.
 *
 * \param nuevoDestinatario eDestinatario*: Puntero a estructura eDestinatario.
 * \param email char*: Cadena de char que se introduce en la estructura.
 * \return int -1 si no se seteo correctamente.
                0 si el seteo fue correcto
 *
 */
int destinatario_SetEmail(eDestinatario* nuevoDestinatario, char* email);


/** \brief Controla e introduce en la estructura dada el estado que se le pasa.
 *
 * \param nuevoDestinatario eDestinatario*: Puntero a estructura eDestinatario.
 * \param estado int: Numero entero que se introduce como Estado en la estructura dada.
 * \return int -1 si no se seteo correctamente.
                0 si el seteo fue correcto
 *
 */
int destinatario_SetEstado(eDestinatario* nuevoDestinatario, int estado);
