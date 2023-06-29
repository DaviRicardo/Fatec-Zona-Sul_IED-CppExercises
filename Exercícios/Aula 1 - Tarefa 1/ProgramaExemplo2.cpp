/*
Este exemplo cria vetores do tipo double e int, os vetores salário e idade são lidos diretamente no for. 
No último loop for os vetores poderão ser exibidos todos juntos, o salário é exibido com 10% de aumento.
*/

#include <iostream>
#include <math.h>
using namespace std;

int const n = 3;

double sal[n];
int ida[n];

int main () { 
    system ("cls");

    double x; 

    for (int i = 0; i < n ; i ++) { 
        cout << "\nDigite salário e idade separados por espaço:";
        cin >> sal[i];
        cin >> ida[i]; 
    }
  
    cout << "\n";
    for (int i= 0; i < n; i++) {
        x = sal[i] * 1.1;
        cout << x << " - " << ida[i] << endl;
    }
    return 0; 
}