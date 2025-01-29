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

// lo puedo generar y devolver o pasarlo por parametro, en este caso lo paso por parametro
void unionColas(Nodo* frente1, Nodo* fin1 , Nodo* frente2, Nodo* fin2, Nodo* &frente3, Nodo* &fin3) {
    int valor;
    while (frente1 != NULL) {
        encolar(frente3, fin3, frente1->dato);
        desencolar(frente1, fin1, frente1->dato);
    }
    while (frente2 != NULL) {
        encolar(frente3, fin3, frente2->dato);
        desencolar(frente2, fin2, frente2->dato);
    }
}

int main() {

    Nodo* frente1 = NULL;
    Nodo* fin1 = NULL;
    Nodo* frente2 = NULL;
    Nodo* fin2 = NULL;
    Nodo* frente3 = NULL;
    Nodo* fin3 = NULL;

    // Encolar algunos elementos en la primera cola
    encolar(frente1, fin1, 1);
    encolar(frente1, fin1, 2);
    encolar(frente1, fin1, 3);

    // Encolar algunos elementos en la segunda cola
    encolar(frente2, fin2, 3);
    encolar(frente2, fin2, 5);
    encolar(frente2, fin2, 6);

    // Unir las dos colas en la tercera cola
    unionColas(frente1, fin1, frente2, fin2, frente3, fin3);

    // Mostrar los elementos de la tercera cola
    int valor;
    while (frente3 != NULL) {
        desencolar(frente3, fin3, valor);
        cout << valor << " ";
    }


    return 0;
}