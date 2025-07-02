#include <iostream>
using namespace std;

class NodoChar {
private:
    char dato;
    NodoChar* sig;
public:
    NodoChar(char dato) {
        this->dato = dato;
        this->sig = nullptr;
    }

    char getDato() {
        return dato;
    }

    NodoChar* getSiguiente() {
        return sig;
    }

    void setSiguiente(NodoChar* nuevo) {
        sig = nuevo;
    }
};

class ListaChar {
private:
    NodoChar* inicio;
    int cant;
public:
    ListaChar() {
        inicio = nullptr;
        cant = 0;
    }

    bool estaVacia() {
        return inicio == nullptr;
    }

    void AgregarFinal(NodoChar* nuevo) {
        if (estaVacia()) {
            inicio = nuevo;
        } else {
            NodoChar* i = inicio;
            while (i->getSiguiente() != nullptr) {
                i = i->getSiguiente();
            }
            i->setSiguiente(nuevo);
        }
        cant++;
    }

    void MostrarLista() {
        if (estaVacia()) {
            cout << "Lista vacía." << endl;
        } else {
            NodoChar* i = inicio;
            cout << "Contenido de la lista: ";
            while (i != nullptr) {
                cout << i->getDato() << " ";
                i = i->getSiguiente();
            }
            cout << endl;
        }
    }

    NodoChar* getInicio() {
        return inicio;
    }
};
