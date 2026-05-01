#pragma once
#include "Mantenimiento.h"
class NodoMante
{
private:
	Mantenimiento* dato;
	NodoMante* siguiente;
public:
	NodoMante(Mantenimiento* dato, NodoMante* siguiente);
	~NodoMante();
	//gets
	Mantenimiento* getDato();
	NodoMante* getSiguiente();
	//sets
	void setDato(Mantenimiento* dato);
	void setNodoSiguiente(NodoMante* siguiente);
};

