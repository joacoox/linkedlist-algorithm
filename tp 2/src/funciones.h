#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define TAMJUGADOR 10 // TAMANIO DE LOS JUGADORES

#define TAMCONF 6 // TAMANIO DE LAS CONFEDERACIONES
// ESTADO
#define LIBRE 1
#define OCUPADO 0

#define DESCRIPTION_SIZE 50

typedef struct
{
	int id;
	char nombre[DESCRIPTION_SIZE];
	char posicion[DESCRIPTION_SIZE];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short anioscontrato;
	short estado;
}eJugador;



typedef struct
{
 int id;
 char nombre[DESCRIPTION_SIZE];
 char region[DESCRIPTION_SIZE];
 int anioCreacion;
 int estado;
}eConfederacion;

#include "input.h"


int MostrarMenu(void);
void comprobarConfirmacion(char mensaje[], char eMensaje[], int retorno);
void mostrarListadoConfederacion(eConfederacion lista[], int size);
void ModificarJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
int subMenuJugadores();
void Informes(eJugador lista[], int size, eConfederacion listaConf[], int sizeConf);
int subMenuInformes(void);
void MostrarUnJugador(eJugador lista, eConfederacion listaConfederacion, int opcion);
void Headers(int opcion);
void MostrarJugadoresSueldoMayorPromedio(int promedio, int contador);
int subMenuConfederaciones();
void Error(int opcion);
void ImprimirUnaConfederacionConUnaVariable(eConfederacion lista, float variable, int opcion);
#endif /* FUNCIONES_H_ */
