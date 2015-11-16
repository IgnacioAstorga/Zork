#include "stdafx.h"

//************ VARIABLES *************

Consola* Consola::instancia = NULL;

//********** CONSTRUCTORES ***********

Consola::Consola() {};

//************** MÉTODOS *************

// Estáticos
void Consola::inicializar() {
	instancia = new Consola();
}

Consola& Consola::obtenerInstancia()
{
	return *instancia;
}

// Propios
void Consola::imprimirCadena(std::string cadena)
{
	std::cout << cadena << "\n";
}

const std::string Consola::leerCadena()
{
	std::string cadena;
	std::getline(std::cin, cadena);
	return cadena;
}