#include "stdafx.h"

#include "OpcionMoverse.h"

using namespace std;

class SituacionInicial : public Situacion {

public:
	void cargarSituacion() {

		// Establece el código de la situación
		setCodigoSituacion("situacion_inicial");

		// Establece el nombre
		setNombre("Theatre");

		// Establece la descripcion
		setDescripcion("You are in front of the royal theatre.");
		
		// Establece las opciones
		getOpciones()->clear();
		getOpciones()->push_back(new OpcionMoverse("* Some suspicius people stand near the north path.\n* The theater is on the east path.\n* There is an empty street to the west.\n* A house blocks the south path.", "", "", "", "", "", ""));
	}
};