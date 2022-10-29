#include "confederacion.h"
/*
 * \brief doy de alta una confederacion
 * \param listaConfederacion pido la lista de confederacion
 * \param size el tamanio de las confederaciones
 * \param confederaciones la cantidad de confederaciones
 * \return -1 si no se dio de alta 1 si se dio de alta
 */
int altaConfederacion(eConfederacion listaConfederacion[], int size, int confederaciones)
{
	int retorno = -1;
    int auxContrato;

    for(int i = 0; i<size; i++){

     if(listaConfederacion[i].estado == LIBRE){

    	 listaConfederacion[i].id = confederaciones+1;

    	 getString(listaConfederacion[i].nombre, "Ingrese el nombre de la confederacion: ",
    	 					"Error, ingrese un nombre valido: ", 4, DESCRIPTION_SIZE);

    	 fflush(stdin);

    	 getString(listaConfederacion[i].region, "Ingrese la region de la confederacion: ",
    	    	 					"Error, ingrese una region valida: ", 4, DESCRIPTION_SIZE);

    	 fflush(stdin);


    	 auxContrato =  getInt("Ingrese el anio de creacion: ", "Error, anio invalido: ",
    	     	 								1900, 2000);
    	 listaConfederacion[i].anioCreacion = auxContrato;

    	 listaConfederacion[i].estado = OCUPADO;

    	 retorno = 1;
    	 break;
     }
    }

return retorno;
}
/*
 * \brief doy de baja una confederacion
 * \param listaConfederacion pido la lista de confederacion
 * \param size el tamanio de las confederaciones
 * \return -1 si no se dio de alta 1 si se dio de alta
 */
int BajaConfederacion(eConfederacion listaConfederacion[], int size)
{
	int i;
	int retorno = -1;
	int index;
   if(listaConfederacion[0].estado == OCUPADO){

	   mostrarListadoConfederacion(listaConfederacion, size);

    index = getInt("\n Ingrese el id a dar de baja: ","\n Error el id ingresado supera los limites: ",0,1000);

    for(i =0 ; i < size; i++)
        {
          if(listaConfederacion[i].id == index)
          {
        	  listaConfederacion[i].estado = LIBRE;
              retorno = 1;
              break;
          }
        }
   }
    return retorno;
}
/**
 * \brief modifico una caracteristica de la confederacion
 * \param lista pido la lista de las confederaciones
 * \param size el tamanio de las confederaciones
 * \return void
 */
void ModificarConfederaciones(eConfederacion lista[], int size)
{
	int opcion;
	int auxId;
	 if(lista[0].estado == OCUPADO){

		  mostrarListadoConfederacion(lista, size);

	auxId = getInt("Ingrese el codigo que quiere modificar: ", "Error, ingrese un codigo valido", 1, 1000);

	do{
		opcion = subMenuConfederaciones();
		switch(opcion){
		case 1:
			ModificarNombreConfederacion(lista, size, auxId);
		break;
		case 2:
			ModificarRegionConfederacion(lista, size, auxId);
		break;
		case 3:
			ModificarAnioDeCreacionConfederacion(lista, size, auxId);
		break;
		case 4:
			printf("volviendo al menu \n");
		break;
		}
	}
	while(opcion != 4);
	 }
}
/*
 * \brief modifico una caracteristica de la confederacion elegida
 * \param lista pido la lista de confederaciones
 * \param size el tamanio de las confederaciones
 * \param index la id de la confederacion a ser modificada
 * \return void
 */
void ModificarNombreConfederacion(eConfederacion lista[], int size, int index)
{
	for (int i = 0; i < size; i++) {

			if(lista[i].estado == OCUPADO && lista[i].id == index){

				 getString(lista[i].nombre, "Ingrese el nombre de la confederacion: ",
				    	 					"Error, ingrese un nombre valido: ", 4, DESCRIPTION_SIZE);

		    	 fflush(stdin);
				      break;
			}
		}
}
/*
 * \brief modifico una caracteristica de la confederacion elegida
 * \param lista pido la lista de confederaciones
 * \param size el tamanio de las confederaciones
 * \param index la id de la confederacion a ser modificada
 * \return void
 */
void ModificarRegionConfederacion(eConfederacion lista[], int size, int index)
{
	for (int i = 0; i < size; i++) {

				if(lista[i].estado == OCUPADO && lista[i].id == index){

			getString(lista[i].region, "Ingrese la region de la confederacion: ",
					    	    	 		"Error, ingrese una region valida: ", 4, DESCRIPTION_SIZE);
					      break;
				}
			}
}
/*
 * \brief modifico una caracteristica de la confederacion elegida
 * \param lista pido la lista de confederaciones
 * \param size el tamanio de las confederaciones
 * \param index la id de la confederacion a ser modificada
 * \return void
 */
void ModificarAnioDeCreacionConfederacion(eConfederacion lista[], int size, int index)
{
	int auxContrato;
	for (int i = 0; i < size; i++) {

				if(lista[i].estado == OCUPADO && lista[i].id == index){

					 auxContrato =  getInt("Ingrese el anio de creacion: ", "Error, anio invalido: ",
					    	     	 								1900, 2000);
					    	 lista[i].anioCreacion = auxContrato;
					      break;
				}
			}
}
/*
 * \brief ordenero por metodo de burbujeo alfabeticamente a las confederaciones
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void OrdenamientoPorNombreDeConfederacion(eConfederacion listaConfederacion[], int sizeConf)
{
	eConfederacion aux;

       for(int i = 0; i<sizeConf-1; i++){

    	   for(int j = i+1; j<sizeConf;j++){

    		   if(strcmp(listaConfederacion[i].nombre, listaConfederacion[j].nombre )>0){

    			   aux = listaConfederacion[i];
    			   listaConfederacion[i] = listaConfederacion[j];
    			   listaConfederacion[j] = aux;
    		   }
    	   }
       }
}
/*
 * \brief itero en las confederaciones
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \return void
 */
void ListadoDeConfederaciones(eConfederacion listaConfederacion[], int sizeConf, eJugador lista[], int size)
{

	for(int i =0; i<sizeConf; i++ ){
		BuscarJugadorPorId(lista, size, listaConfederacion[i].id, listaConfederacion[i]);
	}

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
	for(int i=0;i<size;i++)
	    {
	        if(lista[i].estado == OCUPADO && lista[i].idConfederacion == index)
	        {
	        	MostrarUnJugador(lista[i], listaConfederacion,1);
	        }
	    }
}
/*
 * \brief itero en las confederaciones
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void  ListadoConfederaciones(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{
	for (int i = 0; i < sizeConf; ++i)
	{
		ListadoConfederacionesConSusJugadores(lista, size, listaConfederacion[i], listaConfederacion[i].id);
	}

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
void ListadoConfederacionesConSusJugadores(eJugador lista[], int size, eConfederacion listaConfederacion, int index)
{
	for (int j = 0; j < size; ++j) {

			if(lista[j].estado == OCUPADO && lista[j].idConfederacion == index)
			{
				MostrarUnJugador(lista[j], listaConfederacion, 2);
			}
	}

}
