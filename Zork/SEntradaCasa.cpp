#include "stdafx.h"

#include "SEntradaCasa.h"

#include "AccionCambiarSituacion.h"
#include "AccionFlag.h"
#include "AccionPerder.h"
#include "AccionCondicional.h"
#include "AccionAlternativa.h"
#include "AccionConseguirObjeto.h"

#include "PredicadoObjetivo.h"
#include "PredicadoTieneObjeto.h"

SEntradaCasa::SEntradaCasa() {

	// Establece el código de la situación
	setCodigoSituacion("entrada_casa");
}

void SEntradaCasa::cargarSituacion() {

	// Establece el nombre
	setNombre("House Entrance");

	// Establece la descripcion
	std::string descripcion;
	if (getFlag("intento_abrir_puerta") == 1) {
		descripcion += "\n-> The door is locked! It seems it needs a key.\n\n";
		setFlag("intento_abrir_puerta", 0);
	}
	if (getFlag("puerta_abierta") == 2) {
		descripcion += "\n-> The key fits in the keyhole, the door is now open!\n\n";
		setFlag("puerta_abierta", 1);
	}
	if (getFlag("llave_conseguida") == 2) {
		descripcion += "\n-> There is a key under the doormat! You pick it.\n\n";
		setFlag("llave_conseguida", 1);
	}
	descripcion += "You are in front of the house.";
	setDescripcion(descripcion);

	// Establece las opciones
	getOpciones()->clear();
	Opcion* opcion;

	// Crea la acción de moverse (y abrir la puerta)
	opcion = new Opcion({ "go", "travel" });
	opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "north" }), new AccionCambiarSituacion("* To the north is the main plaza in front of the theatre.", "situacion_inicial")));
	if (getFlag("puerta_abierta") == 1)
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "south" }), new AccionCambiarSituacion("* To the south is the door leading into the house.", "interior_casa")));
	else
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "south" }), new AccionAlternativa(new PredicadoTieneObjeto("llave_entrada_casa"), new AccionFlag("* To the south is the door leading into the house.", "entrada_casa", "puerta_abierta", 2), new AccionFlag("entrada_casa", "intento_abrir_puerta", 1))));
	getOpciones()->push_back(*opcion);

	// Crea un alias para la acción de abrir la puerta
	opcion = new Opcion({ "open", "enter", "use", "unlock" });
	if (getFlag("puerta_abierta") == 1)
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "door" }), new AccionCambiarSituacion("interior_casa")));
	else
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "door" }), new AccionAlternativa(new PredicadoTieneObjeto("llave_entrada_casa"), new AccionFlag("entrada_casa", "puerta_abierta", 2), new AccionFlag("entrada_casa", "intento_abrir_puerta", 1))));
	getOpciones()->push_back(*opcion);

	// Crea la opción de coger la llave del felpudo
	if (getFlag("llave_conseguida") != 1) {
		opcion = new Opcion({ "look", "search", "examine", "inspect", "lift", "raise" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "doormat", "mat" }), { new AccionFlag("* There seems to be a bulge on the doormat.", "entrada_casa", "llave_conseguida", 2), new AccionConseguirObjeto(new Objeto("llave_entrada_casa", { "key" })) }));
		getOpciones()->push_back(*opcion);
	}
}