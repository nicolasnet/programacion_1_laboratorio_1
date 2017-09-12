/*
strcmp(cadena1, cadena2) compara cadenas
strcmp(cadena1, cadena2) compara cadenas sin tener en cuenta minisculas y mayusculas

strupr() pone todo en mayuscula
strwr() poneen minusculas
para estas funciones: es necesaria la biblioteca---> string.h

strcat(destino, origen); copia la cadena "origen" a la cadena destino, si en destino hay un hola y en origen hay un chau.. la cadena destino queda: holachau.
esta funcion concatena lo del origen en el destino.

*/

/*


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20], apellido[20], apellidoNombre[40];//="\0" en lugar de inicializarlo con \0 1ro copiamos el contenido de la cadena Nombre
    int i;


    printf("nombre: ");
    fflush(stdin);
    scanf("%[^\n]", nombre);

    strlwr(nombre);

    nombre[0] = toupper(nombre[0]);

    for(i=0; i<19; i++)
    {
        if(nombre[i] == ' ' && nombre[i+1] != ' ')
        {
            nombre[i+1] = toupper(nombre[i+1]);
        }
    }



    printf("apellido: ");
    fflush(stdin);
    scanf("%[^\n]", apellido);

    strlwr(apellido);

    apellido[0] = toupper(apellido[0]);

    for(i=0; i<19; i++)
    {
        if(apellido[i] == ' ' && apellido[i+1] != ' ')
        {
            apellido[i+1] = toupper(apellido[i+1]);
        }
    }


    strcpy(apellidoNombre, apellido);
    //strcat(apellidoNombre, apellido); //en lugar de inicializarlo con \0 1ro copiamos el contenido de la cadena Nombre
    strcat(apellidoNombre, ", ");
    strcat(apellidoNombre, nombre);

    printf("%s", apellidoNombre);

        return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 3

int main()
{
        int i, j, nota[CANT], auxNota;
        char nombre[CANT][31], auxNombre[31];

        for(i=0; i<CANT; i++)
        {
            printf("nota: ");
            scanf("%d", &nota[i]);

            printf("nombre: ");
            fflush(stdin);
            scanf("%[^\n]", nombre[i]);
            strlwr(nombre[i]);

        }

        //system("cls");

        for(i=0; i<CANT-1; i++)
        {
            for(j=i+1; j<CANT; j++)
            {
                if(nota[i] < nota[j])
                {
                    strcpy(auxNombre, nombre[i]);
                    strcpy(nombre[i], nombre[j]);
                    strcpy(nombre[j], auxNombre);

                    auxNota=nota[i];
                    nota[i]=nota[j];
                    nota[j]=auxNota;
                }
            }
        }
    for(i=0; i<CANT; i++)
    {
        printf("Nombre: %s. Nota: %d\n", nombre[i], nota[i]);
    }


    return 0;
}


/*
 HECHO POR PROFESOR, ORDENAMIENTO CON DOS CRITERIOS:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int main(void){
    int nota[MAX], notaAux, i, j;
    char nombre[MAX][31], nombreAux[31];

    for(i=0; i<MAX; i++){
        system("cls");
        printf("Ingrese el nota: ");
        scanf("%d", &nota[i]);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombre[i]);
    }

    for(i=0; i<MAX-1; i++){

        for(j=i+1; j<MAX; j++){

            if(nota[i] < nota[j]){
                strcpy(nombreAux, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], nombreAux);

                notaAux = nota[i];
                nota[i] = nota[j];
                nota[j] = notaAux;
            }

            if(nota[i] == nota[j]){

                if(strcmp(nombre[i],nombre[j]) > 0){

                    strcpy(nombreAux, nombre[i]);
                    strcpy(nombre[i], nombre[j]);
                    strcpy(nombre[j], nombreAux);
                    //notaAux = nota[i];
                    //nota[i] = nota[j];
                    //nota[j] = notaAux;
                }
            }
        }
    }

    system("cls");
    printf("\nnota\tNombre");

    for(i=0; i<MAX; i++){
        printf("\n%d\t%s", nota[i], nombre[i]);
    }

    return 0;
}

*/


