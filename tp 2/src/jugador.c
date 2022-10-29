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
   short auxCamiseta;
   int auxConfederacion;
   float auxSueldo;
   short auxContrato;

    for(int i = 0; i<size; i++){

     if(lista[i].estado == LIBRE){

    	 lista[i].id = jugadores + 1;

    	 getString(lista[i].nombre, "Ingrese el nombre y apellido: ",
    	 					"Error, ingrese un nombre valido: ", 3, DESCRIPTION_SIZE);

    	 fflush(stdin);

    	 getPosicion(lista[i].posicion);

    	 fflush(stdin);

    	 auxCamiseta =  getInt("Ingrese el nº de camiseta del jugador: ", "Error, ingrese un nº valido: ",
    	     	 								0, 100);
    	 lista[i].numeroCamiseta = auxCamiseta;

    	mostrarListadoConfederacion(listaConfederacion, sizeConf);

         auxConfederacion = getInt("Ingrese el id de la confederacion del jugador: ", "Error, ingrese un id valido: ",
					100, 99+TAMCONF);
    	 lista[i].idConfederacion = auxConfederacion;

    	auxSueldo = getFloat("Ingrese el valor mensual del contrato: ",
    						"Error, ingrese numero valido: ", 0, 999999);

    	lista[i].salario = auxSueldo;

    	auxContrato =  getInt("Ingrese la duracion del contrato en anios: ", "Error, ingrese un anio valido: ",
    	    	 								0, 30);
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

	   Headers(1);
	   ListadoDeConfederaciones(listaConfederacion,  sizeConf, lista, size);

    index = getInt("\n Ingrese el id a dar de baja: ","\n Error el id ingresado supera los limites: ",0,1000);

    for(i =0 ; i < size; i++)
        {
          if(lista[i].id == index)
          {
              lista[i].estado = LIBRE;
              retorno = 1;
              break;
          }
        }

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
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

	    	 getString(lista[i].nombre, "Ingrese el nombre y apellido: ",
	    	 					"Error, ingrese un nombre valido: ", 3, DESCRIPTION_SIZE);
	    	 fflush(stdin);
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
void ModificarPosicion(eJugador lista[], int size, int index)
{
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			getPosicion(lista[i].posicion);
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
void ModificarNumCamiseta(eJugador lista[], int size, int index)
{
	short auxCamiseta;
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			auxCamiseta =  getInt("Ingrese el nº de camiseta del jugador: ", "Error, ingrese un nº valido: ",
			    	     	 								0, 100);
			lista[i].numeroCamiseta = auxCamiseta;
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
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

		mostrarListadoConfederacion(listaConfederacion, sizeConf);

		auxConfederacion = getInt("Ingrese el id de la confederacion del jugador: ", "Error, ingrese un id valido: ",
							100, 99+TAMCONF);
	    lista[i].idConfederacion = auxConfederacion;
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
void ModificarAniosContrato(eJugador lista[], int size, int index)
{
	short auxContrato;
	for (int i = 0; i < size; i++) {

		if(lista[i].estado == OCUPADO && lista[i].id == index){

			auxContrato =  getInt("Ingrese la duracion del contrato ", "Error, ingrese un anio valido: ",
			    	    	 								0, 30);
			lista[i].anioscontrato = auxContrato;
			Error(2);
			      break;
		}else{Error(3);}
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
