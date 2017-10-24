/*
        MEMORIA DINAMICA
Pers = (Person*) malloc(sizeof(Person));  recibe el tamaño de algo(una estructura) y devuelve un puntero a VOID (generico, no importa la estructura o variable q sea).
                                        lo castea a tipo Person, de manera q cuando te muevas por punteros se muevan por la cantidad de bites de la estructura y no por 1 bite (q es lo q ocupa un puntero)
PersAux = realloc(Pers, (sizeof(Person))*2);  //devuelve NULL en caso de no encontrar espacio consecutivo para la cantidad pedida, por eso no se asigna directamente a Pers ya q si es NULL se pierde lo anteriormente cargado

if(PersAux != NULL)
        Pers = PersAux;


free(Pers); libero memoria. OJO NO LIBERAR MEMORIA SI YA SE HIZO O SI EL PUNTERO A PUNTA A NULL!!!!


*/




/*
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
*/



#include <stdio.h>
#include <stdlib.h>
struct persona
{
    char nombre[50];
    int edad;
};


int main()
{

    int seguirCargando;
    int i;
    int auxNuevaLogitud;
    int logitudPersonas = 1;
    struct persona* pArrayPersona;
    struct persona* pAuxPersona;
    // Creamos el array de personas
    pArrayPersona = malloc(sizeof(struct persona));
    if (pArrayPersona == NULL)
    {
        printf("\nNo hay lugar en memoria\n");
        exit(0);
    }
    while(1)
    {
            printf("\nIngrese nombre: ");
            scanf("%s",(pArrayPersona+logitudPersonas-1)->nombre);
            printf("\nIngrese edad: ");
            scanf("%d",&((pArrayPersona+logitudPersonas-1)->edad)); //el operador fecha nos evita usar el *
            printf("\nSi desea cargar otra persona ingrese (1): ");
            scanf("%d",&seguirCargando);

            if(seguirCargando == 1)
            {
                // Calculamos el nuevo tamaño del array
                auxNuevaLogitud = sizeof(struct persona) * logitudPersonas; //por esta multiplicacion es q inicia el logitudPersona en 1.
                // Redimencionamos la lista
                pAuxPersona = realloc( pArrayPersona, auxNuevaLogitud);
                if (pAuxPersona == NULL)
                {
                    printf("\nNo hay lugar en memoria\n");
                    break;
                }
                logitudPersonas++; //Incremento el contador de personas
                pArrayPersona = pAuxPersona;
            }
            else
            {
                break;
            }
    }

    for(i = 0; i < logitudPersonas; i++)
    {
        printf("\nNombre: %s - ",(pArrayPersona+i)->nombre);
        printf("Edad: %d",(pArrayPersona+i)->edad);
    }
    free(pArrayPersona); // Liberamos la memoria
    return 0;




/*
    Person* personArray[50];
    int i;
    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i,i);
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
    }
    scanf(" ");
    return 0;
*/



}

