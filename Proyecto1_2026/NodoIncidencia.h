#pragma once
#include <string>
#include "Incidencia.h"
class NodoIncidencia
{
private:
	NodoIncidencia* siguiente;
	Incidencia* dato;
public:
	NodoIncidencia(NodoIncidencia* Siguiente, Incidencia* Dato);
	~NodoIncidencia();
	//gets
	Incidencia* getDato();
	NodoIncidencia* getSiguiente();
	//sets
	void setIncidencia(Incidencia* Dato);
	void setSiguiente(NodoIncidencia* Siguiente);
};

