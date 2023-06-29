/*
1. Monte o programa FIFO colocando um menu de controle;
2. Altere o código da FIFO, acrescente os atributos Nome e CPF, faça as funções para buscar o nome de uma pessoa...
e também para excluir um registro através do nome, se você excluir um elemento da fila então deverá redirecionar os ponteiros para não quebrar o encadeamento da fila.
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;


struct noFifo {
    char nome[50];
    long long int cpf;
    int posicao;
    noFifo * prox; 
};

noFifo * primeiroNo;
noFifo * ultimoNo; 
int cont = 0; 


void construtor() { 
    system ("cls");
    primeiroNo = ultimoNo = NULL;
    cout << "FIFO iniciada!" << endl;
    system ("pause");
}


bool vazia () {
    return (primeiroNo == NULL);
}

long long int obterCpf() {
    long long int cpf;
    cout << "\nDigite o CPF (apenas números): ";
    cin >> cpf; 
    return cpf;
}

void inserirNo() {
    char entradaNome[50];
    
    cout << endl;
    for (int i = 1; i <= 5; i++)  {
        cont ++;
        cout << endl << i << "° registro" << endl;
        cout << "\nDigite o nome: ";
        cin >> entradaNome;
     
        noFifo * novoNo = (noFifo *) malloc (sizeof (noFifo));

        if (novoNo == NULL) { 
            cout << "\nErro de alocação!" << endl;
            system("pause");
            break; 
        }

        strcpy(novoNo -> nome, entradaNome);
        novoNo -> cpf = obterCpf();
        novoNo -> posicao = cont;
        novoNo -> prox = NULL;
        cout << endl;
    
        if (vazia() == true) { 
            primeiroNo = novoNo;
        } else { 
            ultimoNo -> prox = novoNo; 
        } 
        ultimoNo = novoNo;
    }
}

void mostrar () {
    noFifo * temp;
    temp = primeiroNo;
    
    if (temp == NULL) {
        cout << endl << "\nNão há nomes para serem exibidos!" << endl;
        system ("pause");
        return;
    }

    cout << endl;
    system ("cls");

    while (temp != NULL) {
        cout << endl << temp -> posicao << "° registro" << endl;
        cout << "\nNome: " << temp -> nome << endl;
        cout << "\nCPF: " << temp -> cpf;
        cout << "\n========================================" << endl;
        temp = temp -> prox;
    }
    system("pause");
}


void removerPrimeiroNo() {
    noFifo * temp; 
    temp = primeiroNo; 

    if (!vazia()) {
        cout << endl << "\nO registro de número " << temp -> posicao << ":" << endl;
        cout << "\nNome: " << temp -> nome << endl;
        cout << "\nCPF: " << temp -> cpf << endl;
        cout << "\nFoi excluido com sucesso!" << endl;
        primeiroNo = temp -> prox;
    } else {
        cout << endl << "\nTodos os elementos já foram removidos!" << endl;
    }
    free (temp);
    cont --;
    system("pause");
}

void removerPorNome() {
    noFifo * temp;
    temp = primeiroNo;
    noFifo * anterior;
    anterior = NULL;
    
    int posicao = 0;
    string nome;

    if (temp == NULL) {
        cout << endl << "\nNão há mais registros!" << endl;
        system ("pause");
        return;
    }

    cout << endl << "\nDigite o nome contido em um registro para exclui-lo: ";
    cin >> nome;

    while (temp != NULL) {
        posicao ++; 
        if (nome == temp -> nome) { 
            if (posicao == 1) { 
                primeiroNo = temp -> prox;
            } else {
                anterior -> prox = temp -> prox;
            }
            cout << endl << "\nO registro com nome de '" << temp -> nome << "'" << " e CPF '" << temp -> cpf << "' será excluído!" << endl;
            free (temp);
            break;
        }
        anterior = temp;
        temp = temp -> prox;
    }
    system ("pause");
}

void destrutor() {
    noFifo * temp;
    cont = 0;
  
    while (primeiroNo != NULL) {
        temp = primeiroNo;
        primeiroNo = temp -> prox;
        free (temp);
    }
    
    if (primeiroNo == NULL) {
        cout << endl << "\nPilha destruída com sucesso!" << endl;
    } else {
        cout << endl << "\nNão foi possível destrui a pilha!" << endl;
    }
    system("pause");
}

int main () {
    int opcaoMenu = 0;
    construtor();

    while (opcaoMenu != 6) {
        system ("cls");
        cout << "Opção 1 - Inserir registros";
        cout << "\nOpção 2 - Exibir registros";
        cout << "\nOpção 3 - Excluir primeiro elemento da fila";
        cout << "\nOpção 4 - Excluir registro por nome";
        cout << "\nOpção 5 - Excluir todos os registros";
        cout << "\nOpção 6 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> opcaoMenu;

        switch (opcaoMenu) {
            case 1:
                inserirNo();
            break;
            case 2:
                mostrar();
            break;
            case 3:
                removerPrimeiroNo();
            break;
            case 4:
                removerPorNome();
            break;
            case 5:
                destrutor();
            break;
            case 6:
                cout << endl << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            break;
            default:
                cout << endl << "\nPor favor, digite uma opção de 1 a 6!" << endl;
                system ("pause");
            break;
        }
    }
}