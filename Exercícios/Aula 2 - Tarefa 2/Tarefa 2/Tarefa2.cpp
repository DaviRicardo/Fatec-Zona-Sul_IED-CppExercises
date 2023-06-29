/*
Faça o algoritmo para calcular o valor de uma prestação em atraso com base na multa de 2% e também do juros mensal de 1% sobre o valor principal. 
Declare vetores explícitos para entrada do valor da prestação, valorprincipal [ ] e da quantidade de dias em atraso: dias [ ]. 
Armazene os resultados no vetor ValorPagar [ 5 ]. Ao final imprima a tabela com os vetores valorPrincipal [], dias [] e valorpagar[].
*/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double const taxaMulta = 0.02;
int const n = 5;

void controle ();
double lerPrestacao(int i);
int lerAtrasoDias();
double calculoMulta (double prestacao);
double calculoJuros (double prestacao, int diasAtrasados);
double valorTotal (double prestacao, double multa, double juros);
void exibir (double prestacao, int dias, double valorFinal, int i);

int main () {
    controle ();
    return 0;
}

void controle () {
    int respostaMenu; 
    double multa, juros;
    double valorPrincipal [n];
    int dias [n];
    double valorPagar [n]; 

  while (respostaMenu != 3) {
    system ("cls");
    cout << "Opção 1 - Inserir dados";
    cout << "\nOpção 2 - Exibir dados";
    cout << "\nOpção 3 - Finalizar programa\n";
    cout << "\nPor favor, escolha uma opção: ";
    cin >> respostaMenu;

    switch (respostaMenu) {
      case 1:
        for (int i = 0; i < n; i++) {
            valorPrincipal [i] = lerPrestacao(i);
            dias [i] = lerAtrasoDias();
            multa = calculoMulta (valorPrincipal[i]);
            juros = calculoJuros (valorPrincipal[i], dias[i]);
            valorPagar[i] = valorTotal (valorPrincipal[i], multa, juros);
        }
      break;
      case 2: 
        system ("cls");
        for (int i = 0; i < n; i ++) {
            exibir (valorPrincipal[i], dias[i], valorPagar[i], i);
        }
        system ("pause");
      break;
      case 3:
        cout << "\nFinalizando programa..." << endl;
        system ("pause");
        exit(0);
      break;
      default:
        cout << "\nPor favor, digite uma opção de 1 a 3..." << endl;
        system ("pause");
      break;
    } 
  }
}

// Início das funções de leitura
double lerPrestacao (int i) {
    double prestacao;
    cout << endl << "\nDigite o valor da " << i + 1 << "° prestação (R$): ";
    cin >> prestacao;
    return prestacao;
}

int lerAtrasoDias () {
    int diasEmAtraso;
    cout << "\nDigite a quantidade de dias atrasados: ";
    cin >> diasEmAtraso;
    return diasEmAtraso;
}

// Início das funções de cálculo
double calculoMulta (double prestacao) {
    double valorMulta;
    valorMulta = taxaMulta * prestacao;
    return valorMulta;
}

double calculoJuros (double prestacao, int diasEmAtraso) {
    double valorJuros, jurosSobreDiasAtraso;
    jurosSobreDiasAtraso = diasEmAtraso * 0.033; // 0,033 =  1% juros / 30 dias
    valorJuros = jurosSobreDiasAtraso * prestacao;
    return valorJuros;
}

double valorTotal (double prestacao, double multa, double juros) {
    double valor;
    valor = prestacao + multa + juros;
    return valor;
}

// Função de exibição
void exibir (double prestacao, int dias, double valorFinal, int i) {
    cout << "\n==============================================================\n" << endl;
    cout << i + 1 << "° Prestação: " << prestacao << " | Dias em atraso: " << dias << " | Valor a Pagar: " << valorFinal << endl;
    return; 
}