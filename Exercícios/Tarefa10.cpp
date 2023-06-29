/*
Monte e execute o código da LISTA, crie um menu de controle para controlar o programa, 
mexa nos dados internos do struct de alocação, acrescente os campos nome, cpf e rg. 
Crie as funções para buscar um cpf exibindo o nome da pessoa encontrada e para excluir um registro através do cpf. 
*/

#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

struct noLista {
    char nome[50];
    long long int chave;
    long long int cpf;
    long long int rg;
    noLista *prox;
};

noLista *primeiro;
int cont;


void construtor() {
    system("cls");
    primeiro = NULL;
    cout << "LISTA iniciada!" << endl;
    system("pause");
}

bool vazia() {
    if (primeiro == NULL)
        return true;
    else
        return false;
}

int obterPosicao() {
    int posicao;
    cout << "\nDigite a posicao: ";
    cin >> posicao;
    return posicao;
}

bool inserir(long long int cpf, long long int rg, int pos) {
    noLista *ant; 
    ant = NULL;
    noLista *temp;
    temp = primeiro;
    int cont = 0;
    char entradaNome[50] = "Davi";

    noLista *novoNo = (noLista *) malloc(sizeof(noLista));

    if (novoNo == NULL || (vazia() == true && pos != 1)) return false; 

    strcpy(novoNo -> nome, entradaNome);
    novoNo -> cpf = cpf;
    novoNo -> rg = rg;

    // Situação 1 - Inserir na primeira posição de uma lista vazio.
    if (pos == 1 && vazia() == 1) { 
        novoNo -> prox = NULL;
        primeiro = novoNo;
        return true;
    // Situação 2 - Inserir na primeira posição de uma lista não vazia.
    } else if (pos == 1 && vazia() != 1) {
        novoNo -> prox = primeiro;
        primeiro = novoNo;
        return true;
    // Situação 3 - Inserir em uma posição diferente da primeira em uma lista não vazia.
    } else {
        while (temp != NULL) {
            cont++;
            if (pos == cont) {
                novoNo->prox = temp;
                ant->prox = novoNo;
                return true;
             }
            ant = temp;
            temp = temp->prox;
        }
    }
    return false;
}

void buscarNomePorCpf() {
    noLista *temp;
    temp = primeiro;
    long long int cpf;

    if (temp == NULL) {
        cout << endl << "\nNão há nomes registrados" << endl;
        system ("pause");
        return;
    }
    cout << endl << "\nDigite o CPF: ";
    cin >> cpf;
    
    while (temp != NULL) {
        if (cpf == temp -> cpf) {     
            cout << endl << "\nO nome encontrado é: " << temp -> nome << endl;
            system ("sleep 4");
            break;
        }
    temp = temp -> prox;
  }
}

void removerPorCpf() { 
    noLista * temp;
    temp = primeiro;
    noLista * anterior;
    anterior = NULL;
    
    int posicao = 0;
    long long int cpf;

    if (temp == NULL) {
        cout << endl << "\nNão há mais registros!" << endl;
        system ("pause");
        return;
    }

    cout << endl << "\nDigite o CPF: ";
    cin >> cpf;

    while (temp != NULL) {
        posicao ++; 
        if (cpf == temp -> cpf) { 
            if (posicao == 1) { 
                primeiro = temp -> prox;
            } else {
                anterior -> prox = temp -> prox;
            }

            cout << endl << "\nO registro: " << endl;
            cout << "\nNome: " << temp -> nome;
            cout << "\nCPF: " << temp -> cpf;
            cout << "\nRG: " << temp -> rg;
            cout << endl << "\nSerá excluído!" << endl;
            free (temp);
            break;
        }  
        anterior = temp;
        temp = temp -> prox;
    }
  system ("pause");
}

int total() {
    noLista *temp;
    temp = primeiro;

    while (temp != NULL) {
        cont++;
        temp = temp->prox;
    }
    return cont;
}

void mostrar() {
    system("cls");
    noLista * temp;
    temp = primeiro;
    int pos = 0;
  
    while (temp != NULL) {
        pos++;
        if (pos == 5) {
            free (temp);
            cont --;
            break;
        }   
        cout << endl << pos << "° registro" << endl;
        cout << "\nNome: " << temp -> nome << endl;
        cout << "\nCPF: " << temp -> cpf << endl;
        cout << "\nRG: " << temp -> rg << endl;
        cout << "\n=======================" << endl;
        temp = temp -> prox;
    }
    cout << endl << "Total de registros: " << total() << endl;
    system("pause");
}

void destrutor() {
    noLista *temp;

    while (temp != NULL) {
        temp = temp->prox;
        free(temp);
    }
    free(primeiro);
    cout << endl << "\nLISTA destruída...!\n";
    system("pause");
}


int main() {
    int opcaoMenu;
    construtor();

    while (opcaoMenu != 6) {
        system("cls");
        cout << "Opção 1 - Inserir registro";
        cout << "\nOpção 2 - Listar registros";
        cout << "\nOpção 3 - Buscar nome por CPF";
        cout << "\nOpção 4 - Excluir registro por CPF";
        cout << "\nOpção 5 - Excluir todos os registros";
        cout << "\nOpção 6 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> opcaoMenu;

        switch (opcaoMenu) {
            case 1:
                for (int i = 0; i <= 1; i++) {
                    inserir(12345678912, 456791376, 1);
                    inserir(26489784963, 798456123, 2);
                    inserir(34589497898, 156487951, 3);
                    inserir(12345625649, 123459798, 4);
                }
            break;
            case 2:
                mostrar();
            break;
            case 3:
                buscarNomePorCpf();
            break;
            case 4:
                removerPorCpf();
            break;
            case 5:
                destrutor();
            break;
            case 6:
                cout << "\nFinalizando programa..." << endl;
                system("pause");
                exit(0);
            break;
            default:
                cout << endl << "\nPor favor, escolha uma opção de 1 a 5!" << endl;
                system("pause");
            break;
        }
    }
    return 0;
}