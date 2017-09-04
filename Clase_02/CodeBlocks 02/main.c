#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
    int i;
    for(i=1; i<11; i++){
    printf("%d\n", i);
    }
*/
/*
    int i;
    for(i=0; i<11; i++){
    if(i==0){
      continue;                 éste caso es mas rebuscado.
    }
    printf("%d\n", i);
    }
*/

/*
    int i=0;
    while(i<10){
        i++;
        printf("%d\n", i);
    }
*/

/*
    int i=0;
    do{
        i++;
        printf("%d\n", i);
    }while(i<10);


    return 0; //este hay que ponerlo siempre para finalizar, ya q este es necesario en C !!!!!!!!!
*/

    int nota=0;
    int suma=0;
    float promedio=0;
    int i;

    for(i=0; i<3; i++){
        printf("escribir nota: ");
        scanf("%d", &nota);
        suma=(float) suma+nota;
    }
    promedio=suma/i;

    printf("suma: %d \npromedio: %d", suma, promedio);

    return 0; //este hay que ponerlo siempre para finalizar, ya q este es necesario en C !!!!!!!!!


}
