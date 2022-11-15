#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "Controller.h"
#include "funciones.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int opcion;
    int retorno;
    int cargaJugadores;
    int cargaSelecciones;
    int cargaBinario;
    int bandera=0;
    int guardaArchivos;

    LinkedList* listaJugadores;
    listaJugadores = ll_newLinkedList();

    LinkedList* listaSelecciones;
    listaSelecciones = ll_newLinkedList();

    LinkedList* listaBinario;
    listaBinario = ll_newLinkedList();

    do{
    	opcion = mostrarMenu();

        switch(opcion)
        {
            case 1:
            cargaJugadores = controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            comprobarConfirmacion("\n\t\t||---------CARGA DE JUGADORES CON EXITO---------|| \n", "Error, no se pudieron cargar los jugadores \n", cargaJugadores);

            cargaSelecciones = controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
            comprobarConfirmacion("\n\t\t||---------CARGA DE SELECCIONES CON EXITO---------|| \n", "Error, no se pudieron cargar las selecciones \n", cargaSelecciones);
            break;
            case 2:
            	if(cargaJugadores == 1 && cargaSelecciones == 1)
            	{
            	 retorno = controller_agregarJugador(listaJugadores, listaSelecciones);
            	 comprobarConfirmacion("Se pudo dar de alta el jugador \n", "Error, no se pudo dar de alta el jugador\n", retorno);
            	}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}

            break;
            case 3:
            	if(cargaJugadores == 1 && cargaSelecciones == 1)
            	{
            		 retorno = controller_editarJugador(listaJugadores);
            	comprobarConfirmacion("Se pudo hacer la modificacion con exito! \n", "Error, no se pudo realizar la modificacion\n", retorno);
            	}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}

            break;
            case 4:
            	if(cargaJugadores == 1 && cargaSelecciones == 1)
            	{
            		retorno = controller_removerJugador(listaJugadores);
            	comprobarConfirmacion("Se pudo dar de baja el jugador \n", "Error, no se pudo dar de baja el jugador\n", retorno);
            	}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}

            break;
			case 5:
				if(cargaJugadores == 1 && cargaSelecciones == 1)
				{
					Listados(listaJugadores, listaSelecciones);
				}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}

			break;
			case 6:
				if(cargaJugadores == 1 && cargaSelecciones == 1)
				{
					controller_convocarJugadores(listaJugadores, listaSelecciones);
				}else
				{
				 printf("Cargue los datos de jugadores y de selecciones primero \n");
				}
			break;
			break;
			case 7:
				if(cargaJugadores == 1 && cargaSelecciones == 1)
				{
					ListadosOrdenadosPorCriterio(listaJugadores, listaSelecciones);
				}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}

			break;
			case 8:
				if(cargaJugadores == 1 && cargaSelecciones == 1)
				{
				cargaBinario = controller_cargarJugadoresDesdeBinario("jugadores.txt" , listaJugadores, listaSelecciones);
				comprobarConfirmacion("Se pudieron cargar los jugadores en binario \n", "Error, no se pudieron cargar los jugadores\n", cargaBinario);
				}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero \n");
            	}
			break;
			break;
			case 9:
				if(cargaJugadores == 1 && cargaSelecciones == 1 && cargaBinario == 1)
				{
				retorno = controller_leerJugadoresDesdeBinario("jugadores.txt", listaBinario);
				comprobarConfirmacion("Se pudieron leer los jugadores en binario \n", "Error, no se pudieron leer los jugadores\n", retorno);
				}else
            	{
            	 printf("Cargue los datos de jugadores y de selecciones primero o Cargue en binario los jugadores antes de queres mostrarlo \n");
            	}
			break;
			case 10:
				if(cargaJugadores == 1 && cargaSelecciones == 1)
				{
			retorno = controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores);
			comprobarConfirmacion("\n\t\t||---------GUARDAR JUGADORES CON EXITO---------|| \n", "Error, no se pudieron guardar las selecciones \n", retorno);
			guardaArchivos+= retorno;
			retorno	= controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
				 comprobarConfirmacion("\n\t\t||---------GUARDAR SELECCIONES CON EXITO---------|| \n", "Error, no se pudieron guardar las selecciones \n", retorno);
			guardaArchivos+= retorno;
				}else
					{
					 printf("Cargue los datos de jugadores y de selecciones primero \n");
					}
			break;
			case 11:
				if(guardaArchivos == 2)
				{
					getEntero(&bandera);
				}
				else
				{
					printf("Guarde los archivos en la opcion 10 para salir del programa \n");
				}
			break;

        }
    }while(bandera != 1);

    return 0;
}

