#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"



void mostrarCadena(char *ptrCadena){
            while(*ptrCadena !='\0'){    //----->compara el valor q posee
                printf("%c", *ptrCadena);
                ptrCadena++; //-----> tiene guardada la direccion en memoria de la 1er letra, al incrementarlo pasamos a la 2da variable.
            }
}




#endif
