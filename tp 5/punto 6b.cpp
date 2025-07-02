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


void contarMayusMinus(ListaChar& lista, int& mayus, int& minus) {
    mayus = minus = 0;
    NodoChar* actual = lista.getInicio();
    while (actual != nullptr) {
        char c = actual->getDato();
        if (isupper(c)) {
            mayus++;
        } else if (islower(c)) {
            minus++;
        }
        actual = actual->getSiguiente();
    }
}


void menu() {
    ListaChar lista;
    int opcion;
    char caracter;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar caracter a la lista\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Contar mayusculas y minusculas\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un caracter: ";
                cin >> caracter;
                lista.AgregarFinal(new NodoChar(caracter));
                cout << "Caracter agregado.\n";
                break;

            case 2:
                lista.MostrarLista();
                break;

            case 3: {
                int mayus, minus;
                contarMayusMinus(lista, mayus, minus);
                cout << "Cantidad de mayusculas: " << mayus << endl;
                cout << "Cantidad de minusculas: " << minus << endl;
                break;
            }

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}
