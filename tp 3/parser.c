#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	char id[15];
	char nombreCompleto[100];
	char edad[15];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[15];
	int valoresLeidos;
	int retorno = 0;
	Jugador* aux;

	if(pFile != NULL && pArrayListJugador != NULL)
	{

		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n", id, nombreCompleto, edad, posicion,nacionalidad,idSeleccion);

		do{
			valoresLeidos = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n", id, nombreCompleto, edad, posicion,nacionalidad,idSeleccion);

					if(valoresLeidos == 6)
					{
							aux = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
								if(aux != NULL)
								{
									ll_add(pArrayListJugador, aux);
									retorno =1;
								}

					}
		}while(!feof(pFile));

	}
    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* listaBinario, LinkedList* listaSeleccion)
{
	Jugador* unJugador;
    int retorno = 0;

	if(pFile != NULL && listaBinario != NULL)
	{

		do{
			unJugador = jug_new();
			fread(unJugador, sizeof(Jugador),1,pFile);

			if(feof(pFile))
			{
				jug_delete(unJugador);
				break;
			}
			ll_add(listaBinario, unJugador);
			jug_printOne(unJugador, listaSeleccion);
			retorno = 1;
		}while(!feof(pFile));

	}

    return retorno;
}
int parser_JugadorToBinary(FILE* pFile , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, char confederacion[])
{
	int size;
	int idSeleccion;
	int retorno = 0;
	char confederacionAux[30];
	Jugador* jugador;
    Seleccion* auxSeleccion;

	if(pFile != NULL && pArrayListJugador != NULL)
		{
		size = ll_len(pArrayListJugador);

		          for(int i = 0; i < size; i++)
		          {
		        	  jugador = (Jugador*)ll_get(pArrayListJugador, i);
		        	  jug_getIdSeleccion(jugador, &idSeleccion);

		        	  if(idSeleccion != 0)
		        	  {
                      auxSeleccion = selec_BuscarPorId(pArrayListSeleccion, idSeleccion);
                      selec_getConfederacion(auxSeleccion, confederacionAux);

						  if(strcmp(confederacionAux, confederacion) == 0)
						  {
							  fwrite(jugador, sizeof(Jugador),1, pFile);
							  retorno = 1;
						  }

		        	  }

		          }
		}
 return retorno;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	    char id[15];
		char pais[30];
		char confederacion[30];
		char convocados[15];
		int valoresLeidos;
		int retorno = 0;
		Seleccion* aux;

		if(pFile != NULL && pArrayListSeleccion != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

			do{
		valoresLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
						if(valoresLeidos == 4)
						{
								aux = selec_newParametros(id, pais, confederacion, convocados);
									if(aux != NULL)
									{
										ll_add(pArrayListSeleccion, aux);
										retorno =1;
									}
						}
			}while(!feof(pFile));
		}
	    return retorno;
}
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador)
{
	    int size;
		int retorno = 0;
		int id;
		char nombreCompleto[100];
		int edad;
		char posicion[30];
		char nacionalidad[30];
		int idSeleccion;
		Jugador* jugador;

		if(pFile != NULL && pArrayListJugador != NULL)
			{
			size = ll_len(pArrayListJugador);

			          for(int i = 0; i < size; i++)
			          {
			        	  jugador = (Jugador*)ll_get(pArrayListJugador, i);

			        	   if((jug_getId(jugador, &id)) == 1 &&
			        	  	(jug_getNombreCompleto(jugador, nombreCompleto))== 1 &&
			        	  	(jug_getEdad(jugador, &edad))== 1 &&
			        	  	(jug_getPosicion(jugador, posicion))== 1 &&
			        	  	(jug_getNacionalidad(jugador, nacionalidad))== 1 &&
			        	    (jug_getIdSeleccion(jugador, &idSeleccion)) == 1)
			        	   {
			        		    fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
						    retorno = 1;
			        	   }
			          }
			}
	 return retorno;


}
int parser_SeleccionToText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	        int size;
			int retorno = 0;
			int id;
			char pais[30];
			char confederacion[30];
			int convocados;
			Seleccion* seleccion;

			if(pFile != NULL && pArrayListSeleccion != NULL)
				{
				size = ll_len(pArrayListSeleccion);

				          for(int i = 0; i < size; i++)
				          {
				        	  seleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);

				        	if((selec_getId(seleccion, &id)) == 1 &&
				        	  (selec_getPais(seleccion, pais))== 1 &&
				        	  (selec_getConfederacion(seleccion, confederacion)) == 1 &&
				        	  (selec_getConvocados(seleccion, &convocados))== 1)
				        	{
				        		fprintf(pFile,"%d,%s,%s,%d\n",id,pais,confederacion,convocados);
							    retorno = 1;
				        	}


				          }
				}
		 return retorno;


}
int parser_IdToText(FILE* pFile , int id)
{
	    int retorno = -1;

		if(pFile != NULL && id > 0)
		{
			fprintf(pFile,"%d\n",id);
			retorno = 1;
		}

	 return retorno;
}
int parser_IdFromText(FILE* pFile)
{
	int id = -1;
	char idtxt[10];
	int valoresLeidos;

		if(pFile != NULL)
		{
			valoresLeidos = fscanf(pFile,"%[^\n]\n", idtxt);

			if(valoresLeidos == 1)
			{
		    id = atoi(idtxt);
			id++;
			controller_guardarIdModoTexto("id.txt" , id);
			}
	    }

   return id;
}
