#include "input.h"
#include "jugador.h"
#include "confederacion.h"

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int id=0;
	int altaConfirmada;
	int bajaConfirmada;
	int bandera = 0;

	eConfederacion listaConfederacion[TAMCONF]={{100,"CONMEBOL", "SUDAMERICA",1916,OCUPADO},
	                                            {101,"UEFA", "EUROPA",1954,OCUPADO},
	                                            {102,"AFC", "ASIA",1954,OCUPADO},
	                                            {103,"CAF", "AFRICA",1957, OCUPADO},
	                                            {104,"CONCACAF", "NORTE Y CENTRO AMERICA",1961,OCUPADO},
	                                            {105,"OFC", "OCEANIA",1966,OCUPADO}};

	int jugadores=0; // cantidad de jugadores si es = 0 hay que dar de alta para que se pueda usar el programa
	// si se hardcodea la lista hay que sumar los jugadores a esta variable de control

	 eJugador listaJugador[TAMJUGADOR];


	inicializarJugadores(listaJugador, TAMJUGADOR); // si se va a hardcodear esta funcion te inicializa todos lo espacios en libre

	   do{
		        opcion = MostrarMenu();

		        switch(opcion){

		           case 1:
		        	   altaConfirmada = altaJugador(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF, id);
		        	   comprobarConfirmacion("Se dio de alta con exito el jugador",
		        	   					"Error, No se pudo dar de alta el jugador, puede ser que este lleno de jugadores",
		        	   					altaConfirmada);
		        	   if(altaConfirmada == 1){
		        		   jugadores= jugadores +1;
		        		   id = id+1;
		        	   }
		           break;
		           case 2:
		        	   if(jugadores>0){
		        	 bajaConfirmada = BajaJugador(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF);
		        	 comprobarConfirmacion("Se dio de baja con exito el jugador",
		        	 		        	   					"Error, No se pudo dar de baja el jugador",
		        	 		        	   					bajaConfirmada);
		        	   }else{Error(1);}

		        	   if(bajaConfirmada == 1){
		        	  	jugadores= jugadores -1;
		        	   }
		           break;
		           case 3:
		        	   if(jugadores>0){
		        	   ModificarJugador(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF);
		        	   }else{Error(1);}
		           break;
		           case 4:
		        	   if(jugadores>0){
		        	  Informes(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF);
		        	   }else{Error(1);}
		           break;
		           case 5:
		        	   printf("Esta seguro de que quiere salir del programa? \n0-No\n1-Si\n Su opcion:");
		        	  getEntero(&bandera);
		           break;
		        }
		    }
		    while(bandera != 1);

	   printf("\n\t\tADIOS VUELVA PRONTOS");
	return EXIT_SUCCESS;
}
