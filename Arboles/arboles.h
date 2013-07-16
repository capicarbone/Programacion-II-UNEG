
/*
    Librería para el manejo de árboles binarios.
    Creado para prácticas en las preparadurías de Programación II, UNEG.

    Autor: Carlos Pinelly - cpinelly@gmail.com - @capicp
    Version: 1.0
    Liberado: 16/07/2013
*/


#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "../Listas/listas.h"



// Tipo de dato para el nodo de ábol binario. En un nodo bonario
// cada nodo posee máximo dos hijos. Al igual que en una lista
// se declaran referencias recursivas a otros nodos.

typedef struct NODOARBOL {

    int info;
    struct NODOARBOL* izq;
    struct NODOARBOL* der;
} NodoArbol;

// Crea un nodo para un ábol colocándole información e inicializando sus referencias.
// @param n Información a introducir.
// Retorna el nodo de un árbol inicializado.

NodoArbol* crear_nodo_arbol(int n){

    NodoArbol* nodo = (NodoArbol*) malloc(sizeof(NodoArbol));
    nodo->info = n;
    nodo->der = NULL;
    nodo->izq = NULL;

}

// Realiza la inserción de un nodo en árbol de forma ordenada.
// @param n Información a introducir en el árbol.
// @param raiz Nodo raíz de árbol sobre el que se introducirá el nuevo elemento.
// Retorna el nodo raíz del arbol.

NodoArbol* insertar_ordenado(int n, NodoArbol* raiz){

    if (raiz){

        if ( raiz->info >= n )
            raiz->izq = insertar_ordenado(n, raiz->izq);
        else
            raiz->der = insertar_ordenado(n, raiz->der);

    }else{
        raiz = crear_nodo_arbol(n);
    }

    return raiz;

}

// Muestra un árbol en recorrido in-orden.
// @param raiz Nodo raíz de árbol que se recorerá.

void mostrar_inorden(NodoArbol* raiz){

    if (raiz){
        mostrar_inorden(raiz->izq);
        printf("%d ", raiz->info);
        mostrar_inorden(raiz->der);
    }
}

// Muestra un árbol en recorrido post-orden.
// @param raiz Nodo raíz de árbol que se recorerá.

void mostrar_postorden(NodoArbol* raiz){

    if (raiz){
        mostrar_postorden(raiz->izq);
        mostrar_postorden(raiz->der);
        printf("%d ", raiz->info);
    }
}

// Muestra un árbol en recorrido pre-orden.
// @param raiz Nodo raíz de árbol que se recorerá.

void mostrar_preorden(NodoArbol* raiz){

    if (raiz){
        printf("%d ", raiz->info);
        mostrar_preorden(raiz->izq);
        mostrar_preorden(raiz->der);
    }
}

/*
void mostrar_arbol(NodoArbol* raiz, int prd,  Nodo* l ){

    int i = 0;
    Nodo *aux = NULL;

    if (raiz){

        l = insertar_cola(l, 0);

        //mostrar_lista(l);

        printf("|- ");
        printf("%d\n", raiz->info);

        prd++;

        if (raiz->izq){

            aux = l;

            while(aux){


                if (aux->info == 0)
                    printf("|   ");
                else
                    printf("   ");

                aux = aux->sig;
            }
            mostrar_arbol(raiz->izq, prd, l);
        }

        borrar_nodo(&l, longitud(l)-1);
        l = insertar_cola(l, 1);

        if (raiz->der){

            while(aux){
                if (aux->info == 0)
                    printf("|  ");
                else
                    printf("   ");

                aux = aux->sig;
            }

            mostrar_arbol(raiz->der, prd, l);
        }


        borrar_nodo(&l, longitud(l)-1);
        l = insertar_cola(l, 1);

    }

} */

#endif // ARBOLES_H_INCLUDED
