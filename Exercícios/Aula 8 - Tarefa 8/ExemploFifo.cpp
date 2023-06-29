#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct sfifo fila;

struct sfifo {
    int dado;
    fila * ant;
};

fila * primeiro;
fila * ultimo;


void construtor() {
    primeiro = ultimo = NULL;
}

void inserir (int dado) {
    fila * meuNo = (fila *) malloc (sizeof (fila));
    
    if (meuNo == NULL) {
        cout << "\nAlocação inválida!\n";
        system("pause");
        return; 
    }

    meuNo->dado = dado;
    
    /*Situação 1 - Primeiro elemento da fila */
    if (primeiro == NULL) {
       meuNo->ant = NULL;
       primeiro = meuNo;
    }
    /* Situação 2 - já têm elementos na fila */
    else {  
       ultimo->ant = meuNo;
       meuNo->ant  = NULL;
    }

    ultimo = meuNo;
}

void destrutor ()  {
    fila * temp, * aux;
    temp = primeiro;
    
    while (temp != NULL) {
        aux = temp;
        temp=temp->ant;
        free(aux);
    }
    cout << "\nFila destruída !\n";
    system("pause");
}

void listar () {
    fila * temp = primeiro; 
    system("cls");

    while ( temp != NULL) {
        cout << temp->dado << "\n"; 
        temp = temp->ant;
    }
    system("pause");
}

void remover ( ) {
    fila * temp; 
    fila * aux;
    
    if (primeiro == NULL) {
        cout << "\nA fila já está vazia...!\n";
        system ("pause");
        return;
    }
    temp = primeiro;
    primeiro = temp->ant;
    free (temp);
}

int main() {
    inserir(10); 
    listar();
    remover();
    listar();
    destrutor();
    return 0;
}