#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBESTIAS 29
#define ATQBESTIA 4
#define PROBHUYE 2

int main(); //prototipos
void menu(); 
int caminar(int n, int i);
void bestiario();
int generarCartas(int probabilidad, int cartaATK, int cartaDEF, int n1, int i1);
void Combate();

const char *CATEGORIASCARTAS[]={"Normal", "Especial", "Epica"};
const char *DESCRIPCARTASATK[]={"Golpe ATK base", "Golpeas el DOBLE de tu ATK base", "Golpeas el TRIPLE de tu ATK base"};
const char *DESCRIPCARTASDEF[]={"Escudo de COBALTO", "Escudo de OBSIDIANA", "Escudo de CRUZ"};

int ATKBASE = 200;

int arregloCartasATK[100]={};
int arregloCartasDEF[100]={};
int arregloCartasHAB[100]={};
const char *arregloCategoriaATK[100]={};
const char *arregloCategoriaDEF[100]={};
const char *arregloDescripATK[100]={};
const char *arregloDescripDEF[100]={};

int nATK=0, iDEF=0;

typedef struct Bestia{
	int id;
	char nombre[NUMBESTIAS];
	char descr[256];
	int vidaBest;
} Bestia;

int UltEnemigo = -1;

Bestia ENEMIGOS[NUMBESTIAS];

void menu(){
	int entrada = 0;
	printf("Programa Iniciado\n\n");
	do{
		printf("0. Bestiario\n");
		printf("1. Caminar\n");
		printf("2. Deck\n");
		printf("3. Combate\n");
		printf("4. Salir\n");

		printf("Elija como proceder: ");
		scanf("%d", &entrada);
		printf("\n");

		switch(entrada){
			case 0:
				bestiario();
				break;
			case 1:
				caminar(nATK, iDEF);
				break;
			case 2:
                if (nATK>0 || iDEF>0)
                {
                    if (nATK!=0)
                    {
                        printf("Cartas ATK:\n");
                        for (int cont = 0; cont < nATK; cont++)
                        {
                            printf("(%d->%s->%s) ", arregloCartasATK[cont], arregloCategoriaATK[cont], arregloDescripATK[cont]);
                        }
                        printf("\n");
                    }                    
                    if (iDEF!=0)
                    {
                        printf("Cartas DEF:\n");
                        for (int cont = 0; cont < iDEF; cont++)
                        {
                            printf("(%d->%s->%s) ", arregloCartasDEF[cont], arregloCategoriaDEF[cont], arregloDescripDEF[cont]);
                        }
                        printf("\n");
                    }

                    int eliminar1, eliminar2, eliminar3;
                    printf("Desea eliminar una carta Si(5), No(6): ");
                    scanf("%d", &eliminar1);
                    if (eliminar1==5)
                    {
                        printf("CartaATK(7), CartaDEF(8): ");
                        scanf("%d", &eliminar3);
                        if (eliminar3==7)
                        {
                            printf("Indique el indice: ");
                            scanf("%d", &eliminar2);
                            arregloCartasATK[eliminar2]=NULL;
                            arregloCategoriaATK[eliminar2]=NULL;
                            arregloDescripATK[eliminar2]=NULL;
                            nATK--;
                        }
                        else if (eliminar3==8)
                        {
                            printf("Indique el indice: ");
                            scanf("%d", &eliminar2);
                            arregloCartasDEF[eliminar2]=NULL;
                            arregloCategoriaDEF[eliminar2]=NULL;
                            arregloDescripDEF[eliminar2]=NULL;
                            iDEF--;
                        }    
                    }

                }
                else
                {
                    printf("EL DECK ESTA VACIO\n");
                    break;
                }
                break;
			case 3:
				Combate();
			case 4:
				printf("Cerrando Programa\n\n");
				break;
			default:
				printf("Eleccion invalida. \n\n");
				break;
		}
	}while (entrada!=4);

}

