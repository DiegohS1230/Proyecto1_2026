#pragma once
#include "Equipo.h"
class NodoEquipo
{
private:
	Equipo* dato;
	NodoEquipo* siguiente;
public:
	NodoEquipo(Equipo* dato, NodoEquipo* siguiente);
	~NodoEquipo();
	//gets
	Equipo* getDato();
	NodoEquipo* getSiguiente();
	//sets
	void setDato(Equipo* dato);
	void setNodoSiguiente(NodoEquipo* siguiente);
};

