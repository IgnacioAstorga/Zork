#include "stdafx.h"

#include "AccionCambiarSituacion.h"
#include "AccionFlag.h"
#include "AccionPerder.h"
#include "AccionCondicional.h"

#include "PredicadoObjetivo.h"
#include "PredicadoFlag.h"
#include "PredicadoAND.h"

using namespace std;

class SituacionInicial : public Situacion {

public:
	SituacionInicial() {

		// Establece el código de la situación
		setCodigoSituacion("situacion_inicial");
	}

	void cargarSituacion() {

		// Establece el nombre
		setNombre("Theatre");

		// Establece la descripcion
		std::string descripcion;
		if (getFlag("intento_alcantarilla") == 1) {
			descripcion += "\n-> The sewer is too heavy! You won't be able to move it.\n\n";
			setFlag("intento_alcantarilla", 0);
		}
		if (getFlag("intento_teatro") == 1) {
			descripcion += "\n-> The theatre is closed.\n\n";
			setFlag("intento_teatro", 0);
		}
		if (getFlag("intento_camino") == 2) {
			descripcion += "\n-> As you approach to the street more suspicius people suddenly come out from the shadows!.\n\n";
			setFlag("intento_camino", 1);
		}
		descripcion += "You are in front of the royal theatre.";
		setDescripcion(descripcion);
		
		// Establece las opciones
		getOpciones()->clear();
		Opcion* opcion;

		// Crea la opción de moverse
		opcion = new Opcion({ "go", "travel" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "east" }), new AccionFlag("* The theater is on the east path.", "situacion_inicial", "intento_teatro", 1)));
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "north" }), new AccionPerder("* Some suspicius people stand near the north path.", "You are attacked by bandits!\nThey kill you and take all your belongings.")));
		if (getFlag("intento_camino") == 1)
			opcion->addAccion(new AccionCondicional(new PredicadoAND(new PredicadoObjetivo({ "west" }), new PredicadoFlag("intento_camino", 1)), new AccionPerder("* More suspicius people have appeared on the street to the west.", "You are attacked by bandits!\nThey kill you and take all your belongings.")));
		else
			opcion->addAccion(new AccionCondicional(new PredicadoAND(new PredicadoObjetivo({ "west" }), new PredicadoFlag("intento_camino", 1, false)), new AccionFlag("* There is an empty street to the west.", "situacion_inicial", "intento_camino", 2)));
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "south" }), new AccionCambiarSituacion("* A house blocks the south path.", "entrada_casa")));
		getOpciones()->push_back(*opcion);

		// Crea la opción de abrir la alcantarilla
		opcion = new Opcion({ "open" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo({ "sewer" }), new AccionFlag("* There is a sewer entrance under your feet.", "situacion_inicial", "intento_alcantarilla", 1)));
		getOpciones()->push_back(*opcion);
	}
};