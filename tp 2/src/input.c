#include "input.h"


/** \brief Solicita un numero flotante al usuario
 *
 * \param mensaje recibe un mensaje para mostrar
 * \param eMensaje recibe un mensaje de error para mostrar
 * \param minLimit limite mas bajo para el numero
 * \param maxlimit limite mas alto para el numero
 * \return retorna el numero flotante ingresado
 */
float getFloat(char mensaje[], char eMensaje[], float minLimit, float maxLimit)

{
	float aux;

	printf("%s", mensaje);
	scanf("%f", &aux);

	while (aux < minLimit || aux > maxLimit) {
		printf("%s", eMensaje);
		scanf("%f", &aux);
	}

	return aux;

}
/** \brief Solicita un char al usuario
 *
 * \param input array donde se cargara el char
 * \param message recibe un mensaje para mostrar
 * \param eMessage recibe un mensaje de error para mostrar
 * \param lowLimit limite mas bajo para el char
 * \param hilimit limite mas alto para el char
 * \return retorna [0] en caso de que se ingrese bien o [-1] en caso de que se ingrese mal
 *
 */
int getChar(char *input, char message[], char eMessage[], char lowLimit,
		char hiLimit) {
	int respuesta = -1;
	char aux;
	int scanfOk;
	puts(message);
	scanfOk = scanf("%c", &aux);
	aux = tolower(aux);

	if (scanfOk) {
		if (aux < lowLimit || aux > hiLimit) {
			puts(eMessage);
		} else {
			aux = toupper(aux);
			*input = aux;
			respuesta = 0;

		}
	}
	return respuesta;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char cadena[], char mensaje[], char eMensaje[], int minLimit,
		int maxLimit) {
	int x;
	char aux[400];

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);
	x = strlen(aux);

	while (x < minLimit || x > maxLimit) {
		printf("%s", eMensaje);
		fflush(stdin);
		scanf("%[^\n]", aux);
		x = strlen(aux);
	}

	strcpy(cadena, aux);
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
int esSoloLetas(char cadena[])
{
	 int i=0;
		int retorno = 1;


			for(i=0 ; cadena[i] != '\0'; i++)
			{
				if((cadena[i] != ' ') && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
				{
					retorno = 0;
					break;
				}
			}

		return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */ /*
int getStringLetras(char mensaje[], char input[]) {
	char aux[256];
	int retorno;
	retorno = 0;
	getString(aux, mensaje, mensaje, 1, 256);
	if (esSoloLetras(aux)) {
		strcpy(input, aux);
		retorno = 1;
	}
	return retorno;
}*/

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]) {
	int i = 0;
	int retorno;
	retorno = 1;
	while (str[i] != '\0') {
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < 'A' || str[i] > 'Z')
				&& (str[i] < '0' || str[i] > '9')) {
			retorno = 0;
			i++;
		}

	}
	return retorno;
}
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getEntero(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getStrings(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int getStrings(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
