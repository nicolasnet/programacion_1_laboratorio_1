#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArrayList.h"
#include "numero.h"

#define CANTCARACTERES 50

int main()
{
    char seguir='s';
    int opcion=0, chequeo;

    ArrayList* lista = al_newArrayList();
    ArrayList* subLista;
    FILE* numeros;


    while(seguir=='s')
    {

        opcion = menu("\t\t\tMenu Principal\n\n1- Cargar numeros.\n2- Completar.\n3- Generar y Listar.\n4- Informar.\n5- Salir.\n", 1, 5);
        system("cls");

        switch(opcion)
        {
            case 1:
                numeros = fopen("datos.csv", "r");
                if(numeros == NULL){
                    printf("\nNo se pudo abrir el archivo.");
                    break;
                }

                chequeo = parserNumeros(numeros, lista);
                if(chequeo){
                    printf("\nError al parsear archivo\n\n");
                }
                else{
                    printf("\nArchivo cargado con exito\n\n");
                }

                fclose(numeros);
                break;

            case 2:
                completarLista(lista);
                break;

            case 3:
                subLista = al_clone(lista);
                al_sort(subLista, comparaNumeros, 1);
                  //printf("\nsize: %d\n", subLista->size);
                  //printf("\nsize: %d\n", subLista->len(subLista));
                al_sort(subLista, comparaNumeros, 0);

                imprimeLista(subLista);
                 //printf("\nsize: %d\n", subLista->size);
                 //printf("\nLen size: %d\n", subLista->len(subLista));
                break;

            case 4:
                informar(subLista);
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

