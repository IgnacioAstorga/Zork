#pragma once
#include "stdafx.h"

class Juego {

public:
	static void inicializar();
	static Juego& obtenerInstancia();
	bool isJuegoAcabado();
	void setJuegoAcabado(bool juegoAcabado);
	void iniciar();
	void jugar();
	void perder();

protected:
	Juego();

private:
	static Juego* instancia;
	bool juegoAcabado;
	void mostrarComandosIniciales(Consola consola);
	void mostrarMensajeInicial(Consola consola);
	void mostrarAyuda(Consola consola);
	void mostrarCadenaDesconocida(Consola consola);
	void cerrarJuego();
};