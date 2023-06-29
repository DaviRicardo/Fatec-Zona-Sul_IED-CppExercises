#include <iostream>
#include <cstdlib>
using namespace std;

int cont = 0;

typedef struct me cad;

struct me {
  int pos;
  cad * liga; // Ponteiro que armazena o endereço de memória do struct seguinte, de modo a fazer um encadeamento de structs ou nós.
};

cad * primeiroNO; // Ponteiro do tipo cad que armazena o endereço de memória do primeiro struct alocado na memória
cad * ultimoNo; // Ponteiro do tipo cad que armazena o endereço de memória sempre do último struct alocado na memória

// Sub-rotina responsável por alocar um novo nó dinamicamente na memória.
void alocar () { 
    cont ++;
    cad * newcad = (cad *) malloc (sizeof (cad));

    if (newcad == NULL) {
        cout << "\nDeu errado! Não tem mais memória..! "<< endl;
        exit(0);
    } else { 
        cout << "\n" << sizeof (cad) << " bytes de memória alocados com sucesso!" << endl;
    }

    if (cont == 1 ) {
        newcad-> liga = NULL; 
        newcad-> pos = cont;
        primeiroNO = newcad;
    } else {
        ultimoNo->liga = newcad;
        newcad->liga = NULL;
        newcad-> pos = cont;
    }
    ultimoNo = newcad;
}

void exibir() {
    cad * temp;
    temp = primeiroNO;
    
    while (temp != NULL) {
        cout << temp -> pos << endl;
        temp = temp->liga;
    }
}

void destruir() {
    cad * temp;
    cad * aux;
    temp = primeiroNO;
    
    while (temp != NULL) {
        aux = temp;
        temp = temp->liga; 
        free (aux);
    }
    cout << "\nMemória liberada com sucesso...!" << endl;
}

int main() {
    system ("cls");
    for (int i = 1; i <= 4; i++) {
        alocar();
        exibir();
        destruir ();
    }
}


