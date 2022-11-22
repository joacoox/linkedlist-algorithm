#include "jugador.h"
/*
 * \brief inicializo a los jugadores en estado libre
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \return void
 */
void inicializarJugadores(eJugador lista[], int size){

	for (int i = 0; i < size; i++) {
		lista[i].estado = LIBRE;
	}
}
/*
 * \brief doy de alta un jugador
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion la lista de las confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \param jugadores la cantidad de jugadores
 * \return 1 si se dio de alta -1 si no
 */
int altaJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf, int jugadores){

   int retorno = -1;
   int auxCamiseta;
   int auxConfederacion;
   int auxSueldo;
   int auxContrato;
   int retornoFuncion;
   char auxNombre[DESCRIPTION_SIZE];

    for(int i = 0; i<size; i++){

     if(lista[i].estado == LIBRE){

    	 lista[i].id = jugadores + 1;

    	do{ getString(auxNombre, "Ingrese el nombre y apellido: ",
    	 					"Error, ingrese un nombre valido: ", 3, DESCRIPTION_SIZE);

    	  }while(esSoloLetas(auxNombre) == 0);

    	strcpy(lista[i].nombre, auxNombre);

    	 fflush(stdin);

    	 getPosicion(lista[i].posicion);

    	 fflush(stdin);

			do{
				printf("Ingrese el numero de camiseta: \n");
			retornoFuncion = getEntero(&auxCamiseta);

			}while((auxCamiseta < 0 || auxCamiseta > 100) || retornoFuncion == 1);

           lista[i].numeroCamiseta = auxCamiseta;

    	mostrarListadoConfederacion(listaConfederacion, sizeConf);

    	do
		{
			printf("Ingrese la id de la confederacion en la que su jugador juega: \n");
			retornoFuncion = getEntero(&auxConfederacion);
		}
		 while(retornoFuncion != 0 || (BuscarConfederacionPorId(listaConfederacion, sizeConf, auxConfederacion) != 1));

         lista[i].idConfederacion = auxConfederacion;

         do
		{
			printf("Ingrese el valor mensual del contrato: \n");
			retornoFuncion = getEntero(&auxSueldo);
		}
		 while(auxSueldo < 0 ||  retornoFuncion !=0);

    	lista[i].salario = auxSueldo;

    	do
		{
			printf("Ingrese la duracion del contrato en anios: \n");
			retornoFuncion = getEntero(&auxContrato);
		}
		 while((auxContrato < 0 || auxContrato > 20) || retornoFuncion !=0);

    	 lista[i].anioscontrato = auxContrato;

    	 lista[i].estado = OCUPADO;

    	 retorno = 1;
    	 break;

     }
    }

return retorno;
}
/*
 * \brief doy de baja un jugador
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion la lista de las confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return 1 si se dio de baja -1 si no se dio de baja
 */
int BajaJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{
	int i;
	int retorno = -1;
	int index;
	int retornoFuncion;

	   Headers(1);
	   ListadoDeConfederaciones(listaConfederacion,  sizeConf, lista, size);

   do
	{
		printf("Ingrese el id a dar de baja: \n");
	}
	 while(index < 0 || (getEntero(&index) !=0));

	   retornoFuncion  = BuscarIdValido(lista, size, index);

      if(retornoFuncion == 1)
      {

		   for(i =0 ; i < size; i++)
			{

				  if(lista[i].id == index)
				  {
					  lista[i].estado = LIBRE;
					  retorno = 1;
					  break;
				  }

			}
      }else{printf("No hay un jugador con esa id\n");}


    return retorno;
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarNombre(eJugador lista[], int size, int index)
{
	char auxNombre[DESCRIPTION_SIZE];
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			do{ getString(auxNombre, "Ingrese el nombre y apellido: ",
			    	 					"Error, ingrese un nombre valido: ", 3, DESCRIPTION_SIZE);

			    	  }while(esSoloLetas(auxNombre) == 0);

			    	strcpy(lista[i].nombre, auxNombre);
	    	 Error(2);
			      break;
		}
	}
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarPosicion(eJugador lista[], int size, int index)
{
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			getPosicion(lista[i].posicion);
			Error(2);
		break;
		}
	}
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarNumCamiseta(eJugador lista[], int size, int index)
{
	int auxCamiseta;
	int retornoFuncion;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			do{
				printf("Ingrese el numero de camiseta: \n");
			retornoFuncion = getEntero(&auxCamiseta);

			}while((auxCamiseta < 0 || auxCamiseta > 100) || retornoFuncion == 1);

		   lista[i].numeroCamiseta = auxCamiseta;
			   Error(2);
			      break;
		}
	}
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarSueldo(eJugador lista[], int size, int index)
{
	float auxSueldo;
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

		auxSueldo = getFloat("Ingrese el valor mensual del contrato: ",
			    						"Error, ingrese numero valido: ", 0, 999999);
	    lista[i].salario = auxSueldo;
	    Error(2);
		 break;
		}else{Error(3);}
	}
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarConfederacion(eJugador lista[], int size, int index,eConfederacion listaConfederacion[], int sizeConf)
{
	int auxConfederacion;
	int retornoFuncion;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

		do
		{
			printf("Ingrese la id de la confederacion en la que su jugador juega: \n");
			retornoFuncion = getEntero(&auxConfederacion);
		}
		 while(retornoFuncion != 0 || (BuscarConfederacionPorId(listaConfederacion, sizeConf, auxConfederacion) != 1));

		 lista[i].idConfederacion = auxConfederacion;

	    Error(2);

		 break;
		}
	}
}
/*
 * \brief modifico una caracteristica del jugador elegido
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index la id del jugador a ser modificado
 * \return void
 */
void ModificarAniosContrato(eJugador lista[], int size, int index)
{
	int auxContrato;
	int retornoFuncion;

	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			do
			{
				printf("Ingrese la duracion del contrato en anios: \n");
				retornoFuncion = getEntero(&auxContrato);
			}
			 while((auxContrato < 0 || auxContrato > 20) || retornoFuncion !=0);

			 lista[i].anioscontrato = auxContrato;

			Error(2);
			break;
		}
	}
}
/*
 * \brief ordenero por metodo de burbujeo alfabeticamente a los jugadores
 * \param listaConfederacion pido la lista de jugadores
 * \param sizeConf el tamanio de los jugadores
 * \return void
 */
void OrdenamientoDeJugadorAlfabeticamente(eJugador lista[], int size)
{
	eJugador aux;

       for(int i = 0; i< size-1; i++){

    	   for(int j = i+1; j< size; j++){

    		   if(strcmp(lista[i].nombre, lista[j].nombre )>0){

    			   aux = lista[i];
    			   lista[i] = lista[j];
    			   lista[j] = aux;
    		   }
    	   }
       }
}
/*
 * \brief paso a minusculas lo que el usuario ingrese y valido el tamanio del texto
 * \param cadena la cadena de caracteres a modificar
 * \return void
 */
void getPosicion(char cadena[])
{
	char posicion[DESCRIPTION_SIZE];

do{
	getString(posicion, "Ingrese la posicion\n arquero, defensor, mediocampista o delantero\n su opcion: ",
	    	 					"Error, ingrese una posicion valida: ", 7, 14);

	for(int i =0; posicion[i]!= '\0'; i++){
		posicion[i] = tolower(posicion[i]);
	}

}while(strcmp(posicion,"mediocampista") != 0 && strcmp(posicion,"arquero") != 0 &&strcmp(posicion,"defensor") != 0 &&strcmp(posicion,"delantero") != 0);


	strcpy(cadena, posicion);
}
/*
 * \brief busco un jugador por id
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param index el id a buscar
 * \return -1 si no se encuentra 1 si la encontre
 */
int BuscarIdValido(eJugador lista[], int size, int index)
{
	int retorno = -1;

	for (int i = 0; i < size; ++i)
	{
		if(lista[i].id == index)
		{
			retorno = 1;
		}

	}

  return retorno;
}
/*
 * \brief busco a un jugador por id
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \index la id de la confederacion
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void BuscarJugadorPorId(eJugador lista[], int size, int index, eConfederacion listaConfederacion)
{
	for(int i=0 ; i < size ; i++)
	    {
	        if(lista[i].estado == OCUPADO && lista[i].idConfederacion == index)
	        {
	        	MostrarUnJugador(lista[i], listaConfederacion,1);
	        }
	    }
}