int caminar(int n, int i){
    int prob=0, prob1=0;

    srand(time(NULL));
    prob1 = 0 + rand() % 2;
    if (prob1==1)
    {
        printf("Se encontro una carta\n");
        prob = 0 + rand() % 2;
        if (prob==0)
        {
            int categoria=generarCartas(prob, 0, 0, nATK, iDEF);
            if (categoria!=0)
            {
                arregloCartasATK[n]=categoria;
                nATK++;
            }
        }
        else if (prob==1)
        {
            int categoria=generarCartas(prob, 0, 0, nATK, iDEF);
            if (categoria!=0)
            {
                arregloCartasDEF[i]=categoria;
                iDEF++;
            }
            
        }  
    }
    else
    {
        printf("No se encontro una carta\n");
    }
    return 0;
}


int generarCartas(int probabilidad, int cartaATK, int cartaDEF, int n, int i)
{

    int indice;
    int entrada;

    if (probabilidad==0) //Carta ATK
    {
        probabilidad = 1 + rand() % 3;
        cartaATK = probabilidad*ATKBASE;
        indice=probabilidad-1;
        printf("Carta ATK: Ataque: %d, Categoria: %s, Descripcion: %s\n", cartaATK, CATEGORIASCARTAS[indice], DESCRIPCARTASATK[indice]);
        printf("Aceptar(1) o Rechazar(0): ");
        scanf("%d", &entrada);
        if (entrada==1)
        {
            printf("Carta Agregada al Deck\n");
            arregloCategoriaATK[n]=CATEGORIASCARTAS[indice];
            arregloDescripATK[n]=DESCRIPCARTASATK[indice];
        }
        else
        {
            printf("Carta Rechazada\n");
            return 0;
        }
    }
    else if (probabilidad==1) //Carta DEF
    {
        probabilidad = 1 + rand() % 3;
        cartaDEF = probabilidad*10;
        indice=probabilidad-1;
        printf("Carta DEF: Defensa: %d, Categoria: %s, Descripcion: %s\n", cartaDEF, CATEGORIASCARTAS[indice], DESCRIPCARTASDEF[indice]);
        printf("Aceptar(1) o Rechazar(0): ");
        scanf("%d", &entrada);
        if (entrada==1)
        {
            printf("Carta Agregada al Deck\n");
            arregloCategoriaDEF[i]=CATEGORIASCARTAS[indice];
            arregloDescripDEF[i]=DESCRIPCARTASDEF[indice];
        }
        else
        {
            printf("Carta Rechazada\n");
            return 0;
        }
    }
    if (cartaATK!=0)
    {
        return cartaATK;
    }
    else if (cartaDEF!=0)
    {
        return cartaDEF;
    }
    return 0;
}


