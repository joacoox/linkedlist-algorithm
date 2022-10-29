#include "funciones.h"
/**
 * \brief Muestra el menu al usuario, y solicita una opcion
 * \param void
 * \return la opcion elegida por el usuario
 */
int MostrarMenu(void)
{
    int opcion;
	printf("\n\t\t\t\t\tMenu principal\n");
	printf("\t\t\t\t\t--------------\n\n\n");
	printf("\t\t\tOpcion 1: Alta de Jugador.\n");
	printf("\t\t\tOpcion 2: Baja de Jugador.\n");
	printf("\t\t\tOpcion 3: Modificacion de Jugador.\n");
	printf("\t\t\tOpcion 4: Informes.\n");
	printf("\t\t\tOpcion 5: Salir.\n");
	printf("\n\t\tSu opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
/**
 * \brief compruebo la confirmacion
 * \param mensaje Es el mensaje a ser mostrado si salio bien
 * \param eMensaje el mensaje a ser mostrado si no salio bien
 * \param retorno si el retorno es 1 muestro el mensaje y si no el eMensaje
 * \return void
 */
void comprobarConfirmacion(char mensaje[], char eMensaje[], int retorno)
{
	if (retorno == 1) {
		printf("%s", mensaje);
	} else {
		printf("%s", eMensaje);
	}
}/**
 * \brief muestro una lista de las confederaciones
 * \param Lista[] lista de las confederaciones
 * \param size el tamanio de las confederaciones
 * \return void
 */

void mostrarListadoConfederacion(eConfederacion lista[], int size)
{
	Headers(2);
	for(int i = 0; i<size;i++){
		printf("|%3d| |   %-10s         |  |%-25s|\t\t| %-10d |\n",lista[i].id, lista[i].nombre, lista[i].region, lista[i].anioCreacion);
	}
}
/**
 * \brief modifico una caracteristica del jugador
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion la lista de las confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void ModificarJugador(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{
	int opcion;
	int auxId;

		 Headers(1);
	ListadoDeConfederaciones(listaConfederacion,  sizeConf, lista, size);
	auxId = getInt("Ingrese el codigo que quiere modificar: ", "Error, ingrese un codigo valido", 1, 1000);

	do{
		opcion = subMenuJugadores();
		switch(opcion){
		case 1:
			ModificarNombre(lista, size, auxId);
		break;
		case 2:
			ModificarPosicion(lista, size, auxId);
		break;
		case 3:
			ModificarNumCamiseta(lista, size, auxId);
		break;
		case 4:
			ModificarConfederacion(lista, size, auxId,listaConfederacion, sizeConf);
		break;
		case 5:
			ModificarSueldo(lista, size, auxId);
		break;
		case 6:
			ModificarAniosContrato(lista, size, auxId);
		break;
		case 7:
			printf("volviendo al menu \n");
		break;
		}
	}
	while(opcion != 7);

}
/**
 * \brief muestro un submenu de jugadores
 * \param void
 * \return un entero validado
 */
int subMenuJugadores(){

	int retorno;

	do{
		printf("\n         Modificaciones        \n");
		printf("---------------------------\n");
		printf(
				"1- Nombre y apellido \n 2- Posicion \n 3- Numero de camiseta \n 4- Confederacion \n 5- Salario \n 6- Duracion del contrato\n7-Salir\n Su opcion:");
		scanf("%d", &retorno);
	}while(retorno < 1 || retorno > 7);

	return retorno;
}
/*
 * \brief un bucle del menu con los informes
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion la lista de las confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void Informes(eJugador lista[], int size, eConfederacion listaConf[], int sizeConf){

	int opcion;
	eConfederacion confederacion;

    do{
       opcion = subMenuInformes();

        switch(opcion){
           case 1:
        	   Headers(1);
        	   OrdenamientoPorNombreDeConfederacion(listaConf,  sizeConf);
        	   OrdenamientoDeJugadorAlfabeticamente(lista, size);
        	   ListadoDeConfederaciones(listaConf,  sizeConf, lista, size);
           break;
           case 2:
        	   Headers(4);
        	   ListadoConfederaciones(lista,size, listaConf, sizeConf);
           break;
           case 3:
        	   JugadoresCobranMasQuePromedio(lista, size);
           break;
           case 4:
        	   ConfederacionConMayorDuracionContratos(lista,size, listaConf, sizeConf);
           break;
           case 5:
        	   PorcentajeDeJugadoresPorConfederacion(lista,size ,listaConf, sizeConf);
           break;
           case 6:
        	 confederacion = ConfederacionConMasJugadores(lista,size ,listaConf, sizeConf);
        	 ListadoConfederacionesConSusJugadores(lista, size, confederacion, confederacion.id);
           break;
        }


    }
    while(opcion != 7);

}
/*
 * \brief un submenu de los informes
 * \param void
 * \return un entero validado
 */
int subMenuInformes(void){

	int retorno;

		do {printf("\n---------------------------\n");
			printf("         Informes        \n");
			printf("---------------------------\n");
			printf(" 1 Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador\n 2 Listado de confederaciones con sus jugadores \n 3 Total y promedio de todos los salarios\n 4 Informar la confederación con mayor cantidad de años de contratos total.");
			printf("\n 5 Informar porcentaje de jugadores por cada confederación.  \n 6 Informar cual es la región con más jugadores y el listado de los mismos.\n 7 SALIR\n Su opcion:");
			scanf("%d", &retorno);
		}while(retorno < 1 || retorno > 7);

		return retorno;

}
/*
 * \brief un header para mejorar la presentacion
 * \param opcion selecciono el header que quiero mostrar
 * \return void
 */
void Headers(int opcion)
{
	switch(opcion){
	case 1:
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf("|ID|        |Nombre|\t         |Posicion|       |Nº Camiseta|  |Sueldo|  |Confederacion|  |Años de contrato|");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	break;
	case 2:
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf("|ID|      |Nombre|\t             |Region|                          |Años Creacion|");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	break;
	case 3:
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t|Nombre|\t\t\t|Porcentaje|");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	break;
	case 4:
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	printf("|CONFEDERACION|\t\t\t|JUGADOR|");
	printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	break;
	}
}
/*
 * \brief muestro un jugador
 * \param lista pido la lista de jugadores en la posicion que necesito
 * \param listaConfederacion la lista de las confederaciones en la posicion que necesito
 * \opcion elijo que mostrar
 * \return void
 */
void MostrarUnJugador(eJugador lista, eConfederacion listaConfederacion, int opcion)
{
	switch(opcion){
	case 1:
  printf("|%3d| |   %-10s         |  |%-15s| |%-10d| |%-10.f| |%10s| |%15d\t|\n", lista.id, lista.nombre, lista.posicion, lista.numeroCamiseta, lista.salario, listaConfederacion.nombre, lista.anioscontrato);
	break;
	case 2:
  printf("|   %-10s         |  |   %-10s         |\n",listaConfederacion.nombre, lista.nombre);
	break;
	}
}
/*
 * \brief muestro un jugador con sueldo mayor al promedio
 * \param promedio el promedio del salario
 * \param contador la cantidad de jugadores que cobran mas que el promedio
 * \return void
 */
void MostrarJugadoresSueldoMayorPromedio(int promedio, int contador){

	printf("El promedio de todos los salarios es de: %d y la cantidad de jugadores que cobra mas que el promedio es : %d\n", promedio,contador);
}
/*
 * \brief submenu de las confederaciones
 * \param void
 * \return un entero validado
 */
int subMenuConfederaciones(){

	int retorno;

	do{
		printf("\n         Modificaciones        \n");
		printf("---------------------------\n");
		printf(
				"1- Nombre\n 2- Region \n 3- Anio de creacion \n 4- Salir\n Su opcion:");
		scanf("%d", &retorno);
	}while(retorno < 1 || retorno > 7);

	return retorno;
}
/*
 * \brief muestro mensajes de error o de exito
 * \param opcion la opcion para mostrar lo que quieras
 * \return void
 */
void Error(int opcion)
{
	switch(opcion){
	case 1:
		printf("\n\t\t\tERROR 404\n");
        printf("no hay jugadores cargados, si quiere usar la funcion ingrese un jugador primero\n");
    break;
	case 2:
		printf(" Se pudo hacer la modificacion\n");
	break;
	case 3:
		printf("\n\t\t\tERROR 404\n");
		printf(" No se pudo hacer la modificacion, pruebe ingresando otra id \n");
	break;
	}

}
/*
 * \brief imprimo una confederacion y una variable
 * \param listaConfederacion la lista de las confederaciones en la posicion que necesito
 * \param variable una variable de tipo numerico
 * \param opcion elijo cual mostrar
 * \return void
 */
void ImprimirUnaConfederacionConUnaVariable(eConfederacion lista, float variable, int opcion){

	switch(opcion){
	case 1:
		 printf("La confederacion con mas anios de contrato es %s anios = %.0f \n", lista.nombre, variable);
	break;
	case 2:
		printf("\t%s \t\t\t  %-5.2f\n", lista.nombre, variable);
	break;
	case 3:
		 printf("La region con mas jugadores es %s con  %.0f jugadores \n", lista.region, variable);
	break;

	}


}
