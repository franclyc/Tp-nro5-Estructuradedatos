#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class ListaDoble {
private:
    Nodo* inicio;

public:
    ListaDoble() {
        inicio = nullptr;
    }

    void agregarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            nuevo->siguiente = inicio;
            inicio->anterior = nuevo;
            inicio = nuevo;
        }
    }

    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Nodo* aux = inicio;
            while (aux->siguiente != nullptr) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }

    void agregarOrdenado(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (inicio == nullptr || inicio->dato >= valor) {
            nuevo->siguiente = inicio;
            if (inicio != nullptr) {
                inicio->anterior = nuevo;
            }
            inicio = nuevo;
        } else {
            Nodo* aux = inicio;
            while (aux->siguiente != nullptr && aux->siguiente->dato < valor) {
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            if (aux->siguiente != nullptr) {
                aux->siguiente->anterior = nuevo;
            }
            aux->siguiente = nuevo;
            nuevo->anterior = aux;
        }
    }

    void quitarInicio() {
        if (inicio == nullptr) return;
        Nodo* eliminado = inicio;
        inicio = inicio->siguiente;
        if (inicio != nullptr) inicio->anterior = nullptr;
        delete eliminado;
    }

    void quitarFinal() {
        if (inicio == nullptr) return;
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr)
            aux = aux->siguiente;
        if (aux->anterior != nullptr)
            aux->anterior->siguiente = nullptr;
        else
            inicio = nullptr;
        delete aux;
    }

    void quitarNodo(int valor) {
        Nodo* aux = inicio;
        while (aux != nullptr && aux->dato != valor)
            aux = aux->siguiente;
        if (aux == nullptr) return;
        if (aux->anterior != nullptr) aux->anterior->siguiente = aux->siguiente;
        else inicio = aux->siguiente;
        if (aux->siguiente != nullptr) aux->siguiente->anterior = aux->anterior;
        delete aux;
    }

    bool buscar(int valor) {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            if (aux->dato == valor) return true;
            aux = aux->siguiente;
        }
        return false;
    }

    void mostrar() {
        Nodo* aux = inicio;
        while (aux != nullptr) {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
};