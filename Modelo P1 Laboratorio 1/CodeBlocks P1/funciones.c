#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menu(char items[], int limiteInferior, int limiteSuperior){

    int opciones;
    printf("%s", items);
    printf("elegir: ");
    scanf("%d", &opciones);
    while(opciones<limiteInferior || opciones>limiteSuperior){
        printf("reintente elegir: ");
        scanf("%d", &opciones);
    }
    return opciones;

}











#endif
