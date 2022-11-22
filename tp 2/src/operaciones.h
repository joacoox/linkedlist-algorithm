#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include "confederacion.h"
#include "jugador.h"
#include "input.h"
#include "funciones.h"


void PromedioDeTodosLosSalarios(eJugador lista[], int size);
float sacarPromedio(int resultado, int acumulador);
int JugadoresCobranMasQuePromedio(eJugador lista[], int size, int promedio);
void ConfederacionConMayorDuracionContratos(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
int AcumularAniosJugadorConfederacion(eJugador lista[], int size, int index);
void PorcentajeDeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
float CalcularPorcentajeDeConfederaciones(eJugador lista[], int size, int index);
eConfederacion ConfederacionConMasJugadores(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
int AcumularJugadores(eJugador lista[], int size, int index);
#endif
