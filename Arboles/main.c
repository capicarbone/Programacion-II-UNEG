#include "arboles.h"

main(){
    NodoArbol* raiz;

    raiz = insertar_ordenado(5, raiz);
    raiz = insertar_ordenado(3, raiz);
    raiz = insertar_ordenado(2, raiz);
    raiz = insertar_ordenado(6, raiz);
    raiz = insertar_ordenado(10, raiz);
    raiz = insertar_ordenado(11, raiz);
    raiz = insertar_ordenado(1, raiz);
    raiz = insertar_ordenado(5, raiz);
    raiz = insertar_ordenado(4, raiz);

    mostrar_arbol(raiz, 0);
}
