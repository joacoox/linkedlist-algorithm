#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
// prototipos
void menu();
int validacionMenu(int opcion);
int validacionCasoUno(int opcion);
int obtenerCosto(float* costo);
int validacionCasoDos(int opcion);
int obtenerDatos(int confederacion);
void ingresoDeCamisetas(void);
float porcentajeConfederacion(int confederacion);

#endif
