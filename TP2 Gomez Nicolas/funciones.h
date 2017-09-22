typedef struct {

    char nombre[50];
    int edad;
    int estado; //flag
    long int dni;  //long o array

}EPersona;

int menu(char opciones[]);

void alta(EPersona persona[]);

void inicia(EPersona persona[]);

void borrar(EPersona persona[], int CANT);

void ordenar(EPersona persona[], int CANT);

void listar(EPersona persona[], int CANT);

void graficar(EPersona persona[],int CANT);
