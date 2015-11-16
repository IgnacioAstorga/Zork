#include "stdafx.h"

#include "Objeto.h"

#include "AccionCambiarSituacion.h"
#include "AccionFlag.h"
#include "AccionPerder.h"
#include "AccionCondicional.h"
#include "AccionConseguirObjeto.h"
#include "PredicadoObjetivo.h"

using namespace std;

class SEntradaCasa : public Situacion {

public:
	SEntradaCasa() {

		// Establece el código de la situación
		setCodigoSituacion("entrada_casa");
	}

	void cargarSituacion() {

		// Establece el nombre
		setNombre("House Entrance");

		// Establece la descripcion
		std::string descripcion;
		if (getFlag("intento_abrir") == 1) {
			descripcion += "\n-> The door is locked! It seems it needs a key.\n\n";
			setFlag("intento_abrir", 0);
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

		// Crea la acción de moverse
		opcion = new Opcion({ "go", "travel" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "north" }), new AccionCambiarSituacion("* To the north is the main plaza in front of the theatre.", "situacion_inicial")));
		getOpciones()->push_back(*opcion);

		// Crea la opción de coger la llave del felpudo
		if (getFlag("llave_conseguida") != 1) {
			opcion = new Opcion({ "look", "search", "examine", "inspect", "lift", "raise" });
			opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "doormat", "mat" }), { new AccionFlag("* There seems to be a bulge on the doormat.", "entrada_casa", "llave_conseguida", 2), new AccionConseguirObjeto(new Objeto("entrada_casa")) }));
			getOpciones()->push_back(*opcion);
		}
	}
};