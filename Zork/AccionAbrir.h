#pragma once

#include "stdafx.h"

class AccionAbrir : public Accion {

public:
	AccionAbrir(std::string objetivo, std::string destino);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string objetivo;
	std::string destino;
};