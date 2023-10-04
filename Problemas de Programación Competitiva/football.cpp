// Miguel Bejarano Perdomo

//8959501

/* Respecto a la complejidad de esta solucion:
En un principio creo una funcion para comparar dos strings tomando en cuenta si son
mayusculas o minusculas, esto depende del tamaño de las strings a comparar, y recorre cada elemento del string mas largo
por lo tanto asumiendo que el tamaño del string mas largo que entra por parametro es n, el ciclo se ejecutaria desde 0 hasta n
dandonos una complejidad de O(n) en esta funcion

Luego creo la clase Equipo y sobrecargo el operador <, asi como creo el metodo mismaclasificacion, que simplemente me retorna true o false si dos equipos merecen estar en la misma clasificacion o no

Luego creo una funcion para encontrar un equipo el cual depende directamente de la cantidad de equipos que participan en el torneo esto recorre por la cantidad de equipos hasta encontrar
el indice del equipo correcto segun su nombre, esto puede tener una complejidad de O(n) siendo n la cantidad de equipos o una complejidad O(1) siendo que encuentra al equipo en la primera iteracion
entonces habria que analizar mejor y peor caso

Ya en el main por la cantidad de equipos adiciono su nombre a la tabla de equipos, este ciclo tiene una complejidad de O(n) siendo n la cantidad de equipos en el torneo
luego por la cantidad partidos meto todos los datos a el vector tabla con los equipos, aqui utilizo la funcion de encontrarEquipo, que ya mencione su complejidad, pero en este caso
para el ciclo en el que lleno los datos la complejidad es de O(n) sin contar la funcion de encontrarEquipo, tomandola en cuenta se vuelve una complejidad de O(n^2)

Despues de eso ordeno los equipos usando Sort que tiene una complejidad de O(n*log2(n))

y finalmente inicio el proceso de impresion (Que dolor de cabeza fue esto)
en el proceso hay un ciclo que imprime segun el numero de equipos, este ciclo tiene una complejidad de O(n) y no es nada del otro mundo, solo un
monton de printf() y condicionales


Finalmente esto nos da una complejidad de O(n^2)


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


//Esta parte de codigo no es mi propia idea, es de un video sobre como comparar
//strings tomando en cuenta mayusculas y minusculas.
//Le escribi a ambos y pues la hice antes de obtener respuesta, espero que no
//sea un inconviente pues utilice cosas que aun no explican en clase de estructuras
//Sin embargo si las vi en tecnicas cuando vi la materia (Me refiero al tuopper)
int compararStrings(string cad1, string cad2){
    int i;
    int retorno;
    int bandera = 0;
    for(i = 0; i < min((int)cad1.length(), (int)cad2.length()) && bandera == 0; i++){
        if(toupper(cad1[i]) != toupper(cad2[i]))
            bandera = 1;
            retorno = (int)toupper(cad1[i]) - int(toupper(cad2[i]));
    }
    if (bandera == 0)
        retorno = (int)cad1.length() - (int)cad2.length();
    return retorno;

}




class Equipo {
public:
    string nombre;
    int puntos = 0;
    int partidosJugados = 0;
    int golesFavor = 0;
    int golesContra = 0;
    int diferenciaGoles;
    double porcentajePuntos;
    bool operator<(const Equipo& otro) const{
        if(puntos != otro.puntos){
            return puntos > otro.puntos;
        } else if(diferenciaGoles != otro.diferenciaGoles){
            return diferenciaGoles > otro.diferenciaGoles;
        } else if(golesFavor != otro.golesFavor){
            return(golesFavor > otro.golesFavor);
        } else {
            return compararStrings(nombre, otro.nombre) < 0;
        }
        }
    bool mismaClasificacion(Equipo e){
        return (puntos == e.puntos && diferenciaGoles == e.diferenciaGoles && golesFavor == e.golesFavor);
    }
};


int encontrarEquipo(string nom, int equip, vector<Equipo> tabla){
    int bandera = 0;
    int indice = 0;
    for(int i = 0; i < equip && bandera == 0; i++){
        if(tabla[i].nombre == nom)
            bandera = 1;
            indice = i;
    }
    return indice;
}

int main(){
    int equipos;
    int partidos;
    int i;
    int l = 0;

    while(scanf("%d %d", &equipos, &partidos), equipos && partidos){
        if(l++ != 0)
            printf("\n");
        vector<Equipo> tabla(equipos);
        for(int i = 0; i < equipos; i++){
            cin >> tabla[i].nombre;
        }

        for(int i = 0; i < partidos; i++){
            string local;
            string visitante;
            int localGol;
            int visitanteGol;
            char equi1[100];
            char equi2[100];
            scanf("%s %d - %d %s", equi1, &localGol, &visitanteGol, equi2);
            local = equi1;
            visitante = equi2;
            int it1 = encontrarEquipo(local, equipos, tabla);
            int it2 = encontrarEquipo(visitante, equipos, tabla);
            tabla[it1].partidosJugados++;
            tabla[it2].partidosJugados++;
            tabla[it1].golesFavor += localGol;
            tabla[it2].golesFavor += visitanteGol;
            tabla[it1].golesContra += visitanteGol;
            tabla[it2].golesContra += localGol;
            tabla[it1].diferenciaGoles += localGol - visitanteGol;
            tabla[it2].diferenciaGoles += visitanteGol - localGol;
            if(localGol > visitanteGol)
                tabla[it1].puntos += 3;
            else if(visitanteGol > localGol)
                tabla[it2].puntos += 3;
            else{
                tabla[it1].puntos += 1;
                tabla[it2].puntos += 1;
            }
            }

            sort(tabla.begin(), tabla.end());

            printf(" 1. ");
            printf("%15s", tabla[0].nombre.c_str());
            printf("%4d%4d%4d%4d%4d", tabla[0].puntos, tabla[0].partidosJugados, tabla[0].golesFavor, tabla[0].golesContra, tabla[0].diferenciaGoles);
            if(tabla[0].partidosJugados > 0)
                printf("%7.2f", (tabla[0].puntos * 100.0)/(3.0*tabla[0].partidosJugados));
            else
                printf("%7s", "N/A");
            printf("\n");
            for(i = 1; i <equipos ; i++){
                if(!tabla[i].mismaClasificacion(tabla[i-1]))
                    printf("%2d. ", i+1);
                else
                    printf("    ");
                printf("%15s", tabla[i].nombre.c_str());
                printf("%4d%4d%4d%4d%4d", tabla[i].puntos, tabla[i].partidosJugados, tabla[i].golesFavor, tabla[i].golesContra, tabla[i].diferenciaGoles);
                if(tabla[i].partidosJugados > 0)
                    printf("%7.2f", ((tabla[i].puntos * 100.0) /(3.0*tabla[i].partidosJugados)));
                else{
                    printf("%7s", "N/A");
                }
                printf("\n");
            }
        }

    return 0;
}
