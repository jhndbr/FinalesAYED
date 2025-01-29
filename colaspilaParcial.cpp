// dada dos colar realizar la union en una pila
#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
      int dato;
      Nodo* siguiente;
    };
// encolas solo puedo agregar o suprimir
void encolar(Nodo* &frente, Nodo* &fin, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if (frente == NULL) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
}
void desencolar(Nodo* &frente, Nodo* &fin, int &n) {
    n = frente->dato;
    Nodo* aux = frente;
    if (frente == fin) {
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}   

void push(Nodo* &pila, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}
void pop(Nodo* &pila, int &n) {
    n = pila->dato;
    Nodo* aux = pila;
    pila = pila->siguiente;
    delete aux;
}

// lo puedo generar y devolver o pasarlo por parametro, en este caso lo paso por parametro
void unionColaspila(Nodo* frente1, Nodo* fin1 , Nodo* frente2, Nodo* fin2, Nodo* &pila) {
    int valor;
    while (frente1 != NULL) {
       push(pila, frente1->dato);
        desencolar(frente1, fin1, frente1->dato);
    }
    while (frente2 != NULL) {
        push(pila, frente2->dato);
        desencolar(frente2, fin2, frente2->dato);
    }
}

int main() {
Nodo* frente1 = NULL;
    Nodo* fin1 = NULL;
    Nodo* frente2 = NULL;
    Nodo* fin2 = NULL;
    Nodo* pila = NULL;

    // Encolar algunos elementos en la primera cola
    encolar(frente1, fin1, 1);
    encolar(frente1, fin1, 2);
    encolar(frente1, fin1, 3);

    // Encolar algunos elementos en la segunda cola
    encolar(frente2, fin2, 4);
    encolar(frente2, fin2, 5);
    encolar(frente2, fin2, 6);

    // Unir las dos colas en la pila
    unionColaspila(frente1, fin1, frente2, fin2, pila);

    // Mostrar los elementos de la pila
    int valor;
    while (pila != NULL) {
        pop(pila, valor);
        cout << valor << " ";
    }

    

    return 0;
}