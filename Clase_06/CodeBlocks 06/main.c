/*
            Cadenas (String)

char nombre[31];
 0   1   2   3   4  ... 30
'j' 'u' 'a' 'n' '\0''.....' el ultimo es un solo caracter para darle fin y q luego no imprima nada q haya estado almacenado
                            el '\0' se escribe automaticamente, no se debe escribir.
printf("%s", nombre);


(
#define ESC 27  ----->constante
 char tecla;
 do{
    ----
    ----
    ----
    tecla=getch(); ----> espera que aprietes una tecla
 }while(tecla!=ESC) ---> o tecla!=27----> en caso de no definir la constante
)
char nombre[31];
printf("Ingrese nombre: ");
fflush(stdin); --->limpia
scanf("%s", nombre);  ----> no lleva '&' ya q el nombre representa la direccion del 1er elemento del vector es igual a "&nombre[0]"




*/




/*
#include <stdio.h>
#include <stdlib.h>
#define CANT 31
#define ESC 27
int main()
{
    char letra;
    char nombre[CANT];

    do
{


    system("cls");
    printf("Ingrese nombre: ");
    fflush(stdin); //-----> limpia el directorio para que no quede el "enter" cargado en cola.
    //scanf("%s", nombre);
    //gets(nombre); ---> NO RECOMENDABLE, GENERA PROBLEMAS DE SEGURIDAD EN EL CODIGO DEL PROGRAMA
    //fgets(nombre, 31); ----> la contra de este es q el ultimo elemento lo ocupa con "enter"
    scanf("%[^\n]", nombre);
    printf("%s", nombre);

    printf("\nprecionar cualquier tecla para continuar... ESC para salir");
    letra=getch();

}while(letra!=ESC);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 31
#define ESC 27
int main()
{


    int letras; //---->  distinto a la constante CANT.
    char aux[CANT * 10];
    char nombre[CANT];
    char letra;

    do{
        system("cls");
        do{
        printf("Escribir Nombre: ");
        fflush(stdin);
        scanf("%[^\n]", aux);
        letras= strlen(aux); //-----> devuelve un entero con la cantidad de elementos q posee el vector.

        }while(letras >=30);

        printf("\n\nValidacion correcta\n");
        //nombre=aux----> NOOOOOOO NO SIRVE POR SER VECTORES!!!!!
        strcpy(nombre, aux);  //1ro el destino. 2do el origen. y copia todos los elementos. esto es para CHAR

        printf("\nEl nombre es: %s", nombre);
        printf("\n\nPresione cualquier tecla para continuar... ESC para salir");

        letra = getch();

    }while(letra != ESC);

    return 0;
}
*/

/*LOS OPERADORES RELACIONALES NO SIRVEN PARA CADENAS ( ==  != <  > >= <= )
 SE UTILIZA LA SIGUIENTE FUNCION:

 strcmp (cadena1, cadena dos) -----> devuelve un INT

 si son iguales devuelve =   0
 si la 1er cadena es mayor devuelve     >0
 si la 2da cadena es mayor devuelve     <0

                    vemos reflejado en funcionamiento como son comparados los vectores
                    compara el 1er elemento si son distintos deja de coparar.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESC 27
#define CANT 31

int main()
{
    char nombre[CANT];
    char nombre2[CANT];
    char aux[CANT * 10];
    char aux2[CANT * 10];
    char letra;
    int letras;

    do{
        system("cls");

        do{
            printf("Nombre: ");
            fflush(stdin);
            //scanf("%s", nombre);
            scanf("%[^\n]", aux);
            letras = strlen(aux);
        }while(letras >=30);

        do{
            printf("\nNombre2: ");
            fflush(stdin);
            //scanf("%s", nombre);
            scanf("%[^\n]", aux2);
            letras = strlen(aux2);
        }while(letras >=30);

        printf("\nFuera de la validacion!");
        strcpy(nombre, aux);
        strcpy(nombre2, aux2);

        if(strcmp(nombre, nombre2) == 0){
            printf("\nAmbos nombres son iguales");
        }
        else{
            if(strcmp(nombre, nombre2) > 0){
                printf("\nEl primer nombre es mayor que el segundo");
            }
            else{
                printf("\nEl segundo nombre es mayor que el primero");
            }
        }

        printf("\nEl Nombre es: %s", nombre);

        printf("\nEl Nombre2 es: %s", nombre2);

        printf("\n\nPresione cualquier tecla para continuar... ESC para salir");

        letra = getch();

    }while(letra != ESC);

    return 0;
}






/*
    strupc(); ---> como toupper(); pasa a mayuscula... el 1ro para vectores, el 2do para elementos.
    strlwr(); ---> como tolower(); pasa a miniscula... el 1ro para vectores, el 2do para elementos.

    ARRAYS DE CADENAS... PARA CARGAR VARIOS NOMBRES

    char nombre [CANT][31] ------> en este caso en CANT especificamos la cantidad de nombres y en el 31 la cantidad de elementos de cada nombre.

*/

