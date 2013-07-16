#include "arboles.h"

main(){
    NodoArbol* raiz;

    raiz = insertar_ordenado(104, raiz);
    raiz = insertar_ordenado(5, raiz);
    raiz = insertar_ordenado(3, raiz);
    raiz = insertar_ordenado(2, raiz);
    raiz = insertar_ordenado(10, raiz);
    raiz = insertar_ordenado(22, raiz);
    raiz = insertar_ordenado(87, raiz);

    printf("\npreorden: ");
    mostrar_preorden(raiz);

    printf("\ninorden: ");
    mostrar_inorden(raiz);

    printf("\npostorden: ");
    mostrar_postorden(raiz);

}
