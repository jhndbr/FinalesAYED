#include <iostream>
using namespace std;
///////////////////////////// punto 1 //////////////////////////
struct Nodo {
    int dato;
    Nodo* siguiente;
};
// colas
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
//lista 
void insertarAlFinal(Nodo* &lista, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if (lista == NULL) {
        lista = nuevo_nodo;
    } else {
        Nodo* aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
}
void eliminarDelInicio(Nodo* &lista, int &n) {
    if (lista != NULL) {
        Nodo* aux = lista;
        n = aux->dato;
        lista = aux->siguiente;
        delete aux;
    }
}

// pila 
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

void UnionPilaColaVector(Nodo* pila, Nodo* frente, Nodo* fin, Nodo* &lista, int vec[], int size) {
    int valor;
    while (fin != NULL) {
        desencolar(frente, fin, valor);
        insertarAlFinal(lista, valor);
    }
    while(pila != NULL) {
        pop(pila, valor);
        insertarAlFinal(lista, valor);
    }
    for (int i = 0; i < size; i++) {
        insertarAlFinal(lista, vec[i]);
    }

} 
///////////////////////////// punto 1 //////////////////////////
struct Matriculas {
    int codCurso;
    int cantAlumnos;
    int montoPagado;
};
struct Reserva {
    int codCursoReserva;
    int montoPagadoReserva;
};
struct Nodo1 {
    Reserva reservaDato;
    Nodo1* siguiente;
};

int main() {
    ///////////////////////////// punto 1 //////////////////////////
     Nodo* pila = nullptr;
    Nodo* frente = nullptr;
    Nodo* fin = nullptr;
    Nodo* lista = nullptr;

    // Crear un arreglo y llenarlo con algunos valores
    int miArreglo[] = {1, 2, 3, 4, 5};
    int size = sizeof(miArreglo) / sizeof(miArreglo[0]);

    // Agregar algunos elementos a la pila
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);

    // Agregar algunos elementos a la cola
    encolar(frente, fin, 40);
    encolar(frente, fin, 50);
    encolar(frente, fin, 60);

    // Llamar a la función y pasar el arreglo como argumento
    UnionPilaColaVector(pila, frente, fin, lista, miArreglo, size);

    // Mostrar los elementos de la lista
    Nodo* aux = lista;
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;

    ///////////////////////////// punto 1 //////////////////////////
    Nodo1* listaReserva = nullptr;
    Matriculas matriculas[] = {
        {1, 10, 100},
        {2, 20, 200},
        {3, 30, 300},
        {4, 40, 400},
        {5, 50, 500}
    };
    // matriculo codcurso, cantalumno,monto
    cout << "Matriculas antes de la union" << endl;
    while (listaReserva != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            if (matriculas[i].codCurso == listaReserva->reservaDato.codCursoReserva)
            {
                matriculas[i].cantAlumnos++;
                matriculas[i].montoPagado += listaReserva->reservaDato.montoPagadoReserva;
            }
        }
        Nodo1* aux = listaReserva;
        listaReserva = listaReserva->siguiente;
        delete aux;
    }
    cout << "Matriculas despues de la union" << endl;

    return 0;
}


//"El vector es la mejor estructura para ordenar un archivo."

//Esto no siempre es cierto. El vector puede ser una buena estructura si el archivo a ordenar es pequeño y puede cargarse completamente en memoria. Sin embargo, cuando los archivos son muy grandes y no caben en memoria, se utilizan técnicas de ordenamiento externo, como el algoritmo de mezcla equilibrada (balanced merge sort), que divide el archivo en partes más manejables. Por lo tanto, el vector no es siempre la "mejor" estructura, sino una de las opciones según el contexto.
//"El corte de control se encarga de unir dos archivos con todos sus registros."

//Esta afirmación mezcla conceptos. El corte de control se utiliza en programación para procesar datos agrupados (por ejemplo, generar totales o resúmenes para grupos específicos de datos). El proceso de apareo (o merge) es el que se encarga de unir dos archivos ordenados, intercalando sus registros para mantener el orden. Así que lo que describe aquí es más parecido al apareo, no al corte de control.