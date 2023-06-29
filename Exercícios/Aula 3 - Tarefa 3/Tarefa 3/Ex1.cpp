/*
1. Criar um programa calculadora que apresente um menu de seleções no programa principal. 
Esse menu deverá dar ao usuário a possibilidade de escolher uma entre quatro operações aritméticas. 
Escolhida a opção desejada, deverá ser solicitada à entrada de dois números, e processada a operação deverá ser exibido o resultado. 
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

void calculoAdicao (double num1, double num2);
void calculoSubtracao (double num1, double num2);
void calculoMultiplicacao (double num1, double num2);
void calculoDivisao (double num1, double num2);

int main () {
  int escolhaMenu;
  double val1, val2;
  
  while (escolhaMenu != 5) {
    system ("cls");
    
    cout << "Opcão 1 - Adição";
    cout << "\nOpção 2 - Subtração";
    cout << "\nOpção 3 - Multiplicação";
    cout << "\nOpção 4 - Divisão";
    cout << "\nOpção 5 - Finalizar programa\n";
    cout << "\nPor favor, escolha uma opção: ";
    cin >> escolhaMenu;

    if (escolhaMenu == 5) {
      cout << "\nFinalizando programa..." << endl;
      system ("pause");
      exit (0);
    }
    
    cout << "\nDigite um valor: ";
    cin >> val1;

    cout << "\nDigite outro valor: ";
    cin >> val2;

    switch (escolhaMenu) {
      case 1: 
        calculoAdicao (val1, val2);
      break;
      case 2:
        calculoSubtracao (val1, val2);
      break;
      case 3:
        calculoMultiplicacao (val1, val2);
      break;
      case 4:
        calculoDivisao (val1, val2);
      break;
      default:
        cout <<"\nPor favor, digite uma opção de 1 a 5..." << endl;
        system ("sleep 4");
      break;
    }
  }  
}

void calculoAdicao (double num1, double num2) {
  double resultado = num1 + num2;
  cout << "\nO resultado da adição é: " << resultado << endl;
  system ("pause");
}

void calculoSubtracao (double num1, double num2) {
  double resultado = num1 - num2;
  cout << "\nO resultado da subtração é: " << resultado << endl;
  system ("pause");
  
}

void calculoMultiplicacao (double num1, double num2) {
  double resultado = num1 * num2;
  cout << "\nO resultado da multiplicação é: " << resultado << endl;
  system ("pause");
}

void calculoDivisao (double num1, double num2) {
  double resultado = num1 / num2;
  cout << "\nO resultado da divisão é: " << resultado << endl;
  system ("pause");
}
