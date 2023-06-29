#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

//Declaração de Sub-rotinas
double lerMedidaLado();
double calculoArea (double *ptlado1, double *ptlado2, double *ptlado3);
void exibirArea (double *ptarea); 

int contador = 0;

int main () {  
    int escolhaMenu;
    double medLado1, medLado2, medLado3, areaTriangulo;
    
    while (escolhaMenu != 2) {
        system ("cls");
        cout << "Opção 1 - Iniciar programa";
        cout << "\nOpção 2 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> escolhaMenu;
        
        switch (escolhaMenu) {
            case 1:
                medLado1 = lerMedidaLado();
                medLado2 = lerMedidaLado();
                medLado3 = lerMedidaLado();
                areaTriangulo = calculoArea(&medLado1, &medLado2, &medLado3);
                exibirArea(&areaTriangulo);
            break;
            case 2:
                cout << "\nFinalizando programa..." << endl;
                system ("pause");
                exit(0);
            break;
            default:
                cout << "\nPor favor, digite apenas a opção 1 ou 2..." << endl;
                system ("pause");
            break;
        }
    }
}

double lerMedidaLado() {
    double med;
    contador ++;
    cout << endl << "\nDigite a medida do " << contador << "° lado: ";
    cin >> med;
    return med;    
}

double calculoArea (double *ptlado1, double *ptlado2, double *ptlado3) {
    double areaTriangulo, p; // p = semiperímetro
    // Teorema de Heron
    p = ((*ptlado1 + *ptlado2 + *ptlado3) / 2); 
    areaTriangulo = sqrt (p * ((p - *ptlado1) * (p - *ptlado2) * (p - *ptlado3)));
    return areaTriangulo;
}

void exibirArea (double *ptarea) {
    cout << endl << "\nA área do triângulo é: " << fixed << setprecision(2) << *ptarea << " m²" << endl;
    system ("pause");
    return;
}




