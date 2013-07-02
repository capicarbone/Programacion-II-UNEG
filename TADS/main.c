#include "pilas.h"
#include "colas.h"

main(){

    Pila pila;
    Cola cola;
    int i;

    printf("\n --- PILAS ---- \n");

    printf("Inicializacion de pila...\n");
    inicializar_pila( &pila );

    printf("\nSe empilan: 4,6 y 8... \n\n");
    empilar( &pila, 4 );
    empilar( &pila, 6 );
    empilar( &pila, 8 );

    printf("Pila resultante \n");
    mostrar_pila(pila);

    printf("\nSe procede a desempilarse un elemento..\n");
    i = desempilar( &pila );

    printf("Se recibió %d \n\n", i);

    printf("Pila modificada \n");
    mostrar_pila(pila);

    printf("\nSe procede a liberar toda la pila..");
    liberar_pila(&pila);

    printf("\nPila liberada.");
    mostrar_pila(pila);

    printf("\n --- COLAS ---- \n");

    printf("Inicializacion de cola...\n");
    inicializar_cola( &cola );

    printf("\nSe encolan: 7,8 y 2... \n\n");
    encolar( &cola, 7 );
    encolar( &cola, 8 );
    encolar( &cola, 2 );

    printf("Cola resultante \n");
    mostrar_cola(cola);

    printf("\nSe procede a desempilarse un elemento..\n");
    i = desencolar( &cola );

    printf("Se recibió %d \n\n", i);

    printf("Cola modificada \n");
    mostrar_cola(cola);

    printf("\nSe procede a desempilarse un elemento..\n");
    i = desencolar( &cola );

    printf("Se recibió %d \n\n", i);

    printf("Pila modificada \n");
    mostrar_cola(cola);

    printf("\nSe procede a liberar toda la cola..");
    liberar_cola(&cola);

     printf("\nCola liberada.");
    mostrar_cola(cola);
}
