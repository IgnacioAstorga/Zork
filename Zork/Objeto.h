#pragma once
#include "stdafx.h"

class Objeto {

public:
	Objeto(std::string codigoObjeto);
	std::string getCodigoObjeto();

private:
	std::string codigoObjeto;
};