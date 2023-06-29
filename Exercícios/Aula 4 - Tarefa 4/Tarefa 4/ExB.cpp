/* b) Ler o valor correspondente ao salário mensal (variável SM) de um trabalhador e também o valor do percentual de reajuste (variável PR) a ser atribuído. 
Apresentar o valor do novo salário (variável NS).
a) Os dados de entrada e saída deverão ser armazenados em um struct com várias colunas;
b) Deverá conter um menu com switch case, funções para leitura dos dados de entrada e as respectivas funções para calcular os dados de saída;
c) Tanto os dados de entrada quanto os dados de saída deverão ser armazenados dentro de structs. */

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

//Declaração de Sub-Rotinas
double lerSalario();
double lerReajusteSalarial();
void armazenarValores();
void calculoSalarioFinal();
void exibirResultado();

typedef struct salarioMensal salario;

struct salarioMensal {
  double SM, PR, NS;
};

salario sal;

int main () {
  int escolhaMenu;
  
    while (escolhaMenu != 3) {
        system ("cls");

        cout << "Opção 1 - Inseir dados";
        cout << "\nOpção 2 - Exibir dados";
        cout << "\nOpção 3 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> escolhaMenu;

        switch (escolhaMenu) {
            case 1:
                armazenarValores();
            break;
            case 2:
                calculoSalarioFinal();
                exibirResultado();
            break;
            case 3:
                cout << endl << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            break;
            default:
                cout << "\nPor favor, digite uma opção de 1 a 3..." << endl;
                system ("pause");
        }
    }
}

// Função que invoca as funções de leitura e armazena os dados nos campos do Struct
void armazenarValores() {
    sal.SM = lerSalario();
    sal.PR = lerReajusteSalarial();
}

//Funções de leitura
double lerSalario() { 
    double salario;
    cout << endl << "\nDigite o salário mensal: ";
    cin >> salario;
    return salario;
}

double lerReajusteSalarial() {
    double percentual;
    cout << "\nDigite o percentual do reajuste salárial: ";
    cin >> percentual;
    return percentual;
}

// Função de cálculo
void calculoSalarioFinal () {
    sal.NS = sal.SM + (sal.PR * sal.SM);
}

// Função de exibição
void exibirResultado () {
    cout << endl << "\nO valor final do salário com reajuste é: " << sal.NS << " R$" << endl;
    system ("pause");
}






