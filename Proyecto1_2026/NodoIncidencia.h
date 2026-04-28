#pragma once
#include <string>
#include "Incidencia.h"
class NodoIncidencia
{
private:
	NodoIncidencia* Siguiente;
	Incidencia* Dato;
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

