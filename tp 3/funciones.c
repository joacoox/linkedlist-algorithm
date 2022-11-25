#include "funciones.h"

int mostrarMenu(void)
{
	 int opcion;
	 int retorno = -1;

 printf("\n\t\t╔═══════════════════════════════════════╗\n"
		"\t\t║     »»»»» MENU DE OPCIONES «««««      ║\n"
		"\t\t╠═══════════════════════════════════════╣\n"
		"\t\t╠═»»» 1.  CARGA DE ARCHIVOS             ║\n"
		"\t\t╠═»»» 2.  ALTA DE JUGADOR               ║\n"
		"\t\t╠═»»» 3.  MODIFICACIÓN DE JUGADOR       ║\n"
        "\t\t╠═»»» 4.  BAJA DE JUGADOR               ║\n"
	    "\t\t╠═»»» 5.  LISTADOS                      ║\n"
		"\t\t╠═»»» 6.  CONVOCAR JUGADORES            ║\n"
		"\t\t╠═»»» 7.  ORDENAR Y LISTAR              ║\n"
		"\t\t╠═»»» 8.  GENERAR ARCHIVO BINARIO       ║\n"
		"\t\t╠═»»» 9.  CARGAR ARCHIVO BINARIO        ║\n"
		"\t\t╠═»»» 10.  GUARDAR ARCHIVOS .CSV        ║\n"
		"\t\t╠═»»» 11.  SALIR                        ║\n"
		"\t\t╚═══════════════════════════════════════╝\n");
	printf("\n\t\t╔════════════════╗\n"
			"\t\t╠═»»»Su opcion:  ║"
		      "\n\t\t╚════════════════╝\n");

    if(getEntero(&opcion)==0)
    {
    	retorno = opcion;
    }

		return retorno;
}
void comprobarConfirmacion(char mensaje[], char eMensaje[], int retorno){
	if (retorno == 1) {
		printf("%s", mensaje);
	} else {
		printf("%s", eMensaje);
	}
}
void Listados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion){

	int opcion;

    do{
       opcion = subMenuListados();

        switch(opcion){
           case 1:
        	   controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
           break;
           case 2:
        	   controller_listarSelecciones(pArrayListSeleccion);
           break;
           case 3:
        	   jug_ListaJugadoresPorCriterio(pArrayListJugador, pArrayListSeleccion, 2);
           break;
        }


    }
    while(opcion != 4);

}
int subMenuListados(void){

	int retorno;

		do {printf("\n---------------------------\n");
			printf("         Listados      \n");
			printf("---------------------------\n");
			printf(" 1:Todos los jugadores \n 2:Todas las selecciones \n 3:JUGADORES CONVOCADOS \n 4:SALIR\n Su opcion: \n");
            getEntero(&retorno);
		}while((retorno < 1 || retorno > 4));


		return retorno;

}
int subMenuModificaciones(void){

	int retorno;
		do {printf("\n---------------------------\n");
			printf("         Modificaciones      \n");
			printf("---------------------------\n");
			printf(" 1:Nombre \n 2:Edad \n 3:Posicion \n 4:Nacionalidad \n 5:SALIR\n Su opcion: \n");

			getEntero(&retorno);

		}while((retorno < 1 || retorno > 5));

		return retorno;

}
int ListadosOrdenadosPorCriterio(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	int orden;
	int retorno = 0;

	    do{
	       opcion = subMenuOrdenarListar();
	       if(opcion != 5)
	       {
	    	 orden = getNumeroEntreParametro(1, 0, "Ingrese el orden en el que quiere ver los listados\n0:De Manera Descendente\n1:De manera Ascendente\n");
	       }
	        switch(opcion){
	           case 1:
                  ll_sort(pArrayListJugador, jug_CompararPorNacionalidad, orden);
                  controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
	           break;
	           case 2:
	        	   ll_sort(pArrayListSeleccion, selec_CompararPorNombre , orden);
	        	   controller_listarSelecciones(pArrayListSeleccion);
	           break;
	           case 3:
	        	   ll_sort(pArrayListJugador,jug_CompararPorEdad , orden);
	        	   controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
	           break;
	           case 4:
	        	   ll_sort(pArrayListJugador, jug_CompararPorNombre , orden);
	        	   controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
	           break;
	        }
	    }
	    while(opcion != 5);

    return retorno;
}
int subMenuOrdenarListar(void){

	int retorno;

		do {printf("\n---------------------------\n");
			printf("        ORDENAR Y LISTAR      \n");
			printf("---------------------------\n");
			printf(" 1:JUGADORES POR NACIONALIDAD. \n 2:SELECCIONES POR CONFEDERACIÓN. \n 3:JUGADORES POR EDAD. \n 4: JUGADORES POR NOMBRE. \n 5:SALIR\n Su opcion: \n");

			getEntero(&retorno);

		}while((retorno < 1 || retorno > 5));

		return retorno;

}
int subMenuConvocaciones(void)
{
	int retorno;

		do {printf("\n---------------------------\n");
			printf("        CONVOCAR JUGADORES     \n");
			printf("---------------------------\n");
			printf(" 1:CONVOCAR \n 2:QUITAR DE LA SELECCIÓN. \n 3:SALIR\n Su opcion: \n");
            getEntero(&retorno);

		}while((retorno < 1 || retorno > 3));

		return retorno;

}
void Headers(int opcion)
{
	switch(opcion)
	{
	case 1:
		 printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
		 printf("   ID      NOMBRE\t\tEDAD\t\t\tPOSICION\t\tNACIONALIDAD\t       Seleccion \n");
		 printf("------------------------------------------------------------------------------------------------------------------------------\n");
		break;
	case 2:
		printf("\n------------------------------------------------------------------------------------------------------------\n");
		printf("   ID      NOMBRE\t\tCONFEDERACION\t\tCONVOCADOS\n");
	    printf("------------------------------------------------------------------------------------------------------------\n");
	    break;
	}

}
