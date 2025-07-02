#include<iostream>
using namespace std;
struct nodo{
    int dato;
    nodo *siguiente;    
}
void iniciar_lista(Nodo* &lista);
void agregar_final(Nodo* &lista, int valor);
void mostrar_lista(Nodo* lista);
int minimo(Nodo* lista);

int main() {
    
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
