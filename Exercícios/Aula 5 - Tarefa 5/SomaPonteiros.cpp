#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main () {
    system ("cls");
    int a = 2; 
    int b = 2;
    int *pta;
    int *ptb;
    pta = &a;
    ptb = &b;

    cout << *pta + *ptb << endl;
}