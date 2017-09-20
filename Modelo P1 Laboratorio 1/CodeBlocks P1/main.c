#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANTPROD 5  //cambia a mil para el ejercicio.
#define CANTPROV 3


int main()
{
    eProducto producto[CANTPROD];
    eProveedor proveedor[CANTPROV];
    int flag=0, opciones=0;
    char seguir='s';


    while(seguir=='s')
    {
        opciones = menu("1- Alta producto.\n2-Modificar producto.\n3-Baja Prodcuto.\n4-Informar.\n5-Listar.\n6-Salir.", 1, 6);

        switch(opciones)
        {
            case 1:
                alta();
                flag=1;
                break;

            case 6:
                seguir='n';
                break;


        }

        while(flag==1)
        {
            switch(opciones){
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;





            }



        }


    }





    return 0;
}
