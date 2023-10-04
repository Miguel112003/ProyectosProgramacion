#include "BigInteger.h"
/*
int main() {
    //Prueba de los constructores
    cout << "Prueba de los constructores: " << endl;
    BigInteger constructorString("12345678");
    BigInteger constructorCopia(constructorString);
    BigInteger constructorStringNegativo("-12345678");
    BigInteger constructorCopiaNegativo(constructorStringNegativo);
    cout << constructorString.toString() << endl;
    cout << constructorCopia.toString() << endl;
    cout << constructorStringNegativo.toString() << endl;
    cout << constructorCopiaNegativo.toString() << endl;
    cout << endl << endl;

    //Prueba de Add
    cout << "Prueba de sumas: " << endl;
    cout << (constructorString + constructorStringNegativo).toString() << endl;
    cout << (constructorCopia + constructorCopia).toString() << endl;
    constructorString.add(constructorStringNegativo);
    constructorCopia.add(constructorCopia);
    cout << (constructorString).toString() << endl;
    cout << (constructorCopia).toString() << endl;
    cout << endl << endl;

    //Prueba de Product
    cout << "Prueba de product: " << endl;
    BigInteger productoPositivo("12345678");
    BigInteger productoNegativo("-12345678");
    cout << (productoNegativo * productoNegativo).toString() << endl;
    cout << (productoPositivo * productoNegativo).toString() << endl;
    productoNegativo.product(productoNegativo);
    productoPositivo.product(productoNegativo);
    cout << (productoNegativo).toString() << endl;
    cout << (productoPositivo).toString() << endl;
    cout << endl << endl;

    //Prueba de Substract
    cout << "Prueba de Substract: " << endl;
    BigInteger restaPos("-4");
    BigInteger restaNeg("-8846883");

    cout << (restaPos - restaNeg).toString() << endl;
    cout << (restaNeg - restaNeg).toString() << endl;
    restaPos.substract(restaPos);
    restaNeg.substract(restaNeg);
    cout << (restaPos).toString() << endl;
    cout << (restaNeg).toString() << endl;
    cout << endl << endl;

    //Prueba de Quotient
    cout << "Prueba de Quotient: " << endl;
    BigInteger divisionPos("3213578481");
    BigInteger divisionNeg("2");
    //BigInteger divisionPos("492742895188030243829981411911636618894864499457465776214686926652987147511405857281953857526438460624788514327975114546716738399857991815619172861843442203770607523880318063262681502129946874469769960226357728630795360189243963428743283411928365535454025903147743570438138911789064723650478893991753805668144257696446774091755407180567190605127622414505709139225983925085108777919036699759742625943234579386674259918492938103123815953952644734810790559744");
    //BigInteger divisionNeg("4");
    cout << (divisionPos / divisionNeg).toString() << endl;
    cout << (divisionNeg / divisionPos).toString() << endl;
    cout << (divisionNeg / divisionNeg).toString() << endl;

    //divisionPos.quotient(divisionPos);
    //divisionNeg.quotient(divisionPos);

    //cout << (divisionPos).toString() << endl;
    //cout << (divisionNeg).toString() << endl; //Hay un pequeño problema en la division de un negativo entre un positivo
    cout << endl << endl;


    //Prueba de remainder
    cout << "Prueba de Remainder: " << endl;
    //BigInteger ModuloNum("492742895188030243829981411911636618894864499457465776214686926652987147511405857281953857526438460624788514327975114546716738399857991815619172861843442203770607523880318063262681502129946874469769960226357728630795360189243963428743283411928365535454025903147743570438138911789064723650478893991753805668144257696446774091755407180567190605127622414505709139225983925085108777919036699759742625943234579386674259918492938103123815953952644734810790559744");
    //BigInteger ModuloNum2("4");
    BigInteger ModuloNum("9677");
    BigInteger ModuloNum2("9");
    cout << (ModuloNum % ModuloNum2).toString() << endl;

    ModuloNum.remainder(ModuloNum2);
    cout << (ModuloNum).toString() << endl;

    cout << endl << endl;

    //Prueba de ==
    cout << "Prueba de == : " << endl;
    BigInteger Igual1("12345678");
    BigInteger Igual2("-12345678");

    cout << (Igual1 == Igual1) << endl;
    cout << (Igual2 == Igual1) << endl;

    cout << endl << endl;

    //Prueba de <
    cout << "Prueba de < : " << endl;
    BigInteger Menor1("12345678");
    BigInteger Menor2("-12345678");

    cout << (Menor2 < Menor1) << endl;
    cout << (Menor1 < Menor2) << endl;

    cout << endl << endl;

    //Prueba de <=
    cout << "Prueba de <= : " << endl;
    cout << (Menor1 <= Menor1) << endl;
    cout << (Menor2 <= Menor1) << endl;
    cout << endl << endl;
    //Prueba de SumarListaValores
    cout << "Prueba de SumarListaValores : " << endl;
    BigInteger G1("12345678");
    BigInteger G2("12345678");
    BigInteger G3("12345678");
    list<BigInteger> listado;
    listado.push_back(G1);
    listado.push_back(G2);
    listado.push_back(G3);
    BigInteger sumada = BigInteger::sumarListaValores(listado);
    cout << sumada.toString() << endl;

    //Prueba de MultiplicarListaValores
    cout << "Prueba de MultiplicarListaValores : " << endl;
    BigInteger G4("12345678");
    BigInteger G5("12345678");
    BigInteger G6("12345678");
    list<BigInteger> listado2;
    listado2.push_back(G4);
    listado2.push_back(G5);
    listado2.push_back(G6);
    BigInteger multiplicadaNumeros = BigInteger::multiplicarListaValores(listado2);
    cout << multiplicadaNumeros.toString() << endl;
    return 0;
}

*/

