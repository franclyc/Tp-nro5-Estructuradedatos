#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};
struct lista {
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

