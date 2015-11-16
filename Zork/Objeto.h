#pragma once
#include "stdafx.h"

class Objeto {

public:
	Objeto(const std::string codigoObjeto, const std::vector<std::string> nombres);
	const std::string getCodigoObjeto();
	bool tieneNombre(const std::string nombre);
	const std::vector<std::string> getNombres();

private:
	std::string codigoObjeto;
	std::vector<std::string> nombres;
};