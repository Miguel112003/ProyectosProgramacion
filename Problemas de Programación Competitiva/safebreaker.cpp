#include <iostream>
#include <vector>
#include <string>

using namespace std;

string paraString(int num){
    string resultado = "";

    if(num == 0){
        resultado = "0";
    }
    bool negativo = (num < 0);
    if (negativo){
        num = -num;
    }

    while (num > 0){
        resultado = char('0' + num % 10) + resultado;
        num /= 10;
    }
    if (negativo){
        resultado = "-" + resultado;
    }
    return resultado;
}


void obtenerPista(const string& secreto, const string& adivina, int& digitosCorrectos, int& digitosMal) {
    digitosCorrectos = 0;
    digitosMal = 0;

    vector<int> cuentaSecreta(10);
    vector<int> cuentaAdivina(10);

    for(int i = 0; i != 10; i++){
        cuentaSecreta[i] = 0;
        cuentaAdivina[i] = 0;
    }

    for (int i = 0; i < 4; ++i) {
        if (secreto[i] == adivina[i]) {
            digitosCorrectos++;
        } else {
            cuentaSecreta[secreto[i] - '0']++;
            cuentaAdivina[adivina[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; ++i) {
        digitosMal += min(cuentaSecreta[i], cuentaAdivina[i]);
    }
}



bool verificarCodigo(const vector<string>& adivinanzas, const vector<vector<int>>& pistas, const string& secreto) {
    for (int i = 0; i < adivinanzas.size(); ++i) {
        int digitosCorrectos, digitosMal;
        obtenerPista(secreto, adivinanzas[i], digitosCorrectos, digitosMal);
        if (digitosCorrectos != pistas[i][0] || digitosMal != pistas[i][1]) {
            return false;
        }
    }
    return true;
}



int main() {
    int casos;
    cin >> casos;
    for (int espacio = 0; espacio < casos; ++espacio) {
        int cantidadClaves;
        cin >> cantidadClaves;
        vector<string> adivinanzas(cantidadClaves);
        vector<vector<int>> pistas(cantidadClaves, vector<int>(2)); //Un vector de vectores como se sigue llamando matriz? o el algebra lineal no aplica aqui?
        for (int i = 0; i < cantidadClaves; ++i) {
            cin >> adivinanzas[i] >> pistas[i][0];
            cin.ignore(1);
            cin >> pistas[i][1];
        }

        int codigosPosibles = 0;
        string respuesta;
        for (int i = 0; i <= 9999; ++i) {
            string codigo = paraString(i);
            while (codigo.length() < 4) {
                codigo = codigo + "0";
            }

            if (verificarCodigo(adivinanzas, pistas, codigo)) {
                codigosPosibles++;
                respuesta = codigo;
            }
        }

        if (codigosPosibles == 0) {
            cout << "impossible" << endl;
        } else if (codigosPosibles == 1) {
            cout << respuesta << endl;
        } else {
            cout << "indeterminate" << endl;
        }
    }
}


//Hola, escribo esto porque la arena me rechazo la solucion por se demasiado poco eficiente
//Entiendo que a este punto ya debemos obtener soluciones eficientes y perfectas
//Pero me paso en los dos casos que intente por fuerza bruta, voy a intentar reimplementar pero
//si no subo nada mas a la arena y estan leyendo esto es que no consegui sacar una implementacion diferente
//Que cumpliera con los casos de prueba
//Como no se si esta solucion sera la ultima que suba o no, no analizare complejidad