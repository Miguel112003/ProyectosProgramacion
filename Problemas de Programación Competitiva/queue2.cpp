#include <map>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;
/*
Trate de solucionar esto de forma eficiente y no supe como poder trabajar la lista y el mapa en conjunto
para poder tener la dichosa solucion de n*logn, sin embargo todo lo que intente me dejaba con un pequeño error
aqui el error es que si inserto un paciente al principio de la fila, luego cuando me lo encuentro de nuevo no tengo claro
como hacer para ignorarlo, seguramente hay una solucion simple pero no logre hallar la solucion

int main(){
    int p, c;
    int contador = 1;
    int ValorConfianza = 0;
    while((cin >> p >> c) && p && c){
        cout << "Case: " << contador++ << endl;
        deque<int> fila;
        multimap<int,int> confianza;
        char operacion;
        int indice;
        int cambio = 1;
        int minimo = min(p,c);
        int i = 1;
        for(i; i <= minimo;i++){
            fila.push_back(i);
            confianza.insert({i,ValorConfianza});
        }
        while(c--){
            cin >> operacion;
            int bandera = 0;
            if(operacion == 'N'){
                auto rango = confianza.equal_range(fila.front());
                if(confianza.count(fila.front()) == 1){
                    cout << "Entro" << endl;
                    cout << fila.front() << endl;
                    fila.push_back(fila.front());
                    fila.pop_front();
                }
                else{
                    auto it = rango.first
                    while(it != rango.second){

                        }
                    }
                }

            }
            else{
                cin >> indice;
                if(indice >= i){
                    fila.push_front(indice);
                    confianza.emplace(indice,0);
                }
                else{
                    fila.push_front(indice);
                    confianza.insert({indice,confianza.count(indice)});
                    }
                }
            }
        }
        return 0;
    }
*/


//Solucion Ineficiente

/*
Esta solucion tiene una complejidad de O(n^2) ya que para la cantidad de casos de prueba C (Ya esto es una complejidad de O(n)),
realiza una comparacion para ver si solamente toma el primer dato (Mejor caso) o si tengo que anexar a la fila (O(!)), encontrrar al clon
O(n) y borrarlo O(1). Dandome una complejidad total en el peor caso de O(n^2)
*/

int main(){
    int p, c;
    int contador = 1;
    int ValorConfianza = 0;
    while((cin >> p >> c) && p && c){
        cout << "Case " << contador++ << ":" << endl;
        deque<int> fila;
        char operacion;
        int indice;
        int cambio = 1;
        int minimo = min(p,c);
        int i = 1;
        for(i; i <= minimo;i++){
            fila.push_back(i);
        }
        while(c--){
            cin >> operacion;
            if(operacion == 'N'){
                cout << fila.front() << endl;
                fila.push_back(fila.front());
                fila.pop_front();
            }
            else{
                cin >> indice;
                if(indice >= i){
                    fila.push_front(indice);
                }
                else{
                    fila.push_front(indice);
                    int bandera = 0;
                    for(auto it = fila.begin()+1;it!=fila.end() && bandera == 0;it++){
                       if(*it == indice){
                        fila.erase(it);
                        bandera = 1;
                       }
                    }

                }
            }
        }
    }
    return 0;
}

