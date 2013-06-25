
// Programa para pruebas de la librerías listas.h

#include "listas.h"   // Libreria para el manejo de listas simples enlazadas
#include<stdio.h>     // Libreria estandar de entrada y salida


main(){

    // Apuntador al primer elemento de la lista
    Nodo* lista = NULL;

    // Pruebas para función insertar_cola
    lista = insertar_cola(lista, 7);
    lista = insertar_cola(lista, 4);
    lista = insertar_cola(lista, 12);

    // Pruebas para función insertar_tope
    lista = insertar_tope(lista, 2);
    lista = insertar_tope(lista, 5);
    lista = insertar_tope(lista, 3);

    // Pruebas para función insrtar_tope_m.
    // Nótese que se tiene una llamada más limpia e intuitiva que la de
    // insetar_tope.
    insertar_tope_m( &lista, 6);
    insertar_tope_m( &lista, 10);
    insertar_tope_m( &lista, 22);

    // Se mustra la lista creada.
    mostrar_lista(lista);

    // Liberación de la lista.
    liberar_lista(&lista);

    // Si le la lista fue liberada no debe mostrarse elemento alguno.
    mostrar_lista(lista);

}
