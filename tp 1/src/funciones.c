#include "funciones.h"

/**
 * \brief Sub menu sobre los gastos
 * \param void
 * \return la opcion que elija el usuario validada
 */
int SubMenuGastos(void)
{

    int retorno;
	int retornoNumero;

	do{
		printf("\n         Gastos     \n");
		printf("---------------------------\n");
		printf(
				"1- Costo de hospedaje \n2- Costo de comida \n3- Costo de transporte \n4-Salir\n Su opcion:");
		  retornoNumero  = getEntero(&retorno);
		}while((retorno < 1 || retorno > 4) || (retornoNumero !=0));

	return retorno;

}
/**
 * \brief Calculo los gastos
 * \param mensaje Es el mensaje a ser mostrado
 * \return el numero que ingreso el usuario validado
 */
int CalcularGastos(char mensaje[])
{
	int gastos;
    int retornoNumero;

   do
   {
	printf("%s",mensaje);
    retornoNumero  = getEntero(&gastos);
   }
   while(gastos < 0 || retornoNumero != 0);


   return gastos;
}
/**
 * \brief Sub menu sobre los jugadores
 * \param void
 * \return la opcion que elija el usuario validada
 */
int SubMenuJugadores(void)
{

    int retorno;
	int retornoNumero;

	do{
		printf("\n         Carga de Jugadores     \n");
		printf("----------------------------------\n");
		printf(
				"1- Carga de Arqueros \n2- Carga de Defensores \n3- Carga de Mediocampistas \n4- Carga de Delanteros\n5-Salir\n Su opcion: \n");
		  retornoNumero  = getEntero(&retorno);
		}while((retorno < 1 || retorno > 5) || (retornoNumero !=0));

	return retorno;

}
/**
 * \brief Para que el usuario ingrese la camiseta del jugador
 * \param void
 * \return el numero que ingreso el usuario validado
 */
int IngresoDeCamisetas()
{
	int retornoFuncion;
	int camiseta;
	   do
	   {
		printf("Ingrese el numero de camiseta: ");
		retornoFuncion  = getEntero(&camiseta);
	   }
	   while((camiseta < 0 || camiseta > 100 ) || retornoFuncion != 0);


	return 1;
}
/**
 * \brief Sub menu sobre las confederaciones
 * \param void
 * \return la opcion que elija el usuario validada
 */
int SubMenuConfederacion(void)
{

    int retorno;
	int retornoNumero;

	do{
		printf("\n        Confederaciones    \n");
		printf("----------------------------------\n");
		printf("Elija una confederacion\n"
				"1-Uefa \n2-Conmebol \n3-Concacaf \n4-Afc\n5-Ofc\n6-Caf\nSu opcion: \n");
		  retornoNumero  = getEntero(&retorno);
		}while((retorno < 1 || retorno > 6) || (retornoNumero !=0));

	return retorno;

}
