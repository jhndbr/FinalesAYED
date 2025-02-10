#include <iostream>
using namespace std;

void modificar(int (&arr)[5]) {  // Recibe el arreglo por referencia
    arr[0] = 99;  // Modifica el primer elemento
    arr[4] = 77;  // Modifica el último elemento
}

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};  // Arreglo global en este contexto

    cout << "Antes de modificar: ";
    for (int num : numeros) cout << num << " ";
    cout << endl;

    modificar(numeros);  // Se pasa por referencia y se modifica

    cout << "Después de modificar: ";
    for (int num : numeros) cout << num << " ";
    cout << endl;

    return 0;
}
