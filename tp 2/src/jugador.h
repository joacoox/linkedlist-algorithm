#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "input.h"
#include "funciones.h"

void inicializarJugadores(eJugador lista[], int size);
int altaJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf, int jugadores);
int BajaJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
void ModificarNombre(eJugador lista[], int size, int index);
void ModificarPosicion(eJugador lista[], int size, int index);
void ModificarNumCamiseta(eJugador lista[], int size, int index);
void ModificarSueldo(eJugador lista[], int size, int index);
void ModificarConfederacion(eJugador lista[], int size, int index, eConfederacion listaConfederacion[], int sizeConf);
void ModificarAniosContrato(eJugador lista[], int size, int index);
void OrdenamientoDeJugadorAlfabeticamente(eJugador lista[], int size);

#endif

