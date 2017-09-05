/*
    Arrays (se conocen como sinonimos de Vetor o Arreglado)
  int vec [5] ----> se guardan 5 numeros de caracter entero en distintos directorios (int) de 0 a k-1, siendo "k" en este caso "5"
      vec ----> es solo en nombre, se puede poner cualquier nombre en esta variable.

 con estas pocas lineas se pueden cargar una cant ilimitada de datos:
  jnt i;
  int edad [40]

  for(i=0; i<40; i++)
  {
  printf("edad: ");
  scanf("%d", &edad[i];
  }
------------------------------------
    #define CANT 40  ---->declaro constante (conviene ponerlo el nombre en mayuscula por costumbre profesional.

    for(i=0; i<cant; i++)
    {
    printf("%d", edad[i];
    }




*/
/*#include <stdio.h>
#include <stdlib.h>
#define CANT 3

int main()
{
    //char nombre [CANT];
    int i, edad[CANT], legajo[CANT];
    float salario[CANT];


    for(i=0; i<CANT; i++)
    {
        //printf("Ingresar nombre: ");
        //scanf("%c", &nombre[CANT]);

        legajo[i]=i+1;

        printf("Ingresar edad: ");
        scanf("%d", &edad[i]);

        printf("Ingresar salario: ");
        scanf("%f", &salario[i]);


    }

    system("cls");

    for(i=0; i<CANT; i++)
    {
        printf("legajo %d:  edad: %d y salario: %.2f\n",legajo[i], edad[i], salario[i]);
    }

    //printf("%d", edad[1]);  para chequear como quedan todos guardados

    return 0;
}
*/
    //Carga aleatoria:

#include <stdio.h>
#include <stdlib.h>
#define CANT 3

int main()
{
    int i, estado[CANT], edad [CANT], legajo [CANT], flag;
    float salario [CANT];
    char r;

    for(i=0; i<CANT; i++)
    {
        estado[i]=0;
    }

    do
    {
        flag=0;
        for(i=0; i<CANT; i++)
        {
            if(estado[i]==0)
            {
                //legajo[i]=i+1;

                printf("Ingresar legajo: ");
                scanf("%d", &legajo[i]);


                printf("Ingresar edad: ");
                scanf("%d", &edad[i]);

                printf("Ingresar salario: ");
                scanf("%f", &salario[i]);

                estado[i]=1;
                flag=1;
                break;
            }

        }
        if(flag==0)
        {
            printf("espacio insuficiente\n");
        }
        else
        {
            printf("datos cargados\n");
        }

        fflush(stdin);
        printf("precionar s si desea continuar\n");
        scanf("%c", &r);
    }while(r=='s');

    for(i=0; i<CANT; i++) //para listar los datos cargados
    {
        if(estado[i]==1)
        {
            printf("legajo: %d edad: %d salario: %.2f\n", legajo[i], edad[i], salario[i]);
        }
    }

    //buscar max y min  ...  buscar en la guia




    //ordenar array

    int i, j, aux, vec [5];
    for(i=0; i<CANT-1; i++)
    {
            for(j=0; j<CANT-1; j++)
            {
                if(vec[i]>vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
    }




    return 0;
}





