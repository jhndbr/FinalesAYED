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
//pilas
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

void insertarAlFinal(Nodo* &lista, int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;
    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
}
// mostrar los elementos de la lista
void listar(Nodo* lista) {
    Nodo* aux = lista;
    while (aux != NULL) {
        std::cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}


// lo puedo generar y devolver o pasarlo por parametro, en este caso lo paso por parametro
void unionColasLista(Nodo* frente1, Nodo* fin1 , Nodo* frente2, Nodo* fin2, Nodo* &lista) {
    int valor;
    while (frente1 != NULL) {
        insertarAlFinal(lista, frente1->dato);
        desencolar(frente1, fin1, frente1->dato);
    }
    while (frente2 != NULL) {
        insertarAlFinal(lista, frente2->dato);
        desencolar(frente2, fin2, frente2->dato);
    }
}


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
    Nodo* lista = NULL;

    // Encolar algunos elementos en la primera cola
    encolar(frente1, fin1, 1);
    encolar(frente1, fin1, 2);
    encolar(frente1, fin1, 3);

    // Encolar algunos elementos en la segunda cola
    encolar(frente2, fin2, 4);
    encolar(frente2, fin2, 5);
    encolar(frente2, fin2, 6);

    // Unir las dos colas en la pila
     // Unir las dos colas en la lista
    unionColasLista(frente1, fin1, frente2, fin2, lista);

    // Mostrar los elementos de la pila
    listar(lista);
    

    return 0;}