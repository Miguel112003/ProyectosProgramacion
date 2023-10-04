/*
Autor: Miguel Bejarano
Fecha: 4/05/2023

Implementacion del TAD BigInteger con Vectores

*/

#include "BigInteger.h"
#include <algorithm>

//Operaciones Auxiliares

//La operacion print no es de utilidad, ni es requerida, la dejo como comentario
/*
void BigInteger::print(){ // Imprime el número
    for (int i = digitos.size() - 1; i >= 0; i--) {
        cout << digitos[i];
    }
    cout << endl;
}
*/


/*
Constructor por defecto
Entrada: Nada
Salida: Objeto BigInteger
Descripcion: Esta funcion crea un objeto de la clase
BigInteger con el atributo de negativo como falso
Complejidad: O(1)
*/

BigInteger::BigInteger() {
    negativo = false;
}


/*
Constructor por cadena de digitos
Entrada: string de digitos.
Salida: Objeto BigInteger
Descripcion: Esta funcion crea un objeto de la clase
BigInteger cuya construccion pone las cifras mas significativas al
final del vector de digitos (El numero esta alrevez).

Complejidad: O(N)
La complejidad es lineal ya que recorre la cadena de digitos de entrada
y va almacenandolos en un vector, el recorrido implica que N es el tamaño
de la cadena de caracteres.
*/
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

/*
Constructor de copia
Entrada: Objeto BigInteger.
Salida: Objeto BigInteger
Descripcion: Esta funcion se encarga de copiar los atributos de un BigInteger
a otro BigInteger
Complejidad: O(1)
La complejidad es constante ya que solo almacena en memoria los mismos
atributos del BigInteger que se pasa como parametro
*/
BigInteger::BigInteger(const BigInteger &otro) {
    digitos = otro.digitos;
    negativo = otro.negativo;
}

/*
Sobrecarga del Operador +
Aplica sobre: Objeto BigInteger
Devuelve: Objeto BigInteger
Descripcion: Esta sobrecarga se encarga de hacer el proceso para sumar
dos objetos BigInteger y retornar un tercer objeto como resultado.
Complejidad: O(N)
La complejidad es lineal ya que debe recorrer todos los elementos del vector
de digitos (Tamaño N) para realizar la suma digito por digito, manejar el acarreo y definir
lo que se mete al BigInteger resultado.
*/
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

/*
Sobrecarga del Operador *
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: Objeto BigInteger
Descripcion: Esta sobrecarga se encarga de hacer el proceso para multiplicar
dos objetos BigInteger y retornar un tercer objeto como resultado.
Complejidad: O(N*M)
La complejidad es N*M ya que N y M son los tamaños de los vectores de digitos de
los BigIntegers, el proceso raddica en que se recorre por cada digito del primer
BigInteger, todos los digitos del segundo BigInteger, luego se almacena
El producto en una variable temp, y esta se le adiciona el acarreo
Luego se pone en el vector resultado el digito menor a 10 de temp y el acarreo se cambia
por la decima parte de temp.
Finalmente se quitan los ceros.
Entonces como se recorre por ambos vectores de digitos, la complejidad es la mencionada.
*/

BigInteger BigInteger::operator*(BigInteger& otro){
    BigInteger resultado;
    resultado.digitos.resize(digitos.size() + otro.digitos.size(), 0);

    // Comprobar si el resultado será negativo
    resultado.negativo = negativo != otro.negativo;

    for (int i = 0; i < digitos.size(); i++) {
        int llevamos = 0;
        for (int j = 0; j < otro.digitos.size() || llevamos; j++) {
            long long temp;
            if (j < otro.digitos.size()) {
                temp = (long long)digitos[i] * otro.digitos[j];
            } else {
                temp = 0;
            }
            temp += resultado.digitos[i + j] + llevamos;
            resultado.digitos[i + j] = temp % 10;
            llevamos = temp / 10;
        }
    }

    while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
        resultado.digitos.pop_back();
    }

    return resultado;
}

