//Antonio Cabrera Landín MAIS
#ifndef __TABLERO_H__
#define __TABLERO_H__
#include "tipos.h"

void iniciaTablero(objeto_t **tablero, int numFilas, int numColumnas);
objeto_t** reservaTablero(int numFilas, int numColumnas);
void dibujaTablero(objeto_t **tablero, int numFilas, int numColumnas);
void actualizaTablero(objeto_t** tablero, int numFilas, int numColumnas);
int buscaPersonaje(objeto_t** tablero, int numFilas, int numColumnas);
#endif

