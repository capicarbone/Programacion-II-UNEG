#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#include "../Listas/listas.h"

typedef struct COLA{
    Nodo* ultimo;
    Nodo* siguiente;
    int longitud;
} Cola;

void inicializar_cola(Cola *c){

    c->ultimo = NULL;
    c->siguiente = NULL;
    c->longitud = 0;
}

int cola_vacia(Cola c){

    return (!c.siguiente );
}

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

void longitud_cola(Cola c){
    return c.longitud;
}

void liberar_cola(Cola *c){

    liberar_lista( &(c->siguiente));
    c->ultimo = NULL;
    c->longitud = 0;
}

void mostrar_cola(Cola c){

    printf("\nn: %d \n", c.longitud);
    mostrar_lista(c.siguiente);
}


#endif // COLAS_H_INCLUDED