/*
Sobrecarga del Operador -
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: Objeto BigInteger
Descripcion: Esta sobrecarga se encarga de hacer el proceso para restar
dos objetos BigInteger y retornar un tercer objeto como resultado.
Complejidad: O(N)
La complejidad es lineal ya que debe recorrer todos los elementos del vector
de digitos (Tamaño N) para realizar la resta digito por digito, manejar el acarreo y definir
lo que se mete al BigInteger resultado, similar a la suma, pero no tanto
*/

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

/*
Sobrecarga del Operador /
Aplica sobre: Objeto BigInteger
Devuelve: Objeto BigInteger
Recibe: Objeto BigInteger
Descripcion: Esta sobrecarga se encarga de hacer el proceso para dividir
dos objetos BigInteger por medio de un algoritmo de division larga, y retornar un tercer objeto como resultado.
Complejidad: O(N*M)
El algoritmo recorre en sentido contrario los digitos del dividendo, y va metiendolos a los digitos del BigInteger llamado resto, luego de meter cada digito
se busca el mayor cociente posible, una vez se tiene solo se inserta el cociente en los digitos del resultado, Este algoritmo es mas eficiente que uno totalmente
implementado por restas ya que para los digitos va buscando su cociente, reduciendo significativamente el numero de restas que debe realizar. obteniendo una complejidad
de O(N*M) donde N es el tamaño del vector de digitos del dividendo, y M es la cantidad de iteraciones que debe realizar para encontrar el mayor cociente posible.
*/
BigInteger BigInteger::operator/(BigInteger& otro) {
    BigInteger resultado;

    // Verificar si el resultado será negativo
    resultado.negativo = negativo != otro.negativo;

    // Si el dividendo es menor que el divisor, el resultado es cero
    if (*this < otro) {
        return BigInteger("0");
    }

    BigInteger dividendo(*this);
    dividendo.negativo = false;
    BigInteger divisor(otro);
    divisor.negativo = false;

    BigInteger resto;
    for (int i = dividendo.digitos.size() - 1; i >= 0; --i) {
        resto.digitos.insert(resto.digitos.begin(), dividendo.digitos[i]);

        // Encuentra el mayor cociente posible
        int cociente = 0;
        while (divisor <= resto) {
            resto = resto - divisor;
            ++cociente;
        }

        resultado.digitos.insert(resultado.digitos.begin(), cociente);
    }

    // Eliminar los ceros a la izquierda del resultado
    while (resultado.digitos.size() > 1 && resultado.digitos.back() == 0) {
        resultado.digitos.pop_back();
    }

    return resultado;
}

/*
Sobrecarga del Operador %
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: Objeto BigInteger
Descripcion: Esta sobrecarga se encarga de hacer el proceso para obtener el modulo
dos objetos BigInteger por medio de un algoritmo de division larga, y retornar un tercer objeto como resultado. Es muy similar al proceso de division, pero
cambiando un par de detalles.
Complejidad: O(N*M)
El algoritmo recorre en sentido contrario los digitos del dividendo, y va metiendolos a los digitos del BigInteger llamado resto, luego de meter cada digito
se busca el mayor cociente posible, una vez se tiene solo se comprueba el signo y se eliminan los posibles ceros, Este algoritmo es mas eficiente que uno totalmente
implementado por restas ya que para los digitos va buscando su cociente, reduciendo significativamente el numero de restas que debe realizar. obteniendo una complejidad
de O(N*M) donde N es el tamaño del vector de digitos del dividendo, y M es la cantidad de iteraciones que debe realizar para encontrar el mayor cociente posible.
*/
BigInteger BigInteger::operator%(BigInteger& otro) {

    // Verificar si el dividendo es menor que el divisor
    if (*this < otro) {
        return *this;
    }

    BigInteger dividendo(*this);
    dividendo.negativo = false;
    BigInteger divisor(otro);
    divisor.negativo = false;

    BigInteger resto;
    for (int i = dividendo.digitos.size() - 1; i >= 0; --i) {
        resto.digitos.insert(resto.digitos.begin(), dividendo.digitos[i]);

        // Encuentra el mayor cociente posible
        int cociente = 0;
        while (divisor <= resto) {
            resto = resto - divisor;
            ++cociente;
        }
    }

    // Eliminar los ceros a la izquierda del resultado
    while (resto.digitos.size() > 1 && resto.digitos.back() == 0) {
        resto.digitos.pop_back();
    }

    // Aplicar el signo del dividendo original al resto
    resto.negativo = negativo;

    return resto;
}

