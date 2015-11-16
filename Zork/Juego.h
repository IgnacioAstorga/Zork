#pragma once

#include "stdafx.h"

#include "Opcion.h"

class Juego {

public:
	static void inicializar();
	static Juego& obtenerInstancia();
	bool isJuegoAcabado();
	void setJuegoAcabado(bool juegoAcabado);
	void iniciar();
	void jugar();
	void perder(const std::string mensaje);

protected:
	Juego();

private:
	static Juego* instancia;
	std::vector<Opcion*> opcionesGlobales;
	bool juegoAcabado;
	void mostrarComandosIniciales(Consola consola);
	void mostrarMensajeInicial(Consola consola);
	void mostrarAyuda(Consola consola);
	void mostrarCadenaDesconocida(Consola consola);
	void cerrarJuego();
	bool elegirOpcionGlobal(const std::string accion, const std::string objetivo);
};