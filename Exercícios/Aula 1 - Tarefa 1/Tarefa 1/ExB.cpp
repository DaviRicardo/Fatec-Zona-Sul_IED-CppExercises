/*
b) Fazer um programa que leia através do teclado dados de clientes para um cadastro de um site qualquer, 
os dados deverão ser armazenados em vetores: nome, cpf, endereço, email e telefone. Permitir a leitura de no máximo  4 registros apenas
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

void controle ();
string lerTelefone ();
string lerCpf ();
string lerNome ();
string lerEmail ();
string lerEndereco ();
void exibirResultado (string telefone, string cpf, string nome, string email, string endereco, int i);

int main () { 
    controle();
    return 0; 
}

void controle() {
    int respostaMenu = 0;
    int const n = 4;
    string telefone [n];
    string cpf [n];
    string nome [n];
    string email [n];
    string endereco [n];
    
    while (respostaMenu != 3) {
        system ("cls");
        cout << "Opção 1 - Inserir cadastros";
        cout << "\nOpção 2 - Ler cadastros";
        cout << "\nOpção 3 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> respostaMenu;

        switch (respostaMenu) {
            case 1: 
                cout << "\n";
                for (int i = 0; i < n; i++) {
                    cout << "\n" << i + 1 << "° cadastro\n";
                    nome[i] = lerNome();
                    email[i] = lerEmail();
                    telefone[i] = lerTelefone();
                    endereco[i] = lerEndereco();
                    cpf[i] = lerCpf();
                    cout << "\n====================================" << endl;
                }
            break;
            case 2: 
                system ("cls");
                for (int i = 0; i < n; i++) {
                    exibirResultado (telefone[i], cpf[i], nome[i], email[i], endereco[i], i);
                }
                system ("pause");
            break;
            case 3:
                cout << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            break;
            default:
                cout << "\nPor favor, digite apenas opções entre 1 e 3..." << endl;
                system ("pause");
        }      
    }
}

string lerTelefone () {
    string telefone;
    cout << "\nDigite o telefone (apenas números): ";
    cin >> telefone;
    return telefone;
}

string lerCpf() {
    string cpf;
    cout << "\nDigite o CPF (apenas números): ";
    cin >> cpf;
    return cpf;
}

string lerNome () {
    string nome;
    cout << "\nDigite o nome: ";
    cin.ignore();
    getline(cin, nome);
    return nome;
}

string lerEmail () {
    string email;
    cout << "\nDigite o E-mail: ";
    cin >> email;
    return email;
}

string lerEndereco () {
    string endereco;
    cout << "\nDigite o endereço: ";
    cin.ignore();
    getline(cin, endereco);
    return endereco;
}

void exibirResultado (string telefone, string cpf, string nome, string email, string endereco, int i) {
    cout << i + 1 << "° cadastro" << endl;
    cout << "\nNome: " << nome;
    cout << "\nE-mail: " << email;
    cout << "\nTelefone: " << telefone;
    cout << "\nEndereço: " << endereco;
    cout << "\nCPF: " << cpf << endl;
    cout << "\n====================================\n";
    return;
}




