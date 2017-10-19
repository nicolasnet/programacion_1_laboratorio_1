#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANTCARACTERES 25
#define ARCH "./bin.dat"



int main()
{
    char seguir='s';
    int opcion=0, cant;
    EMovie pelicula;
    FILE *bin;



    //Con estas secuencias, nos aseguramos de q si lo puede leer, no lo elimine y lo cree nuevamente en caso de no existir.
    if ((bin = fopen(ARCH,"rb+"))==NULL){        //con rb+ lee y escribe pero no abre un archivo nuevo en caso de no encontrarlo
        if ((bin = fopen(ARCH,"wb+"))==NULL){     //con wb+ crea un archivo, si ya existia lo borra y crea nuevamente.
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }


    while(seguir=='s')
    {



        opcion = menu("\t\t\tMenu Principal\n\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir\n", 1, 5);
        system("cls");


        switch(opcion)
        {
            case 1:

                agregarPelicula(pelicula, CANTCARACTERES, bin);
                system("cls");
                break;

            case 2:
                borrarPelicula(pelicula, bin);
                break;

            case 3:
                modificaPelicula(pelicula, CANTCARACTERES, bin);

                break;

            case 4:
                //se lleva el indicador de posición al principio para comenzar a leer
                rewind(bin);

                while(!feof(bin)){
                    cant = fread(&pelicula,sizeof(pelicula), 1, bin);

                    if(cant!=1){
                        if(feof(bin)){
                            break;
                        }
                        else{
                            printf("No leyo el ultimo registro");
                            break;
                        }
                    }

                        printf("\nCodigo: %d\t%s\t%d m.\t%s\t%s\t%.2f\n%s\n",pelicula.codigo, pelicula.titulo, pelicula.duracion, pelicula.genero, pelicula.descripcion, pelicula.puntaje, pelicula.linkImagen);
                }
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    fclose(bin);

    return 0;

}
