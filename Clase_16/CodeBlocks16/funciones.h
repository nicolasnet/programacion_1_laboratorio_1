typedef struct{
        int dia;
        int mes;
        int anio;

}eFecha;

typedef struct{
        long int dni;
        char nombre[31];
        eFecha fechaNac;
}ePersona;


void mostrarCadena(char *ptrCadena);
