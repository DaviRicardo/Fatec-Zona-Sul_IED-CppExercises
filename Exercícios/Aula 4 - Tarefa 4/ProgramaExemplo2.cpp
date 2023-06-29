#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

int const n = 5; 
int linha =-1;

struct disciplinas {
    string nome [n];
    double nota1 [n];
    double nota2 [n];
    double media [n]; 
};
 
struct disciplinas tbmedias;

string ler_nome () { 
    string nome;
    cout << "\nNome: "; 
    getline(cin,nome);
    return nome; 
}
 
double ler_nota1 () { 
    double m;
    cout << "\nNota1: "; 
    cin >> m;
    return m;
}
 
double ler_nota2 () { 
    double m;
    cout << "\nNota2: ";
    cin>> m;
    return m;
}

void novoregistro () { 
    linha++; 
    cin.ignore();
    string nom_temp = ler_nome();
    tbmedias.nome[linha]= nom_temp;
    tbmedias.nota1[linha]= ler_nota1();
    tbmedias.nota2[linha]= ler_nota2();
}

void processar () { 
  system("cls");
  for (int i = 0; i <= linha; i++) { 
        tbmedias.media[i] = (tbmedias.nota1[i] + tbmedias.nota2[i]) / 2;
        cout << "Processando...." << endl;
        system("pause"); 
    } 
}

void exibir () { 
  system("cls");
  for (int i = 0; i <= linha; i++) { 
        cout << tbmedias.nome[i];
        cout << " - " << tbmedias.nota1[i];
        cout << " - " << tbmedias.nota2[i];
        cout << " - " << tbmedias.media[i] << endl;
    }
    system("pause"); 
}

int main () { 
  int tecla = 0;
  
  while (tecla != 4 ) {
        system("cls");
        cout<<"1 ler\n2 Processar\n3 Exibir\n4 Sair\n\nItem: ";
        cin >> tecla;
    
        switch (tecla) {
            case 1: 
                novoregistro();
            break;
            case 2: 
                processar (); 
            break;
            case 3: 
                exibir (); 
            break;
            case 4: 
                exit(0);
        }
    } 
}