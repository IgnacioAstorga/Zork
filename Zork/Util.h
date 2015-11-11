#pragma once
#include "stdafx.h"

bool compararCadenasSinMayusculas(const std::string& cadena1, const std::string& cadena2);

std::vector<std::string> &separarCadena(const std::string &s, char delim, std::vector<std::string> &elems);

std::vector<std::string> separarCadena(const std::string &s, char delim);