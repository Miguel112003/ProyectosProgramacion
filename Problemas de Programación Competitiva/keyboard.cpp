#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string linea;
    int bandera = 0;
    while (getline(cin, linea) && bandera == 0) {
        list<char> salida;
        auto cursor = salida.end();

        for (int i = 0; i < linea.length(); i++) {
            char c = linea[i];
            if (c == '[') {
                cursor = salida.begin();
            } else if (c == ']') {
                cursor = salida.end();
            } else {
                salida.insert(cursor, c);
            }
        }

        for (auto it = salida.begin(); it != salida.end(); ++it) {
            char c = *it;
            cout << c;
        }
        cout << endl;

        if (cin.eof()) {
            bandera = 1;
        }
    }
    return 0;
}
/*
Respecto a la complejidad de esta solucion:
Esta solucion recorre el texto de entrada, y verifica en cada caracter si debo seguir, debo irme al inicio o al final (Como en el enunciado del problema)
Luego de eso simplemente imprimo el resultado. Por lo que acabo recorriendo la cadena de entrada 1 vez, y otra para la impresion final por lo tanto
Tengo dos ciclos que ambos van hasta el tamaño de la cadena, uno de la cadena de entrada y el otro al resultado.
Por lo tanto tengo una complejidad de O(n)
*/
