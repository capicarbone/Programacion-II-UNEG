#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "../Listas/listas.h"

typedef struct PILA {
    Nodo* tope;
    int longitud;
} Pila;

int pila_vacia(Pila p){

    return (!p.tope);
}

void inicializar_pila( Pila *p){

    p->tope = NULL;
    p->longitud = 0;
}

void empilar( Pila *p , int n){

    insertar_tope_m( &(p->tope), n );
    (p->longitud)++;

}

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

int longitud_pila(Pila p){
    return p.longitud;
}

void mostrar_pila(Pila p){

    printf("\nn: %d \n", p.longitud);
    mostrar_lista(p.tope);
}

void liberar_pila(Pila *p){

    liberar_lista(&(p->tope));
    p->longitud = 0;
}

#endif // PILAS_H_INCLUDED
