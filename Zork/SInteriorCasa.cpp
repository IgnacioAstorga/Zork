#include "stdafx.h"

#include "SInteriorCasa.h";

#include "AccionCambiarSituacion.h"
#include "AccionFlag.h"
#include "AccionPerder.h"
#include "AccionCondicional.h"
#include "AccionAlternativa.h"

#include "PredicadoObjetivo.h"
#include "PredicadoTieneObjeto.h"
#include "PredicadoFlag.h"

SInteriorCasa::SInteriorCasa() {

	// Establece el código de la situación
	setCodigoSituacion("interior_casa");
}

void SInteriorCasa::cargarSituacion() {

	// Establece el nombre
	setNombre("House Interior");

	// Establece la descripcion
	std::string descripcion;
	if (getFlag("primera_entrada") != 1) {
		descripcion += "\n-> As you enter, you can feel the suspicios people moving towards the house.\n\n";
		setFlag("primera_entrada", 1);
	}
	if (getFlag("intento_puerta") == 1) {
		descripcion += "\n-> The door needs a key.\n\n";
		setFlag("intento_puerta", 0);
	}
	if (getFlag("puerta_cerrada") == 3) {
		descripcion += "\n-> You unlock the door with the key.\n\n";
		setFlag("puerta_cerrada", 0);
	}
	if (getFlag("puerta_cerrada") == 2) {
		descripcion += "\n-> You lock the door with the key.\n\n";
		setFlag("puerta_cerrada", 1);
	}
	descripcion += "You are in the main hall of the house.";
	setDescripcion(descripcion);

	// Establece las opciones
	getOpciones()->clear();
	Opcion* opcion;

	// Crea la acción de moverse
	opcion = new Opcion({ "go", "travel" });
	opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "north" }), new AccionAlternativa(new PredicadoFlag("puerta_cerrada", 1), new AccionFlag("* To the north is the door leading to the street.", "interior_casa", "intento_puerta", 1), new AccionPerder("As you exit the house, you are attacked by bandits!\nThey kill you and take all your belongings."))));
	opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "south" }), new AccionAlternativa(new PredicadoFlag("puerta_cerrada", 1), new AccionCambiarSituacion("* There's a long corridor to the south.", "pasillo_casa"), new AccionPerder("As you prepare to go, bandits suddenly break through the door of the house!\nThey kill you and take all your belongings."))));
	getOpciones()->push_back(*opcion);

	// Crea la acción de cerrar/abrir la puerta
	if (getFlag("puerta_cerrada") != 1) {
		opcion = new Opcion({ "close", "lock", "block" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "door" }), new AccionAlternativa(new PredicadoTieneObjeto("llave_entrada_casa"), new AccionFlag("interior_casa", "puerta_cerrada", 2), new AccionFlag("interior_casa", "intento_puerta", 1))));
		getOpciones()->push_back(*opcion);
	}
	else {
		opcion = new Opcion({ "open", "enter", "use", "unlock" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "door" }), new AccionAlternativa(new PredicadoTieneObjeto("llave_entrada_casa"), new AccionFlag("interior_casa", "puerta_cerrada", 3), new AccionFlag("interior_casa", "intento_puerta", 1))));
		getOpciones()->push_back(*opcion);
	}
}