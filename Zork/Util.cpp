#include "stdafx.h"
#include <string>

bool compararCadenasSinMayusculas(const std::string& cadena1, const std::string& cadena2)
{
	unsigned int longitud = cadena1.size();
	if (cadena2.size() != longitud) {
		return false;
	}
	unsigned int i = 0;
	for (i = 0; i < longitud; ++i) {
		if (tolower(cadena1[i]) != tolower(cadena2[i])) {
			return false;
		}
	}
	return true;
}