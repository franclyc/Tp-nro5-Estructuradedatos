#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};

typedef struct tlista {
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista& lista) {
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo& nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(tlista& lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista& lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}

void QuitarInicio(tlista& lista) {
	if (lista.inicio == NULL) return;
	
	pnodo eliminado = lista.inicio;
	
	if (lista.inicio == lista.fin) {
		// Solo hay un nodo
		lista.inicio = NULL;
		lista.fin = NULL;
	} else {
		lista.inicio = lista.inicio->sig;
		lista.inicio->ant = NULL;
	}
	
	delete eliminado;
}

void QuitarFinal(tlista& lista) {
	if (lista.fin == NULL) return;
	
	pnodo eliminado = lista.fin;
	
	if (lista.inicio == lista.fin) {
		// Solo hay un nodo
		lista.inicio = NULL;
		lista.fin = NULL;
	} else {
		lista.fin = lista.fin->ant;
		lista.fin->sig = NULL;
	}
	
	delete eliminado;
}

void MostrarLista(tlista lista) {
	pnodo aux = lista.inicio;
	cout << "Lista: ";
	while (aux != NULL) {
		cout << aux->dato << " ";
		aux = aux->sig;
	}
	cout << endl;
}


int main() {
	tlista lista;
	IniciarLista(lista);
	
	int opcion, valor;
	pnodo nuevo;
	
	do {
		cout << "\n--- MENU LISTA DOBLE ---\n";
		cout << "1. Agregar al inicio\n";
		cout << "2. Agregar al final\n";
		cout << "3. Quitar del inicio\n";
		cout << "4. Quitar del final\n";
		cout << "5. Mostrar lista\n";
		cout << "0. Salir\n";
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarInicio(lista, nuevo);
			break;
		case 2:
			cout << "Ingrese valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarFinal(lista, nuevo);
			break;
		case 3:
			QuitarInicio(lista);
			cout << "Nodo del inicio eliminado.\n";
			break;
		case 4:
			QuitarFinal(lista);
			cout << "Nodo del final eliminado.\n";
			break;
		case 5:
			MostrarLista(lista);
			break;
		case 0:
			cout << "Saliendo del programa.\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
		
	} while (opcion != 0);
	
	return 0;
}