#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void getString(char cadena[], char mensaje[],int min, int max);
int esSoloLetas(char cadena[]);
int getEntero(int* pResultado);
int esNumerica(char* cadena, int limite);
int getStrings(char* cadena, int longitud);
void PasarAMinusculas(char cadena[], char oracion[]);
int getNumeroEntreParametro(int max, int min, char mensaje[]);
#endif
