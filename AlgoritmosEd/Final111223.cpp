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

// TODO aprender semantica de esta funcion
void insertarOrdenado(Nodo* &lista, int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->siguiente = NULL;
    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        Nodo* aux1 = lista;
        Nodo* aux2 = NULL;
        while (aux1 != NULL && aux1->dato < n) {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        if (aux2 == NULL) {
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        } else {
            aux2->siguiente = nuevoNodo;
            nuevoNodo->siguiente = aux1;
        }
    }
}
void listadedoslistas(Nodo* lista1, Nodo* lista2, Nodo* &lista) {
    Nodo* aux = lista1;
    while (aux != NULL) {
        insertarOrdenado(lista, aux->dato);
        aux = aux->siguiente;
    }
    aux = lista2;
    while (aux != NULL) {
         insertarOrdenado(lista, aux->dato);
        aux = aux->siguiente;
    }
}
// punto 2
struct Reservas
{
    int codHOtel;
    int cantReservas;
    int cantDiasDisponibles;
};

//infor lista
struct InfoLista
{
    int codHotellista;
    int cantdiaslista;
};

struct NodoReservas
{
    Reservas info;
    NodoReservas* siguiente;
};

//punto 3
//PUNTO 3
struct Producto{
    int codigoProducto;
    int peso;
    char tipo;
    int cantidadEnStock;
};

struct NodoProducto{
    Producto producto;
    NodoProducto* sig;
};
void cargarArchivo(char nombreArchivo[], NodoProducto* lista){
    FILE* archivo = fopen(nombreArchivo, "wb");
    Producto producto;
    while(lista){
        producto = lista->producto;
        fwrite(&producto, sizeof(Producto), 1, archivo);
        lista = lista->sig;
    }

    fclose(archivo);

}

void insertarProductoOrdenado(NodoProducto*& lista, Producto producto){ 
    NodoProducto* nuevo = new NodoProducto;
    NodoProducto* anterior; 

    nuevo->producto = producto; 

    if(!lista || lista->producto.codigoProducto > producto.codigoProducto){ 
        nuevo->sig = lista;   
        lista = nuevo; 
    }else{ 
        anterior = lista; 

        while(anterior->sig && anterior->sig->producto.codigoProducto <= producto.codigoProducto){
            anterior = anterior->sig; 
        }   

        nuevo->sig = anterior->sig; 
        anterior->sig = nuevo; 
    } 
} 

NodoProducto* listaProductosSinStock(char nombreArchivo[]){
    NodoProducto* lista;
    FILE* archivo = fopen(nombreArchivo, "rb");
    Producto producto;

    while(fread(&producto, sizeof(Producto), 1, archivo)){
        if(producto.cantidadEnStock == 0){
            insertarProductoOrdenado(lista, producto);
        }
    }
    fclose(archivo);

    return lista;
}

NodoProducto* listaProductosPesados(char nombreArchivo[]){
    NodoProducto* lista;
    FILE* archivo = fopen(nombreArchivo, "rb");
    Producto producto;

    while(fread(&producto, sizeof(Producto), 1, archivo)){
        if(producto.peso > 100 && producto.tipo == 'B'){
            insertarProductoOrdenado(lista, producto);
        }
    }
    fclose(archivo);

    return lista;
}
int main() {

    Nodo* lista = NULL;
    Nodo* lista1 = NULL;
    Nodo* lista2 = NULL;

    insertarAlFinal(lista1, 1);
    insertarAlFinal(lista1, 3);
    insertarAlFinal(lista1, 5);
    insertarAlFinal(lista1, 7);

    insertarAlFinal(lista2, 2);
    insertarAlFinal(lista2, 4);
    insertarAlFinal(lista2, 6);
    insertarAlFinal(lista2, 8);

    listadedoslistas(lista1, lista2, lista);

    std::cout << "Lista: ";
    listar(lista);
    // punto 2
    NodoReservas *listaReservas = NULL;
    Reservas infoReservas [] = {
        {1, 5, 10},
        {2, 3, 5},
        {3, 7, 15},
        {4, 2, 3},
        {5, 4, 8}
    };
    // codhotel,cantidad,cantidad idas disopo
    while (listaReservas != NULL) {
    int codigohotel = listaReservas->info.codHOtel;
    int cantReservas = listaReservas->info.cantReservas;

    if (infoReservas->codHOtel == codigohotel &&  infoReservas->cantDiasDisponibles >= cantReservas) {
        infoReservas->cantReservas = infoReservas->cantReservas - cantReservas;
    }

    NodoReservas *aux = listaReservas->siguiente;
    }
    // punto 3

    FILE *archivo = fopen("STOCK.dat", "rb");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    

    return 0;}