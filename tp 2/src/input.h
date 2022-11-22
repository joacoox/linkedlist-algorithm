#ifndef INPUT_H_
#define INPUT_H_

#include "jugador.h"
#include "confederacion.h"
#include "funciones.h"
#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


float getFloat(char mensaje[], char eMensaje[], float minLimit, float maxLimit);
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
void getString(char cadena[],char mensaje[], char eMensaje[], int minLimit, int maxLimit);
int esSoloLetas(char cadena[]);
int getStringLetras(char mensaje[],char input[]);
int esAlfaNumerico(char str[]);
int getEntero(int* pResultado);
int esNumerica(char* cadena, int limite);
int getStrings(char* cadena, int longitud);
#endif /* INPUT_H_ */


