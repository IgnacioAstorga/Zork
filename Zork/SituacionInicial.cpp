#include "stdafx.h"

#include "AccionMoverse.h"
#include "AccionAbrir.h"
#include "AccionFlag.h"
#include "AccionCondicional.h"
#include "PredicadoObjetivo.h"

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
		descripcion += "You are in front of the royal theatre.";
		setDescripcion(descripcion);
		
		// Establece las opciones
		getOpciones()->clear();
		Opcion* opcion;

		opcion = new Opcion("* Some suspicius people stand near the north path.\n* The theater is on the east path.\n* There is an empty street to the west.\n* A house blocks the south path.", { "go", "travel" });
		opcion->addAccion(new AccionCondicional(*new PredicadoObjetivo("east"), *new AccionFlag("situacion_inicial", "intento_teatro", 1)));
		opcion->addAccion(new AccionMoverse("i_norte_bandidos", "", "situacion_inicial", "", "", ""));
		getOpciones()->push_back(*opcion);

		opcion = new Opcion("* There is a sewer entrance under your feet.", { "open" });
		opcion->addAccion(new AccionAbrir("sewer", "situacion_inicial"));
		opcion->addAccion(new AccionFlag("situacion_inicial", "intento_alcantarilla", 1));
		getOpciones()->push_back(*opcion);
	}
};