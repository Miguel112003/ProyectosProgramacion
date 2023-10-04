#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool esLetra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int contarPalabras(const vector<string>& diccionario, const string& crucigrama) {
    map<char, int> conteoLetrasCrucigrama;
    for (int i = 0; i < crucigrama.length(); i++) {
        char c = crucigrama[i];
        if (esLetra(c))
            conteoLetrasCrucigrama[c]++;
    }

    int contador = 0;
    for (int i = 0; i < diccionario.size(); i++) {
        const string& palabra = diccionario[i];
        map<char, int> conteoLetrasPalabra;
        bool palabraValida = true;
        for (int j = 0; j < palabra.length(); j++) {
            char c = palabra[j];
            if (esLetra(c))
                conteoLetrasPalabra[c]++;
        }
        int bandera = 0;
        for (map<char, int>::const_iterator it = conteoLetrasPalabra.begin(); it != conteoLetrasPalabra.end() && bandera == 0; ++it) {
            char letra = it->first;
            int conteoPalabra = it->second;
            int conteoCrucigrama = conteoLetrasCrucigrama[letra];
            if (conteoCrucigrama < conteoPalabra) {
                palabraValida = false;
                bandera = 1;
            }
        }

        if (palabraValida)
            contador++;
    }

    return contador;
}

int main() {
    vector<string> diccionario;
    string palabra;
    while (getline(cin, palabra) && palabra != "#") {
        diccionario.push_back(palabra);
    }

    string crucigrama;
    while (getline(cin, crucigrama) && crucigrama != "#") {
        int conteoPalabras = contarPalabras(diccionario, crucigrama);
        cout << conteoPalabras << endl;
    }

    return 0;
}

/*Respecto a la complejidad de la solucion:
El for que recorre el crucigrama tiene una complejidad de O(n), donde n es la longitud del crucigrama.
Dentro del bucle for, se realiza una operación de búsqueda en el mapa conteoLetrasCrucigrama. Por lo tanto, la complejidad total para el bucle for es O(n).
El otro ciclo for recorre el diccionario tiene una complejidad de O(m), donde m es el número de palabras en el diccionario.
Dentro del bucle for, se realiza una operación de búsqueda en el mapa conteoLetrasCrucigrama, lo cual tiene una complejidad promedio de O(1)
para cada letra de cada palabra en el diccionario. Por lo tanto, la complejidad total para el bucle for anidado es O(m).
En total, el tiempo de ejecución del código es O(n * m), donde n es la longitud del crucigrama y m es el número de palabras en el diccionario
En menos palabras O(n^2) :(
*/
