#pragma once

#include "stdafx.h"

class OpcionMoverse : public Opcion {

public:
	OpcionMoverse(std::string descripcion, Situacion* norte, Situacion* sur, Situacion* este, Situacion* oeste, Situacion* arriba, Situacion* abajo);
	virtual void elegirOpcion(std::string objetivo);
};