/*
Sobrecarga del Operador ==
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: variable Booleana
Descripcion: Esta sobrecarga se encarga de hacer el proceso de comparacion de igualdad de dos objetos BigInteger
Complejidad: O(N)
El algoritmo recorre en sentido contrario los digitos del primer BigInteger, y va comparando cada digito para ver si cumple o no con ser igual a los del otro
BigInteger, en caso de que alguno no lo sea, se deberia de determinar que una variable de retorno es falsa, y romper el ciclo, pero como use returns en varios sitios
pues lo deje que simplemente retorne false o true, dependiendo si son iguales o no.
La complejidad es O(N) ya que recorre por el vector de digitos del 1 de los dos BigIntegers, podria hacerse ligeramente mas eficiente si se conoce el menor
y se recorre por el menor. Pero N representa el tamaño del vector de digitos del primer BigInteger.
*/

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

/*
Sobrecarga del Operador <
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: variable Booleana
Descripcion: Esta sobrecarga se encarga de hacer el proceso de comparacion de desigualdad < de dos objetos BigInteger
Complejidad: O(N)
El algoritmo primero revisa si con los signos puede definir o no cual es de los dos BigInteger es menor, en caso de poder lo define.
En caso de que tengan tamaños diferentes, se analizan sus signos igualmente, y se define cual de los dos tiene mayor tamaño y esto en conjunto
con el signo define cual es mayor o menor.
Si ninguna de estas condiciones se dispara implica que tienen el mismo signo, y mismo tamaño, por lo que se analiza digito a digito entre ambos
BigInteger, y a partir de ahi define cual es mayor, como se hace un recorrido del vector de digitos en reversa la complejidad es O(N) donde
N representa el tamaño del vector de digitos del primer BigInteger.
*/

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

/*
Sobrecarga del Operador <=
Aplica sobre: Objeto BigInteger
Recibe: Objeto BigInteger
Devuelve: variable Booleana
Descripcion: Esta sobrecarga se encarga de hacer el proceso de comparacion de desigualdad o igualdad <= de dos objetos BigInteger
Complejidad: O(N)
El algoritmo primero revisa si con los signos puede definir o no cual es de los dos BigInteger es menor, en caso de poder lo define.
En caso de que tengan tamaños diferentes, se analizan sus signos igualmente, y se define cual de los dos tiene mayor tamaño y esto en conjunto
con el signo define cual es mayor o menor.
Si ninguna de estas condiciones se dispara implica que tienen el mismo tamaño, por lo que se analiza digito a digito entre ambos
BigInteger, y a partir de ahi define cual es mayor, como se hace un recorrido del vector de digitos en reversa la complejidad es O(N) donde
N representa el tamaño del vector de digitos del primer BigInteger.
*/

