#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

double const txmulta = 0.02;

double lerValor ();
void mostrar(double val, double multa);
double calcMulta(double valorPrestacao);

int main() {
    double valorPrest, valorMulta; int tecla;
  
    MENU: 
        system ("cls");
        cout << "Menu\n1 Executar\n2 Sair\n\nItem: ";
        cin >> tecla;
    
        switch(tecla) { 
            case 1: 
                valorPrest = lerValor();
                valorMulta = calcMulta(valorPrest);
                mostrar (valorPrest, valorMulta);
            break;
            case 2: 
                cout << "\nFim do programa!\n";
                system("pause"); 
                exit(0);
            break;
         } 
    goto MENU; 
    return 0; 
} 

double lerValor () { 
    double val;
    cout << "\nDigite a prestação: ";
    cin >> val; 
    return val;
}

void mostrar (double val, double multa) {
    system ("cls");
    double valorFinal;
    valorFinal= val + multa;
    cout<<"Valor a pagar: "<< valorFinal << endl;
    system ("pause");
}

double calcMulta (double valorPrestacao) { 
    return (valorPrestacao * txmulta ); 
}