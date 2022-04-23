//Antonio Cabrera Landín MAIS
#include "personaje.h"
#include <stdio.h>

////////////////////////////////////////////////////////
//Añadir función para crear un personaje con valores por defecto (todo a 0).

personaje_t CrearPersonajePrincipal(){
	personaje_t personaje = {0,0};
	return personaje;
}

void muevePersonaje (objeto_t* objeto, int numFilas, int numColumnas){

	//Variable para anticipar el movimiento y ver si es correcto
	int dX=0;
	int proximaPos;

	//Pedir movimiento al usuario:“A”: Mover izquierda una unidad “D”: Mover derecha una unidad	“S”: Acabar el juego
	int salir=1;
	char movimiento;
	do{
		salir=1;
		printf("Presione una tecla:");
		movimiento=getchar();
		if(movimiento!='a' && movimiento!='d' && movimiento!='s'){
			printf("Input no reconocido\n");
			salir=0;
		}
		while ( getchar() != '\n' );
	}while(salir!=1);

	//Leer movimiento
	switch(movimiento){
		case 'a':
			dX=-1;
			break;
		case 'd':
			dX=1;
			break;
		case 's':
			objeto->activo=0;
			printf("Saliendo del programa...\n");
			break;
	}

	//comprobar coordenadas correctas:
	proximaPos=dX+objeto->posX;
	if(proximaPos<0 || proximaPos>=numColumnas){
		dX=0;
	}
	proximaPos=dX+objeto->posX;

	//Aplicar el movimiento
	objeto->posX=proximaPos;
}

