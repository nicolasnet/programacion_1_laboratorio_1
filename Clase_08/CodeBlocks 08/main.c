/*              ESTRUCTURAS
Crear tipos de datos porpios en funcion de los tipos de datos primitivos que ya conocemos (int, float, char, double, void)

struct alumno alu; ----> "struc alumno es el tipo de dato creado... "alu" es el nombre de la variable con ese tipo

definir ese tipo de dato: ------> esto se declara en las bibliotecas .h, junto con los prototipos de las funciones
struct alumno{
int legajo;
char nombre [31];
etc, etc;
}

struct alumno alu;

printf("legajo: ");
scanf("%d", &alu.legajo); ---> el %d va xq legajo es de ese tipo
printf("Nombre: ");
fflush(stdin);
scanf("%[^\n]", alu.nombre);



*/

/*
        VALIDACIONES!!!!!!!!!!!!!!

    isalpha ----> funcion q devuelve 0 si no es una letra o 1 si es una letra !!
    isdigit ----> funcion q devuleve 0 si no es un numero o 1 si es un numero !!

    usar getch ---> para no mostrar el caracter q se escribe
    int retorno=1;

    for(i=0; i<31; i++)
    {
        if(isalpha(name[i]) = 0)
        {
            returno = 0;
            break;
        }
    }
    return retorno;


*/
/*  NO FUNCIONA POR AHORA!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipodedatos.h"

int main()
{
    int edad;

    printf("Edad: ");
    edad = getch();
    if (isdigit(edad) == 0)
    {
        getch("%d", edad);
    }

        printf("\n%d\n", edad);

    return 0;
}
*/




/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipodedatos.h"

int main()
{
    struct alumno alu;

    printf("legajo: ");
    scanf("%d", &alu.legajo); //---> el %d va xq legajo es de ese tipo

    printf("Nombre: ");
    fflush(stdin);
    scanf("%[^\n]", alu.nombre);
    strlwr(alu.nombre);
    alu.nombre[0] = toupper(alu.nombre[0]);

    printf("Nota 1er parcial: ");
    scanf("%d", &alu.nota1);

    printf("Nota 2do parcial: ");
    scanf("%d", &alu.nota2);

    alu.promedio = (float) (alu.nota1+alu.nota2)/2;

    system("cls");

    printf("Legado: %d\nNombre: %s\nNota1: %d Nota2: %d\nPromedio: %.2f\n", alu.legajo, alu.nombre, alu.nota1, alu.nota2, alu.promedio);


    return 0;
}
*/


/*        ESTRUCTURA CAMBIO DE NOMBRE
typedef struct{
    int legajo;
    char nombre[31];

}alumno; ---->nuevo nombre de la estructura

alumno alu;
*/


            //ESTRUCTURA DENTRO DE ESTRUCTURA
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

    struct fecha { int dia,mes,anio;};
    struct gente {
        char nombre[20];
        struct fecha f_nacimiento;
        };

int main()
{
    struct gente pers;
    struct fecha fn;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pers.nombre);
    strlwr(pers.nombre);
    pers.nombre[0] = toupper(pers.nombre[0]);


    printf("Ingrese dia de nacimiento: ");
    scanf("%d",&fn.dia);

    printf("Ingrese mes de nacimiento: ");
    scanf("%d",&fn.mes);

    printf("Ingrese a¤o de nacimiento: ");
    scanf("%d",&fn.anio);

    pers.f_nacimiento=fn;

    system("cls");

    printf("Nombre: %s\nFecha de nacimiento: %d/%d/%d\n", pers.nombre, pers.f_nacimiento.dia, pers.f_nacimiento.mes, pers.f_nacimiento.anio);

    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipodedatos.h"

int main()
{
    struct alumno alu [3];
    int i, j;

    for(i=0; i<3; i++)
    {
        printf("legajo: ");
        scanf("%d", &alu[i].legajo); //---> el %d va xq legajo es de ese tipo

        printf("Nombre: ");
        fflush(stdin);
        scanf("%[^\n]", alu[i].nombre);
        strlwr(alu[i].nombre);
        alu[i].nombre[0] = toupper(alu[i].nombre[0]);

        for(j=0; j<31; j++)
        {
            if(alu[i].nombre[j] == ' ' && alu[i].nombre[j+1] != ' ')
            {
                 alu[i].nombre[j+1] = toupper(alu[i].nombre[j+1]);
            }
        }

        printf("Nota 1er parcial: ");
        scanf("%d", &alu[i].nota1);

        printf("Nota 2do parcial: ");
        scanf("%d", &alu[i].nota2);

        alu[i].promedio = (float) (alu[i].nota1+alu[i].nota2)/2;

        system("cls");
    }


    for(i=0; i<3; i++)
    {
        printf("Legajo: %d. Nombre: %s\nNota1: %d. Nota2: %d\nPromedio: %f\n\n", alu[i].legajo, alu[i].nombre, alu[i].nota1, alu[i].nota2, alu[i].promedio);
    }

    return 0;
}