bool BigInteger::operator<=(BigInteger& otro){
    if (negativo && !otro.negativo) {
        return true; // Un número negativo es siempre menor que uno positivo
    }
    if (!negativo && otro.negativo) {
        return false; // Un número positivo es siempre mayor que uno negativo
    }

    // Ambos números tienen el mismo signo, se debe comparar su magnitud
    if (digitos.size() < otro.digitos.size()) {
        return !negativo; // El número con menos dígitos es menor, a menos que sea negativo
    }
    if (digitos.size() > otro.digitos.size()) {
        return negativo; // El número con más dígitos es mayor, a menos que sea negativo
    }

    // Ambos números tienen la misma cantidad de dígitos, se comparan dígito por dígito
    for (int i = digitos.size() - 1; i >= 0; i--) {
        if (digitos[i] < otro.digitos[i]) {
            return !negativo; // El número actual es menor, a menos que sea negativo
        }
        if (digitos[i] > otro.digitos[i]) {
            return negativo; // El número actual es mayor, a menos que sea negativo
        }
    }

    // Los números son iguales
    return true;
}

/*
Operacion Add
Entrada: Objeto BigInteger
Salida: Objeto BigInteger
Descripcion: Esta funcion suma un BigInteger a otro
Complejidad: O(N)
Como solo empleo la sobrecarga del operador +, en cuanto a complejidad temporal no deberia haber diferencias, lo que si puede que
radique en una diferencia es en la complejidad espacial. Es la misma explicacion de complejidad temporal de la sobrecarga
*/

void BigInteger::add(BigInteger &otro){
    *this = *this + otro;
}

/*
Operacion Product
Entrada: Objeto BigInteger
Salida: Objeto BigInteger
Descripcion: Esta funcion multiplica un BigInteger a otro
Complejidad: O(N*M)
Como solo empleo la sobrecarga del operador *, en cuanto a complejidad temporal no deberia haber diferencias, lo que si puede que
radique en una diferencia es en la complejidad espacial. Es la misma explicacion de complejidad temporal de la sobrecarga
*/

void BigInteger::product(BigInteger &otro){
    *this = *this * otro;
}

/*
Operacion Substract
Entrada: Objeto BigInteger
Salida: Objeto BigInteger
Descripcion: Esta funcion resta un BigInteger a otro
Complejidad: O(N)
Como solo empleo la sobrecarga del operador -, en cuanto a complejidad temporal no deberia haber diferencias, lo que si puede que
radique en una diferencia es en la complejidad espacial. Es la misma explicacion de complejidad temporal de la sobrecarga
*/

void BigInteger::substract(BigInteger &otro){
    *this = *this - otro;
}

/*
Operacion Quotient
Entrada: Objeto BigInteger
Salida: Objeto BigInteger
Descripcion: Esta funcion divide un BigInteger a otro
Complejidad: O(N*M)
Como solo empleo la sobrecarga del operador /, en cuanto a complejidad temporal no deberia haber diferencias, lo que si puede que
radique en una diferencia es en la complejidad espacial. Es la misma explicacion de complejidad temporal de la sobrecarga
*/
void BigInteger::quotient(BigInteger &otro){
    *this = *this / otro;
}

/*
Operacion Remainder
Entrada: Objeto BigInteger
Salida: Objeto BigInteger
Descripcion: Esta funcion obtiene el modulo (¿se puede decir modula?) un BigInteger a otro
Complejidad: O(N*M)
Como solo empleo la sobrecarga del operador %, en cuanto a complejidad temporal no deberia haber diferencias, lo que si puede que
radique en una diferencia es en la complejidad espacial. Es la misma explicacion de complejidad temporal de la sobrecarga
*/
void BigInteger::remainder(BigInteger &otro){
    *this = *this % otro;
}

