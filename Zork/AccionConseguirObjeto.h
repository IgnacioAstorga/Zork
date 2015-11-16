#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionConseguirObjeto : public AccionConMensaje {

public:
	AccionConseguirObjeto(Objeto* objeto);
	AccionConseguirObjeto(std::string mensaje, Objeto* objeto);
	virtual bool realizarAccion(std::string objetivo);

private:
	Objeto* objeto;
};