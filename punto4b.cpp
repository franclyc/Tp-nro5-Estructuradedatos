#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* final;
    int cantidad; 

};

void iniciarCola(Cola &c);
bool colaVacia(const Cola &c);
void agregarCola(Cola &c, int valor);     
int  quitarCola(Cola &c);                 
int  frenteCola(const Cola &c);           
int  finalCola(const Cola &c);            
void mostrarCola(Cola c);
int cantidadElementos(const Cola &c);

int main() {
    Cola c;
    iniciarCola(c);

    int opcion, valor;
    do {
        cout << "\n---  MENÚ COLA DINÁMICA  ---\n"
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
                agregarCola(c, valor);
                break;
            case 2:
                if (!colaVacia(c))
                    cout << "Extraído: " << quitarCola(c) << endl;
                else
                    cout << "Cola vacía.\n";
                break;
            case 3:
                if (!colaVacia(c))
                    cout << "Frente: " << frenteCola(c) << endl;
                else
                    cout << "Cola vacía.\n";
                break;
            case 4:
                if (!colaVacia(c))
                    cout << "Final: " << finalCola(c) << endl;
                else
                    cout << "Cola vacía.\n";
                break;
            case 5:
                mostrarCola(c);
                break;
             case 6:
             cout << "Elementos en la cola: " << cantidadElementos(c) << endl;
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

void iniciarCola(Cola &c) {
    c.frente = c.final = nullptr;    
    c.cantidad = 0;                  
}

bool colaVacia(const Cola &c) {
    return c.frente == nullptr;                      
}

void agregarCola(Cola &c, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (colaVacia(c)) {
        c.frente = c.final = nuevo;                   
    } else {
        c.final->siguiente = nuevo;                   
        c.final = nuevo;                              
    }
    c.cantidad++;
}

int quitarCola(Cola &c) {
    if (colaVacia(c)) {
        cout << "La cola está vacía.\n";              
        return -999;                                  
    }
    Nodo* borrado = c.frente;
    int dato = borrado->dato;
    c.frente = c.frente->siguiente;                   
    if (c.frente == nullptr) c.final = nullptr;       
    delete borrado;
    c.cantidad--;
    return dato;
}

int frenteCola(const Cola &c) {
    return colaVacia(c) ? -999 : c.frente->dato;
}

int finalCola(const Cola &c) {
    return colaVacia(c) ? -999 : c.final->dato;
}

void mostrarCola(Cola c) {
    if (colaVacia(c)) {
        cout << "Cola vacía.\n";
        return;
    }
    cout << "Contenido de la cola (frente → final): ";
    while (c.frente != nullptr) {
        cout << c.frente->dato << " ";
        c.frente = c.frente->siguiente;
    }
    cout << endl;
}
int cantidadElementos(const Cola &c) {
    return c.cantidad;
}

