#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int esSoloLetas(char cadena[]);
int getEntero(int* pResultado);
int esNumerica(char* cadena, int limite);
int getStrings(char* cadena, int longitud);
void getString(char cadena[], char mensaje[], char eMensaje[], int minLimit,int maxLimit);
#endif
