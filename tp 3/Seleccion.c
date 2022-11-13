#include "Seleccion.h"

Seleccion* selec_new()
{
	Seleccion* unaSeleccion;
	unaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	return unaSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion;
	unaSeleccion = selec_new();

	if(unaSeleccion != NULL)
	{
		unaSeleccion->id = atoi(idStr);
		strcpy(unaSeleccion->pais, paisStr);
		strcpy(unaSeleccion->confederacion, confederacionStr);
		selec_setConvocados(unaSeleccion ,atoi(convocadosStr));
	}

	return unaSeleccion;
}
void selec_delete(Seleccion* this)
{
	if(this != NULL)
		{
			free(this);
		}
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;

		if(this != NULL && id != NULL)
			{
	         *id = this->id;
		    retorno = 1;
			}

		return retorno;

}
int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this != NULL && pais != NULL)
	{
			strcpy(pais, this->pais);
			retorno = 1;
	}
	return retorno;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
			strcpy(confederacion, this->confederacion);
			retorno = 1;
	}
	return retorno;
}
int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados >= 0)
	{
		  this->convocados = convocados;
		  retorno = 1;
	}

	return retorno;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;

		if(this != NULL && convocados != NULL)
		{
			 *convocados = this->convocados;
			  retorno = 1;
		}

		return retorno;
}

void selec_printOne(Seleccion* this)
{
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;

	selec_getId(this, &id);
	selec_getPais(this, pais);
	selec_getConfederacion(this, confederacion);
	selec_getConvocados(this, &convocados);

	printf("%5d %-25s %-25s %-25d\n",id,pais,confederacion,convocados);
}
int selec_CompararPorNombre(void* unaSeleccion, void* otraSeleccion)
{
	Seleccion* seleccionUno;
	Seleccion* seleccionDos;
	char nombreSeleccionUno[100];
	char nombreSeleccionDos[100];
	int compara;

   if(unaSeleccion != NULL && otraSeleccion != NULL)
   {
	   seleccionUno =(Seleccion*) unaSeleccion;
	   seleccionDos =(Seleccion*) otraSeleccion;
	   selec_getConfederacion(seleccionUno, nombreSeleccionUno);
	   selec_getConfederacion(seleccionDos, nombreSeleccionDos);

	   compara = strcmp(nombreSeleccionUno , nombreSeleccionDos);
   }

   return compara;
}
