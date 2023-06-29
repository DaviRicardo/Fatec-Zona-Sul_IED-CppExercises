/*
Fazer um código para retornar a média dos valores da lista 'int vet [] = {1,3,4,-1,0,4,19}'.
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

float valorMedia();
int vet [] = {1,3,4,-1,0,4,19};


int main () {
    system ("cls");
    float media = valorMedia();
    cout << "A média é: " << media << endl;
    system("pause");
}

float valorMedia() {
    float media = 0;
    int tot = sizeof(vet)/sizeof(int);
    
    for (int i = 0; i< tot; i++) { 
        media += vet[i]; 
    }
  
    media /= tot;
    return (media); 
}