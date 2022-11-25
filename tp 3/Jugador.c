#include "Jugador.h"

Jugador* jug_new()
{
	Jugador* unJugador;
	unJugador = (Jugador*) malloc(sizeof(Jugador));
	return unJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;
	unJugador = jug_new();

	if(unJugador != NULL)
	{
		if(	jug_setNombreCompleto(unJugador,nombreCompletoStr) == -1 ||
				jug_setId(unJugador,atoi(idStr)) == -1 ||
				jug_setEdad(unJugador,atoi(edadStr)) == -1 ||
				jug_setPosicion(unJugador,posicionStr) == -1 ||
				jug_setNacionalidad(unJugador,nacionalidadStr) == -1||
				jug_setIdSeleccion(unJugador,atoi(idSelccionStr)) == -1)
		{
			jug_delete(unJugador);
			unJugador = NULL;
		}
	}

	return unJugador;
}
void jug_delete(Jugador* this)
{
	if(this != NULL)
		{
			free(this);
		}
}
int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

		if(this != NULL && id >= 0)
		{
			  this->id= id;
			  retorno = 1;
		}

	return retorno;
}
int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
		{
         *id = this->id;
	    retorno = 1;
		}

	return retorno;
}
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;
   char aux[100];
	if(this != NULL && nombreCompleto != NULL)
	{
		if(esSoloLetas(nombreCompleto) == 1)
		{
			PasarAMinusculas(nombreCompleto, aux);
			strcpy(this->nombreCompleto, aux);
			retorno = 1;
		}

	}
	return retorno;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
			strcpy(nombreCompleto, this->nombreCompleto);
			retorno = 1;
	}
	return retorno;
}
int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 1;

	if(this != NULL && posicion != NULL)
	{
		if(getPosicion(posicion) == 1)
		{
			strcpy(this->posicion, posicion);
			retorno = 1;
		}

	}
	return retorno;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 1;

		if(this != NULL && posicion != NULL)
		{
				strcpy(posicion, this->posicion);
				retorno = 1;
		}

	return retorno;
}
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

		if(this != NULL && nacionalidad != NULL)
		{
			if(esSoloLetas(nacionalidad) == 1)
			{
				strcpy(this->nacionalidad, nacionalidad);
				retorno = 1;
			}
		}
		return retorno;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

		if(this != NULL && nacionalidad != NULL)
		{
				strcpy(nacionalidad, this->nacionalidad);
				retorno = 1;
		}
		return retorno;
}
int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad >= 0 && edad < 100)
	{
		  this->edad = edad;
		  retorno = 1;
	}

	return retorno;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
		{
			 *edad = this->edad;
			retorno = 1;
		}

	return retorno;
}
int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

			if(this != NULL && idSeleccion >= 0 && idSeleccion <= 32)
			{
				  this->idSeleccion = idSeleccion;
				  retorno = 1;
			}

		return retorno;
}
int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion != NULL)
		{
		 *idSeleccion = this->idSeleccion;
		retorno = 1;
		}

	return retorno;
}
void jug_printOne(Jugador* Jugador,LinkedList* pArraylistSeleccion)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;
	Seleccion* aux;
	char pais[30];

	jug_getId(Jugador, &id);
	jug_getNombreCompleto(Jugador, nombreCompleto);
	jug_getEdad(Jugador, &edad);
	jug_getPosicion(Jugador, posicion);
	jug_getNacionalidad(Jugador, nacionalidad);
	jug_getIdSeleccion(Jugador, &idSeleccion);



	if(idSeleccion == 0)
	{
		printf("%5d %-25s %-25d %-25s %-25s No convocado\n",id,nombreCompleto,edad,posicion,nacionalidad);
	}else
	{
	   aux = selec_BuscarPorId(pArraylistSeleccion, idSeleccion);
	   selec_getPais(aux, pais);
		printf("%5d %-25s %-25d %-25s %-25s %s\n",id,nombreCompleto,edad,posicion,nacionalidad, pais);
	}



}
/*
 * \brief paso a minusculas lo que el usuario ingrese y valido el tamanio del texto
 * \param cadena la cadena de caracteres a modificar
 * \return void
 */
