/* a) Elaborar um programa de computador que efetue a leitura de quatro valores inteiros (variáveis A, B, C e D). 
Ao final o programa deverá apresentar o resultado do produto (variável P) do primeiro com o terceiro valor... 
e o resultado da soma (variável S) do segundo com o quarto valor.
a) Os dados de entrada e saída deverão ser armazenados em um struct com várias colunas;
b) Deverá conter menu com switch case, funções para leitura dos dados de entrada e as respectivas funções para calcular os dados de saída;
c) Tanto os dados de entrada quanto os dados de saída deverão ser armazenados dentro de structs.*/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

// Declaração de Sub-Rotinas
int lerValorA (), lerValorB(), lerValorC(), lerValorD();
void operacaoProduto(); // Função que calcula o produto entre o primeiro e terceiro valor
void operacaoSoma(); // Função que calcula a soma entre o segundo e o quarto valor
void novoRegistro (); // Função que armazena valores nos campos do Struct 'OperacoesComVar'
void exibirResultado ();

typedef struct operacoesComVar ocv; 

struct operacoesComVar {
  int A, B, C, D;
  int P, S;
};
  
ocv tab1; 

int main () {
  int escolhaMenu;

  while (escolhaMenu != 3) {
        system ("cls");

        cout << "Opção 1 - Inserir dados";
        cout << "\nOpção 2 - Exibir dados";
        cout << "\nOpção 3 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção : ";
        cin >> escolhaMenu;

        switch (escolhaMenu) {
            case 1:
                novoRegistro();
            break;
            case 2:
                operacaoProduto();
                operacaoSoma();
                exibirResultado();
            break;
            case 3:
                cout << "\nFinalizando o programa..." << endl;
                system ("pause");
                exit(0);
            default:
                cout << "\nPor favor, digite uma opção de 1 a 3..." << endl;
                system ("pause");
            break;
        }
    }
}

void novoRegistro () {
    tab1.A = lerValorA();
    tab1.B = lerValorB();
    tab1.C = lerValorC();
    tab1.D = lerValorD();
}

// Funções de leitura
int lerValorA() {
    int valor;
    cout << endl << "\nDigite o primeiro valor: ";
    cin >> valor;
    return valor;
}

int lerValorB() {
    int valor;
    cout << "\nDigite o segundo valor: ";
    cin >> valor;
    return valor;
}

int lerValorC() {
    int valor;
    cout << "\nDigite o terceiro valor: ";
    cin >> valor;
    return valor;
}

int lerValorD() {
    int valor;
    cout << "\nDigite o quarto valor: ";
    cin >> valor;
    return valor;
}

//Funções de cálculo
void operacaoProduto() {
    tab1.P = tab1.A * tab1.C;      
}

void operacaoSoma() {
    tab1.S = tab1.B + tab1.D;
}

void exibirResultado() {
    system ("cls");
    cout << "O produto entre " << tab1.A << " e " << tab1.C << " é: " << tab1.P << endl;
    cout << "A soma entre " << tab1.B << " e " << tab1.D << " é: " << tab1.S << endl;
    system ("pause");
}