#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define DESCRIPTION_SIZE 50

typedef struct
{
 int id;
 char nombre[DESCRIPTION_SIZE];
 char region[DESCRIPTION_SIZE];
 int anioCreacion;
 int estado;
}eConfederacion;

#include "funciones.h"
#include "jugador.h"
#include "input.h"


int altaConfederacion(eConfederacion listaConfederacion[], int size, int confederaciones);
int BajaConfederacion(eConfederacion listaConfederacion[], int size);
void ModificarConfederaciones(eConfederacion lista[], int size);
void ModificarNombreConfederacion(eConfederacion lista[], int size, int index);
void ModificarRegionConfederacion(eConfederacion lista[], int size, int index);
void ModificarAnioDeCreacionConfederacion(eConfederacion lista[], int size, int index);
void OrdenamientoPorNombreDeConfederacion(eConfederacion listaConfederacion[], int sizeConf);
void ListadoDeConfederaciones(eConfederacion listaConfederacion[], int sizeConf, eJugador lista[], int size);
void  ListadoConfederaciones(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
void ListadoConfederacionesConSusJugadores(eJugador lista[], int size, eConfederacion listaConfederacion, int index);
int BuscarConfederacionPorId(eConfederacion lista[], int size, int index);
void ListarConfederacion(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf);
#endif

