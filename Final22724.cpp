#include <iostream>
using namespace std;
struct Pelicula{
int codigo;
char titulo[50];
char director[50];
int espectadores;
int fechadeestreno;
};

Pelicula cargaPeli() {
    Pelicula p;
    cout<<"Ingrese el codigo de la pelicula: ";
    cin>>p.codigo;
    cout<<"Ingrese el titulo de la pelicula: ";
    cin>>p.titulo;
    cout<<"Ingrese el director de la pelicula: ";
    cin>>p.director;
    cout<<"Ingrese la cantidad de espectadores de la pelicula: ";
    cin>>p.espectadores;
    cout<<"Ingrese la fecha de estreno de la pelicula: ";
    cin>>p.fechadeestreno;
    return p;
};
void mostrarpelis(Pelicula pelis[], int n){
    for (int i=0; i<n;i++){
        cout<<"Codigo: "<<pelis[i].codigo<<endl;
        cout<<"Titulo: "<<pelis[i].titulo<<endl;
        cout<<"Director: "<<pelis[i].director<<endl;
        cout<<"Espectadores: "<<pelis[i].espectadores<<endl;
        cout<<"Fecha de estreno: "<<pelis[i].fechadeestreno<<endl;
    }
};
void gurdarEnArchivo(Pelicula pelis[], int n){
    FILE *archivo;
    archivo=fopen("peliculas.dat","wb");
    if (archivo==NULL){
        cout<<"Error al abrir el archivo";
        return;
    }
    for (int i=0; i<n;i++){
        fwrite(&pelis[i],sizeof(Pelicula),1,archivo);
    }
    fclose(archivo);
};
int main(){
    Pelicula pelis[2];
    for (int i=0; i<2;i++){
        pelis[i]=cargaPeli();
    };
    mostrarpelis(pelis,2);
    gurdarEnArchivo(pelis,2);
    return 0;
}