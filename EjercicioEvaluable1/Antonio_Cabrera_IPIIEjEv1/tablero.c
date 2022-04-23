//Antonio Cabrera Landín MAIS
#include "tablero.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "objetos.h"

void iniciaTablero(objeto_t **tablero, int numFilas, int numColumnas){

	//iniciar el random
	srand(getpid());
	//inicializar el tablero con objetos "no activos"
	for(int i=0;i<numFilas;i++){
		for(int k=0;k<numColumnas;k++){
			tablero[i][k].activo = 0;
		}
	}
	//numero de enemigos entre 1 y 3
	int nEnemigos = 1+rand()%3;
	//numero de misiles entre 2 y 5
	int nMisiles = 2+rand()%4;
	//aniadir Enemigos
		//la posición está en la mitad superior del tablero (Y<=(numFilas/2))
	int x=0;
	int y=0;
	for(int i=0;i<nEnemigos;i++){
		y=rand()%(numFilas/2);
		x=rand()%numColumnas;
		tablero[y][x] = CrearObjeto(enemigo);
		tablero[y][x].posX = x;
		tablero[y][x].posY = y;
		tablero[y][x].tipo = enemigo;
	}
	//añadir misiles
	while(nMisiles!=0){
		y=rand()%numFilas;
		x=rand()%numColumnas;
		if(tablero[y][x].activo==0){
			tablero[y][x] = CrearObjeto(misil);
			tablero[y][x].posX = x;
			tablero[y][x].posY = y;
			tablero[y][x].tipo = misil;
			nMisiles--;
		}
	}

	//el  personaje principal está en la fila más inferior del tablero, en una columna aleatoria
	y=numFilas-1;
	x=rand()%numColumnas;
	tablero[y][x] = CrearObjeto(personaje);
	tablero[y][x].posX = x;
	tablero[y][x].posY = y;
	tablero[y][x].tipo = personaje;
	
}

objeto_t** reservaTablero(int numFilas, int numColumnas){
	objeto_t **tablero = NULL;
	tablero = (objeto_t **)malloc(sizeof(objeto_t*)*numFilas);
	for(int i=0;i<numColumnas;i++){
		*(tablero+i) = (objeto_t *)malloc(sizeof(objeto_t)*numColumnas);
	}
	return tablero;
}

void dibujaTablero(objeto_t **tablero, int numFilas, int numColumnas){

	//por cada fila,columna de tablero
		//si el objeto está activo
			//mostrar su sprite
		//si no
			//mostrar un espacio en blanco
	printf("╔");
	for(int i=1;i<=numColumnas;i++){
		printf("═");
	}
	printf("╗");
	printf("\n");
	for(int i=0;i<numFilas;i++){
		printf("║");
		for(int k=0;k<numColumnas;k++){
			if(tablero[i][k].activo == 0){
				printf(" ");
			}
			if(tablero[i][k].activo == 1){
				printf("%c",tablero[i][k].sprite);
			}
		}
		printf("║");
		printf("\n");
	}
	printf("╚");
	for(int i=0;i<numColumnas;i++){
		printf("═");
	}
	printf("╝");
	printf("\n");

}

void actualizaTablero(objeto_t** tablero, int numFilas, int numColumnas)
{
	//por cada posición del tablero
	for(int i=0;i<numFilas;i++){
		for(int k=0;k<numColumnas;k++){
				//si es un objeto activo
				if(tablero[i][k].activo==1){
					actualizarObjeto(&tablero[i][k],numFilas,numColumnas);
				}
			}
		}

	//Después de haber movido todos los objetos, actualizar sus posiciones dentro del tablero
	//por cada objeto activo del tablero (recorrerlo con un for doble)
	for(int i=0;i<numFilas;i++){
		for(int k=0;k<numColumnas;k++){
				//si es un objeto activo
				if(tablero[i][k].activo==1){
					//obtener su nueva posición X,Y almacenada en el objeto
					int x,y;
					x=tablero[i][k].posX;
					y=tablero[i][k].posY;

					//comprobar si debe moverse (las nuevas posiciones son distintas de la posición
	 				// actual)
					if(x!=k || y!=i){
						//Comprobar si en esa nueva posición ya hay un objeto activo
						if(tablero[y][x].activo == 1){
							//Si colisiona un Misil, se desactivan ambos
							if(tablero[y][x].tipo == 2 || tablero[i][k].tipo == 2){
								tablero[y][x].activo = 0;
								tablero[i][k].activo = 0;
							}
						}
						else{//En otro caso,(no hay objeto activo) se mueve el objeto a la nueva posición
							tablero[y][x]=tablero[i][k];
						}
						tablero[i][k].activo=0;
					}
				}
			}
		}
}

//Función que indica si hay un personaje activo dentro del tablero:
//retorna 1 si hay un personaje activo
//0 en otro caso
int buscaPersonaje(objeto_t** tablero, int numFilas, int numColumnas)
{
	int encontrado=0;
	//por cada objeto del tablero
	for(int i=0;i<numFilas;i++){
		for(int k=0;k<numColumnas;k++){
				//si es un objeto activo
				if(tablero[i][k].activo==1 && tablero[i][k].tipo==0){
					encontrado=1;
				}
			}
		}
	return encontrado;
}

