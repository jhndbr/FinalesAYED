#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Alumno {
    char nombre[35];
    int legajo;
    int division;
    Alumno* next;
};

void insertarOrdenado(Alumno*& head, Alumno* nuevo) {
    if (head == nullptr || head->legajo > nuevo->legajo) {
        nuevo->next = head;
        head = nuevo;
    } else {
        Alumno* current = head;
        while (current->next != nullptr && current->next->legajo < nuevo->legajo) {
            current = current->next;
        }
        nuevo->next = current->next;
        current->next = nuevo;
    }
}

void leerArchivo(const char* filename, Alumno*& head) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }

    while (!file.eof()) {
        Alumno* nuevo = new Alumno;
        file.read(reinterpret_cast<char*>(nuevo), sizeof(Alumno));
        if (file.gcount() == sizeof(Alumno)) {
            nuevo->next = nullptr;
            insertarOrdenado(head, nuevo);
        } else {
            delete nuevo;
        }
    }

    file.close();
}

void escribirArchivo(const char* filename, Alumno* head) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }

    Alumno* current = head;
    while (current != nullptr) {
        file.write(reinterpret_cast<char*>(current), sizeof(Alumno));
        current = current->next;
    }

    file.close();
}

void liberarMemoria(Alumno* head) {
    while (head != nullptr) {
        Alumno* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Alumno* head = nullptr;

    leerArchivo("ARCHA.dat", head);
    escribirArchivo("ARCHL.dat", head);
    liberarMemoria(head);

    return 0;
}