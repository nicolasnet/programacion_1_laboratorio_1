#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "ArrayList.h"
#include "destinatario.h"

#define CANTCARACTERES 25

int main()
{
    char seguir='s';
    int opcion=0, chequeo;
    //int i;
    //eDestinatario* auxDestinatario;
    char nombreArchivos[CANTCARACTERES*2];

    ArrayList* lista = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    ArrayList* subLista = al_newArrayList();
    FILE* destinatarios;
    FILE* destinatariosBlack;




    while(seguir=='s')
    {

        opcion = menu("\t\t\tMenu Principal\n\n1- Cargar Destinatarios.\n2- Cargar Lista Negra.\n3- Depurar.\n4- Listar.\n5- Salir.\n", 1, 5);
        system("cls");


        switch(opcion)
        {
            case 1:

                printf("Ingrese nombre del archivo (sin extencion de archivo): ");
                fflush(stdin);
                scanf("%[^\n]", nombreArchivos);
                strcat(nombreArchivos, ".csv");

                destinatarios = fopen(nombreArchivos, "r");
                if(destinatarios == NULL){
                    printf("\nNo se pudo abrir el archivo: %s\n", nombreArchivos);
                    break;
                }

                chequeo = parserDestinatario(destinatarios, lista);
                if(chequeo){
                    printf("\nError al parsear archivo\n\n");
                }
                else{
                    printf("\nArchivo cargado con exito\n\n");
                }

                fclose(destinatarios);
                break;

            case 2:
                printf("Ingrese nombre del archivo (sin extencion de archivo): ");
                fflush(stdin);
                scanf("%[^\n]", nombreArchivos);
                strcat(nombreArchivos, ".csv");

                destinatariosBlack = fopen(nombreArchivos, "r");
                if(destinatariosBlack == NULL){
                    printf("\nNo se pudo abrir el archivo: %s\n", nombreArchivos);
                    break;
                }

                chequeo = parserDestinatario(destinatariosBlack, listaNegra);
                if(chequeo){
                    printf("\nError al parsear archivo\n\n");
                }
                else{
                    printf("\nArchivo cargado con exito\n\n");
                }

                fclose(destinatariosBlack);
                break;

            case 3:
                depurarDestinatarios(lista, listaNegra);
                armaSublista(lista, subLista);
                break;

            case 4:
                imprimeLista(lista);
                imprimeLista(subLista);


                /*
                if(lista!= NULL)
                    printf("%d", lista->size);

                for(i=0; i<lista->size; i++){
                    auxDestinatario = (eDestinatario*) al_get(lista, i);
                      if(auxDestinatario == NULL){
                        printf("\nno llego a auxiliar destinatario\n");
                      }
                      else{

                        printf("\n%s\n", auxDestinatario->nombre);
                        printf("\n%s\n", auxDestinatario->email);
                        printf("\n%d\n", auxDestinatario->estado);
                        printf("\n-----------------------------\n");
                      }
                }
                printf("\n\n-----------sublista----------\n\n");

                if(subLista!= NULL)
                    printf("%d", subLista->size);

                for(i=0; i<subLista->size; i++){
                    auxDestinatario = (eDestinatario*) al_get(subLista, i);
                      if(auxDestinatario == NULL){
                        printf("\nno llego a auxiliar destinatario\n");
                      }
                      else{

                        printf("\n%s\n", auxDestinatario->nombre);
                        printf("\n%s\n", auxDestinatario->email);
                        printf("\n%d\n", auxDestinatario->estado);
                        printf("\n-----------------------------\n");
                      }
                }
                */

                break;

            case 5:
                seguir = 'n';
                break;
        }
    }



    return 0;
}
