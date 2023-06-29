/*
2 - Projete uma estrutura chamada cad2 encadeada que contenha nódulos com os seguintes atributos: 
int pos; string nome; *cad2 anterior; A estrutura deverá ser encadeada da seguinte forma: 
Deverá ter um ponteiro chamado UltimoNo que servirá para manter sempre o endereço de memória do ultimoNo que será adicionado na estrutura. 
Cada nódulo deverá ter um ponteiro interno do tipo *cad2 apontando para o nódulo/struct anterior até chegar...
 no primeiro nódulo adicionado que deverá ter seu ponteiro anterior apontando para NULL.
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int cont = 0;

typedef struct me cad2;

struct me {
    int pos; 
    char nome[50];
    cad2 * anterior; 
};

cad2 * ultimoNo;

void construtor () {
    ultimoNo = NULL;
}

void alocar () { 
    char entradaNome[50];
    
    for (int i = 1; i <= 4; i++) {
        cont ++;
        cout << "\nDigite o " << i << "° nome: ";
        cin >> entradaNome;
    
        cad2 * newCad = (cad2 *) malloc (sizeof (cad2)); 

        strcpy(newCad -> nome, entradaNome);  
        newCad -> anterior = ultimoNo; 
        ultimoNo = newCad;
    }  
}

void exibir() {
    system("cls");
    cad2 * temp;
    temp = ultimoNo;
    
    for (int i = 4; i >= 1; i--) {
        cout << "\nPosição do atual nó: " << i << "°" << endl;
        cout << "\nNome: " << temp -> nome << endl; 
        cout << "==============================================" << endl;
        temp = temp -> anterior;
    }
    system ("pause");
}

void destruir() {
    cad2 * temp;
    temp = ultimoNo;
    cont = 0;
  
    while (temp != NULL) {
        temp = temp -> anterior;
        free (temp);
    }

    free (ultimoNo);

    if (temp == NULL) {
        cout << endl << "\nMemória alocada liberada com sucesso!" << endl;
    } else {
        cout << endl << "\nNão foi possível a liberação de memória alocada!" << endl;
    }
}
  
int main() {
    system ("cls");
    
    construtor ();
    alocar();
    exibir();
    destruir();
    return 0;  
}  
