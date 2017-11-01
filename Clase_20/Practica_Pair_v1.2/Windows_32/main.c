#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "validar.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int opciones;
    char seguir='s';


    while(seguir == 's'){

        opciones = menu("\t\t\tMenu Principal\n\n1- Parse del archivo data.csv\n2- Listar Empleados\n3- Ordenar por nombre\n4- Agregar un elemento\n5- Elimina un elemento\n6- Listar empleados (desde/hasta)\n7- Salir\n\n", 1, 7);
        system("cls");



        switch(opciones){

            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:
                al_newArrayList();
                break;

            case 5:

                break;

            case 6:

                break;

            case 7:
                seguir= 'n';
                break;

        }
    }


    return 0;
}
