#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo;
     int retorno =0;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "r");

	   parser_JugadorFromText(pArchivo, pArrayListJugador);

		fclose(pArchivo);
		retorno = 1;
	}


    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo;
    int indexSeleccion;
    int retornoNum;
      int retorno = 0;
	if(path != NULL && pArrayListJugador != NULL)
	{

		controller_listarSelecciones(pArrayListSeleccion);
		do{

			printf("Ingrese la id de la seleccion que quiere cargar a binario con sus respectivos jugadores \n");
			retornoNum  = getEntero(&indexSeleccion);

		}while((indexSeleccion < 1 || indexSeleccion > 32) && retornoNum != 0);
		pArchivo = fopen(path, "wb");

	retorno	= parser_JugadorToBinary(pArchivo, pArrayListJugador, indexSeleccion);

		fclose(pArchivo);
	}


    return retorno;;
}
int controller_leerJugadoresDesdeBinario(char* path, LinkedList* listaBinario)
{
	FILE* pArchivo;
	int retorno = 0;

		if(path != NULL && listaBinario != NULL)
		{

			pArchivo = fopen(path, "rb");

		retorno = parser_JugadorFromBinary(pArchivo, listaBinario);

			fclose(pArchivo);

		}

 return retorno;
}
/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int auxId;
	char auxNombre[100];
	int auxEdad;
	char auxPosicion[30];
	char auxNacionalidad[30];
	int retorno = 0;
    Jugador* jugador;

	if(pArrayListJugador != NULL)
	{

        jugador = jug_new();

		 if(jugador != NULL)
		 {
		   auxId =	controller_AsignarId(pArrayListJugador);

				 if(jug_setId(jugador, auxId) == 1)
				 {
					 do
						{
							getString(auxNombre,"Ingrese el nombre: ", "Error, ingrese un nombre valido: ", 1, 100);
						}
						 while((esSoloLetas(auxNombre) == 0));

						jug_setNombreCompleto(jugador, auxNombre);

						do
						{
							printf("Ingrese la edad: \n");
						}
						 while((auxEdad < 16 || auxEdad > 50) && (getEntero(&auxEdad) !=0) && (auxEdad != ' '));

						jug_setEdad(jugador, auxEdad);

						do
						{
							getString(auxPosicion,"Ingrese la posicion del jugador: ", "Error, ingrese una posicion valida: ", 1, 100);

						}
						 while(getPosicion(auxPosicion) != 1);

						jug_setPosicion(jugador, auxPosicion);

						do
						{
							getString(auxNacionalidad,"Ingrese la nacionalidad: ", "Error, ingrese una nacionalidad valida: ", 1, 30);
						}
						 while(esSoloLetas(auxNacionalidad) == 0);

						jug_setNacionalidad(jugador, auxNacionalidad);

						jug_setIdSeleccion(jugador, 0);

						ll_add(pArrayListJugador, jugador);
						retorno = 1;
				 }

          }
	}

    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
	   retorno = ModificacionesJugador(pArrayListJugador);
	}



    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int size;
	int index;
	int retorno = 0;
	int auxId ;
	Jugador* jugador;

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

	do{	printf("\nPRECAUCION, SI INGRESA MAL UNA ID DARA DE BAJA AL JUGADOR EQUIVOCADO\nIngrese la id a dar de baja: \n");


	  }while((index < 0 || index > 5000) && (getEntero(&index) !=0));

		size = ll_len(pArrayListJugador);

					for(int i = 0; i < size ; i++)
					{
						jugador = (Jugador*)ll_get(pArrayListJugador, i);

						jug_getId(jugador, &auxId);
                           // printf("id: %d index: %d", auxId, index);
                         //   break;
							if(auxId == index)
							{
							 ll_remove(pArrayListJugador, i);
							 retorno = 1;
								break;
							}
					}
	}


    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int size;
	int retorno = 0;
	Jugador* jugador;

	if(pArrayListJugador != NULL)
		{
			size = ll_len(pArrayListJugador);

			for(int i = 0; i<size;i++)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador, i);
					if(jugador != NULL)
					{
						jug_printOne(jugador);
						retorno = 1;
					}

			}
		}
	return retorno;
}
int controller_AsignarId(LinkedList* pArrayListJugador)
{
     int size;
     int mayorId = 0;
     int auxId;
     Jugador* jugador;
     int bandera = 0;


   if(pArrayListJugador != NULL)
   {
	   size = ll_len(pArrayListJugador);
		   for (int i = 0; i < size; ++i)
		 {

			 jugador = (Jugador*)ll_get(pArrayListJugador, i);
			 jug_getId(jugador, &auxId);

				if(bandera == 0 || mayorId < auxId)
				{
					mayorId = auxId;
					bandera = 1;
				}
		 }
		mayorId += 1;
   }

     return mayorId;
}
/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{

	FILE* pArchivo;
	 int retorno =0;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "w");

		parser_JugadorToText(pArchivo, pArrayListJugador);

		fclose(pArchivo);
		retorno = 1;
	}


	return retorno;
}
/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSelec)
{

	FILE* pArchivo;
	 int retorno =0;

	if(path != NULL && pArrayListSelec != NULL)
	{
		pArchivo = fopen(path, "w");

		parser_SeleccionToText(pArchivo, pArrayListSelec);

		fclose(pArchivo);
		retorno = 1;
	}


	return retorno;


}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{




    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo;
     int retorno = 0;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pArchivo = fopen(path, "r");

		parser_SeleccionFromText(pArchivo , pArrayListSeleccion);

		fclose(pArchivo);
		retorno = 1;
	}


    return retorno;
}
/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int size;
	int retorno = 0;
	Seleccion* seleccion;

	if(pArrayListSeleccion != NULL)
		{
			size = ll_len(pArrayListSeleccion);

			for(int i = 0; i<size;i++)
			{
				seleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);
					if(seleccion != NULL)
					{
						selec_printOne(seleccion);
						retorno = 1;
					}

			}
		}
	return retorno;
}

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int opcion;
	 do{
		       opcion = subMenuConvocaciones();

		        switch(opcion){
		           case 1:
		        	   retorno = jug_convocar(pArrayListJugador, pArrayListSeleccion);
		        	   comprobarConfirmacion("Se pudo convocar al jugador \n", "Error, no se pudo convocar al jugador \n", retorno);
		           break;
		           case 2:
		        	   retorno = jug_quitarDeLaSeleccion(pArrayListJugador);
		        	   comprobarConfirmacion("Se pudo convocar al jugador \n", "Error, no se pudo eliminar al jugador \n", retorno);
		           break;
		        }
		    }
		    while(opcion != 3);



	return retorno;
}