int getPosicion(char posicion[])
{
     int retorno = 0;

     for(int i =0; posicion[i]!= '\0'; i++)
  	{
  		posicion[i] = tolower(posicion[i]);
  	}

   if(strcmp(posicion,"mediocentro") == 0 || strcmp(posicion,"portero") == 0 || strcmp(posicion,"defensa central") == 0 || strcmp(posicion,"lateral izquierdo") == 0
		   || strcmp(posicion,"lateral derecho") == 0|| strcmp(posicion,"pivote") == 0 || strcmp(posicion,"mediocentro ofensivo") == 0 || strcmp(posicion,"extremo izquierdo") == 0
		   || strcmp(posicion,"extremo derecho") == 0 || strcmp(posicion,"delantero centro") == 0|| strcmp(posicion,"mediocampista") == 0|| strcmp(posicion,"defensor") == 0|| strcmp(posicion,"delantero") == 0
		   || strcmp(posicion,"arquero") == 0 || strcmp(posicion,"mediapunta") == 0 || strcmp(posicion,"interior derecho") == 0 || strcmp(posicion,"interior izquierdo") == 0)
   {
  	retorno = 1;
   }

    return retorno;
}
int ModificacionesJugador(LinkedList* pArrayListJugador)
{
	int opcion;
	int index;
	int retorno = 0;
    Jugador* jugador = NULL;

 if(pArrayListJugador != NULL)
 {

	index = getNumeroEntreParametro(5000, 1, "Ingrese la id del jugador que quiera modificar: \n");
     jugador = jug_BuscarPorId(pArrayListJugador, index);

    if(jugador != NULL)
    {
     opcion = subMenuModificaciones();
     retorno = jug_Modificaciones(jugador, opcion);
    }
    else
    {
    	printf("El id ingresado no representa a un jugador en servicio\n");
    }
 }
  return retorno;
}
int jug_Modificaciones(Jugador* Jugador, int opcion)
{
int retorno = 0;
    switch(opcion)
    {
          case 1:
        retorno = jug_ModificacionNombre(Jugador);
          break;
          case 2:
        retorno = jug_ModificacionEdad(Jugador);
          break;
          case 3:
        retorno = jug_ModificacionPosicion(Jugador);
          break;
          case 4:
        retorno = jug_ModificacionNacionalidad(Jugador);
          break;
   }
    return retorno;
}
int jug_ModificacionNombre(Jugador* this)
{
	char auxNombre[100];
	int retorno = 0;
	if(this != NULL)
	{
		getString(auxNombre, "Ingrese el nombre completo del jugador: \n",5,100);
		jug_setNombreCompleto(this, auxNombre);
		retorno = 1;
	}
	return retorno;
}
int jug_ModificacionEdad(Jugador* this)
{
	int auxEdad;
	int retorno = 0;
	if(this != NULL)
	{
		auxEdad	= getNumeroEntreParametro(60, 18, "Ingrese la edad del jugador\nTiene que ser entre 18 y 60\nSu opcion: \n\n");
		jug_setEdad(this, auxEdad);
		retorno = 1;
	}
	return retorno;
}
int jug_ModificacionPosicion(Jugador* this)
{
	int retorno = 0;
	char auxPosicion[50];
	if(this != NULL)
	{
		do
		{
			getString(auxPosicion,"Ingrese la posicion del jugador: ",5,100);
		}
		 while(getPosicion(auxPosicion) != 1);
		jug_setPosicion(this, auxPosicion);
		retorno = 1;
	}
	return retorno;
}
int jug_ModificacionNacionalidad(Jugador* this)
{
    char auxNacionalidad[50];
	int retorno = 0;
	if(this != NULL)
	{
		getString(auxNacionalidad,"Ingrese la nacionalidad: \n", 5,30);

		jug_setNacionalidad(this, auxNacionalidad);
		retorno = 1;
	}

	return retorno;
}
int jug_CompararPorNacionalidad(void* unJugador, void* otroJugador)
{
	Jugador* jugadorUno;
	Jugador* jugadorDos;
	char nacionalidadJugadorUno[50];
	char nacionalidadJugadorDos[50];
	int compara;

   if(unJugador != NULL && otroJugador != NULL)
   {
	   jugadorUno =(Jugador*) unJugador;
	   jugadorDos =(Jugador*) otroJugador;
	   jug_getNacionalidad(jugadorUno, nacionalidadJugadorUno);
	   jug_getNacionalidad(jugadorDos, nacionalidadJugadorDos);

	   compara = strcmp(nacionalidadJugadorUno, nacionalidadJugadorDos);
   }

   return compara;
}
int jug_CompararPorEdad(void* unJugador, void* otroJugador)
{
	Jugador* jugadorUno;
	Jugador* jugadorDos;
	int edadJugadorUno;
	int edadJugadorDos;
	int compara =0;

   if(unJugador != NULL && otroJugador != NULL)
   {
	   jugadorUno =(Jugador*) unJugador;
	   jugadorDos =(Jugador*) otroJugador;
	   jug_getEdad(jugadorUno, &edadJugadorUno);
	   jug_getEdad(jugadorDos, &edadJugadorDos);

	  if(edadJugadorUno > edadJugadorDos)
	  {
		  compara = 1;
	  }
	  else
	  {
		  if(edadJugadorUno < edadJugadorDos)
		  {
			 compara = -1;
		  }
	  }
   }

   return compara;
}
int jug_CompararPorNombre(void* unJugador, void* otroJugador)
{
	Jugador* jugadorUno;
	Jugador* jugadorDos;
	char nombreJugadorUno[100];
	char nombreJugadorDos[100];
	int compara;

   if(unJugador != NULL && otroJugador != NULL)
   {
	   jugadorUno =(Jugador*) unJugador;
	   jugadorDos =(Jugador*) otroJugador;
	   jug_getNombreCompleto(jugadorUno, nombreJugadorUno);
	   jug_getNombreCompleto(jugadorDos, nombreJugadorDos);

	   compara = strcmp(nombreJugadorUno, nombreJugadorDos);
   }

   return compara;
}
int jug_convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=0;
    int jugadorIdSeleccion;
	int idSeleccion;
    int convocados;
    int indexJugador;
    int indexSeleccion;

    Jugador* jugador = NULL;
    Seleccion* seleccion = NULL;;

	if(pArrayListJugador!= NULL && pArrayListSeleccion != NULL)
	{

		jug_ListaJugadoresPorCriterio(pArrayListJugador, pArrayListSeleccion, 1);
		indexJugador = getNumeroEntreParametro(5000, 0, "Ingrese el ID del jugador al que quiere convocar: \n");
		jugador = jug_BuscarPorId(pArrayListJugador, indexJugador);
		jug_getIdSeleccion(jugador, &jugadorIdSeleccion);
		if(jugador != NULL && jugadorIdSeleccion == 0)
		{

		controller_listarSelecciones(pArrayListSeleccion);
		indexSeleccion = getNumeroEntreParametro(32, 0, "Ingrese la seleccion a la que quiere convocar al jugador: \n");
		seleccion = selec_BuscarPorId(pArrayListSeleccion, indexSeleccion);
			if(seleccion != NULL)
			{
				selec_getConvocados(seleccion, &convocados);

				if(convocados < 22)
				{
				selec_setConvocados(seleccion, convocados+1);
				selec_getId(seleccion, &idSeleccion);
				jug_setIdSeleccion(jugador, idSeleccion);
				printf("La convocacion fue un exito rotundo\n");
				}else
				{
					printf("Error, ya hay 22 convocados\n");
				}
			}else
			{
				printf("El id ingresado no representa a una seleccion en servicio");
			}
		}else
		{
			printf("El id ingresado no representa a un jugador en servicio\n O el jugador ya esta en una seleccion");
		}

	 }


	return retorno;
}
int jug_quitarDeLaSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=0;
    int selecIdAux;
    int indexJugador;
    int auxConvocados;
    Seleccion* aux = NULL;
    Jugador* jugador = NULL;

	if(pArrayListJugador!= NULL)
	{

		jug_ListaJugadoresPorCriterio(pArrayListJugador, pArrayListSeleccion, 2);
		indexJugador = getNumeroEntreParametro(5000, 0, "Ingrese el id del jugador que quiera sacar de la seleccion: \n");
		jugador = jug_BuscarPorId(pArrayListJugador, indexJugador);

		if(jugador != NULL)
		{
			jug_getIdSeleccion(jugador, &selecIdAux);
			if(selecIdAux != 0)
			{
				aux = selec_BuscarPorId(pArrayListSeleccion, selecIdAux);
				selec_getConvocados(aux, &auxConvocados);
				selec_setConvocados(aux, auxConvocados-1);
				 jug_setIdSeleccion(jugador, 0);
				 printf("Se quito al jugador de la seleccion, la proxima que juegue mejor\n");
				 retorno = 1;
			}else
			{
			 printf("El jugador que quiere sacar de la seleccion no esta en ninguna seleccion\n");
			}
		}else
		{
			printf("El id ingresado no representa a un jugador en servicio \n");
		}
	}

	return retorno;
}
int jug_ListaJugadoresPorCriterio(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int opcion)
{
	int size;
	int retorno = 0;
	int idAux;
	Jugador* jugador= NULL;

	Headers(1);
	if(pArrayListJugador != NULL)
		{
			size = ll_len(pArrayListJugador);

			for(int i = 0; i<size;i++)
			{
				jugador = (Jugador*)ll_get(pArrayListJugador, i);
				jug_getIdSeleccion(jugador, &idAux);
				switch(opcion)
				{
				case 1:
					if(jugador != NULL && idAux == 0) // no convocado
					{
						jug_printOne(jugador, pArrayListSeleccion);
						retorno = 1;
					}
					break;
				case 2:
					if(jugador != NULL && idAux != 0) // convocados
					{
						jug_printOne(jugador, pArrayListSeleccion);
					}
					break;
				}


			}
		}
	return retorno;
}
Jugador* jug_BuscarPorId(LinkedList* pArraylistJugador, int index)
{
	int indice;
	Jugador* aux= NULL;
	Jugador* retorno = NULL;

  if(pArraylistJugador != NULL && index > 0)
  {
	  indice = jug_BuscarPorIndice(pArraylistJugador, index);
	  aux = ll_get(pArraylistJugador, indice);
	      if(aux != NULL)
	      {
	    	  retorno = aux;
	      }

  }

  return retorno;
}
int jug_BuscarPorIndice(LinkedList* pArraylistJugador, int index)
{
	int size;
	int auxId;
	Jugador* aux= NULL;
	int retorno = -1;
	int i;

  if(pArraylistJugador != NULL && index > 0)
  {
	  size = ll_len(pArraylistJugador);

	  if(size > 0)
	  {
		  for(i = 0 ; i < size ; i++)
		  {
			 aux = (Jugador*)ll_get(pArraylistJugador, i);
			 jug_getId(aux, &auxId);
			  		if(auxId == index)
			  		{
			  			retorno = i;
			  			break;
			  		}
		  }

	  }

  }

  return retorno;
}
