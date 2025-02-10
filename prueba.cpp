#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sig;
};

int main(){
    Nodo* lista = NULL;
    int dato = -1; // Inicializar dato con un valor diferente de 0
    while (true){
        cout << "Ingrese un dato (0 para terminar): ";
        cin >> dato;
        if (dato == 0) break; // Salir del bucle si el dato es 0
        Nodo* nuevo = new Nodo();
        nuevo->info = dato;
        nuevo->sig = lista;
        lista = nuevo;
    }
    while (lista != NULL)
    {
        cout << lista->info << endl;
        Nodo* temp = lista;
        lista = lista->sig;
        delete temp; // Liberar memoria
    }
    
    return 0;
}