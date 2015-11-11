#include "stdafx.h"

#include "OpcionMoverse.h"

using namespace std;

class SituacionInicial : Situacion {

public:
	static void cargar() {
		
		vector<Opcion*>* opciones;
		Situacion* situacion;

		opciones = new std::vector<Opcion*>();
		opciones->push_back(new OpcionMoverse("* Some suspicius people stand near the north path.\n* The theater is on the east path.\n* There is an empty street to the west.\n* A house blocks the south path", NULL, NULL, NULL, NULL, NULL, NULL));

		situacion = new Situacion("Theatre", "You are in front of the royal theatre.", *opciones);
		Mundo::obtenerInstancia().addSituacion("situacion_inicial", *situacion);
	}
};