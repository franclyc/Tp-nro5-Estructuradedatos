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

    void setDato(int valor) {
        dato = valor;
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

    void AgregarFinal(Nodo* nuevo) {
        if (estaVacia()) {
            inicio = nuevo;
        } else {
            Nodo* aux = inicio;
            while (aux->getSiguiente() != nullptr) {
                aux = aux->getSiguiente();
            }
            aux->setSiguiente(nuevo);
        }
        cant++;
    }

    void MostrarLista() {
        if (estaVacia()) {
            cout << "Lista vacía." << endl;
            return;
        }

        Nodo* aux = inicio;
        while (aux != nullptr) {
            cout << aux->getDato() << " -> ";
            aux = aux->getSiguiente();
        }
        cout << "null" << endl;
    }

    void OrdenarSeleccion() {
        if (estaVacia() || inicio->getSiguiente() == nullptr) return;

        Nodo* actual = inicio;
        while (actual != nullptr) {
            Nodo* minimo = actual;
            Nodo* sig = actual->getSiguiente();

            while (sig != nullptr) {
                if (sig->getDato() < minimo->getDato()) {
                    minimo = sig;
                }
                sig = sig->getSiguiente();
            }

            if (minimo != actual) {
                int temp = actual->getDato();
                actual->setDato(minimo->getDato());
                minimo->setDato(temp);
            }

            actual = actual->getSiguiente();
        }
    }

    Nodo* getInicio() {
        return inicio;
    }

    void CombinarCon(Lista& otra) {
        Nodo* aux = otra.getInicio();
        while (aux != nullptr) {
            this->AgregarFinal(new Nodo(aux->getDato()));
            aux = aux->getSiguiente();
        }
    }

    Lista CombinarOrdenadoCon(Lista& otra) {
        Lista nueva;
        Nodo* aux1 = this->getInicio();
        Nodo* aux2 = otra.getInicio();

        while (aux1 != nullptr) {
            nueva.AgregarFinal(new Nodo(aux1->getDato()));
            aux1 = aux1->getSiguiente();
        }
        while (aux2 != nullptr) {
            nueva.AgregarFinal(new Nodo(aux2->getDato()));
            aux2 = aux2->getSiguiente();
        }

        nueva.OrdenarSeleccion();
        return nueva;
    }
};

int main() {
    Lista lista1, lista2, listaCombinada, listaCombinadaOrdenada;
    int opcion, valor;

    do {
        cout << "\n--- MENU LISTAS ---" << endl;
        cout << "1. Agregar valor a Lista 1" << endl;
        cout << "2. Agregar valor a Lista 2" << endl;
        cout << "3. Mostrar Lista 1" << endl;
        cout << "4. Mostrar Lista 2" << endl;
        cout << "5. Ordenar Lista 1" << endl;
        cout << "6. Combinar listas (sin ordenar)" << endl;
        cout << "7. Combinar listas (ordenadas)" << endl;
        cout << "8. Mostrar lista combinada" << endl;
        cout << "9. Mostrar lista combinada ordenada" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor para Lista 1: ";
                cin >> valor;
                lista1.AgregarFinal(new Nodo(valor));
                break;
            case 2:
                cout << "Ingrese valor para Lista 2: ";
                cin >> valor;
                lista2.AgregarFinal(new Nodo(valor));
                break;
            case 3:
                cout << "Lista 1: ";
                lista1.MostrarLista();
                break;
            case 4:
                cout << "Lista 2: ";
                lista2.MostrarLista();
                break;
            case 5:
                lista1.OrdenarSeleccion();
                cout << "Lista 1 ordenada." << endl;
                break;
            case 6:
                listaCombinada = Lista();
                listaCombinada.CombinarCon(lista1);
                listaCombinada.CombinarCon(lista2);
                cout << "Listas combinadas (sin ordenar)." << endl;
                break;
            case 7:
                listaCombinadaOrdenada = lista1.CombinarOrdenadoCon(lista2);
                cout << "Listas combinadas y ordenadas." << endl;
                break;
            case 8:
                cout << "Lista combinada (sin ordenar): ";
                listaCombinada.MostrarLista();
                break;
            case 9:
                cout << "Lista combinada ordenada: ";
                listaCombinadaOrdenada.MostrarLista();
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}
