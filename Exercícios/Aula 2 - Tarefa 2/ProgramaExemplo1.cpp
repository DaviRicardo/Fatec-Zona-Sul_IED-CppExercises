/*
Fazer um código para retornar o maior valor e outro para retornar o menor valor da lista 'int xy [ ] = {1, 5, 10, 45, 3 , 9}'. 
*/

#include "iostream"
#include "math.h"
#include "cstdlib"
using namespace std;

int xy [ ] = {1, 5, 10, 45, 3 , 9};

void mostrar ();

int main () {
  mostrar ();
  return 0; 
}

void mostrar () {
    system ("cls");
    
    int maior, menor;
    int tot = sizeof(xy)/sizeof(int); 
    
    for (int i = 0; i< tot; i++) {
        if ( xy[i] > maior || i == 0 ) maior = xy[i];
        if ( xy[i] <menor || i == 0 ) menor = xy[i];
    }
    
    cout << "Maior: " << maior;
    cout << "\nMenor: " << menor << endl;
    system("pause");
}