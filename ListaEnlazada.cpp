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
    }else if (posicion==0) { //No es vacia y queremos insertar al principio
        nuevo->sig=primero;
        primero = nuevo;
    }else if (posicion==n) { //No es vacia y queremos insertar al final
        nuevo->sig=NULL;
        Nodo *paux = getNodo (n-1);
        paux->sig = nuevo;
    }else { //No es vacia y no queremos insertar ni al principio ni al final
        Nodo *nodoSig = getNodo (posicion);
        Nodo *nodoAnt = getNodo (posicion-1);
        nodoAnt->sig=nuevo;
        nuevo->sig=nodoSig;
    }

    n++;
}

void ListaEnlazada::eliminar(int posicion=10) {
    assert (posicion>=0 && posicion <=n-1);

    if (posicion==0) { //No es vacia y queremos insertar al principio
        Nodo *paux = getNodo (posicion);
        primero = primero->sig; //primero = paux->sig;
        free (paux);
    }else { //No es vacia y no queremos insertar ni al principio ni al final
        Nodo *paux = getNodo (posicion);
        Nodo *pant = getNodo (posicion-1);
        pant->sig = paux->sig;
        free (paux);
    }
    n--;
}

ListaEnlazada::~ListaEnlazada() {
    while (n>0) { //Mientras tengas elementos
        eliminar (0);
    }
}


int ListaEnlazada::buscarPosicion (int elemento) {
    bool encontrado = false;
    int posicion = 0;

    if (n==0) {
        return -1;
    }

    Nodo *paux = getNodo (posicion);

    while ((posicion<n) && (!encontrado)) {
        if (paux->info==elemento) {
            encontrado = true;
        }else {
            posicion++;
            paux=paux->sig;
        }
    }

    if (encontrado) {
        return posicion;
    }else {
        return -1;
    }
}


int ListaEnlazada::buscarPosicionV2 (int elemento) {
    int posicion = 0;

    if (n==0) {
        return -1;
    }

    Nodo *paux = getNodo (posicion);

    while (posicion<n) {
        if (paux->info==elemento) {
            return posicion;
        }else {
            posicion++;
            paux=paux->sig;
        }
    }

    return -1;
}




void ListaEnlazada::concatenar (ListaEnlazada l2) {
    for (int i=0; i<l2.getN(); i++) {
        int valor = l2.getValor (i);
        this->insertar (this->getN(), valor);
    }
}