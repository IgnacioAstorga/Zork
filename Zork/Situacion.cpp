#include "stdafx.h"

//************ VARIABLES *************

//********** CONSTRUCTORES ***********
Situacion::Situacion() {
	// Este constructor no deber�a utilizarse
}

Situacion::Situacion(std::string p_nombre, std::string p_descripcion, std::vector<Opcion*> p_opciones) {
	nombre = p_nombre;
	descripcion = p_descripcion;
	opciones = p_opciones;
}

Situacion::~Situacion() {
	// No necesita hacer nada
}

//************** M�TODOS *************

// Propios
std::string Situacion::getNombre()
{
	return nombre;
}

std::string Situacion::getDescripcion()
{
	return descripcion;
}

void Situacion::imprimirSituacion()
{
	Consola consola = Consola::obtenerInstancia();

	// Muestra el nombre y la descripci�n de la situaci�n
	consola.imprimirCadena("~~~~~~~~ " + getNombre() + " ~~~~~~~~");
	consola.imprimirCadena(getDescripcion());

	// Muestra la informaci�n de cada opci�n
	unsigned int i;
	for (i = 0; i < opciones.size(); ++i) {
		opciones[i]->imprimirOpcion();
	}

	// Muestra una l�nea delimitadora
	consola.imprimirCadena("~~~~~~~~~" + std::string(getNombre().size(), '~') + "~~~~~~~~~");
}

void Situacion::elegirOpcion(std::string accion, std::string objetivo)
{
	unsigned int i;
	for (i = 0; i < opciones.size(); ++i) {
		Opcion* opcion = opciones[i];
		if (opcion->accionCompatible(accion)) {
			opcion->elegirOpcion(objetivo);
			break;
		}
	}
}