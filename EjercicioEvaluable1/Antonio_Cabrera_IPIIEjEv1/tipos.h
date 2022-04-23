//Antonio Cabrera Landín MAIS
#ifndef __TIPOS_H__
#define __TIPOS_H__



//////////////////////////////////////////////////////////////////////
// Tipos enumerados.
//////////////////////////////////////////////////////////////////////
// Crear un tipo enumerado direccion_e, que se usará para indicar la dirección de los misiles

// Crear un tipo enumerado tipoObjeto_e, que se usará para indicar el tipo de objeto que 
// se usará en el juego. Hay tres tipos:
// enemigo, misil, personaje



//////////////////////////////////////////////////////////////////////
// Estructuras
//////////////////////////////////////////////////////////////////////

// Estructura "movimiento_t" usada por los enemigos, indica la dirección del siguiente movimiento


typedef struct movimiento_t{
    int x;
    int y;
}movimiento_t;


//////////////////////////////////////////////////////////////////////
// Estructura "enemigo_t" con los datos de los enemigos

typedef struct enemigo_t{
    int vida;
    int puntuacion;
    movimiento_t movimientos[4];
    int numMovimientos;
    int posMovimiento;
}enemigo_t;

//////////////////////////////////////////////////////////////////////
// Estructura misil_t con los datos de los misiles, y la dirección (tipo enumerado) a 
// la que se desplaza en cada turno
typedef enum direccion_e{
    ascendente,
    descendente
}direccion_e;


typedef struct misil_t{
    int dano;
    direccion_e dir;
}misil_t;

//////////////////////////////////////////////////////////////////////
// Estructura personaje_t con los datos del personaje principal

typedef struct personaje_t{
    int vida;
    int puntuacion;
}personaje_t;


typedef enum tipoObjeto_e{
    personaje,
    enemigo,
    misil
}tipoObjeto_e;


typedef union datos_u{
    personaje_t personaje;
    enemigo_t enemigo;
    misil_t misil;
}datos_u;

//////////////////////////////////////////////////////////////////////
// Estructura de objeto genérico, puede ser cualquiera de los 3 anteriores. 
// Para ello se usará una variable enumerada "tipo", y tendrá las tres estructuras
// anteriores anidadas. Sólo habrá datos es la estructura indicada por la variable "tipo"

typedef struct objeto_t{
    int posX;
    int posY;
    int activo;
    tipoObjeto_e tipo;
    char sprite;//'V'-Enemigo '.'-Misil 'A'-Jugador
    datos_u datos;
}objeto_t;

#endif
