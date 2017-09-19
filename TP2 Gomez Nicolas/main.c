#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    EPersona persona[20];
    char seguir='s';
    int opciones=0;


    inicia(persona);

    while(seguir=='s')
    {
       system("cls");
       opciones = menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n", 1, 5);



        switch(opciones)
        {
            case 1:
                alta(persona);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
