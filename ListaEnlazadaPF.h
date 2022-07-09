#pragma once // Esta directiva evita que se incluya por error este archivo m�s de una vez en el main
#include "nodo.h"


class ListaEnlazadaPF
{
private:
	
	
    Nodo* primero;
    Nodo* ultimo;
    int n;
    
    Nodo* getNodo(int posicion);

public:

	ListaEnlazadaPF();

    int getValor(int posicion);
    void setValor(int posicion, int nuevoValor);
    int getN(); 
	void insertar(int posicion, int nuevoValor);
	void eliminar(int posicion);
	~ListaEnlazadaPF();

};





