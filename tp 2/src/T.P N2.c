#include "input.h"

int main(void) {

	setbuf(stdout, NULL);
	int opcion;
	int jugadores=0;
	int altaConfirmada;
	int bajaConfirmada;
	int bandera = 0;

	eConfederacion listaConfederacion[TAMCONF]={{100,"CONMEBOL", "SUDAMERICA",1916,OCUPADO},
	                                            {101,"UEFA", "EUROPA",1954,OCUPADO},
	                                            {102,"AFC", "ASIA",1954,OCUPADO},
	                                            {103,"CAF", "AFRICA",1957, OCUPADO},
	                                            {104,"CONCACAF", "NORTE Y CENTRO AMERICA",1961,OCUPADO},
	                                            {105,"OFC", "OCEANIA",1966,OCUPADO}};

	eJugador listaJugador[TAMJUGADOR];

	inicializarJugadores(listaJugador, TAMJUGADOR);

	   do{
		        opcion = MostrarMenu();

		        switch(opcion){

		           case 1:
		        	   altaConfirmada = altaJugador(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF, jugadores);
		        	   comprobarConfirmacion("Se dio de alta con exito el jugador",
		        	   					"Error, No se pudo dar de alta el jugador, puede ser que este lleno de jugadores",
		        	   					altaConfirmada);
		        	   if(altaConfirmada == 1){
		        		   jugadores= jugadores +1;
		        	   }
		           break;
		           case 2:
		        	   if(jugadores>0){
		        	 bajaConfirmada = BajaJugador(listaJugador, TAMJUGADOR, listaConfederacion, TAMCONF);
		        	 comprobarConfirmacion("Se dio de baja con exito el jugador",
		        	 		        	   					"Error, No se pudo dar de baja el jugador",
		        	 		        	   					bajaConfirmada);
		        	   }else{Error(1);}
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
		        	   bandera = getInt("Esta seguro que quiere salir del programa?\n0-No\n1-Si\n Su opcion: ", "Error, ingrese un nº valido: ",
 								0, 1);
		           break;
		        }
		    }
		    while(bandera != 1);

	return EXIT_SUCCESS;
}
