#include <stdio.h>
#include <stdlib.h>
#include "calculo.h"
// #include "./calculo.h"   ----> ruta relativa (es lo mismo que arriba, va a buscarlo dentro del proyecto.
// #include "../calculo.h" ----> en este caso con el "../" vamos una carpeta hacia atras, para ir 2 carpetas atras: "../../calculo.h"
//  ""D:/GOMEZ NICOLAS RODRIGO/clase 4/calculo.h" ------> ruta absoluta

int main()
{
    int numero1, numero2, resultado;
    char tipo;

    printf("ingrese numero1: ");
    scanf("%d", &numero1);

    printf("ingrese numero2: ");
    scanf("%d", &numero2);

    printf("ingrese tipo de operatoria + o -: ");
    scanf("%c", &tipo);

    system("cls");
    if(tipo == '-')
    {
    resultado=resta(numero1, numero2);
    printf("la resta de los numeros es: %d", resultado);
    }
    else
    {
        if(tipo == '+')
        {
        resultado=suma(numero1, numero2);
        printf("\nla suma de los numeros es: %d", resultado);
        }
    }
    return 0;
}



            //RECURSIVIDAD: APLICADA CON FACTOREO
/*
#include <stdio.h>
int factorial(int );
void main(void)
{
int valor,result;
printf("\nIngrese numero:");
scanf("%d",&valor);
result=factorial(valor);
printf("\nEl factorial de %d es %d",valor,result);
}
int factorial(int n)
{
int resp;
if(n==1)
{
    return 1;
}

resp=n* factorial(n-1);
return (resp);
}
*/








