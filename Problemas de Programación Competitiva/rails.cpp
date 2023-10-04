#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
//Complejidad Objetivo: O(n)

/*
Respecto a la complejidad de esta solucion
La complejidad de este algoritmo es O(n), donde n es el numero de vagones
del tren, ya que iteramos a traves de cada vagon cuando
nos lo encontramos por primera vez, despues lo retiramos de la pila
*/

int main(){
  int vagones;
  while(cin >> vagones && vagones){
    bool termina = false;
    while(!termina){
      vector<int> permutaciones(vagones+1);
      cin >> permutaciones[1];
      if(permutaciones[1] == 0) {
        termina = true;
      }
      else {
        auto it = permutaciones.begin() + 2;
        while(it != permutaciones.end()) {
          cin >> *it++;
        }
        stack<int> estacion;
        bool posible = true;
        int esperado = 1, siguiente = 1;
        bool continua = true;
        while((!estacion.empty() || siguiente <= vagones) && continua){
          if(siguiente <= vagones && esperado == permutaciones[siguiente]) {
            esperado++;
            siguiente++;
          }
          else if(!estacion.empty() && estacion.top() == permutaciones[siguiente]) {
            estacion.pop();
            siguiente++;
          }
          else if(esperado <= vagones) {
            estacion.push(esperado);
            esperado++;
          }
          else {
            posible = false;
            continua = false;
          }
        }
        if(posible && estacion.empty()) {
          cout << "Yes" << endl;
        }
        else {
          cout << "No" << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}

