/*
1. Monte e execute o programa LIFO. Crie uma sub-rotina controle() contendo um menu para executar o código.
2. Faça alterações no programa LIFO, crie o atributo nome dentro do struct, crie uma função para buscar um valor na LIFO, 
quando o valor for encontrado você deverá exibir o nome que está na mesma posição do valor encontrado, 
você pode criar o atributo posição dentro do struct para ajudar.
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

typedef struct nopilha pilha;

struct nopilha {
    int posicao;
    char nome[50];
    pilha * ant;
};

int cont;
pilha * topo;

void construtor ( ) { 
    cont = 0; 
    topo = NULL; 
}

// push = inserção
bool push () { 
    char entradaNome[50];

    cout << endl;
    for (int i = 1; i <= 5; i++) {
        cont ++;
        cout << "\nDigite o " << cont << "° nome: ";
        cin >> entradaNome;

        pilha * newPilha = (pilha *) malloc(sizeof(pilha));
  
        if (newPilha == NULL) return false;
    
        newPilha -> posicao = cont;
        newPilha -> ant = topo;
        strcpy(newPilha -> nome, entradaNome);
        topo = newPilha; 
    }
    return true;
} 

int total () { 
    pilha * temp;
    temp = topo;
    int cont = 0;
  
    while (temp != NULL) { 
        cont ++;
        temp = temp -> ant; 
    }
    return cont; 
}

void exibirPilha() {
    pilha * temp;
    temp = topo;
    
    if (temp == NULL) {
        cout << endl << "\nNão há nomes para serem exibidos!" << endl;
        system ("pause");
        return;
    }
    
    cout << endl;
    system("cls");

    while (temp != NULL) {
        cout << endl << temp -> posicao << "° posição";
        cout << endl << "\nNome: " << temp-> nome << endl;
        cout << "=======================================" << endl;
        temp = temp -> ant;
    }
    cout << endl << "\nQuantidade total de nomes registrados: " << total() << endl;
    system("pause");
}

void buscarNome() {
    pilha * temp;
    temp = topo;
    int posicao;

    if (temp == NULL) {
        cout << endl << "\nNão há mais nomes registrados!" << endl;
        system ("pause");
        return;
    }

    cout << endl << "\nDigite uma posição: ";
    cin >> posicao;

    while (temp != NULL) {
        if (posicao == temp -> posicao) {
            cout << endl << "\nO nome encontrado de posicão " << temp -> posicao << " é: " << temp -> nome << endl;
            system ("pause");
            break;
        }   
        temp = temp -> ant;
    }
  free (temp);
}

// pop = remoção (remove o último valor da LIFO)
bool pop() { 
    string nome;
    pilha * temp;
    temp = topo;

    if (temp == NULL) {
        cout << endl << "\nTodos os elementos já foram removidos!" << endl;
        system("pause");
        return false;
    }
  
    nome = temp -> nome;
    topo = topo -> ant; 
  
    cout << endl << "\nO nome removido foi: '" << nome << "' de posição " << temp -> posicao << endl;
    free(temp);
    system("pause");
    return true;
}


void destrutor() { 
    pilha * temp;
    cont = 0;
    
    while (topo != NULL) { 
        temp = topo;
        topo = topo -> ant;
        free (temp); 
    }

    free (topo);

    if (topo == NULL) {
        cout << endl << "\nPilha destruida com sucesso!" << endl;
    } else {
        cout << endl << "\nNão foi possível destruir a pilha!" << endl;
    }
    system("pause"); 
}

void controle () {
    int opcaoMenu = 0;
    construtor();

    while (opcaoMenu != 6) {
        system ("cls");
        cout << "Opção 1 - Inserir nomes";
        cout << "\nOpção 2 - Exibir nomes";
        cout << "\nOpção 3 - Buscar nome por posição";
        cout << "\nOpção 4 - Remover o último elemento da pilha";
        cout << "\nOpção 5 - Excluir todos os nomes";
        cout << "\nOpção 6 - Finalizar programa\n";
        cout << "\nPor favor, escolha uma opção: ";
        cin >> opcaoMenu;

        switch (opcaoMenu)  {
            case 1:
                push();
            break;
            case 2:
                exibirPilha();
            break;
            case 3:
                buscarNome();
            break;
            case 4:
                pop();
            break;
            case 5:
                destrutor();
            break;
            case 6:
                cout << endl << "\nFinalizando programa..." << endl;
                system ("pause");
                exit (0);
            default:
                cout << endl << "\nPor favor, escolha uma opção de 1 a 6!" << endl;
                system ("pause");
            break;
        }
    }
}


int main () {
    controle();
}