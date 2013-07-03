
/*
    Librería para el manejo de pilas de enteros.
    Creado para prácticas en las preparadurías de Programación II, UNEG.

    Autor: Carlos Pinelly - cpinelly@gmail.com - @capicp
    Version: 1.0
    Liberado: 02/07/2013
*/

#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "../Listas/listas.h"

// Tipo de dato para una pila

typedef struct PILA {
    Nodo* tope;         // Tope de la pila por donde ingresan y salen los elementos;
    int longitud;       // Ńúmero de elementos de la pila.
} Pila;

// Indica si una pila no posee elemento alguno.
// @param p Pila a evaluar
// Retorna verdadero si la pila no posee elementos, de lo contrario, falso.

int pila_vacia(Pila p){

    return (!p.tope);
}

// Inicializa la estructura para una pila. Siempre debe llamarse antes de usarse una cola.
// @param p Apuntador a la estructura de pila a ser inicializada.

void inicializar_pila( Pila *p){

    p->tope = NULL;
    p->longitud = 0;
}

// Inserta un elemento en la pila según el comportamiento definido para una pila.
// @param p Referencia a pa pila en la que se insertará el elemento
// @param n Entero a ser insertado

void empilar( Pila *p , int n){

    insertar_tope_m( &(p->tope), n );
    (p->longitud)++;

}

// Devuelve el siguiente elemento en ser extraido de la pila.
// @param p CReferencia a la pila en la que se desempilará.
// Retorna el entero desencolado.

int desempilar(Pila *p){

    Nodo* l = p->tope;
    int res = 0;

    if (l){
        res = l->info;
        p->tope = l->sig;
        free(l);
        (p->longitud)--;
    }


    return res;

}

// Indica el numero de elementos de una pila.
// @param p Pila a verificar.

int longitud_pila(Pila p){
    return p.longitud;
}

// Muestra los elementos de una pila.
// @param p Pila a mostrar.

void mostrar_pila(Pila p){

    printf("\nn: %d \n", p.longitud);
    mostrar_lista(p.tope);
}

// En vista de la implementación sobre una lista de las pilas, deben liberarse
// todos sus elementos. Esta función libera de memeoria todos los elementos de la pila.
// @param p Pila a liberar

void liberar_pila(Pila *p){

    liberar_lista(&(p->tope));
    p->longitud = 0;
}

#endif // PILAS_H_INCLUDED
