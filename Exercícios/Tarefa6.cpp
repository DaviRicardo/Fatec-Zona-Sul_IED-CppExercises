/* 
Faça um programa com menu de três opções (1 - ler linha, 2 - mostrar e 3 - sair), 
contendo um STRUCT para cadastrar o nome, a idade, o sexo, salário e salarioNovo de pelo menos duas pessoas. 
Crie um ponteiro para manipular o STRUCT. O programa deverá conter as seguintes sub rotinas abaixo: (use switch case )
a) void NovaLinhaStruct ( ) 
b) void listarLinhasStruct ( )
c) ler_idade ( )
d) ler_sexo ( )
e) ler_nome ( )
f) ler_salario ( )
g) getAumento ( double *salario ) aumento de 10% sobre o salário digitado
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
#define aumento 0.1

int linha = -1;
int contadorPessoa = 0;

// Declaração de sub-rotinas
void novaLinhaStruct();
string ler_nome ();
string ler_sexo ();
int ler_idade ();
double ler_salario();
double getAumento (double *salario);
void listarLinhas ();

typedef struct assalariados pessoa;

struct assalariados {
    string nome[2], sexo[2];
    int idade[2];
    double salario[2], salarioNovo[2];
};

pessoa p;
pessoa *ptp;

int main() {
    int escolhaMenu;
    ptp = &p;

    while (escolhaMenu != 3) {
        system ("cls");

        linha = -1;
        contadorPessoa = 0;
    
        cout << "Opção 1 - Ler linha";
        cout << "\nOpção 2 - Mostrar";
        cout << "\nOpção 3 - Sair\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> escolhaMenu;

        switch (escolhaMenu) {
            case 1:
                novaLinhaStruct();
            break;
            case 2:
                listarLinhas();
            break;
            case 3:
                cout << endl << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            break;
            default:
                cout << "Por favor, digite uma opção de 1 a 3..." << endl;
                system ("pause");
            break;
        }
    }
}

void novaLinhaStruct() {
    for (int i = 0; i < 2; i++) {
        linha ++;
        contadorPessoa++;
        ptp -> nome[linha] = ler_nome();
        ptp -> sexo[linha] = ler_sexo();
        ptp -> idade[linha] = ler_idade();
        ptp -> salario[linha] = ler_salario();
        ptp -> salarioNovo[linha] = getAumento(&ptp ->salario[linha]);
    }
}

string ler_nome() { 
    string nome;
    cout << endl << "\nDigite o nome da " << contadorPessoa << "° pessoa: ";
    cin >> nome;
    return nome;
}

string ler_sexo() {
    string sexo;
    cout << "\nDigite o sexo da " << contadorPessoa << "° pessoa: ";
    cin >> sexo;
    return sexo;
}

int ler_idade() {
    int idade;
    cout << "\nDigite a idade da " << contadorPessoa << "° pessoa: ";
    cin.ignore();
    cin >> idade;
    return idade;
}

double ler_salario() {
    double salario;
    cout << "\nDigite o salário da " << contadorPessoa << "° pessoa: ";
    cin >> salario;
    return salario;
}

double getAumento (double *salario) {
    double novoSalario;
    novoSalario = *salario + (*salario * aumento);
    return novoSalario;
}

void listarLinhas() {
    system ("cls");
    for (int i = 0; i < 2; i++) {
        linha ++;
        contadorPessoa++;
        cout << endl << contadorPessoa << "° pessoa" << endl;
        cout << endl << "Nome: " << ptp -> nome[linha];
        cout << endl << "Sexo: " << ptp -> sexo[linha];
        cout << endl << "Idade: " << ptp -> idade[linha];
        cout << endl << "Salário: " << ptp -> salario[linha];
        cout << endl << "Salário aumentado: " << ptp -> salarioNovo[linha] << endl;
    }
    system ("pause");
}