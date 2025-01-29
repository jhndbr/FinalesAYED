#include <iostream>
using namespace std;
void proc (int v[], int len) {
    *v = 10;
}

int main() {
    int *p = NULL;    // Se declara un puntero p inicializado a NULL
    int x = 30;       // Se declara una variable entera x con valor 30
    p = new int[3];   // Se asigna memoria dinámica para un arreglo de 3 enteros
    p[1] = x;         // Se asigna el valor de x (30) a la posición p[1]
    proc(p, 3);       // Se llama a la función proc (pero no modifica el contenido)
    p[2] = *(p+1) + x;  // p+1 apunta a p[1], por lo que (p+1)[0] es p[1] (30). Se suma x (30), obteniendo 60.
    
    for (int i = 0; i < 3; i++)
        cout << *(p + i) << endl; // Se imprime cada elemento del arreglo dinámico

    delete [] p;   // Se libera la memoria asignada a p
    return 0;
}
// muestra 10, 30, 60 