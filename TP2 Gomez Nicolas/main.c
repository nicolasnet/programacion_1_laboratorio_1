#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANT 20


int main()
{
    EPersona persona[CANT];
    char seguir='s';
    int opciones=0, flag=0;


    inicia(persona);

    while(seguir=='s')
    {

       opciones = menu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n\n");
       system("cls");


       switch(opciones)
       {
            case 1:
                alta(persona);
                flag=1;
                system("cls");
                break;

            case 5:
                seguir = 'n';
                break;
       }

       if(flag==1){

            switch(opciones)
            {
                case 2:
                    listar(persona, CANT);
                    borrar(persona, CANT);
                    system("cls");
                    break;

                case 3:
                    ordenar(persona, CANT);
                    listar(persona, CANT);
                    break;

                case 4:
                    graficar(persona, CANT);
                    break;
            }
        }

    }

    return 0;
}
