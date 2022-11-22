#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define TAMJUGADOR 15 // TAMANIO DE LOS JUGADORES

#define TAMCONF 6 // TAMANIO DE LAS CONFEDERACIONES
// ESTADO
#define LIBRE 1
#define OCUPADO 0

#define DESCRIPTION_SIZE 50

#include "jugador.h"
#include "confederacion.h"
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
void MostrarJugadoresSueldoMayorPromedio(int promedio, int jugadoresQueSuperanElPromedio, int total);
int subMenuConfederaciones();
void Error(int opcion);
void ImprimirUnaConfederacionConUnaVariable(eConfederacion lista, float variable, int opcion);
#endif /* FUNCIONES_H_ */
