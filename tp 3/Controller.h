#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"



int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_agregarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);
int controller_AsignarId(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_leerJugadoresDesdeBinario(char* path, LinkedList* pArrayListJugador);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSelec);
