/*
2. Fazer o quadro resumo de sub-rotinas e código fonte de um programa para ler o comprimento, calcular o diâmetro, calcular o raio...
e finalmente a área de um círculo. Faça um menu com as opções necessárias. 
Utilize a simulação 3 como referência / modelo para fazer este trabalho. 
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

double const pi = 3.14;

double lerComprimento();
double calcDiametro (double comprimento);
double calcRaio (double comprimento);
double calcArea (double comprimento);
void exibirResultado (double diametro, double raio, double area);

int main () {
  int escolhaMenu;
  double valorComprimento, valorDiametro, valorRaio, valorArea;
  
  while (escolhaMenu != 2) { 
    system ("cls");

    cout << "Opção 1 - Executar programa";
    cout << "\nOpção 2 - Finalizar programa\n";
    cout << "\nPor favor, escolha uma opção: ";
    cin >> escolhaMenu;

    switch (escolhaMenu) {
      case 1:
        valorComprimento = lerComprimento();
        valorDiametro = calcDiametro (valorComprimento);
        valorRaio = calcRaio (valorComprimento);
        valorArea = calcArea (valorComprimento);
        exibirResultado (valorDiametro, valorRaio, valorArea);
      break;
      case 2:
        cout << "\nFinalizando programa..." << endl;
        system ("pause");
        exit(0);
      break;
      default:
        cout << "\nPor favor, digite uma entre as opções 1 ou 2..." << endl;
        system ("pause");
      break;
    }
  }
}

double lerComprimento() {
  double val;
  cout << "\nDigite o valor do comprimento da circunferência: ";
  cin >> val;
  return val;
}

// Funções para calcular o diâmetro, raio e área da circunferência através do comprimento
double calcDiametro (double comprimento) {
  double diametro;
  diametro = (comprimento / pi);
  return diametro;
}

double calcRaio (double comprimento) {
  double raio, diametro;
  diametro = calcDiametro (comprimento);
  raio = (diametro / 2);
  return raio;
}

double calcArea (double comprimento) {
  double area, raio;
  raio = calcRaio(comprimento);
  area = (pi * pow(raio, 2));
  return area;
}

// Função para o exibir o resultado
void exibirResultado (double diametro, double raio, double area) {
  cout << fixed << setprecision(2) << "\nDiâmetro: " << diametro << endl;
  cout << "Raio: " << raio; 
  cout << "\nÁrea: " << area << " cm²/m²" << endl;
  system ("pause");
  return;
}

