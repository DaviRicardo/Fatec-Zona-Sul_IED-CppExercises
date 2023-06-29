/* 
Este exemplo cria o vetor x [ ] com n elementos, em seguida descobre o número de elementos (n), sizeof(x) é o tamanho total do vetor x, 
sizeof(int) é o tamanho de um elemento do tipo int. Cria-se uma variável aux para armazenar a soma do quadrado do elemento do vetor com ele mesmo. 
O loop for é utilizado para armazenar e exibir o valor de aux. 
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  system ("cls");

  int x[ ] = {1, 0, -1};
  int n = sizeof(x) / sizeof(int); 
  
  int aux = 0;
  
  for (int i = 0; i < n; i++) { 
    aux = pow(x[i], 2) + x [i];
    cout << aux << endl;
  }
  return 0; 
}
  