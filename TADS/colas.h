
/*
    Librería para el manejo de colas de enteros.
    Creado para prácticas en las preparadurías de Programación II, UNEG.

    Autor: Carlos Pinelly - cpinelly@gmail.com - @capicp
    Version: 1.0
    Liberado: 02/07/2013
*/

#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#include "../Listas/listas.h"

// Tipo de dato para una cola

typedef struct COLA{
    Nodo* ultimo;     // Apuntador al último elemento de la cola
    Nodo* siguiente;  // Apuntador al siguiente elemento que saldrá de la cola
    int longitud;     // Numero de elementos de la cola.
} Cola;

// Inicializa la estructura para una cola. Siempre debe llamarse antes de usarse una cola.
// @param c Apuntador a la estructura de cola a ser inicializada.

void inicializar_cola(Cola *c){

    c->ultimo = NULL;
    c->siguiente = NULL;
    c->longitud = 0;
}

// Indica si una cola no posee elemento alguno.
// @param c Cola a evaluar
// Retorna verdadero si la cola no posee elementos, de lo contrario, falso.

int cola_vacia(Cola c){

    return (!c.siguiente );
}

// Inserta un elemento en la cola según el comportamiento definido para una cola.
// @param c Referencia a la cola en la que se insertará el elemento
// @param n Entero a ser insertado

void encolar(Cola* c, int n){

    Nodo* nuevo = crear_nodo(n);

    if ( !c->ultimo ){
        c->siguiente = nuevo;
        c->ultimo = nuevo;
    }else{
        c->ultimo->sig = nuevo;
        c->ultimo = nuevo;
    }

    c->longitud++;
}

// Devuelve el siguiente elemento en ser atendido de la cola.
// @param c Cola en la que se desencolará.
// Retorna el entero desencolado.

int desencolar(Cola *c){

    int i = 0;
    Nodo* l;

    if (c->siguiente){
        i = c->siguiente->info;
        l = c->siguiente;
        c->siguiente = c->siguiente->sig;
        free(l);
        c->longitud--;
    }

    return i;
}

// Indica el numero de elementos de una cola.
// @param c Cola a verificar.

int longitud_cola(Cola c){
    return c.longitud;
}

// En vista de la implementación sobre una lista de las colas deben liberarse
// todos sus elementos. Esta función libera de memeoria todos los elementos de la cola.
// @param c Cola a liberar

void liberar_cola(Cola *c){

    liberar_lista( &(c->siguiente));
    inicializar_cola(c);
}

// Muestra los elementos de una cola.
// @param c Cola a mostrar.

void mostrar_cola(Cola c){

    printf("\nn: %d \n", c.longitud);
    mostrar_lista(c.siguiente);
}


#endif // COLAS_H_INCLUDED
