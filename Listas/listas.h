
/*
    Librería para el manejo de listas simples enlazadas.
    Creado para prácticas en las preparadurías de Programación II, UNEG.

    Autor: Carlos Pinelly - cpinelly@gmail.com - @capicp
    Version: 1.0
    Liberado: 25/06/2013
*/

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>

// Tipo de dato para un nodo. Se define una estructura que corresponde a un nodo
// para el manejo de listas de enteros. Para menejar listas de otros tipos
// sólo debe cambiarse el tipo de dato del campo info.

typedef struct NODO{
    int info;
    struct NODO* sig;
} Nodo;

// Crea un nodo introduciéndole la información especificada.
// @param n Entero que contendrá el nodo.

Nodo* crear_nodo(int n){

    // Se realiza la petición de memoría para almacenar un Nodo.
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));

    // Se rellena el Nodo
    nuevo->info = n;
    nuevo->sig = NULL;

    return nuevo;

}

// Inserción de un nodo en el tope de la lista, pasando a ser el nuevo elemento
// la cabezera de la lista.
// @param lista Apuntador al primer elemento de la lista.
// @param n Información a insertarse
// Retorna la nueva cabezera de la lista.

Nodo* insertar_tope(Nodo* lista, int n){

    // Se crea el nodo con el entero especificado.
    Nodo* nuevo = crear_nodo(n);

    // El siguiente de este nodo será el resto de la lista.
    nuevo->sig = lista;

    // El nuevo elemento será necesariamente la nueva cabecera de la lista.
    return nuevo;

}

// Implementaciónde insertar_tope, con el uso de doble apuntadores, es decir,
// se recibe un apuntador por referencia. Revisese la llamada en el archivo main.c
// @param lista Referencia al apuntador del primer elemento de la lista.
// @int n Información a insertarse

void insertar_tope_m(Nodo** lista, int n){

    // Se crea el nodo para el nuevo elemento
    Nodo* nuevo = crear_nodo(n);

    // Al nuevo nodo se le asigna el resto de la lista
    nuevo->sig = *lista;

    // La cabecera de la lista ahora es el nuevo elemento.
    *lista = nuevo;
}

// Inserción de un elemento en una lista al final de esta, es decir, en su cola.
// @param lista Apuntador al primer elemento de la lista
// @param n Información a insertarse
// Retorna la nueva cabezera de la lista.

Nodo* insertar_cola(Nodo* lista, int n){

    // Se crea un nodo para la nueva información a insetar.
    Nodo* nuevo = crear_nodo(n);

    // En este caso es necesario una variable auxiliar para el desplazamiento en la lista
    // ya que la cabezera se requerirá luego
    Nodo* aux = lista;


    // Desplazamiento en la lista para buscar el último nodo de esta
    while( aux && aux->sig ){
        aux = aux->sig;
    }

    // Si la lista tiene elementos, entonces se inserta el nuevo elemento en el último de la lista.
    // En este caso la cabecera no cambia y se devuelve el mismo apuntador que se recibió.
    if (lista){
        aux->sig = nuevo;
        return lista;
    }else
        // Si la lista se recibe vacía, entonces la nueva cabecera será el nuevo elemento.
        return nuevo;


}

// Número de nodos de la lista recibida
// @param lista Apuntador al primer elemento de la lista
// Retorna número de nodos.

int longitud(Nodo* lista){

    int i;

    for( i= 0; lista; i++, lista = lista->sig);

    return i;
}

// Elimina un nodo de la lista dada una posición. Si no existe, no borra nodo alguno.
// @param lista Apuntador al primer elemento de la lista
// @param pos Posición del nodo a eliminar

void borrar_nodo(Nodo** lista, int pos ){

    int i;
    Nodo* actual = NULL;
    Nodo* aux = NULL;

    if (pos == 0){
        aux = (*lista)->sig;
        free(*lista);
        (*lista) = aux;
        return;
    }

    actual = *lista;

    for (i = 0; i < pos && actual; i++, actual = actual->sig ){

        if ( actual->sig && i == pos-1){
            aux = actual->sig->sig;
            free(actual->sig);
            actual->sig = aux;
        }
    }

}

// Recorre una lista mostrando cada uno de sus elementos.
// @param lista Apuntador al primer nodo de la lista

void mostrar_lista(Nodo* lista){

    while( lista ){
        // Se imprime el elemento de la lista.
        printf("%d", lista->info);

        // Desplazamiento al siguiente elemento
        lista = lista->sig;

        // Si hay un siguiente elemento se imprime una flecha para representar la referencia
        if (lista)
            printf(" -> ");
    }

    printf("\n");
}

// Libera la memoria que ocupa cada uno de los elementos de una lista.
// Esta implementación se realiza con recursividad y con el uso de doble apuntador, es decir,
// se recibe el apuntador al primer nodo de la lista por referencia.
// @param lista Referencia al apuntador del primer nodo de la lista.

void liberar_lista(Nodo** lista){

    if (*lista){
        // Llamada recursiva. Sólo puede liberarse el nodo actual si se ha liberado su siguiente.
        // Si se libera el actual antes, se perdería la referencia al siguiente y con ello al resto de la lista
        liberar_lista( &((*lista)->sig) );

        // Se libera el nodo actual
        free(*lista);

        // Por seguridad, se asigna NULL al apuntador actual.
        *lista = NULL;
    }
}



#endif // LISTAS_H_INCLUDED
