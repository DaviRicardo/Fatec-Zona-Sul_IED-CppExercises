#include <iostream>
#include <cstdlib>
using namespace std;

int main () { 
    system ("cls");

    int *ptx = (int *) malloc(sizeof(int)); // Aloca 4 bytes para um inteiro.

    if (ptx == NULL) { 
        cout <<  "\nNão foi possível a alocação de memória!";
    } else { 
        *ptx = 10;
        cout << "O valor " << *ptx << " será armazenado na memória de endereço: " << ptx << endl; 
    }
  
    system("pause");
    free (ptx);
    return 0; 
}