#include "stdafx.h"

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

std::vector<std::string> &separarCadena(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> separarCadena(const std::string &s, char delim) {
	std::vector<std::string> elems;
	separarCadena(s, delim, elems);
	return elems;
}