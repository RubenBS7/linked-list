#include "ListaEnlazada.h"
#include "cassert"
#include "cstdlib"
#include "iostream"

using namespace std;

Nodo* ListaEnlazada::getNodo(int posicion) {
    Nodo* paux;

    paux=primero;
    for (int i=0; i<posicion;i++) {
        paux=paux->sig;
    }
    return paux;
}


ListaEnlazada::ListaEnlazada() {
    primero = NULL;
    ultimo = NULL;
    n=0;
}

int ListaEnlazada::getValor(int posicion) {
    assert(posicion >= 0 && posicion <= n-1);
    
    Nodo *paux;
    paux = getNodo (posicion);
    return paux->info;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor) {
    assert(posicion >= 0 && posicion <= n-1);
    Nodo *paux;
    paux = getNodo (posicion);
    paux->info = nuevoValor;
}


int ListaEnlazada::getN() {
    return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor) {
    assert(posicion >= 0 && posicion <= n);
    Nodo *nuevo = (Nodo*) malloc (sizeof (Nodo));
    nuevo->info = nuevoValor;
    

    if (primero==NULL) { //Caso especial de lista vacia
        nuevo->sig=NULL;
        primero = nuevo;
        ultimo = nuevo;
    }else if (posicion==0) { //No es vacia y queremos insertar al principio
        nuevo->sig=primero;
        primero = nuevo;
    }else if (posicion==n) { //No es vacia y queremos insertar al final
        nuevo->sig=NULL;
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }else { //No es vacia y no queremos insertar ni al principio ni al final
        Nodo *nodoSig = getNodo (posicion);
        Nodo *nodoAnt = getNodo (posicion-1);
        nodoAnt->sig=nuevo;
        nuevo->sig=nodoSig;
    }

    n++;
}




void ListaEnlazada::eliminar(int posicion) {
    assert(posicion >= 0 && posicion <= n-1);
    Nodo *nodoToRemove;
    if (posicion==0) { //Eliminar el primero
        nodoToRemove = primero;
        primero = primero->sig;
        if (primero==NULL) {
            ultimo = NULL;
        }
    }else {
        nodoToRemove = getNodo (posicion);
        Nodo *nodoAnt = getNodo (posicion-1);
        nodoAnt->sig = nodoToRemove->sig;
        if (nodoAnt->sig==NULL) {
            ultimo = nodoAnt;
        }
    }
    free (nodoToRemove);
    n--;
}

ListaEnlazada::~ListaEnlazada() {
    while (n!=0) {
        eliminar (0);
    }
}
