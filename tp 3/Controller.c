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
    char auxConfederacion[30];
    int retornoFuncion;
      int retorno = 0;
	if(path != NULL && pArrayListJugador != NULL)
	{

		controller_listarSelecciones(pArrayListSeleccion);
	do
	{
	retornoFuncion = selec_PedirConfederacion(auxConfederacion);
	}while(retornoFuncion != 1);


		pArchivo = fopen(path, "wb");

	retorno	= parser_JugadorToBinary(pArchivo, pArrayListJugador, pArrayListSeleccion, auxConfederacion);

		fclose(pArchivo);
	}


    return retorno;;
}
int controller_leerJugadoresDesdeBinario(char* path, LinkedList* listaBinario, LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo;
	int retorno = 0;

		if(path != NULL && listaBinario != NULL)
		{

			pArchivo = fopen(path, "rb");

		retorno = parser_JugadorFromBinary(pArchivo, listaBinario, pArrayListSeleccion);

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
            auxId = controller_cargarIdDesdeTexto("id.txt");
		    jug_setId(jugador, auxId);
		    getString(auxNombre, "Ingrese el nombre completo del jugador: \n",5,100);
			jug_setNombreCompleto(jugador, auxNombre);
			auxEdad	= getNumeroEntreParametro(60, 18, "Ingrese la edad del jugador\nTiene que ser entre 18 y 60\nSu opcion: \n\n");
			jug_setEdad(jugador, auxEdad);
			do
			{
				getString(auxPosicion,"Ingrese la posicion del jugador \nArquero,Defensor,Mediocampista,Delantero\nSu opcion:\n",5,30);
			}
			 while(getPosicion(auxPosicion) != 1);
			jug_setPosicion(jugador, auxPosicion);
			getString(auxNacionalidad,"Ingrese la nacionalidad: \n", 5,30);
			jug_setNacionalidad(jugador, auxNacionalidad);
			jug_setIdSeleccion(jugador, 0);
			ll_add(pArrayListJugador, jugador);
			retorno = 1;
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
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
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
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int index;
	int retorno = 0;
	int auxId;
	int auxConvocados;
	int indice;
	Jugador* jugador = NULL;
	Seleccion* seleccion = NULL;

	if(pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

	index = getNumeroEntreParametro(5000, 0, "\nPRECAUCION, SI INGRESA MAL UNA ID DARA DE BAJA AL JUGADOR EQUIVOCADO\nIngrese la id a dar de baja: \n");

	jugador = jug_BuscarPorId(pArrayListJugador, index);

	if(jugador != NULL)
	{
		jug_getIdSeleccion(jugador, &auxId);

         indice = jug_BuscarPorIndice(pArrayListJugador, index);
		ll_remove(pArrayListJugador, indice);
		retorno = 1;

		if(auxId != 0)
		{
			printf("El jugador que acaba de eliminar estaba convococado, ahora dicha seleccion tiene un espacio mas \n");
			seleccion = selec_BuscarPorId(pArrayListSeleccion, auxId);
			selec_getConvocados(seleccion, &auxConvocados);
			selec_setConvocados(seleccion, auxConvocados-1);
		}

	}else
	{
		printf("El id ingresado no representa a un jugador en servicio\n");
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
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int size;
	int retorno = 0;
	Jugador* jugador;

	Headers(1);
	if(pArrayListJugador != NULL)
		{
			size = ll_len(pArrayListJugador);

			for(int i = 0; i<size;i++)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador, i);
					if(jugador != NULL)
					{
						jug_printOne(jugador, pArrayListSeleccion);
						retorno = 1;
					}

			}
		}
	return retorno;
}
int controller_guardarIdModoTexto(char* path , int id)
{

	FILE* pArchivo;
	 int retorno =0;

	if(path != NULL && id > 0)
	{
		pArchivo = fopen(path, "w");

		parser_IdToText(pArchivo, id);

		fclose(pArchivo);
		retorno = 1;
	}


	return retorno;
}
int controller_cargarIdDesdeTexto(char* path)
{
	FILE* pArchivo;
     int retorno = 0;

     if(path != NULL)
	{
		pArchivo = fopen(path, "r");

		retorno = parser_IdFromText(pArchivo);

		fclose(pArchivo);
	}


    return retorno;
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
		Headers(2);
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
		           break;
		           case 2:
		        	   retorno = jug_quitarDeLaSeleccion(pArrayListJugador, pArrayListSeleccion);
		           break;
		        }
		    }
		    while(opcion != 3);



	return retorno;
}