void bestiario(){

	struct Bestia Bowser = {
		0,
		"Bowser",
		"Malvado Rey de los Koopas con forma antropomorfica y una obsesion con las princesas, y tambien escupe fuego",
		1500
	};

	struct Bestia Eggman = {
		1,
		"Doctor Ivo Robotnik",
		"Es un científico obeso, con un coeficiente intelectual de 300 y su sueño es dominar el mundo en toda su historia.",
		1500
	};

	struct Bestia Nemesis = {
		2,
		"Nemesis",
		"Es una de las armas biológicas más mortales creadas por la Corporación Umbrella, no se mucho mas",
		3000
	};

	struct Bestia Tyrant = {
		3,
		"Tyrant T-102",
		"Es un arma bio-orgánica creada a través de una infección primaria por el virus Tyrant",
		2000
	};


	struct Bestia Trampero = {
		4,
		"Evan MacMillan",
		"un gran monstruo con forma de hombre con una horrible sonrisa desgarrada en la máscara que te sigue acechando cada uno de tus movimientos.",
		1500
	};

	struct Bestia Campanero = {
		5,
		"Philip Ojomo",
		"Hay otra aparición, más aterradora que cualquier cosa que haya visto, cazando entre las sombras aquí. Se mueve como una silueta, apareciendo y desapareciendo al sonido de una temida campana.",
		1000
	};

	struct Bestia Hillbilly = {
		6,
		"Max Thompson Jr.",
		"Su físico está todo retorcido y desfigurado como por algún terrible accidente. Lleva una motosierra mortal y cruel que maneja con una violencia devastadora, aparentemente imbuyéndolo de una velocidad sobrehumana por un tiempo",
		1500
	};

	struct Bestia Enfermera = {
		7,
		"Sally Smithson",
		"La vi mientras ella, de alguna manera, se movía a través de una pared. Cubierto con vendajes que cuentan una historia no contada de algo horrible. Esta... enfermera",
		1000
	};

	struct Bestia Bruja = {
		8,
		"Lisa Sherwood",
		"Su apariencia me parece más intensa que las demás después de un vistazo de su silueta demacrada. Retorcida y desgarrada de maneras indescriptibles, con una piel muerta grisácea extendida sobre su cuerpo demacrado",
		1500
	};

	struct Bestia Doctor = {
		9,
		"Herman Carter",
		"Un hombre vestido con la túnica de un médico se cruzó en mi camino. Desde lejos, lo veo caminando, buscando... Pero él no era... normal. Los ojos y la boca se abrieron de un modo doloroso y perturbador",
		2000
	};

	struct Bestia Cazadora = {
		10,
		"Anna",
		"Una figura vestida con la cabeza de una liebre. Una visión de lo más perturbadora. Esta nueva enemiga tiene algo humano dentro de ella. Algunos fragmentos de la vida ordinaria. Parece ser una cazadora.",
		1500
	};

	struct Bestia Cerda = {
		11,
		"Amanda Young",
		"Amanda Young, un alma atormentada, cuya vida había sido un catálogo de daños, tanto para ella misma como para quienes la rodeaban, desahogandose con sangre",
		1000
	};

	struct Bestia Payaso = {
		12,
		"Kenneth Chase",
		"su disfraz era una mezcolanza de maestro de ceremonias, payaso y otros atuendos de feria. Su cara era una pesadilla pintada con grasa, una caricatura de una sonrisa acuchillada en sus labios flácidos. ",
		1500
	};

	struct Bestia Espiritu = {
		13,
		"Rin Yamaoka",
		"Heredó una furia increíble de sus antepasados. La ira que corre por sus venas es su legado. El terrible dolor que sufrió la desencadenó. Rápida y letal",
		1000
	};

	struct Bestia Oni = {
		14,
		"Kazan Yamaoka",
		"Asesino monstruoso, capaz de absorber la energía de la sangre de sus enemigos heridos y luego usar esa energía para transformarse en un demonio brutal. Usando su poder, la Ira de Yamaoka",
		2000
	};

	struct Bestia Arponero = {
		15,
		"Caleb Quinn",
		"Al atrapar a su presa desprevenido, el Arponero usa su arma hecha a mano, The Redeemer, para ensartar a los sobrevivientes que huyen con un arpón de larga distancia.",
		1500
	};

	struct Bestia Deterioro = {
		16,
		"Talbot Grimes",
		"Es un Asesino impredecible, capaz de correr hacia adelante en un estallido de velocidad y hacer carambola en los obstáculos para herir a quien se proponga",
		2000
	};

	struct Bestia Gemelos ={
		17,
		"Charlotte & Victor Deshayes",
		"Charlotte Deshayes puede dar rienda suelta a su hermano gemelo unido Víctor, quedándose dormido hasta que termine de cazar. Víctor se mueve a gran velocidad y golpea con un ataque de salto que debilita y lesiona.",
		3000
	};

	struct Bestia Trickster = {
		18,
		"Ji-Woon Hak",
		"Armado con un arsenal de cuchillos arrojadizos, The Trickster abruma a los Supervivientes que huyen con un aluvión implacable de cuchillas.",
		1000
	};

	struct Bestia Artista = {
		19,
		"Carmina Mora",
		"No importa la distancia, La Artista y su control de cuervos representan una amenaza constante",
		1500
	};

	struct Bestia Draga = {
		20,
		"Draga",
		"Una abominación retorcida demasiado inquietante para soportar",
		2000
	};

	struct Bestia Vecta = {
		21,
		"Gabriel Miller",
		"Comandante Militar sin escrupulos",
		1500
	};

	struct Bestia Gleam = {
		22,
		"Demonio de Ojos Azules",
		"un monstruo demoníaco con músculos tan tensos como cuerdas que ondeaban en su imponente forma. Su piel era de un azul profundo y sus ojos brillaban con el mismo tono blanco azulado, a juego con el tinte de las llamas en la habitación",
		2500
	};

	struct Bestia Ganondorf = {
		23,
		"Ganondorf",
		"conocido como el Rey Demonio o Señor de la Oscuridad, es el ultimo varon de la raza Gerudo, cuyo objetivo es dominar el mundo",
		2000
	};

	struct Bestia Pretel = {
		24,
		"Alberto Pretel",
		"Doctor en Fisica, especialista en la electricidad y magnetismo, capaz de construir un tren de levitacion magnetica con una bobina de cobre y un tren.",
		1500
	};

	struct Bestia Diana = {
		25,
		"Diana Carolina",
		"Macabra maestra con risa capaz de destruir a los promedios mas altos",
		1000
	};

	struct Bestia Martin ={
		26,
		"Martin Vladimir",
		"Profesor de programacion con poca creencia en el tiempo de trabajo",
		2000
	};

	struct Bestia Esponja ={
		27,
		"Bob Esponja",
		"Una esponja de mar con vida y gran capacidad culinaria",
		1000
	};

	struct Bestia Lenguaje ={
		28,
		"Kernig",
		"Lenguaje de programacion con mas problemas que otra cosa",
		3000
	};
	struct Bestia Estela ={
		29,
		"Estela",
		"Profesor de Termo con pesima coesion",
		1000
	};

	ENEMIGOS[Bowser.id] = Bowser;
	ENEMIGOS[Eggman.id] = Eggman;
	ENEMIGOS[Nemesis.id] = Nemesis;
	ENEMIGOS[Tyrant.id] = Tyrant;
	ENEMIGOS[Trampero.id] = Trampero;
	ENEMIGOS[Campanero.id] = Campanero;
	ENEMIGOS[Hillbilly.id] = Hillbilly;
	ENEMIGOS[Enfermera.id] = Enfermera;
	ENEMIGOS[Bruja.id] = Bruja;
	ENEMIGOS[Doctor.id] = Doctor;
	ENEMIGOS[Cazadora.id] = Cazadora;
	ENEMIGOS[Cerda.id] = Cerda;
	ENEMIGOS[Payaso.id] = Payaso;
	ENEMIGOS[Espiritu.id] = Espiritu;
	ENEMIGOS[Oni.id] = Oni;
	ENEMIGOS[Arponero.id] = Arponero;
	ENEMIGOS[Deterioro.id] = Deterioro;
	ENEMIGOS[Gemelos.id] = Gemelos;
	ENEMIGOS[Trickster.id] = Trickster;
	ENEMIGOS[Artista.id] = Artista;
	ENEMIGOS[Draga.id] = Draga;
	ENEMIGOS[Vecta.id] = Vecta;
	ENEMIGOS[Gleam.id] = Gleam;
	ENEMIGOS[Ganondorf.id] = Ganondorf;
	ENEMIGOS[Pretel.id] = Pretel;
	ENEMIGOS[Diana.id] = Diana;
	ENEMIGOS[Martin.id] = Martin;
	ENEMIGOS[Esponja.id] = Esponja;
	ENEMIGOS[Lenguaje.id] = Lenguaje;
	ENEMIGOS[Estela.id] = Estela;



	if (UltEnemigo > -1){
		printf("La ultima bestia que enfrentaste fue a %s\n", ENEMIGOS[UltEnemigo].nombre);
		printf("Tiene %d, Puntos de vida\n", ENEMIGOS[UltEnemigo].vidaBest);
		printf("%s\n",ENEMIGOS[UltEnemigo].descr);

	}
	else{
		printf("Aun no combates con niguna bestia\n");
	}

	// Aunque lo mas probable es que quiera que usemos memoria dinamica para no dejarlo como variables locales en todo el main
	// Pero pues el ejercicio no dice puntualmente "Utilice la memoria dinamica" por lo que legalmente no es forzoso usarla
	// Y si se considera o no mala practica pues mejor que defina bien que es una mala practica y una buena porque eso de que
	// Una solucion sea "Mala practica" suena un poco arbitrario, no se no tengo orientacion para decir, esto es mala practica
	// Mas alla de porque el profesor lo diga

}


