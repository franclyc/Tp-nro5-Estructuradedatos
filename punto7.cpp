#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* sig;
public:
    Nodo(int dato) {
        this->dato = dato;
        this->sig = nullptr;
    }

    int getDato() {
        return dato;
    }

    Nodo* getSiguiente() {
        return sig;
    }

    void setSiguiente(Nodo* nuevo) {
        sig = nuevo;
    }
};

class Lista {
private:
    Nodo* inicio;
    int cant;
public:
    Lista() {
        inicio = nullptr;
        cant = 0;
    }

    bool estaVacia() {
        return inicio == nullptr;
    }

    void AgregarOrdenado(Nodo* nuevo) {
        if (estaVacia()) {
            inicio = nuevo;
        }
        else {
            if (nuevo->getDato() < inicio->getDato()) {
                nuevo->setSiguiente(inicio);
                inicio = nuevo;
            }
            else {
                Nodo* i = inicio;
                while (i->getSiguiente() != nullptr && i->getSiguiente()->getDato() < nuevo->getDato()) {
                    i = i->getSiguiente();
                }
                nuevo->setSiguiente(i->getSiguiente());
                i->setSiguiente(nuevo);
            }
        }
        cant++;
    }

    void MostrarLista() {
        if (estaVacia()) {
            cout << "Lista vacía" << endl;
        }
        else {
            Nodo* i = inicio;
            while (i != nullptr) {
                cout << i->getDato() << " ";
                i = i->getSiguiente();
            }
            cout << endl;
        }
    }

    Nodo* getInicio() {
        return inicio;
    }
};

void enigma(Nodo* nodo) {
    if (nodo != nullptr) {
        if (nodo->getSiguiente() == nullptr)
            cout << nodo->getDato() << endl;
        else {
            enigma(nodo->getSiguiente());
            cout << nodo->getDato() << endl;
        }
    }
}

int misterio(Nodo* nodo) {
    if (nodo == nullptr)
        return 0;
    else
        return misterio(nodo->getSiguiente()) + 1;
}

int main() {
    Lista lista;
    lista.AgregarOrdenado(new Nodo(6));
    lista.AgregarOrdenado(new Nodo(4));
    lista.AgregarOrdenado(new Nodo(9));
    lista.AgregarOrdenado(new Nodo(5));
    lista.AgregarOrdenado(new Nodo(8));

    cout << "Lista normal (ordenada):" << endl;
    lista.MostrarLista();

    cout << "\nOrden inverso :" << endl;
    enigma(lista.getInicio());

    cout << "\nCantidad de nodos : ";
    cout << misterio(lista.getInicio()) << endl;

    return 0;
}
