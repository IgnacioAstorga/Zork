#include "stdafx.h"

#include "SPasilloCasa.h";

#include "AccionPerder.h"

SPasilloCasa::SPasilloCasa() {

	// Establece el código de la situación
	setCodigoSituacion("pasillo_casa");
}

void SPasilloCasa::cargarSituacion() {

	// Establece el nombre
	setNombre("Main Corridor");

	// Establece la descripcion
	std::string descripcion = "* HERE ENDS THE DEMO *\nThanks for playing!";
	setDescripcion(descripcion);

	// Establece las opciones
	getOpciones()->clear();
	Opcion* opcion;

	// Crea la acción de moverse
	opcion = new Opcion({ "exit" });
	opcion->addAccion(new AccionPerder("* Write exit to end the game.", "You have reached this demo's end!\nThanks for playing!"));
	getOpciones()->push_back(*opcion);
}