#include "stdafx.h"

using namespace std;

class INorteBandidos : public Situacion {

public:
	INorteBandidos() {

		// Establece el código de la situación
		setCodigoSituacion("i_norte_bandidos");
	}

	void cargarSituacion() {
		
		// Establece el nombre
		setNombre("Bandits");

		// Establece la descripcion
		setDescripcion("You are attacked by bandits!\nThey kill you and take all your belongings.");

		// Establece las opciones
		getOpciones()->clear();

		// Pierde el juego
		Juego::obtenerInstancia().setJuegoAcabado(true);
	}
};