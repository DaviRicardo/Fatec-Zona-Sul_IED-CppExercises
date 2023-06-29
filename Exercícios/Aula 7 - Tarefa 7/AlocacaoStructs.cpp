#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct me x;

struct me { 
    int a; 
    float b; 
    char g; 
};

int main () { 
    system ("cls");

    x * ptx = (x *) malloc(sizeof (x)); 
  
    if (ptx == NULL) {
        cout << "\nNão há mais memória!" << endl;
    } else { 
        ptx-> a = 10; 
        ptx-> b = 10.4; 
        ptx-> g = '0'; 
        cout << "O struct ptx foi armazenado na memória com endereço: " << ptx << endl;
        cout << "Valores: "<< ptx-> a << " " << ptx-> b << " "<< ptx-> g << endl; 
    }
    system("pause"); 
    free (ptx);
    return 0; 
}