/*
Operacion Pow
Entrada: variable Int
Salida: Objeto BigInteger
Descripcion: Esta funcion obtiene la exponenciacion un BigInteger a un entero
Complejidad: O(N*LogM)
La complejidad es O(N*LogM) donde M representa el exponente al cual hay que elevar el BigInteger, y N representa el numero de
iteraciones que deben hacerse para poder reducir el exponente a 0 y haber calculado la potencia, es un procedimiento que radica su utilidad
En utilizar las propiedades de la potencia y cada que se pueda calcular el cuadrado de lo que sea base en ese momento, y reducir el exponente a la mitad
es un truco matematico bastante elegante para estos casos. Lo bueno es que me permite obtener complejidades bajas para la multiplicacion. Es similar a lo que el
profe Carlos explico el dia Disco creo que fue.
*/
void BigInteger::pow(int otro) {
    if (otro == 0) {
        // Caso especial: cualquier número elevado a 0 es 1
        digitos.clear();
        digitos.push_back(1);
        negativo = false;
        return;
    }

    // Realizar la potencia iterativamente
    BigInteger base(*this);
    BigInteger resultado("1");

    while (otro > 0) {
        if (otro % 2 == 1) { //Determino si el exponente es impar, si lo implica que el bit menos significativo del exponente es 1
            resultado = resultado * base; //Como el exponente es impar, multiplico resultado por la base
        }
        base = base * base; //En caso de que el exponente sea par se eleva la base al cuadrado
        otro /= 2; //Y como eleve al cuadrado divido el exponente a la mitad
    }

    // Actualizar el valor del objeto actual con el resultado de la potencia
    digitos = resultado.digitos;
    negativo = resultado.negativo;
}

/*
Operacion toString
Entrada: Objeto BigInteger
Salida: string
Descripcion: Esta funcion convierte un objeto BigInteger en una cadena de caracteres
Complejidad: O(N)
Solo recorro por el tamaño del vector de digitos del BigInteger que estoy convirtiendo, luego uso el ascii del 0 para poder convertirlo.
*/
string BigInteger::toString() {
    string resultado = "";

    // Verificar si el número es negativo
    if (negativo) {
        resultado += "-";
    }

    for (int i = digitos.size() - 1; i >= 0; i--) {
        int digito = digitos[i];

        // Convertir el dígito a su representación ASCII
        char ascii = digito + '0';

        resultado += ascii;
    }

    return resultado;
}

/*
Operacion sumarListaValores
Entrada: Contenedor list de Objetos BigInteger
Salida: Objeto BigInteger.
Descripcion: Esta funcion suma una lista de objetos BigIntenger y retorna un BigInteger el cual es el resultado de la suma.
Complejidad: O(N*M)
Recorro la lista de BigIntegers y voy aplicando la suma a cada BigInteger, por lo que el recorrido es O(N) siendo N el tamaño de la lista de BigIntegers
Luego el hacer las M sumas tiene una complejidad de O(M), dandonos una complejidad resultante de O(N*M)
*/
BigInteger BigInteger::sumarListaValores(list<BigInteger>& lista) {
    BigInteger suma;
    for (auto it = lista.begin(); it != lista.end(); ++it) {
        suma = suma + *it;
    }
    return suma;
}

/*
Operacion multiplicarListaValores
Entrada: Contenedor list de Objetos BigInteger
Salida: Objeto BigInteger.
Descripcion: Esta funcion multiplica una lista de objetos BigIntenger y retorna un BigInteger el cual es el resultado de la multiplicacion.
Complejidad: O(N*M*L)
Recorro la lista de BigIntegers y voy aplicando la multiplicacion a cada BigInteger, por lo que el recorrido es O(N) siendo N el tamaño de la lista de BigIntegers
Luego el hacer las M multiplicaciones tiene una complejidad de O(M*L), donde M representa el tamaño de los digitos de cada primer BigInteger a multiplicar y L
el tamaño de los digitos de cada siguiente BigInteger a multiplicar, obteniendo una complejidad resultante de O(N*M*L) o cubica
*/
BigInteger BigInteger::multiplicarListaValores(list<BigInteger>& lista) {
    if (lista.empty()) {
        return BigInteger("0");
    }

    auto it = lista.begin();
    BigInteger multi = *it;
    ++it;

    for (; it != lista.end(); ++it) {
        multi = multi * (*it);
    }

    return multi;
}
