#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int getInt(char mensaje[],char eMensaje[],int min, int max);
float getFloat(char mensaje[], char eMensaje[], float minLimit, float maxLimit);
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
void getString(char cadena[],char mensaje[], char eMensaje[], int minLimit, int maxLimit);
int getStringLetras(char mensaje[],char input[]);
int esAlfaNumerico(char str[]);
float sacarPromedio(int resultado, int acumulador);
int NumeroRepetido(int array[], int i, int numAleatorio,int tamanioArray);
int esSoloLetas(char cadena[]);
void PasarAMinusculas(char cadena[], char oracion[]);
#endif
