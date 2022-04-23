//Antonio Cabrera Landín MAIS
#include "enemigo.h"

//Información de los movimientos del enemigo
int movX[]={
	1,
	0,
	-1,
	0
};
int movY[]={
	0,
	1,
	0,
	-1
};

////////////////////////////
//Añadir función para crear un enemigo con valores por defecto (todo a 0)
enemigo_t CrearEnemigo(){

	enemigo_t enemigo;
	enemigo.vida = 0;
	enemigo.puntuacion = 0;
	enemigo.posMovimiento = 0;
	enemigo.numMovimientos = 4;

	//Rellenar array movimientos
	for(int i=0;i<4;i++){
		enemigo.movimientos[i].x = movX[i];
		enemigo.movimientos[i].y = movY[i];
	}

	return enemigo;
}

void mueveEnemigo(objeto_t* objeto, int numFilas, int numColumnas){

	//Variables para anticipar si el enemigo se sale del tablero
	int dX=0;
	int dY=0;

	//obtener el índice del movimiento que se va a realizar, que está almacenado en la estructura del enemigo
	int indice = objeto->datos.enemigo.posMovimiento;

	//Calcular dX y dY para ver si el movimiento va a ser "legal"
	dX = objeto->datos.enemigo.movimientos[indice].x;
	dY = objeto->datos.enemigo.movimientos[indice].y;

	//Comprobar si la nueva posición está dentro del tablero. Para ello, usar numFilas/numColumnas
	if(objeto->posX+dX>=numColumnas){
		dX=0;
	}
	if(objeto->posY+dY>=numFilas){
		dY=0;
	}

	//Aplicar el movimiento
	objeto->posX=objeto->posX+dX;
	objeto->posY=objeto->posY+dY;

	//sumar una unidad en el índice de movimiento
	objeto->datos.enemigo.posMovimiento++;

	//si es mayor o igual que el tamaño del array de movimientos, vuelve a 0
	if(objeto->datos.enemigo.posMovimiento >= 4){
		objeto->datos.enemigo.posMovimiento=0;
	}
}
