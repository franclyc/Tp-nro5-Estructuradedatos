#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

class Lista {
private:
	Nodo* cabeza;
	
public:
	Lista() {
		cabeza = nullptr;
	}
	
	void agregar(int valor) {
		Nodo* nuevo = new Nodo;
		nuevo->dato = valor;
		nuevo->siguiente = cabeza;
		cabeza = nuevo;
	}
	
	void mostrar() {
		Nodo* actual = cabeza;
		if (actual == nullptr) {
			cout << "La lista está vacía." << endl;
			return;
		}
		cout << "Contenido de la lista: ";
		while (actual != nullptr) {
			cout << actual->dato << " ";
			actual = actual->siguiente;
		}
		cout << endl;
	}
	
	Nodo* getCabeza() {
		return cabeza;
	}
};
bool esPrimo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int contarPrimos(Lista& lista) {
	int contador = 0;
	Nodo* actual = lista.getCabeza();
	while (actual != nullptr) {
		if (esPrimo(actual->dato)) {
			contador++;
		}
		actual = actual->siguiente;
	}
	return contador;
}


void menu() {
	Lista lista;
	int opcion;
	int numero;
	
	do {
		cout << "\n--- MENU ---\n";
		cout << "1. Agregar numero a la lista\n";
		cout << "2. Mostrar lista\n";
		cout << "3. Contar numeros primos\n";
		cout << "0. Salir\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese un numero entero: ";
			cin >> numero;
			lista.agregar(numero);
			cout << "Numero agregado.\n";
			break;
			
		case 2:
			lista.mostrar();
			break;
			
		case 3: {
			int totalPrimos = contarPrimos(lista);
			cout << "Cantidad de numeros primos en la lista: " << totalPrimos << endl;
			break;
		}
		
		case 0:
			cout << "Saliendo del programa...\n";
			break;
			
		default:
			cout << "Opcion no valida. Intente de nuevo.\n";
		}
		
	} while (opcion != 0);
}

int main() {
	menu();
	return 0;
}
