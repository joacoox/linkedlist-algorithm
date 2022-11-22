#ifndef JUGADOR_H_
#define JUGADOR_H_

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

#include "funciones.h"
#include "confederacion.h"
#include "input.h"
#include "operaciones.h"

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
void getPosicion(char cadena[]);
void BuscarJugadorPorId(eJugador lista[], int size, int index, eConfederacion listaConfederacion);
int BuscarIdValido(eJugador lista[], int size, int index);
#endif

