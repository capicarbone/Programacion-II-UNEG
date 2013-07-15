#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include "../Listas/listas.h"

typedef struct NODOARBOL {

    int info;
    struct NODOARBOL* izq;
    struct NODOARBOL* der;
} NodoArbol;

NodoArbol* crear_nodo_arbol(int n){

    NodoArbol* nodo = (NodoArbol*) malloc(sizeof(NodoArbol));
    nodo->info = n;
    nodo->der = NULL;
    nodo->izq = NULL;

}

NodoArbol* insertar_ordenado(int n, NodoArbol* raiz){

    if (raiz){

        if ( raiz->info >= n )
            raiz->der = insertar_ordenado(n, raiz->der);
        else
            raiz->izq = insertar_ordenado(n, raiz->izq);

    }else{
        raiz = crear_nodo_arbol(n);
    }

    return raiz;

}

void espacios(int n){

    int i;
    for (i = 0; i < n ; i++)
                printf(" ");
}

void mostrar_arbol(NodoArbol* raiz, int prd,  Nodo* l ){

    int i = 0;

    l = insetar_cola(l, 0);

    if (raiz){

        printf("|- ", 195);
        printf("%d\n", raiz->info);

        prd++;

        if (raiz->izq){
            espacios(prd*3);
            mostrar_arbol(raiz->izq, prd);
        }

        if (raiz->der){
            espacios(prd*3);
            mostrar_arbol(raiz->der, prd);
        }

    }

}

#endif // ARBOLES_H_INCLUDED
