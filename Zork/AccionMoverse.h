#pragma once

#include "stdafx.h"

class AccionMoverse : public Accion {

public:
	AccionMoverse(std::string norte, std::string sur, std::string este, std::string oeste, std::string arriba, std::string abajo);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string norte;
	std::string sur;
	std::string este;
	std::string oeste;
	std::string arriba;
	std::string abajo;
};