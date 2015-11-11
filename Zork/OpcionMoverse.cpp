#include "stdafx.h"

#include "OpcionMoverse.h"

OpcionMoverse::OpcionMoverse(std::string descripcion, Situacion * norte, Situacion * sur, Situacion * este, Situacion * oeste, Situacion * arriba, Situacion * abajo)
	: Opcion(descripcion, accionesCompatibles)
{
	std::vector<std::string> accionesCompatibles;
	accionesCompatibles.push_back("go");
	accionesCompatibles.push_back("travel");
}

void OpcionMoverse::elegirOpcion(std::string objetivo)
{
	// TODO
}