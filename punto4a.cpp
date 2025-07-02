#include<iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Pila {
    Nodo* tope;
};

void initStack(Pila &p);
bool isEmptyStack(Pila p);
void pushStack(Pila &p, int valor);
int popStack(Pila &p);
int topStack(Pila p);
void mostrarPila(Pila p);

int main() {
    Pila pila;
    initStack(pila);

    int opcion, valor;

    do {
        cout << "\n--- MENU PILA (Dinámica) ---" << endl;
        cout << "1. Insertar (Push)" << endl;
        cout << "2. Eliminar (Pop)" << endl;
        cout << "3. Ver tope" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                pushStack(pila, valor);
                break;
            case 2:
                cout << "Elemento eliminado: " << popStack(pila) << endl;
                break;
            case 3:
                cout << "Tope de la pila: " << topStack(pila) << endl;
                break;
            case 4:
                mostrarPila(pila);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while(opcion != 0);
    return 0;
}

void initStack(Pila &p) {
    p.tope = nullptr;
}

bool isEmptyStack(Pila p) {
    return p.tope == nullptr;
}

void pushStack(Pila &p, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = p.tope;
    p.tope = nuevo;
}

int popStack(Pila &p) {
    if (!isEmptyStack(p)) {
        Nodo* temp = p.tope;
        int valor = temp->dato;
        p.tope = temp->siguiente;
        delete temp;
        return valor;
    } else {
        cout << "Pila vacía, no se puede eliminar." << endl;
        return -1;
    }
}

int topStack(Pila p) {
    if (!isEmptyStack(p)) {
        return p.tope->dato;
    } else {
        cout << "Pila vacía." << endl;
        return -1;
    }
}

void mostrarPila(Pila p) {
    if (isEmptyStack(p)) {
        cout << "Pila vacía." << endl;
    } else {
        cout << "Contenido de la pila: ";
        Nodo* actual = p.tope;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
}