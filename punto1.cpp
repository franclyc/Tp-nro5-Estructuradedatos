#include<iostream>
using namespace std;
struct Nodo{
    int dato;
    Nodo *siguiente;    
};
void iniciar_lista(Nodo* &lista);
void agregar_final(Nodo* &lista, int valor);
void mostrar_lista(Nodo* lista);
int minimo(Nodo* lista);
 int main() {
    Nodo* lista;
    iniciar_lista(lista);

    agregar_final(lista, 7);
    agregar_final(lista, 3);
    agregar_final(lista, 9);
    agregar_final(lista, 1);

    mostrar_lista(lista);

    cout << "Mínimo: " << minimo(lista) <<endl;

    return 0;
}
    

void iniciar_lista(Nodo* &lista) {
    lista = nullptr; 
}
void agregar_final(Nodo* &lista, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}
void mostrar_lista(Nodo* lista) {
    Nodo* aux = lista;
    while (aux != nullptr) {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    }
    cout << "null" <<endl;

}
int minimo(Nodo* lista) {
    if (lista == nullptr) {
        cout << "Lista vacía" << endl;
        return -1;
    }
    int min = lista->dato;
    Nodo* aux = lista->siguiente;
    while (aux != nullptr) {
        if (aux->dato < min) {
            min = aux->dato;
        }
        aux = aux->siguiente;
    }
    return min;
}
