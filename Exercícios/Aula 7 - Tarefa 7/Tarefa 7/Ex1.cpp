/*
1 - Faça um menu para testar o programa 4 e faça as alterações a seguir:
A. Insira mais um atributo no struct para armazenar um número aleatório criado por uma função randomica;
B. Crie uma função que busque e exiba uma posição qualquer de um dos nódulos da estrutura;
C. Crie uma função que informe se a estrutura está vazia.
*/

#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int cont = 0;

typedef struct me cad;

struct me {
    int pos; // Posição que indica qual o número do nó
    int aleatorio;
    cad * liga; // Ponteiro que armazena o endereço de memória do struct seguinte, de modo a fazer um encadeamento de structs ou nós.
};

cad * primeiroNo; // Ponteiro do tipo cad que armazena o endereço de memória do primeiro struct alocado na memória
cad * ultimoNo; // Ponteiro do tipo cad que armazena o endereço de memória sempre do último struct alocado na memória


void construtor () {
    primeiroNo = ultimoNo = NULL;
}

bool vazia() {
    if (primeiroNo == NULL) {
        return true;
    } else {
        return false;
    }
}

int gerarAleatorio (int a, int b) {
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b); 
    return dis(gen);
}

// Sub-rotina responsável por alocar um novo nó dinamicamente na memória.
void alocar () { 
    for (int i = 1; i <= 4; i++) {
        cont ++;
        cad * newcad = (cad *) malloc (sizeof (cad)); 

        newcad -> pos = cont;
        newcad -> aleatorio = gerarAleatorio(1, 1000);
        newcad -> liga = NULL;

        if (vazia() == 1) {
            primeiroNo = newcad;
        } else {
            ultimoNo -> liga = newcad;
            newcad -> pos = cont;
        }
        ultimoNo = newcad; 
    }
}

void exibir() {
    system("cls");
    cad * temp;
    temp = primeiroNo;

    while (temp != NULL) {
        cout << "\nPosição do atual nó: " << temp -> pos << "°" << endl;
        cout << "\nNúmero de geração aleatória: " << temp -> aleatorio << endl;
        cout << "=======================================================" << endl;
        temp = temp -> liga;
    }
    system("pause");
}


void buscarPosicao() {
    if (primeiroNo != NULL) {
        cout << endl << "\nA posição encontrada de um dos nós da estrutura é a: " << gerarAleatorio(1,cont) << "°" << endl;
    } else {
        cout << endl << "\nNão há mais nós!" << endl;
    }
    system("pause");
}


void destruir() {
    cad * temp;
    cont = 0;
    
    while (primeiroNo != NULL) {
        temp = primeiroNo;
        primeiroNo = temp -> liga;
        free(temp);
    }

    if (primeiroNo == NULL) {
        cout << endl << "\nMemória alocada liberada com sucesso!" << endl;
    } else {
        cout << endl << "\nNão foi possível a liberação de memória alocada!" << endl;
    }
    system ("pause");
}


int main() {
    int opcaoMenu = 0;
    construtor();
    
    while (opcaoMenu != 4) {
        system ("cls");
        cout << "Opção 1 - Listar nós";
        cout << "\nOpção 2 - Buscar posição aleatória";
        cout << "\nOpção 3 - Liberar memória";
        cout << "\nOpção 4 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> opcaoMenu;

        switch (opcaoMenu) {
            case 1:
                alocar();
                exibir();
            break;
            case 2:
                buscarPosicao();
            break;
            case 3:
                destruir();
            break;
            case 4:
                cout << endl << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            break;
            default:
                cout << endl << "\nPor favor, digite uma opção entre 1 e 4!" << endl;
                system ("pause");
            break;
        }
    }  
}


