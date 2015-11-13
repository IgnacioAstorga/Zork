#include "stdafx.h"

//************** MÉTODOS *************

// Propios
std::string Situacion::getCodigoSituacion()
{
	return codigoSituacion;
}

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

	// Muestra el nombre y la descripción de la situación
	consola.imprimirCadena("~~~~~~~~ " + getNombre() + " ~~~~~~~~");
	consola.imprimirCadena(getDescripcion());

	// Muestra la información de cada opción
	unsigned int i;
	for (i = 0; i < opciones.size(); ++i) {
		opciones[i].imprimirOpcion();
	}

	// Muestra una línea delimitadora
	consola.imprimirCadena("~~~~~~~~~" + std::string(getNombre().size(), '~') + "~~~~~~~~~");
}

void Situacion::elegirOpcion(std::string accion, std::string objetivo)
{
	unsigned int i;
	for (i = 0; i < opciones.size(); ++i) {
		Opcion opcion = opciones[i];
		if (opcion.accionCompatible(accion)) {
			opcion.elegirOpcion(objetivo);
			break;
		}
	}
}

void Situacion::setFlag(std::string flag, int valor)
{
	mapaFlags[flag] = valor;
}

int Situacion::getFlag(std::string flag)
{
	if (mapaFlags.count(flag) != 0)
		return mapaFlags[flag];
	else
		return -1;
}

// Protegidos
void Situacion::setCodigoSituacion(std::string p_codigoSituacion)
{
	codigoSituacion = p_codigoSituacion;
}

void Situacion::setNombre(std::string p_nombre)
{
	nombre = p_nombre;
}

void Situacion::setDescripcion(std::string P_descripcion)
{
	descripcion = P_descripcion;
}

std::vector<Opcion>* Situacion::getOpciones()
{
	return &opciones;
}
