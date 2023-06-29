#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main () {
    system ("cls");
    typedef struct pessoa p;

    struct pessoa {
        double vet[10];
    };

    p teste; 
    p *ptteste;

    ptteste = &teste;
    ptteste -> vet[0] = 33;

    cout << ptteste -> vet[0] << endl;
}