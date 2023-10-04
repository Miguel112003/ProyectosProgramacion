//Miguel Bejarano Perdomo

//8959501

/*
En cuanto a la complejidad de esta solucion
Una vez tengo los datos almacenados en un vector los ordeno con la funcion sort(), esto tiene una complejidad
de O(n*log2(n)), la cual se debe sumar al T(n) final.

Luego de esto creo un ciclo que depende directamente del tiempo que se tarde en encontrarse una cadena y existe la posibilidad
de que si no se encuentra, sea un ciclo infinito.
Entonces deberiamos analizar mejor y peor caso

Peor caso:
Nunca se encuentra una posible cadena de respuesta y el ciclo se ejecuta infitamente
-No estoy seguro como se explicaria esto en terminos de complejidad pero supongo que se considera un fallo en el programa?
-Supongo que la complejidad no se puede expresar como un tamaño de entrada ya que realmente no se sabe si podria o no terminar


Mejor caso:
El mejor caso se da cuanto la posible respuesta es de 1 sola letra entre la string primera y la string segunda
Es decir que la string primera sea una A y la string segunda sea una C, por lo tanto la respuesta seria B
Seria un caso en que el ciclo while solo se ejecuta 1 vez, el ciclo for interno se ejecuta 2 veces (Pasa por A y por B y en B rompe)

Es decir en el mejor de los casos la complejidad es la misma que el de la funcion sort() ya que al obtener la cadena en este mejor
caso es solamente pasar por el caracter en cuestion. Generalizando un poco mas podria entenderse que la complejidad
del ciclo de recorrido de letras tiene una complejidad dependiendo de la respuesta, es decir desde 0 hasta n, siendo n el caracter
que encaja en el ciclo, pero en terminos mas generales y mas exagerados la complejidad en el mejor caso seria de
O(n*log2(n))


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
    int casos;
    while(scanf("%d", &casos) && casos){
        vector<string> nombres;
        string nombre;
        for(int i = 0; i < casos; i++){
            cin >> nombre;
            nombres.push_back(nombre);
        }
        sort(nombres.begin(),nombres.end());

        string primero = nombres[nombres.size()/2-1];
        string segundo = nombres[nombres.size()/2];
        string respuesta ="";
        int contador = 0;
        string prueba;
        int bandera = 0;
        int bandera2 = 0;

        while(bandera == 0){
            for(int i = 0; i < 26 && bandera2 == 0; i++){
                prueba = respuesta;
                prueba += char(i + 65);
                if(prueba >= primero && prueba < segundo){
                    bandera = 1;
                    bandera2 = 1;
                }
            }
            respuesta += primero[contador++];
        }
        cout << prueba << endl;
    }
    return 0;
}

//Aunque la arena no me lo recibio fue la solucion que pude sacar
