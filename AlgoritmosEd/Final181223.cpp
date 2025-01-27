#include <iostream>
using namespace std;

struct Notas {
    int Legajo;
    int Nota1p;
    int Nota2p;
};
struct NotaRecu2p {
    int Legajo;
    int Notarecu2p;
};
struct Nodo {
    NotaRecu2p dato;
    Nodo* siguiente;
};

int main() {
    Notas Alumnos[5] = {
        {1, 8, 5},
        {2, 7, 4},
        {3, 6, 3},
        {4, 9, 2},
        {5, 5, 1}
    };

    // Lista de nodos
    Nodo* lista = new Nodo{{1, 7}, nullptr};
    lista->siguiente = new Nodo{{2, 8}, nullptr};
    lista->siguiente->siguiente = new Nodo{{3, 9}, nullptr};
    lista->siguiente->siguiente->siguiente = new Nodo{{4, 10}, nullptr};
    lista->siguiente->siguiente->siguiente->siguiente = new Nodo{{5, 6}, nullptr};

    int i = 0;
    while (lista != NULL) {
        if (lista->dato.Legajo == Alumnos[i].Legajo) {
            if (lista->dato.Notarecu2p >= 6) {
                Alumnos[i].Nota2p = lista->dato.Notarecu2p;
            }
            lista = lista->siguiente;
        } else {
            i++;
        }
    }

    cout << "muestro notas " << endl;
    for (int j = 0; j < 5; j++) {
        cout << "Legajo: " << Alumnos[j].Legajo << ", Nota1p: " << Alumnos[j].Nota1p << ", Nota2p: " << Alumnos[j].Nota2p << endl;
    }
    return 0;
}