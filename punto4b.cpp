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

class Cola {
private:
    Nodo* frente;
    Nodo* final;
    int cantidad;

public:
    Cola() {
        frente = nullptr;
        final = nullptr;
        cantidad = 0;
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    void agregar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            frente = final = nuevo;
        } else {
            final->setSiguiente(nuevo);
            final = nuevo;
        }
        cantidad++;
    }

    int quitar() {
        if (estaVacia()) {
            cout << "La cola está vacía.\n";
            return -999;
        }

        Nodo* borrado = frente;
        int valor = borrado->getDato();
        frente = frente->getSiguiente();
        if (frente == nullptr) {
            final = nullptr;
        }
        delete borrado;
        cantidad--;
        return valor;
    }

    int verFrente() const {
        if (!estaVacia())
            return frente->getDato();
        else {
            cout << "Cola vacía.\n";
            return -999;
        }
    }

    int verFinal() const {
        if (!estaVacia())
            return final->getDato();
        else {
            cout << "Cola vacía.\n";
            return -999;
        }
    }

    int obtenerCantidad() const {
        return cantidad;
    }

    void mostrar() const {
        if (estaVacia()) {
            cout << "Cola vacía.\n";
            return;
        }

        Nodo* aux = frente;
        cout << "Contenido de la cola (frente → final): ";
        while (aux != nullptr) {
            cout << aux->getDato() << " ";
            aux = aux->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Cola c;
    int opcion, valor;

    do {
        cout << "\n---  MENÚ COLA DINÁMICA (OOP) ---\n"
             << "1. Insertar \n"
             << "2. Extraer \n"
             << "3. Ver frente\n"
             << "4. Ver final\n"
             << "5. Mostrar cola\n"
             << "6. Cantidad de elementos\n"
             << "0. Salir\n"
             << "Seleccione una opción: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                c.agregar(valor);
                break;
            case 2:
                cout << "Extraído: " << c.quitar() << endl;
                break;
            case 3:
                cout << "Frente: " << c.verFrente() << endl;
                break;
            case 4:
                cout << "Final: " << c.verFinal() << endl;
                break;
            case 5:
                c.mostrar();
                break;
            case 6:
                cout << "Elementos en la cola: " << c.obtenerCantidad() << endl;
                break;
            case 0:
                cout << "Hasta luego.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}


