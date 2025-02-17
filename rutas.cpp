#include<iostream>
usingnamespacestd

struct Ruta{
int localidad1;
int localidad2;
int distancia;
int ruta;
};
// lista de rutas
Ruta rutas[];
//matriz 100x100 que contiene las distancias y numeros de rutas entre las localidades
int M[100][100];

void InicialzizarM (M[100][100],Ruta[],int cantRutas){
}

int encontrarRuta(int l1,int l2,m[100][100]){
if(i>j){
return m[j]][i];
}else {
return m[i]][j];;
}}


void MostrarRuta(int localidad1,int localidad2, m[100][100]){
int a = encontrarRuta(l1,l2,m[100][100];
if(a<0){
cout<<"la ruta es:", a<<endl;
}
else {
cout<<"la ruta no existe"<<endl;
}}


void mostrarVecinas(l1,l2m[][]){

int a = encontrarruta(l1.l2.m[][])

   for (int fila = 0; fila < 3; fila++) {
        for (int col = 0; col < 3; col++) {
            if (m[fila][col] == a){
            cout<<"son vecinos", fila,
            }
        }
        cout << endl;  // Para mover a la siguiente línea después de cada fila
    }
}

int main(){

// el equipo debe desarrollar un sistema para consultar distancias y rutas entre localidades



























return 0;}
