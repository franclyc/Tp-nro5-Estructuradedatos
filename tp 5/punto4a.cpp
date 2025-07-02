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

    Nodo* getSiguiente() {
        return siguiente;
    }

    void setSiguiente(Nodo* nodo) {
        siguiente = nodo;
    }
};

class Pila {
private:
    Nodo* tope;

public:
    Pila() {
        tope = nullptr;
    }

    bool estaVacia() {
        return tope == nullptr;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->setSiguiente(tope);
        tope = nuevo;
    }

    int pop() {
        if (!estaVacia()) {
            Nodo* temp = tope;
            int valor = temp->getDato();
            tope = temp->getSiguiente();
            delete temp;
            return valor;
        } else {
            cout << "Pila vacía, no se puede eliminar." << endl;
            return -1;
        }
    }

    int obtenerTope() {
        if (!estaVacia()) {
            return tope->getDato();
        } else {
            cout << "Pila vacía." << endl;
            return -1;
        }
    }

    void mostrarPila() {
        if (estaVacia()) {
            cout << "Pila vacía." << endl;
        } else {
            cout << "Contenido de la pila: ";
            Nodo* actual = tope;
            while (actual != nullptr) {
                cout << actual->getDato() << " ";
                actual = actual->getSiguiente();
            }
            cout << endl;
        }
    }
};

int main() {
    Pila pila;
    int opcion, valor;

    do {
        cout << "\n--- MENU PILA (Dinámica, OOP) ---" << endl;
        cout << "1. Insertar (Push)" << endl;
        cout << "2. Eliminar (Pop)" << endl;
        cout << "3. Ver tope" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                pila.push(valor);
                break;
            case 2:
                cout << "Elemento eliminado: " << pila.pop() << endl;
                break;
            case 3:
                cout << "Tope de la pila: " << pila.obtenerTope() << endl;
                break;
            case 4:
                pila.mostrarPila();
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
