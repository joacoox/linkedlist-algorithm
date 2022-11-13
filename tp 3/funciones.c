#include "funciones.h"

int mostrarMenu(void)
{
	 int opcion;

	printf("\n\t\t\t\t\tMenu principal\n");
	printf("\t\t\t\t\t--------------\n\n\n");
	printf("\t\t\tOpcion 1: CARGA DE ARCHIVOS.\n");
	printf("\t\t\tOpcion 2: ALTA DE JUGADOR.\n");
	printf("\t\t\tOpcion 3: MODIFICACIÓN DE JUGADOR.\n");
	printf("\t\t\tOpcion 4: BAJA DE JUGADOR.\n");
	printf("\t\t\tOpcion 5: LISTADOS.\n");
	printf("\t\t\tOpcion 6: CONVOCAR JUGADORES.\n");
	printf("\t\t\tOpcion 7: ORDENAR Y LISTAR.\n");
	printf("\t\t\tOpcion 8: GENERAR ARCHIVO BINARIO.\n");
	printf("\t\t\tOpcion 9: CARGAR ARCHIVO BINARIO.\n");
	printf("\t\t\tOpcion 10: GUARDAR ARCHIVOS .CSV.\n");
	printf("\t\t\tOpcion 11: Salir.\n");
	printf("\n\t\tSu opcion: ");
	scanf("%d", &opcion);

		return opcion;
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
        	   controller_listarJugadores(pArrayListJugador);
           break;
           case 2:
        	   controller_listarSelecciones(pArrayListSeleccion);
           break;
           case 3:
        	   jug_printJugadoresListados(pArrayListJugador);
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
			scanf("%d", &retorno);
		}while(retorno < 1 || retorno > 4);

		return retorno;

}
int subMenuModificaciones(void){

	int retorno;

		do {printf("\n---------------------------\n");
			printf("         Modificaciones      \n");
			printf("---------------------------\n");
			printf(" 1:Nombre \n 2:Edad \n 3:Posicion \n 4:Nacionalidad \n 5:SALIR\n Su opcion: \n");
			scanf("%d", &retorno);
		}while(retorno < 1 || retorno > 5);

		return retorno;

}
int ListadosOrdenadosPorCriterio(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int opcion;
	int retorno = 0;

	    do{
	       opcion = subMenuOrdenarListar();

	        switch(opcion){
	           case 1:
                  ll_sort(pArrayListJugador, jug_CompararPorNacionalidad, 1);
                  controller_listarJugadores(pArrayListJugador);
	           break;
	           case 2:
	        	   ll_sort(pArrayListSeleccion, selec_CompararPorNombre , 1);
	        	   controller_listarSelecciones(pArrayListSeleccion);
	           break;
	           case 3:
	        	   ll_sort(pArrayListJugador,jug_CompararPorEdad , 1);
	        	   controller_listarJugadores(pArrayListJugador);
	           break;
	           case 4:
	        	   ll_sort(pArrayListJugador, jug_CompararPorNombre , 1);
	        	   controller_listarJugadores(pArrayListJugador);
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
			scanf("%d", &retorno);
		}while(retorno < 1 || retorno > 5);

		return retorno;

}
int subMenuConvocaciones(void)
{
	int retorno;

		do {printf("\n---------------------------\n");
			printf("        CONVOCAR JUGADORES     \n");
			printf("---------------------------\n");
			printf(" 1:CONVOCAR \n 2:QUITAR DE LA SELECCIÓN. \n 3:SALIR\n Su opcion: \n");
			scanf("%d", &retorno);
		}while(retorno < 1 || retorno > 3);

		return retorno;

}
