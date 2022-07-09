#include "utilidades.h"
#include "iostream"
#include "cassert"
#include "cstdlib"

void borrarNumerosPares (ListaEnlazada *lista) {
    int i=0;
    while (i<lista->getN()) {
        if (lista->getValor (i) % 2 == 0) {
            lista->eliminar (i);
        }else {
            i++;
        }
    }
}
void borrarPosicionesPares (ListaEnlazada *lista) {
    int i=0;
    while (i<lista->getN()) {
        if (i % 2 == 0) {
            lista->eliminar (i);
        }
        i++;
    }
}
