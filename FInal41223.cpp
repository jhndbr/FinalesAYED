#include <iostream>

using namespace std;
struct Pasajero {
    int id;
    string nombre;
    string apellido;
    string destino;
    string fecha;
    string hora;
};
struct Nodo {
    Pasajero dato;
    Nodo* siguiente;
};

void agregarPasajero(Nodo*& lista, Pasajero pasajero) {
    Nodo* nuevo = new Nodo{pasajero, nullptr};
    if (lista == nullptr) {
        lista = nuevo;
    } else {
        Nodo* actual = lista;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void visualizarPasajeros(Nodo* lista,string Nombre) {
    Nodo* actual = lista;
    while (actual != nullptr) {
        if (actual->dato.nombre == Nombre) {
            cout << "ID: " << actual->dato.id << endl;
            cout << "Nombre: " << actual->dato.nombre << endl;
            cout << "Apellido: " << actual->dato.apellido << endl;
            cout << "Destino: " << actual->dato.destino << endl;
            cout << "Fecha: " << actual->dato.fecha << endl;
            cout << "Hora: " << actual->dato.hora << endl;
            cout << endl;
        }
        actual = actual->siguiente;
    }
}

void visulizarListaTotal(Nodo* lista) {
    Nodo* actual = lista;
    while (actual != nullptr) {
        cout << "ID: " << actual->dato.id << endl;
        cout << "Nombre: " << actual->dato.nombre << endl;
        cout << "Apellido: " << actual->dato.apellido << endl;
        cout << "Destino: " << actual->dato.destino << endl;
        cout << "Fecha: " << actual->dato.fecha << endl;
        cout << "Hora: " << actual->dato.hora << endl;
        cout << endl;
        actual = actual->siguiente;
    }
}

void visualizarListacantenDestino(Nodo* lista, string destino) {
    Nodo* actual = lista;
    int cant = 0;
    while (actual != nullptr) {
        if (actual->dato.destino == destino) {
            cant++;
        }
        actual = actual->siguiente;
    }
    cout << "Cantidad de pasajeros con destino " << destino << ": " << cant << endl;
}

void eliminarPasajero(Nodo*& lista, string nombre) {
    Nodo* actual = lista;
    Nodo* anterior = nullptr;
    while (actual != nullptr) {
        if (actual->dato.nombre == nombre) {
            if (anterior == nullptr) {
                lista = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void modificarPasajero(Nodo* lista, string nombre ){
    Nodo* actual = lista;
    while (actual != nullptr) {
        if (actual->dato.nombre == nombre) {
            cout << "Ingrese el nuevo nombre: ";
            cin >> actual->dato.nombre;
            cout << "Ingrese el nuevo apellido: ";
            cin >> actual->dato.apellido;
            cout << "Ingrese el nuevo destino: ";
            cin >> actual->dato.destino;
            cout << "Ingrese la nueva fecha: ";
            cin >> actual->dato.fecha;
            cout << "Ingrese la nueva hora: ";
            cin >> actual->dato.hora;
            return;
        }
        actual = actual->siguiente;
    }
}    
    
    
int main() {




    return 0;
}
