#pragma once

#include "stdafx.h"

class OpcionMoverse : public Opcion {

public:
	OpcionMoverse(std::string descripcion, std::string norte, std::string sur, std::string este, std::string oeste, std::string arriba, std::string abajo);
	virtual void elegirOpcion(std::string objetivo);

private:
	std::string norte;
	std::string sur;
	std::string este;
	std::string oeste;
	std::string arriba;
	std::string abajo;
};