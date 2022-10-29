#include "operaciones.h"
/*
 * \brief calculo el promedio de todos los salarios
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \return el promedio de los salarios
 */
float PromedioDeTodosLosSalarios(eJugador lista[], int size)
{
	int acumulador=0;
     int contador=0;
     float promedio;

	for(int i = 0; i<size; i++){
	if(lista[i].estado == OCUPADO){
		acumulador += lista[i].salario;
       contador++;
	  }
	}

	promedio = sacarPromedio(acumulador, contador);
	return promedio;
}
/*
 * \brief calculo el promedio
 * \param pido un primer valor
 * \param y el acumulador por el que va a ser dividido
 * \return el promedio
 */
float sacarPromedio(int resultado, int acumulador)
{
	float total;

	total = resultado / acumulador;

	return total;
}
/*
 * \brief calculo los jugadores que cobran mas que el promedio
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \return void
 */
void JugadoresCobranMasQuePromedio(eJugador lista[], int size)
{
	int promedio;
	int contador=0;
	promedio = PromedioDeTodosLosSalarios(lista, size);

    for(int i =0;i<size;i++){

    	if(lista[i].salario>promedio){
    		contador++;
    	}
    }
    MostrarJugadoresSueldoMayorPromedio(promedio, contador);
}
/*
 * \brief busco la confederacion con mayor duracion de los contratos
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void ConfederacionConMayorDuracionContratos(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{
 // int contador;
  int acumulador;
  int bandera = 0;
  int maximo;
  eConfederacion aux;

    for(int i= 0; i< sizeConf ; i++)
    {
        acumulador = 0;

     acumulador  = AcumularAniosJugadorConfederacion(lista, size, listaConfederacion[i].id);

        if(bandera == 0 ||maximo < acumulador){

        bandera =1;
        maximo = acumulador;
        aux = listaConfederacion[i];
        }
     }
    ImprimirUnaConfederacionConUnaVariable(aux, maximo, 1);
}
/*
 * \brief acumulo los anios de los contratos de los jugadores
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \index la id de la confederacion
 * \return void
 */
int AcumularAniosJugadorConfederacion(eJugador lista[], int size, int index)
{
	int acumulador =0;
	for(int j=0; j<size; j++)
	        {
	            if(lista[j].estado == OCUPADO && lista[j].idConfederacion == index)
	            {
	                acumulador += lista[j].anioscontrato;
	            }
	        }
	return acumulador;
}
/*
 * \brief itero en las confederaciones y luego llamo a una funcion que imprime
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return void
 */
void PorcentajeDeJugadoresPorConfederacion(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{

float total;
      Headers(3);
    for(int i= 0; i< sizeConf ; i++)
    {

    	total = CalcularPorcentajeDeConfederaciones(lista,size, listaConfederacion[i].id);

    	 ImprimirUnaConfederacionConUnaVariable(listaConfederacion[i], total, 2);
    }

}
/*
 * \brief calculo el porcentaje de las confederaciones
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \index la id de la confederacion
 * \return el porcentaje por confederacion
 */
float CalcularPorcentajeDeConfederaciones(eJugador lista[], int size, int index)
{
	     float total;
	     int acumulador=0;
	     int contador = 0;

	        for(int j= 0; j< size ; j++)
	        {
					 if(lista[j].estado == OCUPADO)
					 {
						contador++;
						   if(lista[j].idConfederacion == index)
							{
							acumulador++;
							}
					 }
			}
	        total = (float)(acumulador * 100) / contador;

	        return total;
}
/*
 * \brief calculo la confederacion con mas jugadores
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \param listaConfederacion pido la lista de confederaciones
 * \param sizeConf el tamanio de las confederaciones
 * \return retorno la confederacion con mas jugadores
 */
eConfederacion ConfederacionConMasJugadores(eJugador lista[], int size, eConfederacion listaConfederacion[], int sizeConf)
{
 // int contador;
  int acumulador;
  int bandera = 0;
  int maximo;
  eConfederacion aux;

    for(int i= 0; i< sizeConf ; i++)
    {

     acumulador  = AcumularJugadores(lista, size, listaConfederacion[i].id);

        if(bandera == 0 ||maximo < acumulador){

        bandera =1;
        maximo = acumulador;
        aux = listaConfederacion[i];
        }
     }
    ImprimirUnaConfederacionConUnaVariable(aux, maximo, 3);

    return aux;
}
/*
 * \brief acumulo jugadores por confederacion
 * \param lista pido la lista de jugadores
 * \param size el tamanio de los jugadores
 * \index la id de la confederacion
 * \return la cantidad de jugadores por confederacion
 */
int AcumularJugadores(eJugador lista[], int size, int index)
{
	int acumulador =0;
	for(int j=0; j<size; j++)
	        {
	            if(lista[j].estado == OCUPADO && lista[j].idConfederacion == index)
	            {
	                acumulador ++;
	            }
	        }
	return acumulador;
}
