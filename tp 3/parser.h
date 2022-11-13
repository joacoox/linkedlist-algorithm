
#ifndef PARSER_H_
#define PARSER_H_



int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* listaBinario);
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador, int indexSeleccion);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador);
#endif /* PARSER_H_ */
