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
void jug_printOne(Jugador* Jugador)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];

	jug_getId(Jugador, &id);
	jug_getNombreCompleto(Jugador, nombreCompleto);
	jug_getEdad(Jugador, &edad);
	jug_getPosicion(Jugador, posicion);
	jug_getNacionalidad(Jugador, nacionalidad);

	printf("%5d %-25s %-25d %-25s %-25s\n",id,nombreCompleto,edad,posicion,nacionalidad);
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
	int size;
	int auxId;
	int retorno = 0;
	int retornoIndex;
    Jugador* jugador;

 if(pArrayListJugador != NULL)
 {
	 do{
		 printf("Ingrese el id a modificar: \n");
		 retornoIndex = getEntero(&index);

       }while((index < 0 || index > 5000) && retornoIndex != 0);


      opcion = subMenuModificaciones();
      size = ll_len(pArrayListJugador);

       for(int i = 0; i<size; i++)
       {
    	   jugador = (Jugador*)ll_get(pArrayListJugador, i);

    	   jug_getId(jugador, &auxId);

    	    if(auxId == index){

    	    	retorno	= jug_Modificaciones(jugador, opcion);
    	    	break;
    	    }
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
		do
		{
			getString(auxNombre,"Ingrese el nombre: ", "Error, ingrese un nombre valido: ", 1, 100);
		}
		 while(esSoloLetas(auxNombre) == 0);

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
		do
		{
		printf("Ingrese la edad\n");
		}
		 while((auxEdad < 16 || auxEdad > 50) && (getEntero(&auxEdad) !=0));

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
			getString(auxPosicion,"Ingrese la posicion del jugador: ", "Error, ingrese una posicion valida: ", 1, 100);

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
		do
		{
			getString(auxNacionalidad,"Ingrese la nacionalidad: ", "Error, ingrese una nacionalidad valida: ", 1, 30);
		}
		 while(esSoloLetas(auxNacionalidad) == 0);

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
	int size;
	int sizeConf;
    int jugadorId;
	int idSeleccion;
	int idSeleccionJug;
    int convocados;
    int indexJugador;
    int indexSeleccion;

    int retornoNumeros;
    Jugador* jugador;
    Seleccion* seleccion;

	if(pArrayListJugador!= NULL && pArrayListSeleccion != NULL)
	{

		controller_listarJugadores(pArrayListJugador);

		do
		{
			printf("Ingrese el id del jugador que quiere convocar: ");
			retornoNumeros= getEntero(&indexJugador);

		}while((indexJugador <= 0 || indexJugador > 5000) && retornoNumeros != 0);

		controller_listarSelecciones(pArrayListSeleccion);

		do
		{
			 printf("Ingrese la seleccion a la que quiere convocar al jugador: ");
			 retornoNumeros= getEntero(&indexSeleccion);

		}while((indexSeleccion  < 0 || indexSeleccion  > 33) && retornoNumeros != 0);

		size=ll_len(pArrayListJugador);
        sizeConf = ll_len(pArrayListSeleccion);

			for(int i = 0; i < size; i++)
			{

				jugador = (Jugador*)ll_get(pArrayListJugador, i);
                jug_getId(jugador, &jugadorId); // ID JUGADOR
                jug_getIdSeleccion(jugador, &idSeleccionJug); // ID DE LA SELECCION JUGADOR

				for(int j= 0; j< sizeConf; j++)
				{
					seleccion = (Seleccion*)ll_get(pArrayListSeleccion, j);
					selec_getId(seleccion, &idSeleccion); // ID SELECCION
					selec_getConvocados(seleccion, &convocados);// CANTIDAD DE CONVOCOADOS POR SELECCION

					  if(jugadorId == indexJugador && idSeleccion == indexSeleccion)
						{
							   if(convocados < 22 && idSeleccionJug == 0)
							   {
								   selec_setConvocados(seleccion, convocados+1);
								   jug_setIdSeleccion(jugador, indexSeleccion);
								   retorno = 1;
							   }
						}
				}

			}
	}

	return retorno;
}
int jug_quitarDeLaSeleccion(LinkedList* pArrayListJugador)
{
	int retorno=0;
	int size;
    int jugadorId;
    int indexJugador;
    int retornoNum;
    Jugador* jugador;

	if(pArrayListJugador!= NULL)
	{

		jug_printJugadoresListados(pArrayListJugador);

		do
		{
			 printf("Ingrese el id del jugador que quiere quitar: \n");
			 retornoNum = getEntero(&indexJugador);

		}while((indexJugador < 0 || indexJugador > 5000) && retornoNum != 0);

		size=ll_len(pArrayListJugador);

			for(int i = 0; i < size; i++)
			{

				jugador = (Jugador*)ll_get(pArrayListJugador, i);
                jug_getId(jugador, &jugadorId);

                 if(jugadorId == indexJugador)
                 {
                	 jug_setIdSeleccion(jugador, 0);
                	 return 1;
                 }

			}
	}

	return retorno;
}
void jug_printJugadoresListados(LinkedList* pArrayListJugador)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
    int size;
    int idSeleccion;
    Jugador* jugador;


	if(pArrayListJugador != NULL)
	{
		size = ll_len(pArrayListJugador);
		for(int i = 0; i < size; i++)
		{
			jugador = (Jugador*)ll_get(pArrayListJugador, i);
				jug_getId(jugador, &id);
				jug_getNombreCompleto(jugador, nombreCompleto);
				jug_getEdad(jugador, &edad);
				jug_getPosicion(jugador, posicion);
				jug_getNacionalidad(jugador, nacionalidad);
				jug_getIdSeleccion(jugador, &idSeleccion);
				if(idSeleccion != 0)
				{
			    	jug_printOne(jugador);
				}
		}
	}
}
