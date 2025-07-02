#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};
struct Lista {
    Nodo* inicio;
    Nodo* final;
    int cantidad;

};
void iniciar_lista(Lista &lista);
void agregar_final(Lista &lista, int valor);
Nodo* eliminar_inicio(Lista &lista);
void mostrar_lista(Lista lista);
int obtener_cantidad(Lista lista);
int buscar_indice(Lista lista, int valor);
Nodo* buscar_por_indice(Lista lista, int indice);

int main(){
    Lista miLista;
    iniciar_lista(miLista);

    agregar_final(miLista, 10);
    agregar_final(miLista, 20);
    agregar_final(miLista, 30);
    agregar_final(miLista, 40);

    mostrar_lista(miLista);

    int indice = buscar_indice(miLista, 30);
    cout << "Índice del valor 30: " << indice << endl;

    Nodo* resultado = buscar_por_indice(miLista, 2);
    if (resultado != nullptr) {
        cout << "Elemento en índice 2: " << resultado->dato << endl;
    } else {
        cout << "Índice fuera de rango" << endl;
    }

    return 0;
}
    

void iniciar_lista(Lista &lista) {
    lista.inicio = nullptr;
    lista.final = nullptr;
    lista.cantidad = 0;
}
void agregar_final(Lista &lista, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (lista.inicio == nullptr) {
        lista.inicio = nuevo;
        lista.final = nuevo;
    } else {
        lista.final->siguiente = nuevo;
        lista.final = nuevo;
    }
    lista.cantidad++;
}   

Nodo* eliminar_inicio(Lista &lista) {
        Nodo* borrado;

    if (lista.inicio == nullptr) {
        borrado = nullptr;
    } else {
        borrado = lista.inicio;
        lista.inicio = borrado->siguiente;
        borrado->siguiente = nullptr;

        if (lista.inicio == nullptr) {
            lista.final = nullptr;
        }

        lista.cantidad--;
    }
    return borrado;
}

void mostrar_lista(Lista lista) {
    Nodo* aux = lista.inicio;
    while (aux != nullptr) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "null" << endl;
}
int obtener_cantidad(Lista lista) {
    return lista.cantidad;
}
int buscar_indice(Lista lista, int valor) {
    Nodo* aux = lista.inicio;
    int indice = 0;

    while (aux != nullptr) {
        if (aux->dato == valor) {
            return indice;
        }
        aux = aux->siguiente;
        indice++;
    }
    return -1; 
}
Nodo* buscar_por_indice(Lista lista, int indice) {
    if (indice < 0 || indice >= lista.cantidad) {
        return nullptr;
    }

    Nodo* aux = lista.inicio;
    int actual = 0;

    while (aux != nullptr && actual < indice) {
        aux = aux->siguiente;
        actual++;
    }

    return aux; 
}