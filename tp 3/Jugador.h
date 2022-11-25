#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "funciones.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

void jug_printOne(Jugador* Jugador, LinkedList* pArraylistSeleccion);
int jug_ListaJugadoresPorCriterio(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int opcion);

int getPosicion(char posicion[]);

int ModificacionesJugador(LinkedList* pArrayListJugador);
int jug_Modificaciones(Jugador* Jugador, int opcion);

int jug_ModificacionNombre(Jugador* this);
int jug_ModificacionEdad(Jugador* this);
int jug_ModificacionPosicion(Jugador* this);
int jug_ModificacionNacionalidad(Jugador* this);

int jug_CompararPorNacionalidad(void* unJugador, void* otroJugador);
int jug_CompararPorEdad(void* unJugador, void* otroJugador);
int jug_CompararPorNombre(void* unJugador, void* otroJugador);

int jug_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int jug_quitarDeLaSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

Jugador* jug_BuscarPorId(LinkedList* pArraylistJugador, int index);
int jug_BuscarPorIndice(LinkedList* pArraylistJugador, int index);

#endif // jug_H_INCLUDED
