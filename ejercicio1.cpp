#include <iostream>
using namespace std;
int main(){
    int num[] = {1, 2, 3, 4, 5,0,0,0,0,3,1,-1,-3,4,1,3};
    cout << "cantidad de 0" << endl;
    int cont =0;
    for (int i = 0; i < 16; i++){
        if (num[i] == 0){
            cont++;
        }
    }
    cout << cont << endl;
    cout << "cantidad de nuemros positivos" << endl;
    cont = 0;
    for (int i = 0; i < 16; i++){
        if (num[i] >0){
            cont++;
        }
    }
    cout << cont << endl;
    cout << "suma de nuemros negativos" << endl;
    int suma = 0;
    for (int i = 0; i < 16; i++){
        if (num[i] <0){
            suma = suma + num[i];
        }
    }
    cout << suma << endl;

    
    return 0;
}