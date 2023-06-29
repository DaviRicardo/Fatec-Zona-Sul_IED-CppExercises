/*
a) Fazer o programa fonte de um algoritmo para exibir os vetores: string nome [] = {“Sara Lemes”,”Ricardo Jafé”}, 
double salario [] = {12000, 10243.20} e int idade[]={30, 45}; O salário deverá ser exibido com 10% de aumento. Implemente um menu de execução. 
*/

#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
   int respostaMenu = 0;
   int idade[] = {30, 45};
   double salario[] = {12000, 10243.20};
   string nome[] = {"Sara Lemes", "Ricardo Jafé"};

   while (respostaMenu != 2) {
      system("cls");
      cout << "Opção 1 - Iniciar execução";
      cout << "\nOpção 2 - Finalizar programa\n";
      cout << "\nPor favor, escolha uma opção: ";
      cin >> respostaMenu;

      switch (respostaMenu) {
         case 1:
            cout << "\n" << endl;
            for (int i = 0; i < 2; i++) {
               cout << "Nome: " << nome[i];
               cout << "\nIdade: " << idade[i];
               cout << "\nSalário: " << salario[i] * 1.1 << endl;
               cout << "==================================" << endl;
            }
            system("pause");
         break;
         case 2:
            cout << "\nFinalizando programa..." << endl;
            system("pause");
            exit(0);
         break;
         default:
            cout << "\nPor favor, digite apenas opções de 1 a 2..." << endl;
            system("pause");
         break;
      }
   }
}
