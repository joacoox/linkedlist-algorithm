#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
    int opcionJugadores;
    int opcionConfederacion;

    int costosHospedeje=0;
    int costosComida=0;
    int costosTransporte=0;

    int gastosDeMantenimiento;
    int aumento;
    int precioFinal;

    int arqueros =0;
    int defensores =0;
    int mediocampistas =0;
    int delanteros =0;
    int jugadores = 0;

    float uefa = 0;
    float conmebol = 0;
    float concacaf = 0;
    float afc = 0;
    float ofc = 0;
    float caf = 0;

    int totalConfederaciones;

    int banderaUefa = 0;
    int banderaJugador;
    int bandera = 0;

	do {
		printf("\n1. Ingreso de los costos de Mantenimiento");
		printf("\nCostos de hospedaje -> $%d", costosHospedeje);
		printf("\nCostos de Comida -> $%d", costosComida);
		printf("\nCostos de Transporte -> $%d", costosTransporte);
		printf("\n2. Carga de jugadores");
		printf("\nArqueros -> %d", arqueros);
		printf("\nDefensores -> %d", defensores);
		printf("\nMediocampistas -> %d", mediocampistas);
		printf("\nDelanteros -> %d", delanteros);
		printf("\n3. Realizar todos los calculos");
		printf("\n4. Informar todos los resultados");
		printf("\n5. Salir\nSu opcion: ");

		getEntero(&opcion);

		switch (opcion) {
		case 1:

			do {

				opcion = SubMenuGastos();

				switch (opcion) {
				case 1:
                   costosHospedeje = CalcularGastos("Ingrese los gastos del hospedaje\n Gastos: ");
					break;
				case 2:
					costosComida = CalcularGastos("Ingrese los gastos de la comida\n Gastos: ");
					break;
				case 3:
					costosTransporte = CalcularGastos("Ingrese los gastos del transporte\n Gastos: ");
					break;
				}
			} while (opcion != 4);

			break;

		case 2:

			do {

				opcionJugadores = SubMenuJugadores();
				banderaJugador = 0;
				switch (opcionJugadores)
				{
				case 1:

					if(arqueros < 2)
					{
						IngresoDeCamisetas();
						arqueros++;
						jugadores++;
						banderaJugador = 1;
					}else{printf("No se pueden ingresar mas arqueros\n");}
					break;

				case 2:

					if(defensores < 8)
					{
						IngresoDeCamisetas();
					    defensores++;
					    jugadores++;
					    banderaJugador = 1;
					}else{printf("No se pueden ingresar mas defensores\n");}
					break;

				case 3:

					if(mediocampistas < 8)
					{
						IngresoDeCamisetas();
						mediocampistas++;
						jugadores++;
						banderaJugador = 1;
					}else{printf("No se pueden ingresar mas mediocampistas\n");}
					break;

				case 4:

					if(delanteros < 4)
					{
						IngresoDeCamisetas();
						delanteros++;
						jugadores++;
						banderaJugador = 1;
					}else{printf("No se pueden ingresar mas delanteros\n");}
					break;
				}

				   if(banderaJugador == 1)
				   {
					   opcionConfederacion = SubMenuConfederacion();

					   switch(opcionConfederacion)
						{
						case 1:
						    uefa++;
							break;
						case 2:
							conmebol++;
							break;
						case 3:
							concacaf++;
							break;
						case 4:
							afc++;
							break;
						case 5:
							ofc++;
							break;
						case 6:
							caf++;
							break;
						}
				   }


			} while (opcionJugadores != 5);

			break;

		case 3:
         if(jugadores > 2 && costosTransporte > 0 && costosComida > 0 && costosTransporte > 0)
         {
        	 printf("\tSe realizaron todos los calculos \n");
        	 gastosDeMantenimiento = costosComida + costosHospedeje + costosTransporte;

        	 totalConfederaciones = uefa + conmebol + concacaf + afc + ofc + caf;

        	 if((totalConfederaciones/2) < uefa)
        	 {
        		 aumento = gastosDeMantenimiento * 0.35;
        		 precioFinal = gastosDeMantenimiento + aumento;
        		 banderaUefa = 1;
        	 }
        	 bandera = 1;
         }
         else
         {
        	 printf("Ingrese al menos dos jugadores y todos los costos\n");
         }
			break;

		case 4:
         if(bandera == 1)
         {

        	 printf("Promedio Uefa: %f Porcentaje: %f\n",uefa / totalConfederaciones, (uefa / totalConfederaciones)*100);
        	 printf("Promedio Conmebol: %f Porcentaje: %f\n",conmebol/ totalConfederaciones, (conmebol / totalConfederaciones)*100);
        	 printf("Promedio Concacaf: %f Porcentaje: %f\n",concacaf/ totalConfederaciones, (concacaf / totalConfederaciones)*100);
        	 printf("Promedio Afc: %f Porcentaje: %f\n", afc/ totalConfederaciones, (afc / totalConfederaciones)*100);
        	 printf("Promedio Ofc: %f Porcentaje: %f\n", ofc/ totalConfederaciones, (ofc / totalConfederaciones)*100);
        	 printf("Promedio Caf: %f Porcentaje: %f\n",caf/ totalConfederaciones, (caf / totalConfederaciones)*100);

           if(banderaUefa == 1)
           {
        	   printf("El costo de mantenimiento era de $%d y recibio un aumento de $%d, su nuevo valor es de: $%d \n", gastosDeMantenimiento, aumento, precioFinal);
           }
           else
           {
        	   printf("El costo de mantenimiento es de: $%d \n", gastosDeMantenimiento);
           }
         }
         else
         {
        	 printf("Ingrese a la opcion 3 primero\n");
         }

			break;

		}

	}while (opcion != 5);

	return EXIT_SUCCESS;
}
