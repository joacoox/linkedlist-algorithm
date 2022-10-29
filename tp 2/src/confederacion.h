#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include "input.h"
#include "funciones.h"

int altaConfederacion(eConfederacion listaConfederacion[], int size, int confederaciones);
int BajaConfederacion(eConfederacion listaConfederacion[], int size);
void ModificarConfederaciones(eConfederacion lista[], int size);
void ModificarNombreConfederacion(eConfederacion lista[], int size, int index);
void ModificarRegionConfederacion(eConfederacion lista[], int size, int index);
void ModificarAnioDeCreacionConfederacion(eConfederacion lista[], int size, int index);
void OrdenamientoPorNombreDeConfederacion(eConfederacion listaConfederacion[], int sizeConf);
void ListadoDeConfederaciones(eConfederacion listaConfederacion[], int sizeConf, eJugador lista[], int size);
void BuscarJugadorPorId(eJugador lista[], int size, int index, eConfederacion listaConfederacion);
void  ListadoConfederaciones(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
void ListadoConfederacionesConSusJugadores(eJugador lista[], int size, eConfederacion listaConfederacion, int index);
#endif
