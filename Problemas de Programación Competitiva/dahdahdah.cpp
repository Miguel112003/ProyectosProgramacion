// Miguel Bejarano Perdomo
// 8959501

/*Respecto a la complejidad de esta solucion:
Dejando de lado las lineas en las que declaro variables que sumarian componentes constantes e ignorando el ciclo acorde al numero de casos que se evaluaran, tengo un ciclo for que va desde
0 hasta el largo de la cadena de entrada largo que interpretaremos como n, en incrementos de 1 en 1. Es decir este ciclo se evalua n+1 veces, sin embargo solo ingresa n veces.
A partir de este punto hay una cantidad de condicionales que se ejecutan dependiendo del contenido de la cadena, por lo tanto podemos evaluar un mejor y peor caso.

En el Mejor caso:
Se trata de que la cadena de entrada tiene 1 solo caracter y no tiene espacios dobles o simples, esto causa que el solo se ingrese al primer condicional y por ende se ejecute la linea 1 sola vez
el resto de condiciones no se cumplen y pasa fuera del ciclo for interno, en las lineas siguientes ejecuta una funcion auxiliar "descifrar" que se encarga de recibir una cadena y mediante find comparar
si esta en un vector de codigo morse, esta operacion  busca el valor entre todas las posiciones entre los dos iteradores que se le pasan. En el peor de los casos debe recorrer todas las posiciones entonces su complejidad es lineal (O(n)) con respecto al tamaño de la secuencia sobre la que se hace la búsqueda (siendo n dicho tamaño). Sin embargo,
dado que el vector en el que buscas siempre tiene tamaño predefinido constante entonces para efectos de este problema la operación find tiene complejidad O(1).
Es decir en el mejor caso tenemos que en la solucion absoluta del problema involucrando el metodo para descifrar y la impresion en pantalla tenemos una complejidad constante (ignorando el numero de casos)
es decir O(1)

En el peor caso:
Se trataria de una cadena de tamaño indefinido n en la cual puede o no haber espacios dobles o simples, causando que se ejecuten los condicionales un total de n veces y luego
se toma en cuenta las lineas por fuera del ciclo for interno, que son de complejidad constante

Dandonos como resultado en el peor caso una complejidad O(n) Si y solo si ignoramos el numero de casos, si se toma en cuenta la complejidad aumenta en un grado, pero como el enunciado de la
tarea dice "En la cabecera de cada archivo debe incluir comentarios donde explique la complejidad de su solución. Para
esto debe considerar únicamente el proceso mismo de dar solución a cada caso e imprimir el resultado."
No tomo en cuenta el ciclo del numero de casos.

*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string descifrar(string mensajeParaDescifrado){
    string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
    string letrasCode[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9",".",",","?","\'","!","/","(",")","&",":",";","=","+","-","_","\"","@"};
    vector<string> morse(morseCode, morseCode + sizeof(morseCode)/sizeof(string));
    vector<string> letras(letrasCode, letrasCode+sizeof(letrasCode)/sizeof(string));
    vector<string>::iterator it = find(morse.begin(), morse.end(), mensajeParaDescifrado);
    string mensajeTraducido = letras[it-morse.begin()];
    return mensajeTraducido;
}

int main(){
    string entrada;
    string mensajeParaDescifrado;
    string mensajeFinal;
    char delimitador = ' ';
    int casos;
    int casoActual = 1;
    int bandera = 1;
    scanf("%d", &casos);
    cin.ignore();
    while(casos--){
        getline(cin,entrada);
        cout << "Message #" << casoActual << endl;
        for(std::string::size_type i = 0; i < entrada.length(); i++){
            if(entrada[i] != delimitador){
                mensajeParaDescifrado += entrada[i];
                bandera = 1;
            }
            else if(entrada[i] == delimitador && entrada[i+1] != delimitador && bandera == 1){
                mensajeFinal += descifrar(mensajeParaDescifrado);
                mensajeParaDescifrado = "";
            }
            else if(entrada[i] == delimitador && entrada[i+1] == delimitador){
                mensajeFinal += descifrar(mensajeParaDescifrado);
                mensajeParaDescifrado = "";
                mensajeFinal += " ";
                bandera = 0;
            }
        }
        mensajeFinal += descifrar(mensajeParaDescifrado);
        if (casos == 0)
            cout << mensajeFinal;
        else
            cout << mensajeFinal << endl;
        cout << endl;
        mensajeParaDescifrado = "";
        mensajeFinal = "";
        casoActual++;
        }
    return 0;
    }


