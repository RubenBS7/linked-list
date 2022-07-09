#pragma once // Esta directiva evita que se incluya por error este archivo m�s de una vez en el main
#include "nodo.h"


class ListaEnlazada
{
private:
	
	
    Nodo* primero;
    int n;
    
    Nodo* getNodo(int posicion);

public:

	ListaEnlazada();

    int getValor(int posicion);
    void setValor(int posicion, int nuevoValor);
    int getN(); 
	void insertar(int posicion, int nuevoValor);
	void eliminar(int posicion);
	~ListaEnlazada();

	//Nuevas funciones
	int buscarPosicion (int elemento);
	int buscarPosicionV2 (int elemento);

	void concatenar (ListaEnlazada l2);
};





