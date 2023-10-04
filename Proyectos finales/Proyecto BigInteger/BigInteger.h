/*
Autor: Miguel Bejarano
Fecha Inicio: 4/05/2023
Fecha Final: 28/05/2023
Version: 2.0
Implementacion TAD BigInteger con Vectores

*/

#include <iostream>
#include <vector>
#include <string>
#include <list>

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;

class BigInteger {
private:
    vector<int> digitos;
    bool negativo;

public:
    BigInteger(); //Constructor por defecto
    BigInteger(string numStr); //Constructor con string
    BigInteger(const BigInteger &otro); //Constructor de copia

    //Operadores Booleanos
    bool operator==(BigInteger &otro);
    bool operator<(BigInteger &otro);
    bool operator<=(BigInteger &otro);

    //Operaciones de Modificacion
    void add(BigInteger &otro);
    void product(BigInteger &otro);
    void substract(BigInteger &otro);
    void quotient(BigInteger &otro);
    void remainder(BigInteger &otro);
    void pow(int otro);
    string toString();

    //Operadores Aritmeticos
    BigInteger operator +(BigInteger&);
    BigInteger operator -(BigInteger&);
    BigInteger operator *(BigInteger&);
    BigInteger operator /(BigInteger&);
    BigInteger operator %(BigInteger&);

    //Operaciones Estaticas
    static BigInteger sumarListaValores(list<BigInteger> &lista);
    static BigInteger multiplicarListaValores(list<BigInteger> &lista);

    //Operaciones Auxiliares (No son requeridas)
    //void print();
};


#endif // BIGINTEGER_H
