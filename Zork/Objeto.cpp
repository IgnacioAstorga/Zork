#include "stdafx.h"

Objeto::Objeto(std::string p_codigoObjeto)
{
	codigoObjeto = p_codigoObjeto;
}

std::string Objeto::getCodigoObjeto()
{
	return codigoObjeto;
}
