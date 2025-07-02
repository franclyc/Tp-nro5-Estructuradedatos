#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* siguiente;
	
public:
	Nodo(int valor) {
		dato = valor;
		siguiente = nullptr;
	}
	
	int getDato() {
		return dato;
	}
	
	void setDato(int valor) {
		dato = valor;
	}
	
	Nodo* getSiguiente() {
		return siguiente;
	}
	
	void setSiguiente(Nodo* nodo) {
		siguiente = nodo;
	}
};

class Lista {
private:
	Nodo* inicio;
	Nodo* final;
	int cantidad;
	
public:
	Lista() {
		inicio = nullptr;
		final = nullptr;
		cantidad = 0;
	}
	
	void agregarFinal(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (inicio == nullptr) {
			inicio = nuevo;
			final = nuevo;
		} else {
			final->setSiguiente(nuevo);
			final = nuevo;
		}
		cantidad++;
	}
	
	Nodo* eliminarInicio() {
		Nodo* borrado = nullptr;
		if (inicio != nullptr) {
			borrado = inicio;
			inicio = inicio->getSiguiente();
			borrado->setSiguiente(nullptr);
			
			if (inicio == nullptr) {
				final = nullptr;
			}
			
			cantidad--;
		}
		return borrado;
	}
	
	void mostrarLista() {
		Nodo* aux = inicio;
		while (aux != nullptr) {
			cout << aux->getDato() << " -> ";
			aux = aux->getSiguiente();
		}
		cout << "null" << endl;
	}
	
	int obtenerCantidad() {
		return cantidad;
	}
	
	int buscarIndice(int valor) {
		Nodo* aux = inicio;
		int indice = 0;
		
		while (aux != nullptr) {
			if (aux->getDato() == valor) {
				return indice;
			}
			aux = aux->getSiguiente();
			indice++;
		}
		return -1;
	}
	
	Nodo* buscarPorIndice(int indice) {
		if (indice < 0 || indice >= cantidad) {
			return nullptr;
		}
		
		Nodo* aux = inicio;
		int actual = 0;
		
		while (aux != nullptr && actual < indice) {
			aux = aux->getSiguiente();
			actual++;
		}
		
		return aux;
	}
};

int main() {
	Lista miLista;
	
	miLista.agregarFinal(10);
	miLista.agregarFinal(20);
	miLista.agregarFinal(30);
	miLista.agregarFinal(40);
	
	miLista.mostrarLista();
	
	int indice = miLista.buscarIndice(30);
	cout << "indice del valor 30: " << indice << endl;
	
	Nodo* resultado = miLista.buscarPorIndice(2);
	if (resultado != nullptr) {
		cout << "Elemento en índice 2: " << resultado->getDato() << endl;
	} else {
		cout << "indice fuera de rango" << endl;
	}
	
	return 0;
}