#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class BigInteger {
private:
    vector<int> digitos;
    bool negativo;

public:
    BigInteger(); //Constructor por defecto
    BigInteger(string numStr); //Constructor con string
    BigInteger(const BigInteger &otro); //Constructor de copia
    bool operator==(BigInteger &otro);
    bool operator<(BigInteger &otro);
    BigInteger operator -(BigInteger&);
    BigInteger operator +(BigInteger&);
    string toString();

};
//Constructor por defecto
BigInteger::BigInteger() {
    negativo = false;
}

// Constructor que toma una cadena de dígitos
BigInteger::BigInteger(string numStr) {
    int inicio = 0;
    if (numStr[0] == '-') {
        negativo = true;
        inicio = 1;
    } else {
        negativo = false;
    }

    for (int i = numStr.length() - 1; i >= inicio; i--) {
        int digito = numStr[i] - '0';
        digitos.push_back(digito);
    }
}

//Constructor de Copia
BigInteger::BigInteger(const BigInteger &otro) {
    digitos = otro.digitos;
    negativo = otro.negativo;
}

bool BigInteger::operator<(BigInteger& otro) {
    if (negativo != otro.negativo) {
        return negativo; // Si uno es negativo y el otro no, el negativo es menor
    }

    if (digitos.size() != otro.digitos.size()) {
        if (negativo) {
            return digitos.size() > otro.digitos.size(); // Si ambos son negativos, el de mayor longitud es menor
        } else {
            return digitos.size() < otro.digitos.size(); // Si ambos son positivos, el de menor longitud es menor
        }
    }

    for (int i = digitos.size() - 1; i >= 0; i--) {
        if (digitos[i] != otro.digitos[i]) {
            if (negativo) {
                return digitos[i] > otro.digitos[i]; // Si ambos son negativos, el de menor valor es mayor
            } else {
                return digitos[i] < otro.digitos[i]; // Si ambos son positivos, el de mayor valor es menor
            }
        }
    }

    return false; // Son iguales
}

//Sobrecarga de Operador +
BigInteger BigInteger::operator +(BigInteger &otro) {
    BigInteger resultado;
    int llevamos = 0;
    int i = 0;
    int maxSize = max(digitos.size(), otro.digitos.size());

    // Verificar si los dos números son negativos
    if (negativo && otro.negativo) {
        resultado.negativo = true;
    } else if (negativo) {  // Si solo el primero es negativo
        BigInteger temp = *this;
        temp.negativo = false;
        resultado = otro - temp;
        return resultado;
    } else if (otro.negativo) {  // Si solo el segundo es negativo
        BigInteger temp = otro;
        temp.negativo = false;
        resultado = *this - temp;
        return resultado;
    } //Discrimino si uno de los BigIntegers es negativo, ya que la resta no es conmutativa. El orden importa

    while (i < maxSize || llevamos) {
        int suma = llevamos;
        if (i < digitos.size()) {
            suma += digitos[i];
        }
        if (i < otro.digitos.size()) {
            suma += otro.digitos[i];
        }
        llevamos = suma / 10;
        resultado.digitos.push_back(suma % 10);
        i++;
    }

    return resultado;
}

bool BigInteger::operator==(BigInteger& otro){
    if (negativo != otro.negativo || digitos.size() != otro.digitos.size()) {
        return false;
    }
    for (int i = digitos.size() - 1; i >= 0; i--) {
        if (digitos[i] != otro.digitos[i]) {
            return false;
        }
    }
    return true;
}

BigInteger BigInteger::operator-(BigInteger& otro) {
    BigInteger resultado;

    // Si ambos números son negativos, se realiza la resta cambiando de signo
    if (negativo && otro.negativo) {
        BigInteger temp = otro;
        temp.negativo = false;
        resultado = *this + temp;
        return resultado;
    }

    // Si solo el primer número es negativo, se realiza la suma con el segundo número
    if (negativo) {
        BigInteger temp = *this;
        temp.negativo = false;
        resultado = temp + otro;
        resultado.negativo = true;
        return resultado;
    }

    // Si solo el segundo número es negativo, se realiza la suma con el primer número
    if (otro.negativo) {
        BigInteger temp = otro;
        temp.negativo = false;
        resultado = *this + temp;
        return resultado;
    }

    // Si ninguno de los números es negativo, se realiza la resta normal
    if (*this < otro) {
        resultado = otro - *this;
        resultado.negativo = true;
        return resultado;
    }

    int resta = 0;
    int llevamos = 0;
    for (int i = 0; i < digitos.size(); i++) {
        resta = digitos[i] - llevamos;
        if (i < otro.digitos.size()) {
            resta -= otro.digitos[i];
        }
        if (resta < 0) {
            resta += 10;
            llevamos = 1;
        } else {
            llevamos = 0;
        }
        resultado.digitos.push_back(resta);
    }

    // Eliminar los ceros a la izquierda del resultado
    while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
        resultado.digitos.pop_back();
    }

    return resultado;
}

//Operacion toString

string BigInteger::toString() {
    string resultado = "";

    // Verificar si el número es negativo
    if (negativo) {
        resultado += "-";
    }

    for (int i = digitos.size() - 1; i >= 0; i--) {
        resultado += to_string(digitos[i]);
    }

    return resultado;
}

La idea:
Comparar las partes enteras, si ahi ya puedo definir el mayor parar, sino
pasar a comparar las partes decimales, usando la resta me saco de encima los casos que tienen muchos 0



int main() {
    int caso = 1;
    char primero[1001];
    char segundo[1001];
    while(scanf("%s %s", &primero, &segundo)!= EOF){
        string primeraString = string(primero);
        string segundaString = string(segundo);
        string primeroEntero;
        string primeroDecimal;
        string segundoEntero;
        string segundoDecimal;
        BigInteger cero("-0");

        int indicePunto1 = primeraString.find('.');
        int indicePunto2 = segundaString.find('.');

        if(indicePunto1 != string::npos){
            primeroEntero = primeraString.substr(0, indicePunto1);
            primeroDecimal = primeraString.substr(indicePunto1 + 1);
        }
        if(indicePunto2 != string::npos){
            segundoEntero = segundaString.substr(0, indicePunto2);
            segundoDecimal = segundaString.substr(indicePunto2 + 1);
        }
        BigInteger EnteroPrimero(primeroEntero);
        BigInteger DecimalPrimero(primeroDecimal);
        BigInteger EnteroSegundo(segundoEntero);
        BigInteger DecimalSegundo(segundoDecimal);

        //cout << (DecimalPrimero-DecimalSegundo).toString() << endl;

        int situacion = 0;
        cout << "Case " << caso << ": ";

        if(EnteroPrimero < EnteroSegundo){
            situacion = 1;
        }
        else if(EnteroSegundo < EnteroPrimero){
            situacion = 2;
        }
        else if(EnteroPrimero == EnteroSegundo){
            situacion = 3;
        }
        if(situacion == 3){
            if((DecimalPrimero - DecimalSegundo) < cero)
                situacion = 1;
            else if((DecimalSegundo - DecimalPrimero) < cero)
                situacion = 2;
            else
                situacion = 3;
        }
        if(situacion == 1)
            cout << "Smaller" << endl;
        else if(situacion == 2)
            cout << "Bigger" << endl;
        else
            cout << "Same" << endl;
        caso++;
    }
    return 0;
}

