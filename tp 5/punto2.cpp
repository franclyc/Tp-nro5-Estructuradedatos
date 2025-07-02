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
};

int main() {
    Lista miLista;

    miLista.agregarFinal(5);
    miLista.agregarFinal(10);
    miLista.agregarFinal(3);

    miLista.mostrarLista();
    cout << "Cantidad de elementos: " << miLista.obtenerCantidad() << endl;

    Nodo* eliminado = miLista.eliminarInicio();
    if (eliminado != nullptr) {
        delete eliminado; // liberar memoria
    }

    miLista.mostrarLista();
    cout << "Cantidad de elementos: " << miLista.obtenerCantidad() << endl;

    return 0;
}
