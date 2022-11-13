#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "input.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"

int mostrarMenu(void);
void comprobarConfirmacion(char mensaje[], char eMensaje[], int retorno);
void Listados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int subMenuListados(void);
int subMenuModificaciones(void);
int ListadosOrdenadosPorCriterio(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int subMenuOrdenarListar(void);
int subMenuConvocaciones(void);
#endif
