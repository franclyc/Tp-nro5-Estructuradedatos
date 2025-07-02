#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* siguiente;

public:
    explicit Nodo(int valor) : dato(valor), siguiente(nullptr) {}

    int  getDato() const        { return dato; }
    void setDato(int valor)     { dato = valor; }

    Nodo* getSiguiente() const  { return siguiente; }
    void  setSiguiente(Nodo* p) { siguiente = p; }
};

class Lista {
private:
    Nodo* inicio;

public:
    Lista() : inicio(nullptr) {}
    
    ~Lista() {
        while (inicio != nullptr) {
            Nodo* aux = inicio;
            inicio = inicio->getSiguiente();
            delete aux;
        }
    }

    bool estaVacia() const { return inicio == nullptr; }

    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            inicio = nuevo;
        } else {
            Nodo* aux = inicio;
            while (aux->getSiguiente() != nullptr)
                aux = aux->getSiguiente();
            aux->setSiguiente(nuevo);
        }
    }

    void mostrar() const {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            cout << aux->getDato() << " -> ";
            aux = aux->getSiguiente();
        }
        cout << "null" << endl;
    }

    int minimo() const {
        if (estaVacia()) {
            cout << "Lista vacía" << endl;
            return -1;
        }
        int min = inicio->getDato();
        Nodo* aux = inicio->getSiguiente();
        while (aux != nullptr) {
            if (aux->getDato() < min)
                min = aux->getDato();
            aux = aux->getSiguiente();
        }
        return min;
    }
};

int main() {
    Lista lista;

    lista.agregarFinal(7);
    lista.agregarFinal(3);
    lista.agregarFinal(9);
    lista.agregarFinal(1);

    lista.mostrar();
    cout << "Mínimo: " << lista.minimo() << endl;

    return 0;
}
