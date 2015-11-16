#include "stdafx.h"

#include "AccionCondicional.h"
#include "AccionCogerObjeto.h"

#include "PredicadoObjetivo.h"

//************** MÉTODOS *************

// Propios
const std::string Situacion::getCodigoSituacion()
{
	return codigoSituacion;
}

const std::string Situacion::getNombre()
{
	return nombre;
}

const std::string Situacion::getDescripcion()
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
			return;
		}
	}
	Consola::obtenerInstancia().imprimirCadena("\n-> " + accion + " is not a valid action.\n");
}

void Situacion::addObjeto(Objeto* objeto)
{
	objetos[objeto->getCodigoObjeto()] = objeto;
}

void Situacion::removeObjeto(Objeto* objeto)
{
	objetos.erase(objeto->getCodigoObjeto());
}

Objeto* Situacion::getObjeto(std::string codigoObjeto)
{
	if (objetos.count(codigoObjeto) == 0)
		return NULL;
	else
		return objetos[codigoObjeto];
}

Objeto* Situacion::getObjetoPorNombre(std::string nombre)
{
	std::unordered_map<std::string, Objeto*>::iterator it;
	for (it = objetos.begin(); it != objetos.end(); ++it)
		if (it->second != NULL && it->second->tieneNombre(nombre))
			return it->second;
	return NULL;
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

void Situacion::cargarOpcionesDeObjetos()
{
	std::unordered_map<std::string, Objeto*>::iterator it;
	for (it = objetos.begin(); it != objetos.end(); ++it) {
		Opcion* opcion = new Opcion({ "pick", "take" });
		opcion->addAccion(new AccionCondicional(new PredicadoObjetivo(it->second->getNombres()), new AccionCogerObjeto("* There is a " + it->second->getNombres()[0] + " near by.", it->second)));
		opciones.push_back(*opcion);
	}
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
