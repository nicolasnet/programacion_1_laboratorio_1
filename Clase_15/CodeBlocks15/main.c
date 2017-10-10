/*
            PUNTEROS

int nro = 5, *ptrNro;
ptrNro = &nro; -----> le asignamos al puntero la direccion de memoria (directorio) de la variable. No se le asigna un valor de una variable sino su direccion en memoria

* (asterisco) operador de indireccion,
*ptrNro ---> trae el valor de la variable, no su directorio (q eso es lo q se guarda en el puntero)
*ptrNro = 81; cambiamos el valor de la variable nro.
nro = 17; vuelve a cambiarse el valor de la variable, el puntero no tiene cambios sigue almacenando una direccion de memoria de esta variable.

int *ptrNro2; --->otro puntero

ptrNro2 = ptrNro; ---> guardamos en el nuevo puntero la direccion de memoria q tenia el 1er puntero

*ptrNro2 = *ptrNro; ---> a la direccion almacenada en el nuevo puntero se le asigna el valor de la variable q podee el 1er puntero
                        el ultimo valor q se asigno fue 17, osea ese 17 sera el nuevo valor de la varable cuya direccion en memoria posee la nuevo puntero.


COMPARACION DE PUNTEROS

if(ptrNro == ptrNro2)
if(ptrNro == &nro)  ----> compara la direccion de mem. q posee el puntero con la direccion de mem de la variable
if(ptrNro == 0X10ABFS) ---> poco usado comparar literalmente con una direccion de mem.
if(ptrNro == NULL) -----> ptrNro=NULL; ---> le asignamos NULL para q el puntero no apunte a cualquier lado.


int i, vec[5], *ptr;

ptr=vec;  //== ptr=&vec[0]; se le asigna la direccion de mem del 1er indice del vector.

for(i=0; i<5; i++){

    vec[i] = i+3;
}

for(i=0; i<5; i++){

    printf("\n %d", vec[i]);
}

for(i=0; i<5; i++){

    printf("\n %d", *(ptr+i)); //----> con cada suma pasa a la siguiente dir. de mem del vector, ya q le suma un entero q son 4 bytes;

}




*/



#include <stdio.h>
#include <stdlib.h>

int main()
{ //cargamos el vector y despues cargamos datos al vector a travez del puntero.
    int i, vec[5], *ptr;

    ptr = vec;

    for(i=0; i<5; i++){

        vec[i] = i+3;
    }

    //mostar como vector
    for(i=0; i<5; i++){

        printf("\n %d", vec[i]);
    }

    //cargar como puntero
    for(i=0; i<5; i++){

        *(ptr+i) = i*4;
    }

    for(i=0; i<5; i++){

        printf("\n %d", *(ptr+i));
    }

    for(i=0; i<5; i++){

        printf("\n %d", vec[i]);
    }

    return 0;
}
