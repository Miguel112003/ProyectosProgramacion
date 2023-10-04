//Miguel Bejarano Perdomo

//8959501

/* Respecto a la complejidad de esta solucion:

*En este caso como los ciclos depende de varios datos de entrada no tenia muy claro
de como hacer el analisis, deje todo en temrinos de una sola variable de entrada n
que en verdad representa entradas de distinto tamaño*

En un principio en cuanto recibo los datos tengo que crear una matriz con las llegadas
del piloto, esto tiene una complejidad dependiendo del tamaño de la matriz,
Conociendo que no siempre se trata de una matriz cuadrada analizaremos casos

La matriz de pilotos es de tamaño 100*500 (Para fines de analisis tomaremos un dato de entrada variable)
Como el tamaño de la matriz depende de ambos terminos (Carreras y pilotos) suponiendo que ambos terminos
se relacionen a una variable, llamada n seria el numero de pilotos que entraran a la matriz
obtiendo en este ciclo una complejidad de n, ya que recorre la matriz y asigna segun la cantidad de pilotos
n

Ahora hace falta analizar para el numero de puntajes a recibir como sera la complejidad del resto del codigo
Asumiendo que la cantidad de puntajes a analizar es n, se va a recorrer un ciclo for desde 0 hasta n
es decir por cada puntaje se realiza un analisis.
Dentro de esto se crea otro ciclo que va desde 0 hasta la cantidad de pilotos y se llena un arreglo con los id
de los pilotos en orden y su puntaje correspondiente. Teniendo una complejidad lineal pues solo recorro un arreglo

Luego de esto empiezo a crear ciclos para asignar puntajes y determinar el puntaje ganador con este sistema de puntuacion
entonces lo que hago es que a partir del primer termino del sistema de puntuacion
creo un ciclo que va desde 0 hasta ese puntaje de inicio y dentro de este ciclo
almaceno la cantidad de puntos que van entrando. Este ciclo tiene una complejidad
asumiendo la entrada como n, lineal ya que por el tamaño voy recorriendo en ese ciclo

Despues de esto dependiendo del numero de carreras exploro la matriz de pilotos (Usando un doble ciclo)
que ambos son lineales si se asume su entrada como n
y empiezan algunos condicionales dependiendo si la posicion del piloto es igual al indice a partir del cual
un piloto gana puntos en este sistema de puntuacion
en caso de que el piloto gane puntos se analiza si es el ganador o no
finalmente en un ultimo ciclo recorro la lista de pilotos (complejidad lineal)
e imprimo en pantalla el numero de los ids del o los pilotos ganadores

Entonces en complejidad total nos queda

O(n^2) para el ciclo donde genero la matriz de los pilotos

*O(n) para el ciclo por la cantidad de sistemas de puntuacion a analizar

O(n) para el ciclo donde genero el arreglo de corredores (OJO ESTO ES POR CADA SISTEMA DE PUNTUACION)

O(n) para el ciclo dependiendo del primer piloto que recibe puntos (OJO ESTO ES POR CADA SISTEMA DE PUNTUACION)

*O(n) para para el numero de carreras para generar puntos (OJO ESTO ES POR CADA SISTEMA DE PUNTUACION)

*O(n) para el segundo indice de la matriz de pilotos (OJO ESTO ES POR CADA SISTEMA DE PUNTUACION Y EL NUMERO DE CARRERAS)

O(n) para el ciclo de impresion de ganadores

Obteniendo una complejidad de O(n^3) bajo las asumpciones que hicimos

*/

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_CARRERAS = 100;
const int MAX_PILOTOS = 500;

struct Corredor {
    int id, puntos;
};

int main() {
    int carreras, p;
    int cantidadPuntajes;
    int i, j, t, b;
    int puntosInicio;
    int puntosPiloto;
    int puntajeGanador;
    Corredor corredores[MAX_PILOTOS];
    //Genero un arreglo con las llegadas de los pilotos
    while (scanf("%d %d", &carreras, &p), carreras && p) {
        int pilotos[MAX_CARRERAS][MAX_PILOTOS];
        for (i = 0; i < carreras; ++i) {
            for (j = 0; j < p; ++j)
                cin >> pilotos[i][j];
        }
        //Añado al arreglo corredores las puntuaciones iniciales para cada corredor segun la cantidad de puntajes que evaluamos
        cin >> cantidadPuntajes;
        for (i = 0; i < cantidadPuntajes; ++i) {
            for (t = 0; t < p; ++t) {
                corredores[t].id = t + 1;
                corredores[t].puntos = 0;
            }
            //Aqui meto los puntos ganados por piloto a su respectiva posicion en corredores respetando la struct
            puntajeGanador = 0;
            cin >> puntosInicio;
            for (j = 1; j <= puntosInicio; ++j) {
                cin >> puntosPiloto;
                for (t = 0; t < carreras; ++t) {
                    for (int bandera = 0, b = 0; b < p && bandera == 0; ++b) {
                        //Aqui verifico si el piloto esta en el rango de ganar puntos, caso de que si le sumo, sino no
                        if (pilotos[t][b] == j) {
                            corredores[b].puntos += puntosPiloto;
                            //Ahora verifico si el puntaje es mayor al ganador, si lo es asigno un nuevo ganador
                            if (corredores[b].puntos > puntajeGanador)
                                puntajeGanador = corredores[b].puntos;
                            bandera = 1;
                        }
                    }
                }
            }
            //Aqui imprimo el ganador(es) segun su orden
            for (t = 0; t < p; ++t) {
                if (corredores[t].puntos == puntajeGanador)
                    cout << corredores[t].id << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

