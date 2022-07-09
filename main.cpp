#include "iostream"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"

using namespace std;



int main() {

	ListaEnlazada lista;

	cout << "Nueva ListaEnlazada creada:\n";
	imprimirListaEnlazada(&lista);

	cout << "Rellenando ListaEnlazada:\n";
	for (int i = 0; i <= 11; i++) {
		lista.insertar(lista.getN(),i); // Introducimos el nuevo elemento
		imprimirListaEnlazada(&lista);
	}
	cout << "Elemento0=" << lista.getValor(0) << "|Elemento11=" << lista.getValor(11) << endl;

	cout << "Cambio elemento 4 por 50. Nueva ListaEnlazada:\n";
	lista.setValor(4, 50);
	imprimirListaEnlazada(&lista);

	// Borramos los ultimos cuatro elementos
	for (int i = 0; i < 4; i++) {
		cout << "Borramos el ultimo elemento. Nueva ListaEnlazada:\n";
		lista.eliminar(lista.getN()-1);
		imprimirListaEnlazada(&lista);
	}

	// Insertamos 100, 101, 102 y 103 al final
	for (int i = 100; i <= 103; i++) {
		cout << "Insertamos " << i << " al final. Nueva ListaEnlazada:\n";
		lista.insertar(lista.getN(),i);
		imprimirListaEnlazada(&lista);
	}
	return 0;
}


