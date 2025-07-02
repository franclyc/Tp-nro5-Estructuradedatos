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

int main(){
     Lista miLista;
    iniciar_lista(miLista);

    agregar_final(miLista, 5);
    agregar_final(miLista, 10);
    agregar_final(miLista, 3);

    mostrar_lista(miLista);

    cout << "Cantidad de elementos: " << obtener_cantidad(miLista) << endl;

    eliminar_inicio(miLista);
    mostrar_lista(miLista);

    cout << "Cantidad de elementos: " << obtener_cantidad(miLista) << endl;

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
