#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {


        opcion = menu("\t\t\tMenu Principal\n\n1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Salir\n", 1, 4);
        system("cls");


        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;

}
