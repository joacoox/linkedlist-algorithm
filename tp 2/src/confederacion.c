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
    char auxNombre[DESCRIPTION_SIZE];
    char auxRegion[DESCRIPTION_SIZE];

    for(int i = 0; i<size; i++){

     if(listaConfederacion[i].estado == LIBRE){

    	 listaConfederacion[i].id = confederaciones+1;

    	 do
    	 {

    		getString(auxNombre, "Ingrese el nombre de la confederacion: ",
    	 					"Error, ingrese un nombre valido: ", 0, DESCRIPTION_SIZE);

    	 }while(esSoloLetas(auxNombre) == 0);

         strcpy(listaConfederacion[i].nombre, auxNombre);

    	 fflush(stdin);
    	 do
		 {

			getString(auxRegion, "Ingrese la region de la confederacion: ",
    	    	 					"Error, ingrese una region valida: ", 0, DESCRIPTION_SIZE);

		 }while(esSoloLetas(auxRegion) == 0);

    	 strcpy(listaConfederacion[i].region, auxRegion);

    	 fflush(stdin);

    	 do
		{
			printf("Ingrese el anio de creacion \n");
		}
		 while((auxContrato < 1900 || auxContrato > 2020) || (getEntero(&auxContrato) !=0));

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
    int retornoFuncion;

	   mostrarListadoConfederacion(listaConfederacion, size);

    do
	{
		printf("Ingrese el id a dar de baja: \n");
	}
	 while(index < 0 || (getEntero(&index) !=0));

  retornoFuncion = BuscarConfederacionPorId(listaConfederacion, size, index);

	  if(retornoFuncion == 1)
	  {
	  		for(i =0 ; i < size; i++)
			{
			  if(listaConfederacion[i].id == index)
			  {
				  listaConfederacion[i].estado = LIBRE;
				  retorno = 1;
				  break;
			  }
			}
	  }else{printf("No hay ninguna confederacion con esa id\n");}


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

	do
		{
			printf("Ingrese el codigo que quiere modificar: \n");
		}
		 while(auxId > 0 && (getEntero(&auxId) !=0) && (auxId != ' '));
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
	char auxNombre[DESCRIPTION_SIZE];
	for (int i = 0; i < size; i++) {

			if(lista[i].estado == OCUPADO && lista[i].id == index){

				do
				 {

					getString(auxNombre, "Ingrese el nombre de la confederacion: ",
									"Error, ingrese un nombre valido: ", 0, DESCRIPTION_SIZE);

				 }while(esSoloLetas(auxNombre) == 0);

				 strcpy(lista[i].nombre, auxNombre);
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
	char auxRegion[DESCRIPTION_SIZE];
	for (int i = 0; i < size; i++) {

				if(lista[i].estado == OCUPADO && lista[i].id == index){

					do
				 {

					getString(auxRegion, "Ingrese la region de la confederacion: ",
											"Error, ingrese una region valida: ", 0, DESCRIPTION_SIZE);

				 }while(esSoloLetas(auxRegion) == 0);

				 strcpy(lista[i].region, auxRegion);
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

					 do
					{
						printf("Ingrese el anio de creacion \n");
					}
					 while((auxContrato < 1900 || auxContrato > 2020) || (getEntero(&auxContrato) !=0));

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
	for(int i = 0;  i < sizeConf ; i++ )
	{
		BuscarJugadorPorId(lista, size, listaConfederacion[i].id, listaConfederacion[i]);
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
/*
 * \brief busco una conferencia por id
 * \param lista pido la lista de confederacion
 * \param size el tamanio de las confederaciones
 * \param index el id a buscar
 * \return -1 si no se encuentra 1 si la encontre
 */
int BuscarConfederacionPorId(eConfederacion lista[], int size, int index)
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
 * \brief un litado de conferencia
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaconfederacion lista de confederacion
 *  \param sizeconf tamanio de la confederaciones
 * \return void
 */
void ListarConfederacion(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{

     for (int i = 0; i < sizeConf; ++i)
     {
		printf("%-20s\n",listaConfederacion[i].nombre);
     ListadoConfederacionesConSusJugadores(lista, size, listaConfederacion[i], listaConfederacion[i].id);
	 }
}
