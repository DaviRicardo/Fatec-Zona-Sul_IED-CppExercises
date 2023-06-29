#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

double const pi = 3.14;

// Declaração das Sub-rotinas
double lerRaio();
double calcArea (double *ptraio);
void exibirResultado (double *ptarea);

int main () {
    int escolhaMenu;
    double valorRaio, valorArea;
    
    while (escolhaMenu != 2) {
        system ("cls");

        cout << "Opção 1 - Executar programa";
        cout << "\nOpção 2 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma dentre as opções: ";
        cin >> escolhaMenu;

        switch (escolhaMenu) {
            case 1:
                valorRaio = lerRaio();
                valorArea = calcArea (&valorRaio);
                exibirResultado (&valorArea);
            break;
            case 2:
                cout << "\nFinalizando programa..." << endl;
                system ("pause");
            break;
            default:
                cout << "\nPor favor, digite apenas a opção 1 ou 2..." << endl;
                system ("pause");
            break;
        }
    } 
}

// Função de leitura
double lerRaio(){
    double val;
    cout << endl << "\nDigite o valor do raio do círculo: ";
    cin >> val;
    return val;
}

// Função de cálculo da área do círculo
double calcArea (double *ptraio) {
    double area;
    area = (pi * pow(*ptraio, 2));
    return area;
}

// Função para o exibir o resultado
void exibirResultado (double *ptarea) {
    cout << endl << "\nA área do círculo é: " << fixed << setprecision(2) << *ptarea << " cm²/m²" << endl;
    system ("pause");
    return;
}

