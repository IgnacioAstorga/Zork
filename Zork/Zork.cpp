// Zork.cpp: define el punto de entrada de la aplicaci�n de consola.
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[]) {

	// Inicia la consola
	Consola::inicializar();

	// Inicia el juego
	Juego::inicializar();
	Juego::obtenerInstancia().iniciar();

	return 0;
};