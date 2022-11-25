
#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* listaBinario, LinkedList* listaSeleccion);
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, char confederacion[]);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_IdToText(FILE* pFile , int id);
int parser_IdFromText(FILE* pFile);
#endif /* PARSER_H_ */
