#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionConseguirObjeto : public AccionConMensaje {

public:
	AccionConseguirObjeto(Objeto* objeto);
	AccionConseguirObjeto(const std::string mensaje, Objeto* objeto);
	virtual bool realizarAccion(const std::string objetivo);

private:
	Objeto* objeto;
};