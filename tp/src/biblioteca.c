#include "biblioteca.h"
// funciones
// en esta funcion no pido ni devuelvo nada lo uso para mantener el main mas vacio
void menu(){
    printf("1. Ingreso de los costos de Mantenimiento");
    printf("\nCostos de hospedaje -> $0");
    printf("\nCostos de Comida -> $0");
    printf("\nCostos de Transporte -> $0");
    printf("\n2. Carga de jugadores");
    printf("\nArqueros -> 0");
    printf("\nDefensores -> 0");
    printf("\nMediocampistas -> 0");
    printf("\nDelanteros -> 0");
    printf("\n3. Realizar todos los calculos");
    printf("\n4. Informar todos los resultados");
    printf("\n5. Salir");
}
// aca pido y devuelvo una opcion para que el usuario se pueda mover en el
// menu, ademas la valido para que no se rompa el programa
int validacionMenu(int opcion){

    printf("\nIngrese una opcion para moverte en el menu: ");
    scanf("%d", &opcion);

     while(opcion>5||opcion<1){
            printf("\nIngrese un numero valido");
            printf("\n********************************");
            printf("\nSolo puede elegir las opciones entre 1 y 5.\nVuelva a ingresar un numero: ");
            scanf("%d", &opcion);
        }
      return opcion;
}
// aca pido y valido un numero en la parte de gastos para que eliga que gasto quiere cargar y retorno la opcion al main
int validacionCasoUno(int opcion){

     printf("\nIngrese una opcion para elegir que dato cargar: ");
     scanf("%d", &opcion);

     while(opcion>3||opcion<1){
            printf("\nIngrese un numero valido");
            printf("\n********************************");
            printf("\nSolo puede elegir las opciones entre 1 y 3.\nVuelva a ingresar un numero: ");
            scanf("%d", &opcion);
        }
      return opcion;
}
// aca pido y valido los gastos que cargo ademas de retornar los valores por punteros para que se me actualize el menu
int obtenerCosto(float* precio){

    int costo;
    printf("\nIngrese el costo: ");
    scanf("%d", &costo);
    while(costo<0){
    printf("\nIngrese el costo : ");
    scanf("%d", &costo);}

    *precio = costo;

    return 0;
}
// aca pido y valido un numero en la parte de gastos para que eliga que gasto quiere cargar, y retorno la opcion al main
int validacionCasoDos(int opcion){

     printf("\nIngrese 1 o 4 dependiendo que posicion quiere ingresar: ");
     scanf("%d", &opcion);

     while(opcion>4||opcion<1){
            printf("\nIngrese un numero valido");
            printf("\n********************************");
            printf("\nSolo puede elegir las opciones entre 1 y 4.\nVuelva a ingresar un numero: ");
            scanf("%d", &opcion);
        }
      return opcion;
}
// aca pido y valido la opcion sobre que confedaracion es el jugador
// retorno la opcion al main validada
int obtenerDatos(int confederacion){


  printf("\n1.AFC");
  printf("\n2.CAF");
  printf("\n3.CONCACAF");
  printf("\n4.CONMEBOL");
  printf("\n5.UEFA");
  printf("\n6.OFC");

  do{
      printf("\nEn que confederacion juega?: ");
      scanf("%d", &confederacion);
  }
  while(confederacion>6||confederacion<1);


    return confederacion;
}
// no devuelvo nada, solo pido el numero de camiseta del jugador
void ingresoDeCamisetas(void){
int numero;
    printf("\nIngrese el numero de camiseta del jugador: ");
    scanf("%d", &numero);
}
// aca pido que me pase el dato de cuantos jugadores son en su confederacion
// y le retorno el %
float porcentajeConfederacion(int confederacion){

    float resultado;

    resultado = (100 * (float)confederacion) / 22;

    return resultado;
}

