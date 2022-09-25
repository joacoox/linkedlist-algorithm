/******************************************************************************
*******************************************************************************/
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
int main ()
{
setbuf(stdout, NULL);

int opcion;
  float hospedaje = 0;
  float comida = 0;
  float transporte = 0;
  float arqueros = 0;
  float defensores = 0;
  float medioCampistas = 0;
  float delanteros = 0;
  int bandera = 0;
  float afc=0;
  float caf =0;
  float concacaf=0;
  float conmebol=0;
  float uefa=0;
  float ofc=0;
  int opcionCasoUno;
  int opcionCasoDos;
  int contadorJugadores;
  int confederacion;
  int banderaUno = 0;
  int costoDeMantenimiento;
  int aumento;
  int costoDeMantenimientoAumento;


  menu();
  do
    {

      switch (opcion)
	{
	case 1:
	  printf ("\n1. Ingreso de los costos de Mantenimiento");
	  printf ("\n1.Costos de hospedaje -> $%.0f", hospedaje);
	  printf ("\n2.Costos de Comida -> $%.0f", comida);
	  printf ("\n3.Costos de Transporte -> $%.0f", transporte);
	  if ((hospedaje && comida && transporte) == 0)
	  {
	    opcionCasoUno = validacionCasoUno (opcionCasoUno);
	    switch (opcionCasoUno)
	      {
	      case 1:
		obtenerCosto (&hospedaje);
		break;
	      case 2:
		obtenerCosto (&comida);
		break;
	      case 3:
		obtenerCosto (&transporte);
		break;
	      }// switch
	  }	 else {
	    printf("\n********************************");
	    printf ("\nYa se cargaron los tres datos");
	    printf("\n********************************");
		      }// else
	break;
	case 2:
	printf ("\n2. Carga de jugadores");
	printf ("\n1.Arqueros -> %.0f", arqueros);
	printf ("\n2.Defensores -> %.0f", defensores);
	printf ("\n3.Mediocampistas -> %.0f", medioCampistas);
	printf ("\n4.Delanteros -> %.0f", delanteros);


	opcionCasoDos = validacionCasoDos(opcionCasoDos);
	contadorJugadores = arqueros + defensores + delanteros + medioCampistas;
	if(contadorJugadores<23){

	confederacion = obtenerDatos(confederacion);

	switch(confederacion){
      case 1:
      afc++;
      break;
      case 2:
      caf++;
      break;
      case 3:
      concacaf++;
      break;
      case 4:
      conmebol++;
      break;
      case 5:
      uefa++;
      break;
      ofc++;
      case 6:
      break;
    }
	ingresoDeCamisetas();
	switch(opcionCasoDos)
	{
	 case 1:
	 if(arqueros == 2){
         printf("\n Ya se ingresaron dos arqueros");}
	else{ arqueros++; }
	 break;
	 case 2:
	 if(defensores == 8){
	      printf("\n Ya se ingresaron ocho defensores");
	 }else{
	 defensores++;}
	 break;
	 case 3:
	 if(medioCampistas == 8){
	      printf("\n Ya se ingresaron ocho medioCampistas");
	 }else{
	 medioCampistas++;}
	 break;
	 case 4:
	 if(delanteros == 4){
	      printf("\n Ya se ingresaron cuatro delanteros");
	 }else{
	 delanteros++;}
	 break;
	}//switch
	 }else{printf("Ya se ingresaron 22 jugadores");}

	break;
	case 3:
	printf ("\n3. Realizar todos los calculos");
	if(contadorJugadores > 21){
	if(hospedaje != 0|| comida != 0|| transporte != 0){
	    printf("\n Se realizaron todos los calculos");
	banderaUno = 1;
	uefa = porcentajeConfederacion(uefa);
	conmebol = porcentajeConfederacion(conmebol);
	concacaf = porcentajeConfederacion(concacaf);
	afc = porcentajeConfederacion(afc);
	ofc = porcentajeConfederacion(ofc);
	caf = porcentajeConfederacion(caf);
	costoDeMantenimiento = hospedaje + comida + transporte;
	if(uefa > 49){
	    aumento = costoDeMantenimiento * 35 / 100;
	    costoDeMantenimientoAumento = costoDeMantenimiento + aumento;
	}}}else{printf ("\nTiene que ingresar a las opciones anteriores antes de llegar aca");}
	break;
	case 4:
	printf ("\n4. Informar todos los resultados");
	if(banderaUno == 1){
    printf("\n Porcentaje Uefa: %2.f",uefa);
	printf("\n Porcentaje Conmebol: %2.f",conmebol);
	printf("\n Porcentaje Concacaf: %2.f",concacaf);
	printf("\n Porcentaje Afc: %2.f",afc);
	printf("\n Porcentaje Ofc: %2.f",ofc);
	printf("\n Porcentaje Caf: %2.f",caf);
	if(uefa > 49){
	  printf("\n El costo de Mantenimiento era de: $%d y recibio un aumento de: $%d, su nuevo valor es de: $%d", costoDeMantenimiento, aumento, costoDeMantenimientoAumento);
	}else{printf("\n El costo de Mantenimiento es de: $%d",costoDeMantenimiento);}}
	else{printf ("\nTiene que ingresar a las opciones anteriores antes de llegar aca ");}
	break;
	case 5:
	printf ("\nsalio del programas vuelva prontos");
	exit(1);
	break;
	}// switch
	opcion = validacionMenu (opcion);
    }// do
		    while (bandera == 0);



}// main

