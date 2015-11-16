#include "stdafx.h"

Objeto::Objeto(std::string p_codigoObjeto, std::vector<std::string> p_nombres)
{
	codigoObjeto = p_codigoObjeto;
	nombres = p_nombres;
}

const std::string Objeto::getCodigoObjeto()
{
	return codigoObjeto;
}

bool Objeto::tieneNombre(std::string nombre)
{
	unsigned int i;
	for (i = 0; i < nombres.size(); ++i)
		if (nombres[i] == nombre)
			return true;
	return false;
}

const std::vector<std::string> Objeto::getNombres()
{
	return nombres;
}
