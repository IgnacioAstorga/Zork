#include "stdafx.h"

//************ VARIABLES *************

Juego* Juego::instancia = NULL;

//********** CONSTRUCTORES ***********

Juego::Juego() {};

//************** MÉTODOS *************

// Estáticos
void Juego::inicializar() {
	if (instancia == NULL) {
		instancia = new Juego();
	}
}

Juego& Juego::obtenerInstancia()
{
	return *instancia;
}

bool Juego::isJuegoAcabado()
{
	return juegoAcabado;
}

void Juego::setJuegoAcabado(bool p_juegoAcabado)
{
	juegoAcabado = p_juegoAcabado;
}

// Propios
void Juego::iniciar()
{
	Consola consola = Consola::obtenerInstancia();

	// Establece la situación inicial
	Mundo::obtenerInstancia().setSituacionActual(Mundo::obtenerInstancia().getSituacion("situacion_inicial"));

	// Muestra el mensaje inicial
	mostrarMensajeInicial(consola);
	mostrarComandosIniciales(consola);

	while (true) {
		// Pide la acción inicial
		std::string cadena = consola.leerCadena();
		if (cadena == "help") {
			// Muestra la ayuda del juego
			mostrarAyuda(consola);
			mostrarComandosIniciales(consola);
		}
		else if (cadena == "start") {
			// Empieza el juego
			setJuegoAcabado(false);
			jugar();
			break;
		}
		else if (cadena == "exit") {
			// Cierra el juego
			cerrarJuego();
			break;
		}
		else {
			// Cadena no reconocida
			mostrarCadenaDesconocida(consola);
			mostrarComandosIniciales(consola);
		}
	}
}

void Juego::mostrarComandosIniciales(Consola consola) {
	consola.imprimirCadena("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	consola.imprimirCadena("* Write \"help\" to see a short guide about the game.");
	consola.imprimirCadena("* Write \"start\" to start your adventure.");
	consola.imprimirCadena("* Write \"exit\" to close the game.");
	consola.imprimirCadena("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void Juego::mostrarMensajeInicial(Consola consola) {
	consola.imprimirCadena("~~~~~~~~~~~~~~ ZORK ~~~~~~~~~~~~~~~");
	consola.imprimirCadena("Welcome to Zork!");
	consola.imprimirCadena("This game was made by Ignacio Astorga Coto and it's a test for the Master in Videogame Desgin and Creation of the UPC.");
}

void Juego::mostrarAyuda(Consola consola) {
	consola.imprimirCadena("~~~~~~~~~~~~~~ HELP ~~~~~~~~~~~~~~~");
	consola.imprimirCadena("Zork is adventure game where you use you keyboard to explore and interact with the world.");
	consola.imprimirCadena("Each time the game asks your for an action, you'll have to write what your choice is.");
	consola.imprimirCadena("-> To make a choice, write it in the console.");
	consola.imprimirCadena("-> Each choice follows the schema \"verb target\".");
	consola.imprimirCadena("-> The verb is the action itself, like \"open\", \"go\" or \"use\".");
	consola.imprimirCadena("-> The target completes the action, like \"open door\", \"go north\" or \"use switch\".");
	consola.imprimirCadena("-> If you write something wrong, the game will ask you again.");
}

void Juego::mostrarCadenaDesconocida(Consola consola) {
	// En principio no se muestra nada especial, se volverán a mostrar las opciones del menú
	//consola.imprimirCadena("~~~~~~~~~~~~~~ ERROR ~~~~~~~~~~~~~~~");
	//consola.imprimirCadena("Unrecognized option.");
}

void Juego::cerrarJuego() {
	// No es necesario hacer nada, el flujo de operaciones finalizará el programa automáticamente
}

void Juego::jugar() {
	while (!isJuegoAcabado()) {
		// Muestra la información de la situación actual
		Situacion* situacionActual = &Mundo::obtenerInstancia().getSituacionActual();
		situacionActual->cargarSituacion();
		situacionActual->imprimirSituacion();

		// Solicita la orden del jugador y la procesa
		std::string orden = Consola::obtenerInstancia().leerCadena();
		std::vector<std::string> separado = separarCadena(orden, ' ');
		std::string accion = separado[0];
		std::string objetivo = separado.size() > 1 ? separado[1] : "";

		// Pasa la orden procesada a la situación
		Mundo::obtenerInstancia().setObjetivoActual(objetivo);
		situacionActual->elegirOpcion(accion, objetivo);
	}

	// Reinicia el juego
	iniciar();
}

void Juego::perder(std::string mensaje) {
	Consola consola = Consola::obtenerInstancia();
	consola.imprimirCadena("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	consola.imprimirCadena("~~~~~~~~~~~~ GAME OVER ~~~~~~~~~~~~");
	consola.imprimirCadena("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	consola.imprimirCadena(mensaje);
	consola.imprimirCadena("");

	setJuegoAcabado(true);
}