//Antonio Cabrera Landín MAIS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "objetos.h"
#include "tablero.h"

/////////////////////////////////////////////////
// Programa principal

void limpiarPantalla();
int main(int argc, char** argv)
{	
	limpiarPantalla();
	//Imprimir el título
	printf("\n");	
	printf(" █████╗ ███████╗ ██████╗██╗██╗    ██╗███╗   ██╗██╗   ██╗ █████╗ ██████╗ ███████╗██████╗ ███████╗\n");
	printf("██╔══██╗██╔════╝██╔════╝██║██║    ██║████╗  ██║██║   ██║██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝\n");
	printf("███████║███████╗██║     ██║██║    ██║██╔██╗ ██║██║   ██║███████║██║  ██║█████╗  ██████╔╝███████╗\n");
	printf("██╔══██║╚════██║██║     ██║██║    ██║██║╚██╗██║╚██╗ ██╔╝██╔══██║██║  ██║██╔══╝  ██╔══██╗╚════██║\n");
	printf("██║  ██║███████║╚██████╗██║██║    ██║██║ ╚████║ ╚████╔╝ ██║  ██║██████╔╝███████╗██║  ██║███████║\n");
	printf("╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝╚═╝    ╚═╝╚═╝  ╚═══╝  ╚═══╝  ╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝\n");
	
	//Pedir las filas y las columnas del tablero al usuario
	int filas,columnas;
	printf("Introduzca él número de filas del tablero:\n");
	scanf("%i",&filas);
	printf("Introduzca él número de columnas del tablero:\n");
	scanf("%i",&columnas);
	limpiarPantalla();
	while ( getchar() != '\n' );

	//Iniciar el tablero
	objeto_t** tablero = reservaTablero(filas,columnas);
	iniciaTablero(tablero,filas,columnas);

	while(buscaPersonaje(tablero,filas,columnas)==1){
		limpiarPantalla();
		dibujaTablero(tablero,filas,columnas);
		actualizaTablero(tablero,filas,columnas);
	}
	//Imprimir el mensaje de game over
	limpiarPantalla();
	printf("\n");
	printf("  ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗\n" );
	printf("██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗\n");
	printf("██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝\n");
	printf("██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	printf("╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║\n");
	printf(" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");

	//liberar memoria del tablero
	free(tablero);

}
void limpiarPantalla(){
	printf("\e[H\e[2J\e[3J");

}

