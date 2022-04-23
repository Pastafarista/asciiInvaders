//Antonio Cabrera Landín MAIS
#include "misil.h"

////////////////////////////////////////////////////////
//Añadir la función para crear un misil con valores por defecto (todo a 0, dirección ascendente).

misil_t CrearMisil(){
 misil_t misil = {0,descendente};
 return misil;
}

void mueveMisil (objeto_t* objeto, int numFilas, int numColumnas){
    //si la dirección del misil es ascendente:
    if(objeto->datos.misil.dir == 1){
        //sumar 1 a la coordenada Y de su posición
        objeto->posY++;
    }
    else{
        //restar 1 a la coordenada Y de su posición
        objeto->posY--;
    }

    //si está fuera del número de Filas válidas del tablero, se desactiva
    if(objeto->posY <= 0 || objeto->posY >= numFilas){
        objeto->activo=0;
    }

}
