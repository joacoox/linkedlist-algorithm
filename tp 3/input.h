#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
void getString(char cadena[],char mensaje[], char eMensaje[], int minLimit, int maxLimit);
int getStringLetras(char mensaje[],char input[]);
int esAlfaNumerico(char str[]);
float sacarPromedio(int resultado, int acumulador);
int NumeroRepetido(int array[], int i, int numAleatorio,int tamanioArray);
int esSoloLetas(char cadena[]);
void PasarAMinusculas(char cadena[], char oracion[]);
int getEntero(int* pResultado);
int esNumerica(char* cadena, int limite);
int getStrings(char* cadena, int longitud);
#endif
