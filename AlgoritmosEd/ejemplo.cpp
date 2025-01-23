#include <iostream>

// Función recursiva para calcular el factorial
unsigned long long factorial(int n) {
    if (n <= 1) return 1; // Caso base
    return n * factorial(n - 1); // Llamada recursiva
}

int main() {
    int num;

    // Solicitar al usuario un número
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "El factorial no está definido para números negativos.\n";
    } else {
        std::cout << "El factorial de " << num << " es " << factorial(num) << ".\n";
    }

    return 0;
}