void Combate(){
	int indiBestia = 0;
	int Health = 150;
	int contAtq = 2;
	int suma = 2;
	int selectorAtq;
	int huye;
	int logroHuir;
	int vidaB;
	int cantidadAtqBestia;

	srand(time(0));
	indiBestia = rand() % NUMBESTIAS;

	UltEnemigo = indiBestia;
	printf("El indiBestia es %d\n", indiBestia);
	printf("Inicia el combate:\n");
	printf("Te enfrentas a %s\n", ENEMIGOS[indiBestia].nombre);
	printf("Tiene %d puntos de salud\n", ENEMIGOS[indiBestia].vidaBest);
	printf("Tienes vida de %d\n", Health);

	do{
		if(suma%2 == 0){
			do{
				logroHuir = 0;
				printf("Es tu turno\n");
				printf("1. Ataque Basico (-1 Turno)\n");
				printf("2. Ataque Especial (-2 Turnos)\n");
				printf("3. Sanar vida (-2 Turnos)\n");
				printf("4. Huir\n");
				scanf("%d", &selectorAtq);
				printf("\n");

				if(selectorAtq == 1 && contAtq > 0){
					vidaB -= 100;
					contAtq --;
					printf("Ataque basico. Te quedan %d Turnos \n" , contAtq);
					printf("Actualmente la bestia tiene %d puntos de vida\n" , vidaB);
				}
				
				else if(selectorAtq == 2 && contAtq == 2){
					printf("Ataque especial. Ya no te quedan Turnos.\n");
					vidaB -= 250;
					contAtq -= 2;
					printf("Actualmente la bestia tiene %d puntos de vida.\n\n" , vidaB);
				}
				
				else if(selectorAtq == 3 && contAtq == 2){
					printf("Te has curado, viajero. Ya no te quedan turnos\n");
					Health = 150;
					contAtq -= 2;
				}
		
				else if(selectorAtq == 4){
					srand(time(0));
					huye = rand() % PROBHUYE;
					
					if(huye == 0){
						printf("Has logrado huir.\n");
						Health = 0;
						contAtq -= 2;
						logroHuir = 1;
					}
					
					else if(huye == 1){
						printf("No logras Huir\n");
						contAtq -= 2;
						logroHuir = 0;
					}
				}
				
				else{
					printf("No tienes turnos suficientes para eso.\nTienes %d Turnos \n", contAtq);
					suma--;
				}
				
			}while(contAtq > 0  && vidaB > 0);
			suma++;

			}
			else if(suma%2 == 1){
				printf("Turno del enemigo.\n\n");
				srand(time(0));
				cantidadAtqBestia = rand()% ATQBESTIA;
				Health -= cantidadAtqBestia*25;
				printf("El enemigo ha lanzado %d ataques\n", cantidadAtqBestia);
				printf("El enemigo ha hecho su movimiento, ahora tienes %d puntos de salud\n\n", Health);
				contAtq = 2;
				suma ++;
		}
	}while(vidaB > 0 && Health > 0);

	if (vidaB <=0){
		printf("El enemigo ha muerto\n");
	}

	else if (Health <=0 && logroHuir == 0){
		printf("HAS MUERTO\n");
	}

}

int main(){
	menu();
	return 0;
}
