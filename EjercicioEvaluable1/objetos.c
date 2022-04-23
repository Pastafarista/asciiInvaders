//Antonio Cabrera Landín MAIS
#include "objetos.h"
#include "misil.h"
#include "personaje.h"
#include "enemigo.h"

////////////////////////////////////////////////////////////
//Añadir la función para crear un objeto de un tipo dado. Inicializa sus valores "tipo",
//"sprite" y "posición" dependiendo del tipo indicado. La posición por defecto es "X=0" "Y=0"
//
// Por defecto, los objetos creados están activos (la variable "activo"=1) 

objeto_t CrearObjeto(tipoObjeto_e tipo){
	objeto_t r;
	r.posX = 0;
	r.posY = 0;
	r.activo = 1;
	if(tipo==0){
		r.sprite = 'A';
		r.datos.personaje = CrearPersonajePrincipal();
	}
	if(tipo==1){
		r.sprite = 'V';
		r.datos.enemigo = CrearEnemigo();
	}
	if(tipo==2){
		r.sprite = '.';
		r.datos.misil = CrearMisil();
	}
	return r;
}

void actualizarObjeto(objeto_t* objeto, int numFilas, int numColumnas){
	int tipo = objeto->tipo;
	switch(tipo){
		case 0:
			muevePersonaje(objeto,numFilas,numColumnas);
			break;
		case 1:
			mueveEnemigo(objeto,numFilas,numColumnas);
			break;
		case 2:
			mueveMisil(objeto,numFilas,numColumnas);
			break;
	}
}

